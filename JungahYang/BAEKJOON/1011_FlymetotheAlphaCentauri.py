def rule(x, y):
    while True:
        dist = y-x
        i = int(dist**0.5)
        if dist <=3:
            return dist
        if i**2 - dist >= 0:
            return i*2-1
        elif i**2+i < dist:
            return i*2+1
        else:
            return i*2
                
if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        x = input()
        x = x.split(' ')
        ret = rule(int(x[0]), int(x[1]))
        print(ret)
