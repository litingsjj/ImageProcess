function [net, info] = cnn_belt(varargin)

% vl_compilenn('enableGpu', true)
% A test for flower classification.
vl_setupnn;
global im_height,global im_width;
im_height=100;
im_width=100;

opts.expDir = 'model';
opts.imdbPath ='D:/dataset/belt_detection/imdb.mat';
opts.train.batchSize = 30;
opts.train.numEpochs = 300 ;
opts.train.continue = true ;
opts.train.gpus=[] ;
opts.train.learningRate = 0.005 ;

%expDir �Ǵ��cnn model��
opts.train.expDir = opts.expDir ;
opts = vl_argparse(opts, varargin) ;
opts.errorType='binary';

% --------------------------------------------------------------------
%                                                         Prepare data
% --------------------------------------------------------------------

if exist(opts.imdbPath, 'file')
  imdb = load(opts.imdbPath) ;
else
  imdb = generate_head_imdb() ;
  %mkdir(opts.expDir) ;
  save(opts.imdbPath,'-struct','imdb') ;
end

% Define a network similar to LeNet
f=1/100 ;
net.layers = {} ;
net.layers{end+1} = struct('type', 'conv', ...
                           'filters', f*randn(8,8,1,64, 'single'), ...
                           'biases', zeros(1, 64, 'single'), ...
                           'stride', 1, ...
                           'pad', 0) ;
net.layers{end+1} = struct('type', 'pool', ...
                           'method', 'max', ...
                           'pool', [2 2], ...
                           'stride', 2, ...
                           'pad', 0) ;
net.layers{end+1} = struct('type', 'conv', ...
                           'filters', f*randn(5,5,64,64, 'single'),...
                           'biases', zeros(1,64,'single'), ...
                           'stride', 1, ...
                           'pad', 0) ;
net.layers{end+1} = struct('type', 'pool', ...
                           'method', 'max', ...
                           'pool', [2 2], ...
                           'stride', 2, ...
                           'pad', 0) ;
net.layers{end+1} = struct('type', 'conv', ...
                           'filters', f*randn(4,4,64,128, 'single'),...
                           'biases', zeros(1,128,'single'), ...
                           'stride', 1, ...
                           'pad', 0) ;
net.layers{end+1} = struct('type', 'relu') ;
net.layers{end+1} = struct('type', 'conv', ...
                           'filters', f*randn(4,4,128,500, 'single'),...
                           'biases', zeros(1,500,'single'), ...
                           'stride', 1, ...
                           'pad', 0) ;
net.layers{end+1} = struct('type', 'pool', ...
                           'method', 'max', ...
                           'pool', [2 2], ...
                           'stride', 2, ...
                           'pad', 0) ;                      
net.layers{end+1} = struct('type', 'relu') ;                       
net.layers{end+1} = struct('type', 'conv', ...
                           'filters', f*randn(1,1,500,100, 'single'),...
                           'biases', zeros(1,100,'single'), ...
                           'stride', 1, ...
                           'pad', 0) ;
net.layers{end+1} = struct('type', 'conv', ...
                           'filters', f*randn(7,7,100,100, 'single'),...
                           'biases', zeros(1,100,'single'), ...
                           'stride', 1, ...
                           'pad', 0) ;
net.layers{end+1} = struct('type', 'conv', ...
                           'filters', f*randn(1,1,100,2, 'single'),...
                           'biases', zeros(1,2,'single'), ...
                           'stride', 1, ...
                           'pad', 0) ;
net.layers{end+1} = struct('type', 'softmaxloss') ;

% Other details
net.normalization.imageSize = [im_height, im_width, 3] ;
net.normalization.interpolation = 'bicubic' ;
% --------------------------------------------------------------------
%                                                                Train
% --------------------------------------------------------------------

% Take the mean out and make GPU if needed
% if opts.train.useGpu
%   imdb.images.data = gpuArray(imdb.images.data) ;
% end

[net,info] = cnn_train(net, imdb, @getBatch, ...
    opts.train, ...
    'val', find(imdb.images.set == 2)) ;
end


% --------------------------------------------------------------------
function [im, labels] = getBatch(imdb, batch)
 %global im_width;global im_height;
