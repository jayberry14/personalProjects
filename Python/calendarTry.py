import calendar

c = calendar.TextCalendar(calendar.SUNDAY)
# st = c.formatmonth(2020, 1, 0, 0)
# print(st)

# hc = calendar.HTMLCalendar(calendar.SUNDAY)
# st = hc.formatmonth(2020, 1)
# print(st)

# for i in c.itermonthdays(2020, 8):
#     print(i)

# for name in calendar.month_name:
#     print(name)

# for day in calendar.day_name:
#     print(day)

print("Team meetings will be on ")
for m in range(1, 13):
    cal = calendar.monthcalendar(2020, m)
    weekone=cal[0]
    weektwo=cal[1]

    if weekone[calendar.FRIDAY] !=0:
        meetday = weekone[calendar.FRIDAY]
    else:
        meetday = weektwo[calendar.FRIDAY]
    
    print("%10s %2d" % (calendar.month_name[m], meetday))