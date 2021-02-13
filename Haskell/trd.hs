trd :: (a, b, c) -> ((a, b, c), c)
trd triplet@(_, _, z) = (triplet, z) -- don't care about the first two
