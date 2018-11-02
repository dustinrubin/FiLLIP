#!/bin/python3



def maximumToys(prices, money):
    toys = 0
    for toy in sorted(prices):
        money -= toy
        if money == 0:
            toys += 1
            break
        if money < 0:
            break
        toys += 1
    return toys