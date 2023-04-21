def main():
    x, y = 10, 100

    if (x < y):
        st = "x is less than y"
    elif (y < x):
        st = "x is greater than y"
    else:
        st = "x is equal to y"
    print(st)
    st = "x is less than y" if (x<y) else "x is greater than or the same as y"
    print(st)

if __name__ == "__main__":
    main()