function [contour_map,max_length] = make_map(maze_row_size,maze_col_size,maze_goal,maze_serial)
%make_map �Ǐ�񂩂瓙����MAP�𐶐�
%���� ���H�c�T�C�Y,���H���T�C�Y,�S�[�����W(2*2�s��),���H���(16�i��)
%�o�� ������map,�ő�o�H��

% ���H�p�����[�^�ݒ�
max_length = (maze_col_size-1)*(maze_row_size-1)-1;

%MAP�̏�����(���ׂĂ̗v�f��max_length�����)
contour_map = ones(maze_row_size-1,maze_col_size-1).*max_length;

%�S�[�����W��0�����
for n = 1:4
    contour_map(maze_goal(n,1),maze_goal(n,2)) = 0;
end


while 1
    change_flag = 0; %map�X�V�m�F�p�t���O
    for i = 1:1:16
        for j=1:1:16
            
            %����MAP�̒l���m�F�A�l���Ȃ����continue
            if contour_map(i,j) == max_length
                continue                
            end
            
            %�k���̕ǂ̂���Ȃ�����
            if bitand(maze_serial(i,j),2^t_direction.North) == 0 
                %�k����MAP���X�V����Ă��邩���f�A����Ă��Ȃ���Ώ�������
                if contour_map(i+1,j) == max_length 
                contour_map(i+1,j) = contour_map(i,j)+1;
                change_flag = 1;
                end
            end
            
            %�����̕ǂ̂���Ȃ�����
            if bitand(maze_serial(i,j),2^t_direction.East) == 0 
                %������MAP���X�V����Ă��邩���f�A����Ă��Ȃ���Ώ�������
                if contour_map(i,j+1) == max_length 
                contour_map(i,j+1) = contour_map(i,j)+1;
                change_flag = 1;
                end
            end
            
            %�쑤�̕ǂ̂���Ȃ�����
            if bitand(maze_serial(i,j),2^t_direction.South) == 0 
                %�k����MAP���X�V����Ă��邩���f�A����Ă��Ȃ���Ώ�������
                if contour_map(i-1,j) == max_length 
                contour_map(i-1,j) = contour_map(i,j)+1;
                change_flag = 1;
                end
            end
            
            %�����̕ǂ̂���Ȃ�����
            if bitand(maze_serial(i,j),2^t_direction.West) == 0 
                %�k����MAP���X�V����Ă��邩���f�A����Ă��Ȃ���Ώ�������
                if contour_map(i,j-1) == max_length 
                contour_map(i,j-1) = contour_map(i,j)+1;
                change_flag = 1;
                end
            end            
        end
    end
    
    if change_flag == 0
        break;
    end
       
end


end
