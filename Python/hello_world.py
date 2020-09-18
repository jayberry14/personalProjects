def main():
    print("Hello World!")
    # f = 0
    # print(f)
    # f = "abc"
    # print(f)
    # print("this is a string " + str(123))

def someFunction():
    global f
    f="def"
    print(f)

if __name__ == "__main__":
    main()

f=0
someFunction()
print(f)

# del f
# print(f)