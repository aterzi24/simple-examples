data Valarray a = Array [a] deriving Show -- diff. names to confuse less

-- could be defined more easily with common helpers
instance Num a => Num (Valarray a) where 
    (+) (Array v1) (Array v2) = Array $ zipWith (+) v1 v2
    (-) (Array v1) (Array v2) = Array $ zipWith (-) v1 v2
    (*) (Array v1) (Array v2) = Array $ zipWith (*) v1 v2
    negate (Array v) = Array $ map negate v
    abs (Array v) = Array $ map abs v
    signum (Array v) = Array $ map signum v
    fromInteger x = Array [fromInteger x]
