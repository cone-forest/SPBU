A = rand(5, 3);
B = rand(3, 2);

C = vertcat(horzcat(A, ones(5, 2)), horzcat(transpose(B), eye(2)))

C(1:end,5)
