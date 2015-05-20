function []=data_prepossessing()
neg_path='cropped/neg/';
pos_path='cropped/pos/';
%filename transfer.
transfer_file_name(neg_path);

data_mean_pos=calculate_mean(pos_path,1076);
data_mean_neg=calculate_mean(neg_path,1676);

data_mean=data_mean_pos;

save('dataset/data_mean.mat','data_mean');
end


function [data_mean]=calculate_mean(path,n)
data_mean=zeros(50,50,3);
  for i=1:n
    file_name=[path,'image_',sprintf('%04d',i),'.jpg'];
    now_im=imread(file_name);
    now_im=double(imresize(now_im,[50 50]));
    data_mean=data_mean+now_im;
  end
  data_mean=data_mean./n;
end

function transfer_file_name(path)
root=(GetPresentPath);
t = cd(path);                        % dos����cd���õ�ǰ·�����������ã����°���ȫ���������ļ�
allnames = struct2cell(dir);             % dos����dir�г����е��ļ�����struct2cellת��ΪԪ������
[m,n] = size(allnames);
fileInfo={};
for i= 3:n                               % ��3��ʼ��ǰ��������ϵͳ�ڲ���
     name = allnames{1,i}                  %  ���ȡ���ļ���
     if ( (findstr(name,'.jpg')>=1))
        filename=[name];                   %   ����ļ���
        fileInfo=[fileInfo;filename];
     end
end

jpgCount=size(fileInfo,1);

clc;
for i=1:jpgCount
  %eval(['!rename', [',',fileInfo{i}] [',image_',sprintf('%04d',i),'.jpg']]);
  im=imread(fileInfo{i});
  imwrite(im,['image_',sprintf('%04d',i),'.jpg']);
  delete(fileInfo{i});
end

t=cd(root);
end

function res=GetPresentPath()
clc;
p1=mfilename('fullpath');
disp(p1);
i=findstr(p1,'/');
if (isempty(i))         %Differ between Linux and Win
    i=findstr(p1,'\');
end
disp(i);
p1=p1(1:i(end));
res=p1;
end