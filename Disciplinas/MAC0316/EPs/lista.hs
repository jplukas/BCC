
p1 :: (Eq t, Num t) => t -> [a] -> [a]
p1 0 (h:rest) = []
p1 i [] = []
p1 i (h:rest) = h:(p1 (i-1) rest)

p2 :: (Eq t, Num t) => t -> [a] -> [a]
p2 i [] = []
p2 0 (h:resto) = resto
p2 i (h:resto) = p2 (i-1) resto

p3 :: Ord a => a -> [a] -> [a]
p3 i [] = []
p3 i (h:resto) = (if h > i then [h] else []) ++ p3 i resto

p4 :: Num a => [a] -> a
p4 [] = 0
p4 [x] = x
p4 (x:resto) = x * p4 resto

p5 :: Ord a => [a] -> a
p5 [x] = x
p5 [x, y] = if x > y then x else y
p5 (x:y:resto) = p5 ((p5 [x, y]):resto)

p6 [] = 0
p6 lista@(x:resto) = do
   let p6a i [] = -1
   let p6a i (x:resto) = if x == i then 1 else (let r = 1 + p6a i resto in if r > 0 then r else -1)
   let n = p5 lista
   p6a n lista

p7 [] [] = []
p7 (x:r1) (y:r2) = (x, y): p7 r1 r2

p8 [] = ([], [])
p8 ((x,y):resto) = let (r1, r2) = p8 resto in (x:r1, y:r2) 


p9 0 lista@(x:resto) = []
p9 i lista@(x:resto) = lista:(p9 (i-1) lista)
p9 0 [] = []
p9 i [] = []:(p9 (i-1) [])

main = print (p9 10 [1..2])