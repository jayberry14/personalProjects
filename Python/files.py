def main():
    # f = open("textfile.txt", "w+") # Open a file for writing and create it if it doesn't exist
    f = open("textfile.txt", "r") # Open the file for appending text to the end

    # for i in range(10): # Write some lines to the file
    #     f.write("This is line " + str(i) + "\r\n")

    if f.mode == 'r':
        # contents = f.read()
        fl = f.readlines()
        for x in fl:
            print(x)
        # print(contents)

if __name__ == "__main__":
    main();