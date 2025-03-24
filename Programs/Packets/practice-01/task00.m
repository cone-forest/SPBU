theta = 0 : pi/100 : 2*pi;
r = sin(theta) ./ theta;

[x, y] = pol2cart(theta, r);

h = plot(x, y);

waitfor(h)
