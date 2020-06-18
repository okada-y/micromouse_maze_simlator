clearvars
close all
clc
%% �p�X��`
currentdir = cd;
addpath(strcat(currentdir,'/src'),'-end')

%% �f�o�b�O���[�h��`
    global maze_data_get_debug;
    maze_data_get_debug = 0;   

%% �V�~�����[�V�������[�h�I��
    sim_mode.unknown = uint8(0); %�Ǐ�񂪂Ȃ���Ԃ���A�T���A�ŒZ�̎��s
    sim_mode.known = uint8(1); %�Ǐ������m�Ƃ��āA�ŒZ�̎��s
    
    %�V�~�����[�V�������[�h�ɉ����Ĉȉ���ύX
    %sim_mode_flg = sim_mode.unknown;
    sim_mode_flg = sim_mode.known;
%% mode��`
    r_mode.search = uint8(0);
    r_mode.fust_run = uint8(1);
    r_mode.fust_run_diagonal = uint8(2);
%% ���H�f�[�^�擾
global  maze_serial;
 [maze_row_size,maze_col_size,maze_row_data,maze_col_data] = maze_data_get;
 maze_row_size = uint8(maze_row_size);
 maze_col_size = uint8(maze_col_size);

 maze_data_to_serial(maze_row_size,maze_col_size,maze_row_data,maze_col_data);
%% ���H���v���b�g

%�v���b�g����figure,axis���`
global maze_fig;
global maze_fig_ax;
maze_fig_ax = gca;
maze_fig = gcf;

%figure�̏o�͈ʒu
maze_fig.Position = [1,41,1920,963];

%%
maze_data_plot(maze_row_size,maze_col_size,maze_row_data,maze_col_data);
%% ���H�p�����[�^�ݒ�
global maze_goal
maze_goal = uint8(zeros(9,2));

%�w�肷����H�ɍ��킹�ăS�[�����W�A�T�C�Y��ύX
%���@�@�@x  y size
%2019�S���{�@18 14 9
%2019�����@�@7 10 4
%2018�֓��@ 10 10 4
%2018�S�Z�~ 13 13 4 

goal_size = uint8(4);%�S�[���T�C�Y����͂���
goal_x = 10;%�S�[��������x���W
goal_y = 10;%�S�[��������y���W


goal_size_d = double(goal_size);

%�S�[�����W����
for i = 1:sqrt(goal_size_d)
    for l = 1:sqrt(goal_size_d)
        maze_goal((l-1)*sqrt(goal_size_d)+i,:) = [goal_x+(i-1),goal_y+(l-1)];
    end
end

%% �ǃZ���T�l�����l����(C�R�[�h�����p)
%�ǃZ���TAD�l�i�[�ϐ�
global wall_sensor_front;
global wall_sensor_right;
global wall_sensor_left;
%�ǃZ���T臒l
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
    %% �����@�ŒT��

    %% ���H��񏉊���
    [maze_wall,maze_wall_search] = maze_init(maze_row_size,maze_col_size);
    maze_wall_plotall(maze_row_size,maze_col_size,maze_wall);

    %% ���[�h��`
    run_mode = r_mode.search;
    [maze_wall,maze_wall_search,contour_map] = maze_solve(maze_wall,maze_wall_search,maze_row_size,maze_col_size,goal_size,run_mode);

    %% �T���������ƂɍŒZ���s

    %���[�h��`
    run_mode = r_mode.fust_run;
    [maze_wall,maze_wall_search,contour_map] = maze_solve(maze_wall,maze_wall_search,maze_row_size,maze_col_size,goal_size,run_mode);
end

if sim_mode_flg == sim_mode.known
%% �S�ǂ����m�Ƃ����ŒZ���s
    
    %���[�h��`
    run_mode = r_mode.fust_run_diagonal;
    maze_wall_search = ones(32,32,'uint8')*15;
    [maze_wall,maze_wall_search,contour_map,row_num_node,col_num_node] = maze_solve(maze_serial,maze_wall_search,maze_row_size,maze_col_size,goal_size,run_mode);


end


