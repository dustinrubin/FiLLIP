main = interact $ show . solve . (map.map) read  . map words . lines

smallnumber = -999

hourglassSum ((n1:n2:n3:_):(_:n4:_:_):(n5:n6:n7:_):_) = n1 + n2 + n3 + n4 + n5 + n6 + n7
hourglassSum _ = smallnumber

solve ([]:xs) = smallnumber
solve ([]) = smallnumber
solve array = maximum $ [hourglassSum array,solve $ tail array,solve $ map tail array]


testData = [[1,1,1,0,0,0],
            [0,1,0,0,0,0],
            [1,1,1,0,0,0],
            [0,0,2,4,4,0],
            [0,0,0,2,0,0],
            [0,0,1,2,4,0]]



