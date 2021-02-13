class Polygon a where
    points :: a -> [(Double, Double)]
    circumference :: a -> Double
    area :: a -> Double
