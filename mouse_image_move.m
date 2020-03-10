clearvars
close all
clc
%%
RGB = imread("manacov2.png");
% figure
% imagesc(RGB)
% axis image
%%
[IND,map] = rgb2ind(RGB,8);
[ysize,xsize,~] = size(IND);
% figure
% imagesc(IND)
% colormap(map)
% axis image
% colorbar
% alpha 0.5
% grid on
%% 
% 
ax = axes('XLim',[0 100],'YLim',[0 100],'ZLim',[-100 100]);
pbaspect([1 1 1])
view(2)
grid on

ycenter = 266;


[x,y]=meshgrid(-xsize/2:1:xsize/2-1,ycenter-ysize:1:ycenter-1);
z = x .* 0;


amap = uint8(IND ~= 3).*1000;

h = surface(x,y,z,IND,...
    'FaceColor','texturemap',...
    'EdgeColor','none',...
    'CDataMapping','direct',...
    'FaceAlpha','texturemap',...
    'AlphaDataMapping','none',...
    'AlphaData',amap);
colormap(map);


% amap = ones(8,1);
% amap(5,1) = 0.8;
% alphamap(amap);



% test = max(IND,[],3)
% h.AlphaData = test
%h.AlphaData = alphamap;


t = hgtransform('Parent',ax);
set(h,'Parent',t);

Rz = eye(4);
Sxy = Rz; 

for n = 1:200:1000
    Txy = makehgtform('translate',[4.5 4.5 0]);
 for r = 1:0.05:6*pi
    % Z-axis rotation matrix
    Rz = makehgtform('zrotate',r);
    % Scaling matrix
    Sxy = makehgtform('scale',1/100);
    % Concatenate the transforms and
    % set the transform Matrix property
    set(t,'Matrix',Txy*Rz*Sxy);
    drawnow
 end
end
 
 
 
 pause(1)


%% 
%