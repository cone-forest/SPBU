function result = f(x)
    result = x - round(x);
end

function result = y(x)
    result = (1/4 - 2 * f(x).^2) .* 0.8.^x;
end

x = linspace(-10, 10, 1000);

y_values = y(x);

plot(x, y_values);
xlabel('x');
ylabel('y');
title('Plot of y = (1/4 - 2f(x)^2) * 0.8^x');
grid on;
