def rule(x):
    cnt = 0
    for i in range(1, x+1):
        a = i
        b = 1
        for _ in range(0, i):      
            cnt += 1
            if(cnt == x):
                if(i%2==0):
                    return b, a
                else:
                    return a, b 
            a -= 1
            b += 1  

if __name__ == '__main__':
    x = int(input())
    u, d = rule(x)
    print('%d/%d' % (u, d))
