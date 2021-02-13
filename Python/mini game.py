print("aklından 1 ile x arasında sayı tut(x'i gir)")
b = int(input())
a = b // 2
b += 1
k = 0
print("Tuttuğun sayı", a)
c = input("(e)vet, (b)üyük, (k)üçük\n")
while True:
    if c == "e":
        break
    elif c == "b":
        k = a
        a = (a + b) // 2
        if a == k:
            print("yanlış girdiniz çıkılıyor...")
            break
    elif c == "k":
        b = a
        a = (a + k) // 2
        if b == a:
            print("Yanlış girdiniz çıkılıyor...")
            break
    else:
        c = input("Tekrar girer misin?")
        continue
    print("Tuttuğun sayı", a)
    c = input("(e)vet, (b)üyük, (k)üçük\n")
