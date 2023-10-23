clc;clear all;close all;
x=-5:.1:5;
y=-5:.1:5;
[x1,x2]=meshgrid(x,y);
f=(x1.^2+x2-11).^2+(x1+x2.^2-7).^2;
figure;
surf(x1,x2,f);
xlabel('x1');ylabel('x2');
zlabel('Amplitude');
figure;
[C,H]=contour(x1,x2,f,[0.1:10:250]);
clabel(C,H,'manual')