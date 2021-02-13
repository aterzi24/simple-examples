temp = input()
n = int(temp[:temp.find(" ")])
m = int(temp[temp.find(" ")+1:])
a = []
temp = input()
for i in range(n):
    a.append(int(temp[:temp.find(" ")]))
    temp = temp[temp.find(" ")+1:]

j = 1
while j <= len(a) / 2:
    i = 0
    while(i + 2 * j <= len(a)):
        if( a[i:i+j] == a[i+j:i+2*j] ):
            a[i:i+2j] = a[i:i+j]
            continue
        i += 1

    j += 1
