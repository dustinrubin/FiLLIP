def minimumAbsoluteDifference(array):
    minimumAbsoluteDifference = 9999999
    array.sort()
    for i in range(len(array) - 1):
        difference = abs(array[i + 1] - array[i])
        minimumAbsoluteDifference = min(minimumAbsoluteDifference, difference)
    return minimumAbsoluteDifference