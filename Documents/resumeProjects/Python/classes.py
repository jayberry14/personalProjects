class myClass():
    def method1(self):
        print("myClass method1")
    
    def method2(self, someString):
        print("myClass method2 " + someString)

class myClass2(myClass):
    def method1(self):
        myClass.method1(self)
        print("myClass2 method1")
    
    def method2(self, someString):
        print("myClass2 method2 " + someString)

def main():
    c = myClass()
    c.method1()
    c.method2("this is a string")
    c2 = myClass2()
    c2.method1()
    c2.method2("this is a string")

if __name__ == "__main__":
    main()