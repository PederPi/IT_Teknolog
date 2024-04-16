def averageFunction(manArg, *args):
    """Calculates average of a list"""
    nominator = 0
    denominator = 0

    for argument in args:
        nominator += sum(argument)
        denominator += len(argument)
    return (nominator + sum(manArg)) / (denominator + len(manArg))

testList1 = [1, 2, 3, 4, 5]
testList2 = [6, 7, 8, 9, 10]
print(averageFunction(testList1, testList2))
