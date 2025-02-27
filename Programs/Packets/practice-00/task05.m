a = rand(4, 4)
[v, lambda] = eig(a)

a * v - v * lambda
