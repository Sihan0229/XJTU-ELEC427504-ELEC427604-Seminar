clc,clear
D=[31:1:80];
n=length(D);
Uin=120;
u_ripple=zeros(1,n);
i_ripple=zeros(1,n);
G=zeros(1,n);

for i=1:(n-1)
    Dinsimu=D(i+1);
    Dinsimu
    sim('simulation4_Part1');
    G(1,i+1)=Uo(end,1)/Uin;
    u_ripple(1,i+1)=max(uo(199000:250000,1))-min(uo(199000:250000,1));
    i_ripple(1,i+1)=max(iL(199000:250000,1))-min(iL(199000:250000,1));
end



D=D./100;
G_T=1./(1-D);

% figure
% plot(D,G,linewidth=3,color='r');
% hold on
% plot(D,G_T,linewidth=1.5,color='b');
% xlabel("D");
% ylabel("Voltage Gain");
% title("Relationship between D and Voltage Gain");

u_T(1,:)=120/100*1000*1/20*1/100*10^-6.*D(1,:)./(1-D(1,:));

figure
plot(D,u_ripple,linewidth=3,color='r');
hold on
plot(D,u_T,linewidth=1.5,color='b');
xlabel("D");
ylabel("Capacitor Voltage Ripple");
title("Relationship between Duty Cycle and Capacitor Voltage Ripple");

% 
% i_T=zeros(30:81);
% for i=1:81
%     i_T(1,i)=0.5*((i-1)/100)*(1-(i-1)/100);
% end
% 
% figure
% plot(D,i_ripple,linewidth=3,color='r');
% hold on
% plot(D,i_T,linewidth=1.5,color='b');
% xlabel("Duty Cycle D");
% ylabel("Inductor Current Ripple / A");
% title("Relationship between Duty Cycle and Inductor Current Ripple");
% 
