function result = newtonMethod(f, df, x0)
  tol = 1e-6;
  max_iter = 100;

  x = x0;
  fx = f(x);

  for iter = 1:max_iter
      dfx = df(x);
      x = x - fx ./ dfx;
      fx = f(x);
  end

  result = x;
end
