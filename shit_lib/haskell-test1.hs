
    map' :: (a -> b) -> [a] -> [b]
    map' _ [] = []
    map' func (e:es) = func e:map' func es

    main = print $ length $ map' (> 0)[1..5000000]
