data Tree a = Empty | Leaf a | Node a (Tree a) (Tree a)

sizeOf :: Tree a -> Int
sizeOf Empty = 0
sizeOf (Leaf _) = 1
sizeOf (Node _ left right) = 1 + sizeOf left + sizeOf right
