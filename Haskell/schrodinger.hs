data SchrödingersBox a = Full a | Empty

checkBox :: Show a => SchrödingersBox a -> String
checkBox (Full sth) = "Aha, I found a " ++ show sth ++ "!"
checkBox Empty = "Oh, the box is empty..."
