clearvars
close all

%% mode定義
    r_mode.search = uint8(0);
    r_mode.fust_run = uint8(1);

%% 迷路データ取得
 [maze_row_size,maze_col_size,maze_row_data,maze_col_data] = maze_data_get;
 maze_row_size = uint8(maze_row_size);
 maze_col_size = uint8(maze_col_size);

 maze_data_to_serial(maze_row_size,maze_col_size,maze_row_data,maze_col_data);
%% 迷路をプロット
map_fig = figure;
maze_data_plot(maze_row_size,maze_col_size,maze_row_data,maze_col_data);
%% 迷路パラメータ設定
%[x,y]とする
maze_goal = uint8(zeros(9,2));
maze_goal(1:4,:) = uint8([7,10; 7,11; 8,10; 8,11]);
goal_size = uint8(4);
%% 壁センサ値初期値入力(Cコード生成用)
%壁センサAD値格納変数
global wall_sensor_front;
global wall_sensor_right;
global wall_sensor_left;
%壁センサ閾値
global wall_sensor_front_th;
global wall_sensor_right_th;
global wall_sensor_left_th;

wall_sensor_front = int16(0);
wall_sensor_right = int16(0);
wall_sensor_left = int16(0);
wall_sensor_front_th = int16(0);
wall_sensor_right_th = int16(0);
wall_sensor_left_th = int16(0);

%% 足立法で探索

%迷路情報初期化
[maze_wall,maze_wall_search] = maze_init(maze_row_size,maze_col_size);
maze_wall_plotall(maze_row_size,maze_col_size,maze_wall);

%モード定義
run_mode = r_mode.search;
[maze_wall,maze_wall_search] = maze_solve(maze_wall,maze_wall_search,maze_row_size,maze_col_size,maze_goal,goal_size,run_mode);

%% 探索情報をもとに最短走行
%モード定義
run_mode = r_mode.fust_run;
maze_solve(maze_wall,maze_wall_search,maze_row_size,maze_col_size,maze_goal,goal_size,run_mode);

%% 全壁を既知とした最短走行

% %% 等高線MAPを作成
% [contour_map,max_length] = make_map(maze_row_size,maze_col_size,maze_goal,maze_sirial);
% %% 等高線マップをプロット 
% contor_fig = figure;
% [x,y]=meshgrid(0.5:1:15.5,0.5:1:15.5);
% surf(x,y,contour_map,'Marker','.','MarkerSize',10,'FaceColor','none','EdgeColor','interp')
% colorbar
% view(2)
% %% 最短経路算出
% figure(map_fig);
% fust_run(maze_sirial,contour_map,maze_goal,max_length);




