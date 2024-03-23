% 定义变量范围
a = linspace(0, pi, 100);
b = linspace(0, pi, 100);
% 定义c的取值
c_values = 0.069

% 创建网格
[A, B] = meshgrid(a, b);

% 绘制a-b曲线
figure;
hold on;
for i = 1:length(c_values)
    c = c_values(i);
    
    % 计算方程左侧和右侧的值
    left_side = sin(A + B - c);
    right_side = sin(A  - c ) .* exp(-B ./ tan(c));
    
    % 绘制当前c值下的a-b曲线
    contour(A, B, left_side - right_side, [0 0], 'LineWidth', 2);
end
hold off;
title('a-b曲线');
xlabel('a');
ylabel('b');
grid on;

hold on 
 a=0.001:0.001:pi;
% b=-1.00*a + 3.2106;
% b(b > pi) = pi;
% d=b;
% d(2860:3141)=a(2860:3141)*(-1.045)+ 3.3356;
d=e;
b=d;
e(3100:3141)=a(3100:3141)*(-1.681)+ 1.681*pi;
plot(a,d)