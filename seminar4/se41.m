clc,clear
D=[0:1:20];
n=length(D);
Uin=200;
u_ripple=zeros(1,n);
i_ripple=zeros(1,n);
G=zeros(1,n);

for i=1:(n-1)
    Duty_cycle=D(i+1);
    Duty_cycle
    sim('Simu4_Part1.slx');
    G(1,i+1)=Uo(end,1)/Uin;
    u_ripple(1,i+1)=max(uo1(999000:end,1))-min(uo1(999000:end,1));
    i_ripple(1,i+1)=max(iL(999000:end,1))-min(iL(999000:end,1));
end

D=D./100;
G_T=D;

figure
plot(D,G,linewidth=3,color='r');
hold on
plot(D,G_T,linewidth=1.5,color='b');
xlabel("Duty Cycle D");
ylabel("Voltage Gain");
title("Relationship between Duty Cycle and Voltage Gain");

u_ripple=u_ripple.*1000;
u_T=zeros(1,21);
for i=1:81
    u_T(1,i)=1/80*((i-1)/100)*(1-(i-1)/100)*1000;
end

figure
plot(D,u_ripple,linewidth=3,color='r');
hold on
plot(D,u_T,linewidth=1.5,color='b');
xlabel("Duty Cycle D");
ylabel("Capacitor Voltage Ripple / mV");
title("Relationship between Duty Cycle and Capacitor Voltage Ripple");


i_T=zeros(1,21);
for i=1:21
    i_T(1,i)=0.5*((i-1)/100)*(1-(i-1)/100);
end

figure
plot(D,i_ripple,linewidth=3,color='r');
hold on
plot(D,i_T,linewidth=1.5,color='b');
xlabel("Duty Cycle D");
ylabel("Inductor Current Ripple / A");
title("Relationship between Duty Cycle and Inductor Current Ripple");

