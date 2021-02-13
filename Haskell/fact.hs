fact :: Integer -> Integer
fact 0 = 1 -- base case, should be the first!
fact n = n * fact (n - 1) -- recursive case
