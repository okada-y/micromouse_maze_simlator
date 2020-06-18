clearvars
close all
clc
%% パス定義
currentdir = cd;
addpath(strcat(currentdir,'/src'),'-end')

%% デバッグモード定義
    global maze_data_get_debug;
    maze_data_get_debug = 0;   

%% シミュレーションモード選択
    sim_mode.unknown = uint8(0); %壁情報がない状態から、探索、最短の実行
    sim_mode.known = uint8(1); %壁情報を既知として、最短の実行
    
    %シミュレーションモードに応じて以下を変更
    sim_mode_flg = sim_mode.unknown;
    %sim_mode_flg = sim_mode.known;
%% mode定義
    r_mode.search = uint8(0);
    r_mode.fust_run = uint8(1);
    r_mode.fust_run_diagonal = uint8(2);
%% 迷路データ取得
global  maze_serial;
 [maze_row_size,maze_col_size,maze_row_data,maze_col_data] = maze_data_get;
 maze_row_size = uint8(maze_row_size);
 maze_col_size = uint8(maze_col_size);

 maze_data_to_serial(maze_row_size,maze_col_size,maze_row_data,maze_col_data);
%% 迷路をプロット

%プロットするfigure,axisを定義
global maze_fig;
global maze_fig_ax;
maze_fig_ax = gca;
maze_fig = gcf;

%figureの出力位置
maze_fig.Position = [1,41,1920,963];

%%
maze_data_plot(maze_row_size,maze_col_size,maze_row_data,maze_col_data);
%% 迷路パラメータ設定
global maze_goal
maze_goal = uint8(zeros(9,2));

%指定する迷路に合わせてゴール座標、サイズを変更
%大会名　　　x  y size
%2019全日本　18 14 9
%2019中部　　7 10 4
%2018関東　 10 10 4
%2018全セミ 13 13 4 

goal_size = uint8(4);%ゴールサイズを入力する
goal_x = 10;%ゴール左下のx座標
goal_y = 10;%ゴール左下のy座標


goal_size_d = double(goal_size);

%ゴール座標入力
for i = 1:sqrt(goal_size_d)
    for l = 1:sqrt(goal_size_d)
        maze_goal((l-1)*sqrt(goal_size_d)+i,:) = [goal_x+(i-1),goal_y+(l-1)];
    end
end

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

if sim_mode_flg == sim_mode.unknown
    %% 足立法で探索

    %% 迷路情報初期化
    [maze_wall,maze_wall_search] = maze_init(maze_row_size,maze_col_size);
    maze_wall_plotall(maze_row_size,maze_col_size,maze_wall);

    %% モード定義
    run_mode = r_mode.search;
    [maze_wall,maze_wall_search,contour_map] = maze_solve(maze_wall,maze_wall_search,maze_row_size,maze_col_size,goal_size,run_mode);

    %% 探索情報をもとに最短走行

    %モード定義
    run_mode = r_mode.fust_run;
    [maze_wall,maze_wall_search,contour_map] = maze_solve(maze_wall,maze_wall_search,maze_row_size,maze_col_size,goal_size,run_mode);
end

if sim_mode_flg == sim_mode.known
%% 全壁を既知とした最短走行
    
    %モード定義
    run_mode = r_mode.fust_run_diagonal;
    maze_wall_search = ones(32,32,'uint8')*15;
    [maze_wall,maze_wall_search,contour_map,row_num_node,col_num_node] = maze_solve(maze_serial,maze_wall_search,maze_row_size,maze_col_size,goal_size,run_mode);


end


