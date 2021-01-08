%% 迷路ログ取得

addpath('C:\Users\岡田 泰裕\OneDrive\マイクロマウス\02_開発環境\matlab\logger')   
addpath('./src')   
maze_log


%% ログをプロット
close all
%% 迷路をプロット

%プロットするfigure,axisを定義
global maze_fig;
global maze_fig_ax;


%プロット形式整え
maze_fig_ax = gca;
set(maze_fig_ax,'color','none','NextPlot','add');
maze_fig = gcf;
%figureの出力位置
maze_fig.Position = [2,42,958,954];
maze_step =  9;
maze_x_size = double(maze_x_size);
maze_y_size = double(maze_y_size);

[poleX,poleY] = meshgrid(0:maze_step:(maze_y_size-1)*maze_step,0:maze_step:(maze_x_size-1)*maze_step);
plot(poleX,poleY,'s','MarkerSize',5,...
    'MarkerEdgeColor',[0 0 0],...
    'MarkerFaceColor',[0.5 0.5 0.5]);
xlim([0 (maze_y_size-1)*maze_step])
ylim([0 (maze_x_size-1)*maze_step])
xticks(0:maze_step/2:(maze_y_size-1)*maze_step)
yticks(0:maze_step/2:(maze_x_size-1)*maze_step)
xticklabels({})
yticklabels({})
pbaspect([1 1 1])
grid on

maze_fig_ax.TickLength = [0.0 0.0];

%ログデータプロット
maze_wall_plotall(maze_y_size,maze_x_size,maze_wall_data);
maze_search_plot(maze_search_data,maze_y_size,maze_x_size,9);

%% ログから、経路算出
maze_goal = maze_goal_col;
%モード定義
%% mode定義
%走行モード(run_mode_1)
run_mode1.search = uint8(0);
run_mode1.fust_run = uint8(1);
%探索モード(run_mode_2)
run_mode_2_search.adachi = uint8(0);
run_mode_2_search.all = uint8(1);
run_mode_2_search.short = uint8(2);
run_mode_2_fust.straight = uint8(0);
run_mode_2_fust.diagonal = uint8(1);
%モード選択
run_mode1_flg = run_mode1.fust_run;
run_mode2_flg = run_mode_2_fust.diagonal;

[maze_wall,maze_wall_search,contour_map] = maze_solve(maze_wall_data,maze_search_data,maze_y_size,maze_x_size,maze_goal_size,maze_goal,run_mode1_flg,run_mode2_flg);
   