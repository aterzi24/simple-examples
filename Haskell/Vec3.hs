module Vec3 (
    Vec3,
    mag,
    dot,
    cross
    ) where

data Vec3 = Vec3 Double Double Double

mag :: Vec3 -> Double
mag (Vec3 x y z) = sqrt $ x^2 + y^2 + z^2

dot :: Vec3 -> Vec3 -> Double
dot (Vec3 x1 y1 z1) (Vec3 x2 y2 z2) = x1*x2 + y1*y2 + z1*z2

cross :: Vec3 -> Vec3 -> Vec3
cross (Vec3 x1 y1 z1) (Vec3 x2 y2 z2) = 
    let cx = y1*z2 - y2*z1
        cy = z1*x2 - z2*x1
        cz = x1*y2 - x2*y1
     in Vec3 cx cy cz
