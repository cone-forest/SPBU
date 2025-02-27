a = rand(3, 5)
aa = a(1:3,1:3)

det(aa)

aaa = vertcat(zeros(1,3), aa(2:end,1:end))

det(aaa)
