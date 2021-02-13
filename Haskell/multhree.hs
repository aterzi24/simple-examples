multhree :: Int -> Int -> Int -- implicit currying
multhree = \x y z -> x * y * z

multhree' :: Int -> Int -> Int -- explicit currying
multhree' = \x -> (\y -> (\z -> x * y * z))
