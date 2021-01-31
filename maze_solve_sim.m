clearvars
close all
clc
%% �p�X��`
currentdir = cd;
addpath(strcat(currentdir,'/src'),'-end')

%% �f�o�b�O���[�h��`
global maze_data_get_debug;
maze_data_get_debug = 0;
global video_flg;
global vidObj; %����쐬�p�̃r�f�I�I�u�W�F�N�g
%�r�f�I�t���O
video_flg = 0;

%% �r�f�I�L�^�p�ϐ��̐錾
if video_flg
    vidObj = VideoWriter('result.mp4','MPEG-4');
    vidObj.FrameRate = 1/0.1;
    open(vidObj);
end
%% �V�~�����[�V�������[�h�I��
sim_mode.unknown = uint8(0); %�Ǐ�񂪂Ȃ���Ԃ���A�T���A�ŒZ�̎��s
sim_mode.known = uint8(1); %�Ǐ������m�Ƃ��āA�ŒZ�̎��s

%% mode��`
%���s���[�h(run_mode_1)
run_mode1.search = uint8(0);
run_mode1.fust_run = uint8(1);
%�T�����[�h(run_mode_2)
run_mode2.adachi = uint8(0);
run_mode2.all = uint8(1);
run_mode2.short = uint8(2);
run_mode2.straight = uint8(0);
run_mode2.diagonal = uint8(1);

%% �V�~�����[�V�������[�h��ݒ�i����́j
sim_mode_flg = sim_mode.unknown;
run_mode1_flg =  run_mode1.search;
run_mode2_flg = run_mode2.adachi;
%% ���H�p�����[�^�ݒ�(�����)
% global maze_goal
maze_goal = uint8(zeros(9,2));

%�w�肷����H�ɍ��킹�ăS�[�����W�A�T�C�Y��ύX
%���@�@�@x  y size
%2019�S���{�@18 14 9
%2019�����@�@7 10 4
%2018�֓��@ 10 10 4
%2018�S�Z�~ 13 13 4
%2017�S���{ 20 21 9
%2020�S���{�w�� 4 4 4

goal_x =10;%�S�[��������x���W
goal_y = 10;%�S�[��������y���W
goal_size = uint8(4);%�S�[���T�C�Y����͂���

goal_size_d = double(goal_size);

%�S�[�����W����
for i = 1:sqrt(goal_size_d)
    for l = 1:sqrt(goal_size_d)
        maze_goal((l-1)*sqrt(goal_size_d)+i,:) = [goal_x+(i-1),goal_y+(l-1)];
    end
end


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
set(maze_fig_ax,'color','none','NextPlot','add')
maze_fig = gcf;

%figure�̏o�͈ʒu
maze_fig.Position = [2,42,958,954];

%%
maze_data_plot(maze_row_size,maze_col_size,maze_row_data,maze_col_data);


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
    run_mode1_flg = run_mode1.search;
    run_mode2_flg = run_mode2.adachi;
    [maze_wall,maze_wall_search,contour_map] = maze_solve(maze_wall,maze_wall_search,maze_row_size,maze_col_size,goal_size,maze_goal,run_mode1_flg,run_mode2_flg);
    
    %% �T���������ƂɍŒZ���s
    %���[�h��`
    run_mode1_flg = run_mode1.fust_run;
    run_mode2_flg = run_mode2.diagonal;
    [maze_wall,maze_wall_search,contour_map] = maze_solve(maze_wall,maze_wall_search,maze_row_size,maze_col_size,goal_size,maze_goal,run_mode1_flg,run_mode2_flg);
end

if sim_mode_flg == sim_mode.known
    %% �S�ǂ����m�Ƃ����ŒZ���s(����)
    
    %���[�h��`
    run_mode1_flg = run_mode1.fust_run;
    
    maze_wall_search = ones(32,32,'uint8')*15;
    [maze_wall,maze_wall_search,contour_map,row_num_node,col_num_node] = maze_solve(maze_serial,maze_wall_search,maze_row_size,maze_col_size,goal_size,maze_goal,run_mode1_flg,run_mode2_flg);
    
end

%% �r�f�I�쐬�̊���
if video_flg
    close(vidObj);
end


