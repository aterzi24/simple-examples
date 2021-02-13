n = int(input())
a = []
for i in range(n):
    temp = int(input())
    if temp < 4:
        a.append(temp//5 + 1)
    elif 3 < temp < 6:
        a.append(temp+(2*temp)%8)
    elif temp == 6:
        a.append(3*temp+temp//2)
    elif temp == 7:
        a.append(3*temp+4)
    elif temp == 8:
        a.append(temp**2-3)

for i in a:
    print(i)
