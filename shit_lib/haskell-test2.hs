
    map' :: (a -> b) -> [a] -> [b]
    map' func es = [func e | e <- es]

    main = print $ length $ map' (> 0)[1..5000000]
