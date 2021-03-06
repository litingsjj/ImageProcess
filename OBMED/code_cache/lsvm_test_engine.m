%test engine for our lsvm model.
function [accuracy,fval] = lsvm_test_engine(itecount,test_set,test_object,object_bank_word,model_folder)
addpath(genpath('VLFEATROOT/'));
addpath(genpath('libsvm-3.18/'));
  try
      make;
      vl_setup;
  catch
      disp('Error compiling libsvm OR vlfeat..');
      pause;
  end
 
 
 %itecount=1;                    %select models of the n-th iteration.
 load([model_folder,'/',test_object,'_Word_',num2str(object_bank_word),'_1vN_Models_After_ITE_',num2str(itecount),'.mat']);   %load models.
 try
   fval=model.fval;
 catch
    fval=inf;
 end
 success=0; total=0;
 
 datacount=1;
 tests=test_set{datacount}.tests;
 test_label=test_set{datacount}.label;
 featureCount=size(tests,2);
 
 score=[];
 for i=1:featureCount
   feat=tests{i};     %raw feat for each video.
  % feat=feat(:,1:(object_bank_word)*252);
   feat=feat(:,(object_bank_word-1)*252+1:(object_bank_word)*252);
   if (isempty(feat))
      continue;
   end
   
         total=total+1;

       thetaMat=model.thetaMat;
       %first we get the actual feature by multiply feature matrix with
       %pooling-parameter theta.
       vec=thetaMat*feat;
       
       %get decision value by w,b in svm. >0: belongs to pos, <0 belongs to
       %nega.
       decision_values=model.w'*vec'+model.b;

       score=[score;decision_values];

       if (decision_values>0); max_dec_p=1; else max_dec_p=-1;end

       if (test_label(i,1)==max_dec_p)
          success=success+1;
       end
   
   
 end
 %  clc;
    [RECALL, PRECISION, INFOAP]=vl_pr(test_label,score);
    accuracy=INFOAP.ap;
    
   % subplot(1,2,1);
   % vl_pr(test_label,score);
   % plot(recall,precision);
   % subplot(1,2,2);
   % vl_roc(test_label,score);
    
 %   saveas(gcf,['figures/AP_ROC_',test_object,'_ITE_',num2str(itecount),'.fig']);
end

