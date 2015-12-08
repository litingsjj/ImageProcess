function fcnTestModelZoo()
% Test the FCN models imported from Caffe ModelZoo into MatConvNet

model = 'fcn32s';
model = 'fcn16s' ;
model = 'fcn8s' ;
model = 'fcn8s-tvg-voc12' ;
model = 'fcn8s-tvg-voc11' ;

switch model
  case {'fcn32s', 'fcn16s', 'fcn8s'}
    fcnTest('modelPath', sprintf('matconvnet/data/models/pascal-%s-dag.mat',model), ...
            'modelFamily', 'ModelZoo', ...
            'expDir', 'data/fcn-voc11', ...
            'dataDir', 'data/voc11', ...
            'vocEdition', '11', ...
            'vocAdditionalSegmentations', true, ...
            'vocAdditionalSegmentationsMergeMode', 2) ;

  case {'fcn8s-tvg-voc12'}
    fcnTest('modelPath', 'matconvnet/data/models/pascal-fcn8s-tvg-dag.mat', ...
            'modelFamily', 'TVG', ...
            'expDir', 'data/fcn-tvg-voc12', ...
            'dataDir', 'data/voc12', ...
            'vocEdition', '12', ...
            'vocAdditionalSegmentations', true, ...
            'vocAdditionalSegmentationsMergeMode', 3) ;

  case {'fcn8s-tvg-voc11'}
    fcnTest('modelPath', 'matconvnet/data/models/pascal-fcn8s-tvg-dag.mat', ...
            'modelFamily', 'TVG', ...
            'expDir', 'data/fcn-tvg-voc11', ...
            'dataDir', 'data/voc11', ...
            'vocEdition', '11', ...
            'vocAdditionalSegmentations', true, ...
            'vocAdditionalSegmentationsMergeMode', 2) ;
end