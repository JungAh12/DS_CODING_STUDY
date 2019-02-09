def find(num):
    p=[]
    k=0
    r_max = 0
    l_max = 0
    for n in num:
        if k*n < 0:
            p.append(k)
            k=n
        else:
            k+=n
    p.append(k)

    i = p.index(max(p))

    if p[i]<=0 :
        return max(num)
    else:
        s = 0
        if p[i]!=p[-1]:
            for r in p[i+1:]:
                s += r
                if s>r_max:
                    r_max = s
        elif p[i]!=p[0]:
            for l in p[i-1::-1]:
                s += l
                if s>l_max:
                    l_max = s

    return l_max + max(p) + r_max

n= int(input())
print(find(list(map(int, input().split(' ')[0:n]))))
