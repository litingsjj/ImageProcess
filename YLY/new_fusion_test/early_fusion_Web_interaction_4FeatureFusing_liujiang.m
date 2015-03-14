clear all;
clc;
experi_folder = {'Traj','HOG','HOF','MBHx','MBHy','HOGHOF','MBHxMBHy','TrajHOG','TrajHOF','TrajHOGHOF','TrajMBHx','TrajMBHy','TrajMBHxMBHy','HOGHOFMBHxMBHy','ALL','STIP','3DSIFT','MoSIFT','SIFT'};
cls = {'chase','exchange_object','handshake','highfive','hug','hustle','kick','kiss','pat'};
try
    addpath(genpath('libsvm-3.18'));
catch
end
for experi_num = [1,4]
    
    result = [];
    score = [];
    accuracy_vector = [];
    for test_fold= 1:1:10   %ÿѭ��һ�� ��һ�飨5����������Ϊtest
        mkdir('/data/collegestudent/liujiang/YLY/new_fusion_test/storage/',[char(cellstr(experi_folder(experi_num))),'+STIP+SIFT+MoSIFT']);  %/data/collegestudent/liujiang/YLY/new_fusion_test/storage is the path that you store the results
        %---------------------------------------------------------------------------------------------------------------------
        %                                                                                               load feature and label
        %---------------------------------------------------------------------------------------------------------------------
        %---------------------------training data------------------------
        
        feature_struct1 = load(['/data/collegestudent/liujiang/YLY/new_fusion_test/feature/',char(cellstr(experi_folder(16))),'/',char(cellstr(cls(1))),'/',sprintf('%06d',1)]);  %/data/collegestudent/liujiang/YLY/new_fusion_test/feature is the path that holds all the encoded features
        feature_struct2 = load(['/data/collegestudent/liujiang/YLY/new_fusion_test/feature/',char(cellstr(experi_folder(18))),'/',char(cellstr(cls(1))),'/',sprintf('%06d',1)]);  %/data/collegestudent/liujiang/YLY/new_fusion_test/feature is the path that holds all the encoded features
        feature_struct3 = load(['/data/collegestudent/liujiang/YLY/new_fusion_test/feature/',char(cellstr(experi_folder(19))),'/',char(cellstr(cls(1))),'/',sprintf('%06d',1)]);%/data/collegestudent/liujiang/YLY/new_fusion_test/feature is the path that holds all the encoded features
        feature_struct4 = load(['/data/collegestudent/liujiang/YLY/new_fusion_test/feature/',char(cellstr(experi_folder(experi_num))),'/',char(cellstr(cls(1))),'/',sprintf('%06d',1)]);%/data/collegestudent/liujiang/YLY/new_fusion_test/feature is the path that holds all the encoded features
        
        feature_dim = length(feature_struct1.encoding) + length(feature_struct2.encoding) + length(feature_struct3.encoding) + length(feature_struct4.encoding);
        
        training_instance_matrix = zeros(405, feature_dim);
        training_label_vector = [];
        testing_instance_matrix = zeros(45, feature_dim);
        testing_label_vector = [];
        training_ordinal = [];
        
        %��training_ordinal����ѵ�����������
        test_begin = (test_fold-1) * 5 + 1;
        test_end = test_begin + 4;
        for ordinal = [1:test_begin-1,test_end+1:50]
            training_ordinal = [training_ordinal;ordinal];
        end
        
        
        for cls_num = 1:1:9
            for seq_pnt = 1:1:45 %seq_pnt����ָ��training_ordinal�е�ÿһ��Ԫ��
   
                feature_struct1 = load(['/data/collegestudent/liujiang/YLY/new_fusion_test/feature/',char(cellstr(experi_folder(16))),'/',char(cellstr(cls(cls_num))),'/',sprintf('%06d',training_ordinal(seq_pnt))]);   %/data/collegestudent/liujiang/YLY/new_fusion_test/feature is the path that holds all the encoded features
                feature1 = feature_struct1.encoding;
                feature_struct2 = load(['/data/collegestudent/liujiang/YLY/new_fusion_test/feature/',char(cellstr(experi_folder(18))),'/',char(cellstr(cls(cls_num))),'/',sprintf('%06d',training_ordinal(seq_pnt))]);  %/data/collegestudent/liujiang/YLY/new_fusion_test/feature is the path that holds all the encoded features
                feature2 = feature_struct2.encoding;
                feature_struct3 = load(['/data/collegestudent/liujiang/YLY/new_fusion_test/feature/',char(cellstr(experi_folder(19))),'/',char(cellstr(cls(cls_num))),'/',sprintf('%06d',training_ordinal(seq_pnt))]);%/data/collegestudent/liujiang/YLY/new_fusion_test/feature is the path that holds all the encoded features
                feature3 = feature_struct3.encoding;
                feature_struct4 = load(['/data/collegestudent/liujiang/YLY/new_fusion_test/feature/',char(cellstr(experi_folder(experi_num))),'/',char(cellstr(cls(cls_num))),'/',sprintf('%06d',training_ordinal(seq_pnt))]);%/data/collegestudent/liujiang/YLY/new_fusion_test/feature is the path that holds all the encoded features
                feature4 = feature_struct4.encoding;
                feature = [feature1;feature2;feature3;feature4];
                training_instance_matrix((cls_num-1)*45+seq_pnt,:) = feature';
                training_label_vector = [training_label_vector;cls_num];
            end
            %     end
        end
        
        %---------------------------testing data------------------------
        for cls_num = 1:1:9
            loop = 0;
            for test_seq_num = test_begin:1:test_end
                loop = loop+1;

                feature_struct1 = load(['/data/collegestudent/liujiang/YLY/new_fusion_test/feature/',char(cellstr(experi_folder(16))),'/',char(cellstr(cls(cls_num))),'/',sprintf('%06d',test_seq_num)]);  %/data/collegestudent/liujiang/YLY/new_fusion_test/feature is the path that holds all the encoded features
                feature1 = feature_struct1.encoding;
                feature_struct2 = load(['/data/collegestudent/liujiang/YLY/new_fusion_test/feature/',char(cellstr(experi_folder(18))),'/',char(cellstr(cls(cls_num))),'/',sprintf('%06d',test_seq_num)]);  %/data/collegestudent/liujiang/YLY/new_fusion_test/feature is the path that holds all the encoded features
                feature2 = feature_struct2.encoding;
                feature_struct3 = load(['/data/collegestudent/liujiang/YLY/new_fusion_test/feature/',char(cellstr(experi_folder(19))),'/',char(cellstr(cls(cls_num))),'/',sprintf('%06d',test_seq_num)]);  %/data/collegestudent/liujiang/YLY/new_fusion_test/feature is the path that holds all the encoded features
                feature3 = feature_struct3.encoding;
                feature_struct4 = load(['/data/collegestudent/liujiang/YLY/new_fusion_test/feature/',char(cellstr(experi_folder(experi_num))),'/',char(cellstr(cls(cls_num))),'/',sprintf('%06d',test_seq_num)]);  %/data/collegestudent/liujiang/YLY/new_fusion_test/feature is the path that holds all the encoded features
                feature4 = feature_struct4.encoding;
                feature = [feature1;feature2;feature3;feature4];
                testing_instance_matrix((cls_num-1)*5+loop,:) = feature';
                testing_label_vector = [testing_label_vector;cls_num];
            end
        end
        
        %---------------------------------------------------------------------------------------------------------------------
        %                                                                                           scale before training
        %---------------------------------------------------------------------------------------------------------------------
        %     scale_instance = max(max(training_instance_matrix));
        %     scale_label = max(training_label_vector);
        %     training_instance_matrix = training_instance_matrix/scale_instance;
        %     training_label_vector = training_label_vector/scale_label;
        %     testing_instance_matrix = testing_instance_matrix/scale_instance;
        %     testing_label_vector = testing_label_vector/scale_label;
        %
        
        
        %---------------------------------------------------------------------------------------------------------------------
        %                                                                                           train with SVM from libsvm
        %---------------------------------------------------------------------------------------------------------------------
        model = svmtrain(training_label_vector, training_instance_matrix, '-s 0 -t 0 -b 1 -c 100');
        %---------------------------------------------------------------------------------------------------------------------
        %                                                                                           test with SVM from libsvm
        %---------------------------------------------------------------------------------------------------------------------
        [predicted_label, accuracy,prob_estimate] = svmpredict(testing_label_vector, testing_instance_matrix, model','-b 1');
        score = [score prob_estimate];
        result = [result predicted_label];
%         save(['/data/collegestudent/liujiang/YLY/new_fusion_test/storage/',char(cellstr(experi_folder(experi_num))),'+STIP+SIFT+MoSIFT','/model',int2str(test_fold),'.mat'],'model'); %����model���ڵ���ĳ����������ʶ��AP���   %/data/collegestudent/liujiang/YLY/new_fusion_test/storage is the path that you store the results
        model = [];
    end
    
    save(['/data/collegestudent/liujiang/YLY/new_fusion_test/storage/',char(cellstr(experi_folder(experi_num))),'+STIP+SIFT+MoSIFT','/result.mat'],'result');  %/data/collegestudent/liujiang/YLY/new_fusion_test/storage is the path that you store the results
    save(['/data/collegestudent/liujiang/YLY/new_fusion_test/storage/',char(cellstr(experi_folder(experi_num))),'+STIP+SIFT+MoSIFT','/score.mat'],'score');  %/data/collegestudent/liujiang/YLY/new_fusion_test/storage is the path that you store the results
end