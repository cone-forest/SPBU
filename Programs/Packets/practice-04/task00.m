fun = @(x) x.^3 - 1;
dfun = @(x) x.^2 .* 3;

width  = 1000;
height = 1000;

myroots = [
  -0.5000 + 0.8660i;
  -0.5000 - 0.8660i;
   1.0000 +      0i;
];

imagebits = zeros(height, width, 3);

confusion = 0.001;

red = 50;
green = 0;
blue = 250;
trans = 0;

[w_grid, h_grid] = meshgrid(-width / 2 : width/2, -height/2:height/2);
z = w_grid + h_grid * i;
myroots2 = newtonMethod(fun, dfun, z);

result = zeros(height+1, width+1);
result(myroots2 - myroots(1) < confusion) = red;
result(myroots2 - myroots(2) < confusion) = green;
result(myroots2 - myroots(3) < confusion) = blue;

img = image(result);
waitfor(img);
