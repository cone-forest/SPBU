A = rand(3, 3)

file = fopen('taskextra-output.txt', 'w')

for k = 1:3
  for h = 1:3
    if h == 3
      fprintf(file, '%d\n', A(k, h))
    else
      fprintf(file, '%d | ', A(k, h))
    end
  end
end

fclose(f)
