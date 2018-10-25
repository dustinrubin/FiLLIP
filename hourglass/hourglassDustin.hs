main = interact $ show . solve . (map.map) read  . map words . lines

hourglassSum ((n1:n2:n3:_):(_:n4:_:_):(n5:n6:n7:_):_) = n1 + n2 + n3 + n4 + n5 + n6 + n7

solve ((x:y:[]):_) = smallnumber
solve array = maximum $ [hourglassSum array,solveDown $ tail array,solve $ map tail array]

solveDown (ys:xs:[]) = smallnumber
solveDown array = maximum $ [hourglassSum array, solveDown $ tail array]

smallnumber = -999

testData = [[1,1,1,0,0,0],
            [0,1,0,0,0,0],
            [1,1,1,0,0,0],
            [0,0,2,4,4,0],
            [0,0,0,2,0,0],
            [0,0,1,2,4,0]]



