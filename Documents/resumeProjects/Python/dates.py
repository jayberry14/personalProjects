from datetime import date
from datetime import time
from datetime import datetime

def main():
    # today = date.today()
    # print("Today's date is ", today)
    # print("Date components: ", today.day, today.month, today.year)
    # print("Today's weekday # is: ", today.weekday())
    # days = ["Mon","Tue","Wed","Thu","Fri","Sat","Sun"]
    # print("Which is a: ", days[today.weekday()])
    today = datetime.now()
    print("The current date and time is: ", today)
    time = datetime.time(datetime.now())
    print(time)



if __name__ == "__main__":
    main();