#!/bin/python3

# Complete the alternatingCharacters function below.
def alternatingCharacters(string):
    lastCharater = ''
    deletedCharacters = 0
    for charater in string:
        if not lastCharater:
            lastCharater = charater
            continue
        if lastCharater == charater:
            deletedCharacters += 1
        else:
            lastCharater = charater
    return deletedCharacters
