function [h] = hgtransform_init()
%hgtransform_init 移動オブジェクト初期設定
%現在の軸に対する移動オブジェクトを生成
global maze_fig_ax;
h = hgtransform('Parent',maze_fig_ax);
end

