clear all;

u = -2 : 1/10 : 2;
v = -2 : 1/10 : 2;

[X, Y] = meshgrid(u, v);

g = @(x,y) sin (sqrt (x.^2 + y.^2)) ./ sqrt (x.^2 + y.^2);

f = @(x,y) 20 - x.^2 - y.^2;
F = @(x,y,z) z + x.^2 + y.^2 - 20

dfdx = @(x, y, z) 10 * (F(x, y, z) - F(x + 0.1, y, z));
dfdy = @(x, y, z) 10 * (F(x, y, z) - F(x, y + 0.1, z));
dfdz = @(x, y, z) 10 * (F(x, y, z) - F(x, y, z + 0.1));

s = surf(X, Y, f(X, Y));
hold on;

plot3(dfdx, dfdy, dfdz);
waitfor(s)
