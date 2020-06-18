function [] =straight_plot(current_node,current_node_property,current_move_dir,current_move_mode,straight_count)

global matrix_dir;
global g_d_direction;
global move_dir_property;


%����
%���H�v���b�g��cm�P�ʁA�O�Ճf�[�^��m�P�ʂȂ̂ŁA�ϊ����K�v
%quiver(x,y,u,v)

%�s�m�[�h�̏ꍇ
if current_node_property == matrix_dir.Row
    %�x�N�g���̈ʒu���`
    x = double(current_node(2)-1)*9+4.5;
    y = double(current_node(1)-1)*9;
    %���i�̏ꍇ     
    if current_move_mode == move_dir_property.straight
        %�i�s�����ɉ����āA�x�N�g���ʒu�𒲐�
        if current_move_dir == g_d_direction.North
            y = y+4.5;
        elseif current_move_dir == g_d_direction.South
            y = y-4.5;
        end
        %�x�N�g���̑傫�����`
        vec_mag = 9*double(straight_count);
        u = vec_mag * sin(double(current_move_dir)*pi/4);
        v = vec_mag * cos(double(current_move_dir)*pi/4);        
    %�΂߂̏ꍇ
    else
        %�x�N�g���̑傫�����`
        vec_mag = 9/sqrt(2)*double(straight_count);
        u = vec_mag * sin(double(current_move_dir)*pi/4);
        v = vec_mag * cos(double(current_move_dir)*pi/4);    
    end
    
%��m�[�h�̏ꍇ
elseif current_node_property == matrix_dir.Col
    %�x�N�g���̈ʒu���`
    x = double(current_node(2)-1)*9;
    y = double(current_node(1)-1)*9+4.5;
    %���i�̏ꍇ     
    if current_move_mode == move_dir_property.straight
        %�i�s�����ɉ����āA�x�N�g���ʒu�𒲐�
        if current_move_dir == g_d_direction.East
            x = x+4.5;
        elseif current_move_dir == g_d_direction.West
            x = x-4.5;
        end
        %�x�N�g���̑傫�����`
        vec_mag = 9*double(straight_count);
        u = vec_mag * sin(double(current_move_dir)*pi/4);
        v = vec_mag * cos(double(current_move_dir)*pi/4);        
    %�΂߂̏ꍇ
    else
        %�x�N�g���̑傫�����`
        vec_mag = 9/sqrt(2)*double(straight_count);
        u = vec_mag * sin(double(current_move_dir)*pi/4);
        v = vec_mag * cos(double(current_move_dir)*pi/4);    
    end
else
    error("�z�肵�Ă��Ȃ��s�񑮐��ł��B�i�����v���b�g�j")
end
hold on
quiver(x,y,u,v,'AutoScale','off','LineWidth',2,'Color','k','MaxHeadSize',0.5)
hold off
end