% db_root_path='20flowers/';
% --------------------------------------------------------------------
im = imdb.images.data(:,:,:,batch) ;
% data=zeros(im_height,im_width,3,size(batch,2));
% 
% for i=1:size(batch,2)
%   im_path=[db_root_path,'image_',sprintf('%04d',batch(1,i)),'.jpg'];
%   im_tmp=imread(im_path);
%   im_tmp=double(imresize(im_tmp,[im_height,im_width]));  
%   im_tmp=im_tmp-imdb.images.data_mean;
%   data(:,:,:,i)=im_tmp;
% end
labels = imdb.images.labels(1,batch) ;
im=single(im);
end

% --------------------------------------------------------------------
function imdb = generate_head_imdb()
% --------------------------------------------------------------------
   
%get image mean and image labels.
    global im_width;global im_height;
    pos_db_root_path='D:/dataset/belt_detection/images/belted/';
    neg_db_root_path='D:/dataset/belt_detection/images/belt_free/';
    
    %total count of heads.
    head_pos_count=2858; head_nega_count=1392;
    
    %total count of training samples.
    pos_trn_count=2558; nega_trn_count=1092;
    
    %save raw data.
    data=zeros(im_height,im_width,1,head_pos_count+head_nega_count);
    
    %save data_mean.
    data_mean=double(zeros(im_height,im_width,1));
    labels=zeros(1,head_pos_count+head_nega_count);
    
    %save trn/test label.
    set=zeros(1,head_pos_count+head_nega_count);
    
    for i=1:head_pos_count+head_nega_count
       if (i<=head_pos_count)  %is head
           im_path=[pos_db_root_path,'image_',sprintf('%04d',i),'.jpg'];
           labels(i)=1;
           if (i<=pos_trn_count); set(i)=1;else set(i)=2; end  %1 is train; 2 is test.
       else                    %is not head
           im_path=[neg_db_root_path,'image_',sprintf('%04d',i-head_pos_count),'.jpg'];
           labels(i)=2;
           if (i-head_pos_count<=nega_trn_count); set(i)=1;else set(i)=2; end  %1 is train; 2 is test.
       end
       
       %calculate mean.
       im_tmp=imread(im_path);
       %im_tmp=im_tmp./(max(max(im_tmp))-min(min(im_tmp)))*255;
       %imwrite(im_tmp,im_path);
       im_tmp=double(imresize(im_tmp,[im_height,im_width]));
       data_mean=data_mean+im_tmp;
       data(:,:,:,i)=im_tmp;
      
    end
    
    data_mean=data_mean/(head_pos_count+head_nega_count);
    %save('D:/dataset/belt_detection/data_mean.mat','data_mean');
    for i=1:size(data,4)
      data(:,:,:,i)=data(:,:,:,i)-data_mean;
    
    end
    imdb.images.data_mean=data_mean;                                    %save mean.
    imdb.images.labels=labels;                                          %save labels.
    imdb.images.data=data;                                              %save raw data.
    imdb.images.set=set;                                                %save set id.
    
%     labels=zeros(1,flower_count);
%     
%     load('truth.mat');
%     
%     for i=1:flower_count
%  
%       im_path=[db_root_path,'image_',sprintf('%04d',i),'.jpg'];
%       im_tmp=imread(im_path);
%       im_tmp=double(imresize(im_tmp,[im_height,im_width]));
%       data_mean=data_mean+im_tmp;
%       %data(:,:,:,i)=im_tmp;
%       labels(i)=truth(i,1);
%      
%     end
%     
%     
%     data_mean=data_mean./flower_count;
%     imdb.images.data_mean=data_mean;                                    %save mean.
%     imdb.images.labels=labels;                                          %save labels.
%     %imdb.images.data=data;
%     
% %     for i=1:flower_count
% %         imdb.images.data(:,:,:,i)=imdb.images.data(:,:,:,i)-data_mean;
% %     end
% 
%    
% %get set.(trn,val,tst)
%    load('datasplits.mat');
%    set=zeros(1,flower_count);
%    for i=1:flower_count
%      if (ismember(i,trn1))
%          set(i)=1;
%      elseif (ismember(i,val1))
%          set(i)=1;
%      else
%          set(i)=3;
%      end
%    end
%    
 

end
