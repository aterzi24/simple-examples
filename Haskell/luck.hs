luck :: [Int] -> Int
luck [] = 0
luck (x:xs) = let luckIncrement = case x of 7 -> 1   -- lucky!
                                            13 -> -1 -- unlucky :(
                                            _ -> 0   -- who cares?
               in luckIncrement + luck xs
