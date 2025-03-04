%clc,clear
%alpha_range=0.01*[0:10:180]./180;
alpha_range=0.01*[180:-1:0]./180;
n=length(alpha_range);
u_rms=zeros(1,n);
i_count=zeros(1,n);

for i=1:n
    %alpha_use=0.01*170/180;
    alpha_use=alpha_range(i)
    alpha_use2=alpha_use+0.01;
    
    % 运行Simulink模型
    simOut = sim('part1.slx');
    % 获取u0变量的值
    u0 = simOut.get('u0');
    
    %i0 = simOut.get('i0');
    % 在命令窗口中显示u0的值
    u0_rms = rms(u0(end-30:end));
    
    u_rms(1,i)=u0_rms;
    %i_count(i) = sum(i0 == 0);
end

figure
alpha=alpha_range./0.01*180;
plot(alpha,u_rms,linewidth=2);

hold on;

% 添加垂直线
%xline(3.96, 'r--', 'LineWidth', 1);
u=220* sqrt(b./ pi + (1 / (2 * pi)) * (sin(2* a) - sin(2 .* (a+b))));
a1=a.*180./pi;
plot(a1,u)