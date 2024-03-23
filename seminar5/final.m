%%计算alpha与theta，并分段拟合数值结果
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

%%计算u
a=0.001:0.001:pi;
b=-0.329*a + 3.2985;
c=3.954/180*pi;
b(b > pi) = pi;
plot(a,b)
u=380* sqrt(b./ pi + (1 / (2 * pi)) * (sin(2* a) - sin(2 .* (a+b))));
plot(a,u)

%%
%仿真结果
%alpha_range=0.01*[0:10:180]./180;
alpha_range=0.01*[180:-1:0]./180;
n=length(alpha_range);
u_rms=zeros(1,n);
i_count=zeros(1,n);
% 运行Simulink模型
simOut = sim('part1.slx');
% simOut = sim('part1.slx');
% simOut = sim('part1.slx');

for i=1:n
    i=n
    %alpha_use=0.01*170/180;
    alpha_use=0%alpha_range(i)
    alpha_use2=alpha_use+0.01;
    
    % 运行Simulink模型
    simOut = sim('part1.slx');
    % 获取u0变量的值
    u0 = simOut.get('u0');
    
    %i0 = simOut.get('i0');
    % 在命令窗口中显示u0的值
    u0_rms = rms(u0(end-30:end));
    ccm_u(:,i)=u0(end-100:end)
    
    u_rms(1,i)=u0_rms;
    %i_count(i) = sum(i0 == 0);
end

figure
alpha=alpha_range./0.01*180;
plot(alpha,u_rms,linewidth=2);

hold on;

% 添加垂直线
%xline(3.96, 'r--', 'LineWidth', 1);
u=220* sqrt(d./ pi + (1 / (2 * pi)) * (sin(2* a) - sin(2 .* (a+d))));
a1=a.*180./pi;
plot(a1,u)
% x=1:1:101;
% x=x'
% plot(x,ccm_u(:,181),x,ccm_u(:,180))
%%计算零点数量
% 统计每一列绝对值小于1的元素数量
counts = sum(abs(ccm_u) < 0.5);

% 将结果存储为 1x181 的列表
result = [counts];

result = flip(result);

rr=1:181;
plot(rr,result)