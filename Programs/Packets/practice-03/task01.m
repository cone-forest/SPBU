f = @(x) x^2 - 1;
df = @(x) 2 * x;
x0 = 0.1
tol = 1e-6;
max_iter = 100;

x = x0;
fx = f(x);
iter = 0;

if abs(fx) < tol
    root = x;
    return;
end

for iter = 1:max_iter
    dfx = df(x);
    if dfx == 0
        error('Derivative is zero :(');
    end
    x = x - fx / dfx;
    fx = f(x);

    if abs(fx) < tol
        root = x;
        return;
    end
end

root = x

