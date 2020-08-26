function [] = goal_plot(goal_size,maze_goal)
global goal_line

%前回のゴールラインオブジェクトを削除する
delete(goal_line)
%新規ゴールラインオブジェクトを生成する
goal_line = gobjects(9,1);
if(goal_size~=0)
    for i = 1:goal_size
        %     hold on
        goal_line(i) = plot(double(maze_goal(i,1))*9-4.5,double(maze_goal(i,2))*9-4.5,'p','MarkerSize',15,'MarkerEdgeColor','r','MarkerFaceColor','y');
        %     hold off
    end
end

end