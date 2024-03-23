alpha1=[0:1:180];
theta1=zeros(1,181);
for i = 1:1:181
    alpha = alpha1(i)
    phi = 3.954; 
    alpha_rad = deg2rad(alpha);
    phi_rad = deg2rad(phi);
    % 定义隐式方程
    equation = @(theta) sin(alpha_rad + theta - phi_rad) - sin(alpha_rad - phi_rad) * exp(-theta / tan(phi_rad));
    
    % 求解方程
    initial_guess = 90; % 初始猜测值
    theta = fsolve(equation, initial_guess);
    
    % 将θ从弧度转换为度
    theta_deg = rad2deg(theta);
        % 限制解的范围在1到π之间
    theta_deg = mod(theta_deg, 360); % 将角度转换到0到360度之间
    if theta_deg < 1
        theta_deg = theta_deg + 360; % 将角度调整到1到360度之间
    end
    % 输出结果
    fprintf('θ的值为：%f 度\n', theta_deg);


end
plot(alpha1,theta1)
