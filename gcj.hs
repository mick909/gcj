-- $ cat test.in | ghc -e main gcj.hs
 
import Control.Applicative
import Data.List
 
main = enumFromTo 1 <$> readLn >>= mapM_ doCase
    where doCase n = parse >>=  format n . solve
          format n r = putStrLn $ "Case #" ++ show n ++ ": " ++ show r
 
-- Get input data for a case
parse = map read . words <$> getLine
 
solve [a, b] = a + b