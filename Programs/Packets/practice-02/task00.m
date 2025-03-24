u = 0 : pi/100 : 2*pi;
v = -1 : 1/100 : 1;

[X, Y] = meshgrid(u, v);

f = @(x,y) sin (sqrt (x.^2 + y.^2)) ./ sqrt (x.^2 + y.^2);
Z = f(X, Y);

s = surf(X, Y, Z);
waitfor(s)
