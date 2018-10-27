import Data.List

main = interact $ show . solve . words 

solve [a, b] = (length (a \\ b)) + ( length ( b \\  a))