function [h] = hgtransform_init()
%hgtransform_init 移動オブジェクト初期設定
%現在の軸に対する移動オブジェクトを生成
ax = gca;
h = hgtransform('Parent',ax);
end

