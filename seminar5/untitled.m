a=0.001:0.001:pi;
b=-0.329*a + 3.2985;
c=3.954/180*pi;
b(b > pi) = pi;
plot(a,b)
u=380* sqrt(b./ pi + (1 / (2 * pi)) * (sin(2* a) - sin(2 .* (a+b))));
plot(a,u)