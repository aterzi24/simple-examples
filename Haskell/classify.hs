classify :: Double -> String
classify x
    | x < 1e-10 = "That's tiny! Just like a pebble."
    | x < 1e-5  = "Almost negligible."
    | x < 1e5   = "A pretty normal value, if I've ever seen one."
    | x < 1e10  = "Not bad, some pretty good stuff you've got there."
    | otherwise = "BigValue (TM)"
