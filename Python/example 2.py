# returns the sum of each bits in x
def func(x):
    t = 0
    while x != 0:
        t += x % 2
        x //= 2
    return t


n = int(input())
l = []
c = []
for i in range(n):
    temp = input()
    t = int(temp[:temp.find(" ")])
    a = int(temp[temp.find(" ")+1:])
    if t == 1:
        l.append(a)
    else:
        min = 30
        for j in l:
            g = j ^ a
            cvp = func(g)
            if cvp < min:
                min = cvp
        c.append(min)



for i in c:
    print(i)
