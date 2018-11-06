#!/usr/bin/env python3
# Initialize problem directory for FiLLIP
# NOTE execute this script from the directory you want to create the problem directoy in
# reltivePathToScript/makeProblemDirectory.py
# Also wrap URL in ""

import os
import sys





#Validate correct amount of comand line arguments
if len(sys.argv) != 3:
    print("usage: makeProblemDirectory.py [nameOfDirectoy] [URLOfProblem]")
    sys.exit(0)
#Parse Input
directoryName = sys.argv[1]
url = sys.argv[2]

print("Creating directoy in " + os.getcwd())
os.mkdir(directoryName)
os.chdir(directoryName)
#Initialize readme
makefile = open("README.md", 'w')
makefileContents = """View the prompt on HackerRank: [Problem](""" + url + """)

TIME COMPLETED:

Dustin:

Talitha:
"""
makefile.write(makefileContents)