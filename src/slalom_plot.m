function [] =slalom_plot(current_node,current_node_property,current_move_dir,current_move_mode,slalom_num)

global maze_fig_ax;
global matrix_dir;
global g_d_direction;
global move_dir_property;
global turn_pattern;

%����
%���H�v���b�g��cm�P�ʁA�O�Ճf�[�^��m�P�ʂȂ̂ŁA�ϊ����K�v


%�X�����[���f�[�^�̕ۑ�����p�X�ɒǉ�
current_dir = cd; %��ƃf�B���N�g���̃p�X���擾
addpath(strcat(current_dir,'/�X�����[���O�Ճf�[�^'),'-end')

%�x�[�X�ƂȂ�e�p�^�[���̃X�����[���O�Ղ���]�A�ړ�����
%���]�̋O�ՂƂȂ�悤�ɕϊ�����i���_����ɂāj
hold on
%�E45�x
if slalom_num == turn_pattern.r_45
    load("fust_run_45 .mat","mouse_x","mouse_y")
    %�X�^�[�g��(0,0�ɒ���)
    adjust_x = (mouse_x-0.045)*100;
    adjust_y = (mouse_y+0.045)*100;

    %�i�s���������i�̏ꍇ
    if current_move_mode == move_dir_property.straight
        %��]������I�u�W�F�N�g���쐬
        h = plot(adjust_x,adjust_y,'LineWidth',2,'Color','b');
        t = hgtransform('Parent',maze_fig_ax);
        set(h,'Parent',t)
        % Z-axis rotation matrix
        %�ړ������ɉ����ĉ�]�p�x��ύX
        Rz = makehgtform('zrotate',-(pi/4)*double(current_move_dir));
%         set(t,'Matrix',Rz)
        
    %�i�s�������΂߂̏ꍇ
    elseif current_move_mode == move_dir_property.diagonal
        %�p�^�[�����]����
        adjust_x = adjust_x-4.5;
        adjust_y = adjust_y-9;
        h = plot(adjust_x,adjust_y,'LineWidth',2,'Color','b');
        t = hgtransform('Parent',maze_fig_ax);
        set(h,'Parent',t)
        % Z-axis rotation matrix
        Rz1 = makehgtform('axisrotate',[1 1 0],pi);
        Rz2 = makehgtform('zrotate',3*(pi/4)+(pi/4)*double(current_move_dir));
        Rz = Rz1*Rz2;
%         set(t,'Matrix',Rz)
    end
%��45�x
elseif slalom_num == turn_pattern.l_45
    load("fust_run_45 .mat","mouse_x","mouse_y")
    %�X�^�[�g��(0,0�ɒ���)
    adjust_x = (mouse_x-0.045)*100;
    adjust_y = (mouse_y+0.045)*100;
    %�i�s���������i�̏ꍇ
    if current_move_mode == move_dir_property.straight
        %��]������I�u�W�F�N�g���쐬
        h = plot(adjust_x,adjust_y,'LineWidth',2,'Color','b');
        t = hgtransform('Parent',maze_fig_ax);
        set(h,'Parent',t)
        % Z-axis rotation matrix
        %�ړ������ɉ����ĉ�]�p�x��ύX
        Rz1 = makehgtform('zrotate',-(pi/4)*double(current_move_dir));
        Rz2 = makehgtform('yrotate',pi);
        Rz = Rz1*Rz2;
%         set(t,'Matrix',Rz)
        
    %�i�s�������΂߂̏ꍇ
    elseif current_move_mode == move_dir_property.diagonal
        %�p�^�[�����]����
        adjust_x = adjust_x-4.5;
        adjust_y = adjust_y-9;
        h = plot(adjust_x,adjust_y,'LineWidth',2,'Color','b');
        t = hgtransform('Parent',maze_fig_ax);
        set(h,'Parent',t)
        % Z-axis rotation matrix
        Rz = makehgtform('zrotate',-3/4*pi-(pi/4)*double(current_move_dir));
%         set(t,'Matrix',Rz)
    end
    
%�E90�x
elseif slalom_num == turn_pattern.r_90
    %�i�s���������i�̏ꍇ
    if current_move_mode == move_dir_property.straight
        load("fust_run_90 .mat","mouse_x","mouse_y")
        %�X�^�[�g��(0,0�ɒ���)
        adjust_x = (mouse_x-0.045)*100;
        adjust_y = (mouse_y+0.045)*100;
        %��]������I�u�W�F�N�g���쐬
        h = plot(adjust_x,adjust_y,'LineWidth',2,'Color','r');
        t = hgtransform('Parent',maze_fig_ax);
        set(h,'Parent',t)
        % Z-axis rotation matrix
        %�ړ������ɉ����ĉ�]�p�x��ύX
        Rz = makehgtform('zrotate',-(pi/4)*double(current_move_dir));
    %�i�s�������΂߂̏ꍇ
    elseif current_move_mode == move_dir_property.diagonal
        load("fust_run_v90 .mat","mouse_x","mouse_y")
        %�X�^�[�g��(0,0�ɒ���)
        adjust_x = (mouse_x-0.045)*100;
        adjust_y = (mouse_y)*100;
        %��]������I�u�W�F�N�g���쐬
        h = plot(adjust_x,adjust_y,'LineWidth',2,'Color','m');
        t = hgtransform('Parent',maze_fig_ax);
        set(h,'Parent',t)
        % Z-axis rotation matrix
        %�ړ������ɉ����ĉ�]�p�x��ύX
        Rz = makehgtform('zrotate',-(pi/4)*(double(current_move_dir)-1));
    end
    
