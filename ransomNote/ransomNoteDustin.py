
def loadListIntoDictonary(list):
    dictonary = {}
    for word in list:
        if word in dictonary:
            dictonary[word] += 1
        else:
            dictonary[word] = 1
    return dictonary

def checkMagazine(magazine, note):
    magazineDictonary = loadListIntoDictonary(magazine)
    noteDictonary = loadListIntoDictonary(note)
    for word in noteDictonary:
        if not word in magazineDictonary:
            return "No"
        if noteDictonary[word] > magazineDictonary[word]:
            return "No"
    return "Yes"