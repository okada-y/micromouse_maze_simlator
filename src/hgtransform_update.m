function [] = hgtransform_update(h,current_x,current_y,search_start_x,search_start_y,maze_step)
%hgtransform_init 移動オブジェクト初期設定
%現在の軸に対する移動オブジェクトを生成
current_x = double(current_x);
current_y = double(current_y);
search_start_x = double(search_start_x);
search_start_y = double(search_start_y);
m = makehgtform('translate',(current_x-search_start_x)*maze_step,(current_y-search_start_y)*maze_step,0);
h.Matrix = m;
end