-- Enumerated (sum) types 
data Bool' = T | F
data Color = Red | Green | Blue
-- A product type, like tuples. The type can
-- have the same name as the value constructor.
data Point = Point Double Double
-- A combination of both sum & prod. types
data Pet = Dog String Int | Cat String Int | Butterfly String 
-- Some example values:
bestColor = Green
origin = Point 0.0 0.0
yourPets = [Cat "Boncuk" 3, Cat "Prenses" 7, Butterfly "Pırpır"]
