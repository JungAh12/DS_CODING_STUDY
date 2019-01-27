def rule(month, day):
    days = [31,28,31,30,31,30,31,31,30,31,30,31]
    week = ['SUN','MON','TUE','WED','THU','FRI','SAT']
    ret = 0
    for i in range(0, month-1):
        ret += days[i]
    ret += day
    ret %= 7
    return week[ret]
    
if __name__ == '__main__':
    date = input()
    date = date.split(' ')
    ret = rule(int(date[0]),int(date[-1]))
    print(ret)
