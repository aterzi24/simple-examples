class insan:
    def __init__(self,a="isim",b="soyisim",c=0,d="meslek"):
        self.ad = a
        self.soyad = b
        self.yas = c
        self.meslek = d
    def buyu(self):
        self.yas += 1
    def print(self):
        print(self.ad, self.soyad, self.yas, self.meslek)


ben = insan("ahmet", "terzi", 20, "öğrenci")
ben.print()
