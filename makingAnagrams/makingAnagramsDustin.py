#!/bin/python3

import math
import os
import random
import re
import sys

def makeAnagram(a, b):
    arrayOfLetters = [0  for x in range(26)]
    for charater in a:
        postionInArray = ord(charater) - ord('a') 
        arrayOfLetters[postionInArray] += 1
    for charater in b:
        postionInArray = ord(charater) - ord('a') 
        arrayOfLetters[postionInArray] -= 1
    returnValue = 0
    for count in arrayOfLetters:
        returnValue += abs(count)
    return returnValue
