#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the checkMagazine function below.
def checkMagazine(magazine, note):
    #dictonary is hash
    wordsDict = {}
    
    # add words to dict
    for word in magazine:
        if word in wordsDict:
            wordsDict[word] += 1
        else:
            wordsDict[word] = 1
            
    # use words for note
    canMakeNote = True
    for word in note:
        if (word not in wordsDict) or (wordsDict[word] < 1):
            canMakeNote = False;
            break
        else:
            wordsDict[word] -= 1
    
    #print result
    if canMakeNote:
        print ("Yes")
    else:
        print ("No")
    

if __name__ == '__main__':
    mn = input().split()

    m = int(mn[0])

    n = int(mn[1])

    magazine = input().rstrip().split()

    note = input().rstrip().split()

    checkMagazine(magazine, note)
