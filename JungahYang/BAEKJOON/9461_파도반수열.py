def rule(n,s):
    if n <= 5 or s[n]!=0:
        return s[n]
    else :
        s[n]= rule(n-1,s)+rule(n-5,s)
        return s[n]

if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        n = int(input())
        if n<=5:
            s=[0 for _ in range(6) if True]
        else:
            s=[0 for _ in range(n+1) if True]
        s[1] = s[2] = s[3] = 1
        s[4] = s[5] = 2

        print(rule(n,s))
