function [contour_map,max_length] = make_map(maze_row_size,maze_col_size,maze_goal,maze_serial)
%make_map 壁情報から等高線MAPを生成
%入力 迷路縦サイズ,迷路横サイズ,ゴール座標(2*2行列),迷路情報(16進数)
%出力 等高線map,最大経路長

% 迷路パラメータ設定
max_length = (maze_col_size-1)*(maze_row_size-1)-1;

%MAPの初期化(すべての要素にmax_lengthを入力)
contour_map = ones(maze_row_size-1,maze_col_size-1).*max_length;

%ゴール座標に0を入力
for n = 1:4
    contour_map(maze_goal(n,1),maze_goal(n,2)) = 0;
end


while 1
    change_flag = 0; %map更新確認用フラグ
    for i = 1:1:16
        for j=1:1:16
            
            %歩数MAPの値を確認、値がなければcontinue
            if contour_map(i,j) == max_length
                continue                
            end
            
            %北側の壁のありなし判定
            if bitand(maze_serial(i,j),2^t_direction.North) == 0 
                %北側のMAPが更新されているか判断、されていなければ書き込み
                if contour_map(i+1,j) == max_length 
                contour_map(i+1,j) = contour_map(i,j)+1;
                change_flag = 1;
                end
            end
            
            %東側の壁のありなし判定
            if bitand(maze_serial(i,j),2^t_direction.East) == 0 
                %東側のMAPが更新されているか判断、されていなければ書き込み
                if contour_map(i,j+1) == max_length 
                contour_map(i,j+1) = contour_map(i,j)+1;
                change_flag = 1;
                end
            end
            
            %南側の壁のありなし判定
            if bitand(maze_serial(i,j),2^t_direction.South) == 0 
                %北側のMAPが更新されているか判断、されていなければ書き込み
                if contour_map(i-1,j) == max_length 
                contour_map(i-1,j) = contour_map(i,j)+1;
                change_flag = 1;
                end
            end
            
            %西側の壁のありなし判定
            if bitand(maze_serial(i,j),2^t_direction.West) == 0 
                %北側のMAPが更新されているか判断、されていなければ書き込み
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

