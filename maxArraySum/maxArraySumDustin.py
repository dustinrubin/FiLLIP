#!/bin/python3

import math
import os
import random
import re
import sys



def maxSubsetSum(list):
    oneBackSolution = 0
    twoBackSolution = 0
    for index in range(len(list)):
        currentValue = list[index]
        if currentValue > 0 and twoBackSolution + currentValue > oneBackSolution:
            ( twoBackSolution, oneBackSolution) =  ( oneBackSolution, twoBackSolution + currentValue)
        else:
            twoBackSolution = oneBackSolution
            
    return max(twoBackSolution, oneBackSolution)




if __name__ == "__main__":
    l =[ 3, 5, 8, 10, 4, 5]
    l2 = [3, 5, -7, 8, 10]

    print(maxSubsetSum(l))
    print(maxSubsetSum(l2))
    