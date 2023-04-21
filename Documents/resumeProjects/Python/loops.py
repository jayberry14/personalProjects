def main():
    x = 0
    # while (x<5):
    #     print(x)
    #     x=x+1
    
    # for x in range(5, 10):
    #     print(x)

    days = ["Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"]
    for i, d in enumerate(days):
        print(i, d)

    for x in range(5, 10):
        # if (x==7): break
        if (x % 2 == 0): continue
        print(x)

if __name__ == "__main__":
    main()