def rule(N):
    if N == 1:
        return 1
    num = 1
    start = 2
    while True:
        if start+(6*num)-1 >= N:
            return num+1
        start += (6*num)
        num += 1

if __name__ == '__main__':

    N = int(input())
    result = rule(N)
    print(result)