%��90�x
elseif slalom_num == turn_pattern.l_90
    %�i�s���������i�̏ꍇ
    if current_move_mode == move_dir_property.straight
        load("fust_run_90 .mat","mouse_x","mouse_y")
        %�X�^�[�g��(0,0�ɒ���)
        adjust_x = (mouse_x-0.045)*100;
        adjust_y = (mouse_y+0.045)*100;
        %��]������I�u�W�F�N�g���쐬
        h = plot(adjust_x,adjust_y,'LineWidth',2,'Color','r');
        t = hgtransform('Parent',maze_fig_ax);
        set(h,'Parent',t)
        % Z-axis rotation matrix
        %�ړ������ɉ����ĉ�]�p�x��ύX
        Rz1 = makehgtform('yrotate',pi);
        Rz2 = makehgtform('zrotate',(pi/4)*double(current_move_dir));
        Rz = Rz1*Rz2;
    %�i�s�������΂߂̏ꍇ
    elseif current_move_mode == move_dir_property.diagonal
        load("fust_run_v90 .mat","mouse_x","mouse_y")
        %�X�^�[�g��(0,0�ɒ���)
        adjust_x = (mouse_x-0.045)*100;
        adjust_y = (mouse_y)*100;
        %��]������I�u�W�F�N�g���쐬
        h = plot(adjust_x,adjust_y,'LineWidth',2,'Color','m');
        t = hgtransform('Parent',maze_fig_ax);
        set(h,'Parent',t)
        % Z-axis rotation matrix
        %�ړ������ɉ����ĉ�]�p�x��ύX
        Rz1 = makehgtform('yrotate',pi); 
        Rz2 = makehgtform('zrotate',(pi/4)*(double(current_move_dir)-7));
        Rz = Rz1*Rz2;
    end
    
%�E135�x
elseif slalom_num == turn_pattern.r_135
    load("fust_run_135 .mat","mouse_x","mouse_y")
    %�X�^�[�g��(0,0�ɒ���)
    adjust_x = (mouse_x-0.045)*100;
    adjust_y = (mouse_y+0.045)*100;
    %�i�s���������i�̏ꍇ
    if current_move_mode == move_dir_property.straight
        %��]������I�u�W�F�N�g���쐬
        h = plot(adjust_x,adjust_y,'LineWidth',2,'Color','g');
        t = hgtransform('Parent',maze_fig_ax);
        set(h,'Parent',t)
        % Z-axis rotation matrix
        %�ړ������ɉ����ĉ�]�p�x��ύX
        Rz = makehgtform('zrotate',-(pi/4)*double(current_move_dir));
    %�i�s�������΂߂̏ꍇ
    elseif current_move_mode == move_dir_property.diagonal
        adjust_x = adjust_x-9;
        adjust_y = adjust_y-4.5;
        %��]������I�u�W�F�N�g���쐬
        h = plot(adjust_x,adjust_y,'LineWidth',2,'Color','g');
        t = hgtransform('Parent',maze_fig_ax);
        set(h,'Parent',t)
        % Z-axis rotation matrix
        %�ړ������ɉ����ĉ�]�p�x��ύX
        Rz1 = makehgtform('axisrotate',[1 1 0],pi);
        Rz2 = makehgtform('zrotate',-3*(pi/4)+(pi/4)*double(current_move_dir));
        Rz = Rz1*Rz2;
    end
