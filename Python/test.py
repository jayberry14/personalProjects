def main():
    # dayOne()
    dayTwo()

def dayOne():
    for i in range(1000, 10000):
        f = i // 1000
        s = (i // 100) % 10
        t = (i // 10) % 10
        l = i % 10
        r = l * 1000 + t * 100 + s * 10 + f
        if i == r * 4:
            print(i)

def dayTwo():
    plm = 12
    
    g = 1
    l = 2
    s = 3
    m = 4
    n = 5
    p = 6
    t = 9
    r = 10
    b = 11
    v = 14

    e = 1
    a = 2
    u = 3
    i = 4
    o = 6
    sumOfConsonants = p + r + b + l + m + s + l + v + n + g
    sumOfVowels = o + e + i + o
    print(sumOfConsonants * sumOfVowels)

if __name__ == "__main__":
    main()