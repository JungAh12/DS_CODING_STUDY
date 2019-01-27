person = [[0 for j in range(15)]for i in range(15)]

def rule():
    for i in range(0,15):
        person[i][0] = 1
        person[0][i] = i+1
    for i in range(1,15):
        for j in range(1,15):
            person[i][j] = person[i-1][j]+person[i][j-1]

if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        rule()
        k = int(input())
        n = int(input())-1
        ret = person[k][n]
        print(ret)
