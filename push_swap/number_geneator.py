from random import randint

length = int(input("length: "))
min = int(input("min: "))
max = int(input("max: "))
if (max - min < length or min > max):
    print("impossible")
    exit()
tab = []
while (len(tab) != length):
    x = randint(min, max)
    if x not in tab:
        tab.append(x)

s = " "
for e in tab:
    if e == tab[-1]:
        s = ""
    print(e, end = s)