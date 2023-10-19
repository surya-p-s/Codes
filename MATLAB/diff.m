clc;clear all;close all;
syms x1 x2 y;
f=(x1^2+x2-11)^2+(x1+x2^2-7)^2;
%Gradient in Function form
g(1,1)=diff(f,x1);
g(2,1)=diff(f,x2);
X=[x1;x2];x0=[1;-2];
g_x0=subs(g,X,x0)
f_x0=subs(f,X,x0)