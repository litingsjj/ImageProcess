function []=cnn_1024_naive_SVM()

% optimization finished, #iter = 5351
% nu = 0.000230
% obj = -6.906240, rho = 1.294614
% nSV = 209, nBSV = 0
% Total nSV = 209
% Accuracy = 75.1073% (525/699) (classification)
  
load('net-epoch-x.mat');
  
  data_mean_path='dataset/data_mean.mat';
  global feature_path;
  feature_path='dataset/feat_cnn_1024/';
  neg_path='cropped/neg/';
  pos_path='cropped/pos/';
  load(data_mean_path);
  global data_mean;
  data_mean=imresize(data_mean,[net.normalization.imageSize(1,1),net.normalization.imageSize(1,2)]);
  net.layers{end}.type = 'softmax';
 
  global net;
  %tst1=[tst1,val1,trn1];
  
 'Loading training and testing data...'
 
 [pos_trn_data,pos_trn_label,pos_tst_data,pos_tst_label]=get_trn_tst_data(pos_path,300,840,[feature_path,'pos/'],1);
 [neg_trn_data,neg_trn_label,neg_tst_data,neg_tst_label]=get_trn_tst_data(neg_path,300,459,[feature_path,'neg/'],-1);

   %%
   %Training SVM...
  % [bestCVaccuarcy,bestc,bestg,pso_option] = psoSVMcgForClass([pos_trn_label;neg_trn_label],[pos_trn_data;neg_trn_data]);
   svmmodel=svmtrain([pos_trn_label;neg_trn_label],[pos_trn_data;neg_trn_data],'-s 0 -t 0 -c 100 -g 0.01');
   %clear train_label;
  % clear train_feat;
   [predict_label, accuracy, prob] = svmpredict([pos_tst_label;neg_tst_label], [pos_tst_data;neg_tst_data], svmmodel);
   
end

function [trn_data,trn_label,tst_data,tst_label]=get_trn_tst_data(path,trn_absolute_value,all_count,feature_root_path,present_label)

global data_mean;
global net;
trn_data=[];
trn_label=[];
tst_data=[];
tst_label=[];

for i=1:all_count
  im_filename=[path,'image_',sprintf('%04d',i),'.jpg'];
  feat_filename=[feature_root_path,'image_',sprintf('%04d',i),'.mat']
  if (~exist(feat_filename,'file'))
      im=imread(im_filename);
      im=imresize(im,[net.normalization.imageSize(1,1),net.normalization.imageSize(1,2)]);
      im=double(im)-data_mean;
      im=single(im);
      res=vl_simplenn(net,im);
      tmp_feat=gather(res(20).x(:)');
      save(feat_filename,'tmp_feat');
  else
      load(feat_filename);
  end
  
  if (i<=trn_absolute_value)
      trn_data=[trn_data;tmp_feat];
      trn_label=[trn_label;present_label];
  else
      tst_data=[tst_data;tmp_feat];
      tst_label=[tst_label;present_label];
  end
end

trn_data=double(trn_data);
tst_data=double(tst_data);
end