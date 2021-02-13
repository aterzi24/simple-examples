a = 100

func()
print(a)
while a > 0:
    print("asd")
    a = a // 2

def func():
    global a
    print(a)
    a += 1