%��135�x
elseif slalom_num == turn_pattern.l_135
    load("fust_run_135 .mat","mouse_x","mouse_y")
    %�X�^�[�g��(0,0�ɒ���)
    adjust_x = (mouse_x-0.045)*100;
    adjust_y = (mouse_y+0.045)*100;
    %�i�s���������i�̏ꍇ
    if current_move_mode == move_dir_property.straight
        %��]������I�u�W�F�N�g���쐬
        h = plot(adjust_x,adjust_y,'LineWidth',2,'Color','g');
        t = hgtransform('Parent',maze_fig_ax);
        set(h,'Parent',t)
        % Z-axis rotation matrix
        %�ړ������ɉ����ĉ�]�p�x��ύX
        Rz1 = makehgtform('yrotate',pi);
        Rz2 = makehgtform('zrotate',(pi/4)*double(current_move_dir));
        Rz = Rz1*Rz2;       
    %�i�s�������΂߂̏ꍇ
    elseif current_move_mode == move_dir_property.diagonal
        adjust_x = adjust_x-9;
        adjust_y = adjust_y-4.5;
        %��]������I�u�W�F�N�g���쐬
        h = plot(adjust_x,adjust_y,'LineWidth',2,'Color','g');
        t = hgtransform('Parent',maze_fig_ax);
        set(h,'Parent',t)
        % Z-axis rotation matrix
        %�ړ������ɉ����ĉ�]�p�x��ύX
        Rz = makehgtform('zrotate',-1/4*pi-(pi/4)*double(current_move_dir));
    end
%�E180�x
elseif slalom_num == turn_pattern.r_180
    load("fust_run_180 .mat","mouse_x","mouse_y")
    %�X�^�[�g��(0,0�ɒ���)
    adjust_x = (mouse_x-0.045)*100;
    adjust_y = (mouse_y+0.045)*100;
    %�i�s���������i�̏ꍇ
    if current_move_mode == move_dir_property.straight
        %��]������I�u�W�F�N�g���쐬
        h = plot(adjust_x,adjust_y,'LineWidth',2,'Color','c');
        t = hgtransform('Parent',maze_fig_ax);
        set(h,'Parent',t)
        % Z-axis rotation matrix
        %�ړ������ɉ����ĉ�]�p�x��ύX
        Rz = makehgtform('zrotate',-(pi/4)*double(current_move_dir));
    end
    
%��180�x
elseif slalom_num == turn_pattern.l_180
    load("fust_run_180 .mat","mouse_x","mouse_y")
    %�X�^�[�g��(0,0�ɒ���)
    adjust_x = (mouse_x-0.045)*100;
    adjust_y = (mouse_y+0.045)*100;
    %�i�s���������i�̏ꍇ
    if current_move_mode == move_dir_property.straight
        %��]������I�u�W�F�N�g���쐬
        h = plot(adjust_x,adjust_y,'LineWidth',2,'Color','c');
        t = hgtransform('Parent',maze_fig_ax);
        set(h,'Parent',t)
        % Z-axis rotation matrix
        %�ړ������ɉ����ĉ�]�p�x��ύX
        Rz1 = makehgtform('yrotate',pi);
        Rz2 = makehgtform('zrotate',(pi/4)*double(current_move_dir));
        Rz = Rz1*Rz2;
    end
    
end    
%�쐬�����O�Ղ����݃m�[�h�̈ʒu�A�ړ����������܂�`��J�n�ʒu�Ɉړ�
%���i��
 if current_move_mode == move_dir_property.straight
     %�ړ������ɕ`��ʒu��Ή�������
     if current_move_dir == g_d_direction.North
         Txy = makehgtform('translate',[4.5+double(current_node(2)-1)*9 4.5+double(current_node(1)-1)*9 0]);
     elseif current_move_dir == g_d_direction.East
         Txy = makehgtform('translate',[4.5+double(current_node(2)-1)*9 4.5+double(current_node(1)-1)*9 0]);
     elseif current_move_dir == g_d_direction.South
         Txy = makehgtform('translate',[4.5+double(current_node(2)-1)*9 -4.5+double(current_node(1)-1)*9 0]);   
     elseif current_move_dir == g_d_direction.West
         Txy = makehgtform('translate',[-4.5+double(current_node(2)-1)*9 4.5+double(current_node(1)-1)*9 0]);
     end
     set(t,'Matrix',Txy*Rz)
%�΂߂̎�
 elseif current_move_mode == move_dir_property.diagonal
     %�m�[�h��������A�v���b�g�J�n�ʒu��ύX
     if current_node_property == matrix_dir.Row
        Txy = makehgtform('translate',[4.5+double(current_node(2)-1)*9 double(current_node(1)-1)*9 0]);
     elseif current_node_property == matrix_dir.Col
        Txy = makehgtform('translate',[double(current_node(2)-1)*9 4.5+double(current_node(1)-1)*9 0]);
     end
     set(t,'Matrix',Txy*Rz)
 end
    


hold off
end