def fib(n):
    if cnt[0][n] != 0 or cnt[1][n] != 0:
        return
    else:
        if n == 0:
            cnt[0][n] += 1
            return

        elif n == 1:
            cnt[1][n] += 1
            return
        else:
            fib(n - 1)
            fib(n - 2)

    cnt[0][n] = cnt[0][n - 1] + cnt[0][n - 2]
    cnt[1][n] = cnt[1][n - 1] + cnt[1][n - 2]
    return


cnt = [[0 for i in range(41)] for j in range(2)]
t = int(input())
for i in range(t):
    n = int(input())
    fib(n)
    # print(cnt)
    print(cnt[0][n], cnt[1][n])
