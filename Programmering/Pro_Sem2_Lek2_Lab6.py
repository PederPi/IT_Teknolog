import math

def radiansFunction(degrees):
    return round(degrees * (math.pi / 180), 2)


for x in range(0, 181):
    print("|", x, "|", radiansFunction(x), "|")