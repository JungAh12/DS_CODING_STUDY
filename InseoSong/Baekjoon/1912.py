n = int(input())
s = input()
num = list(map(int, s.split(' ')))

cm = -2000
cs = -2000
m = []
a = []
for i in range(n):
    if cs == -2000:
        cs = num[i]
        m.append(i)

        if cs > cm:
            cm = cs
    else:
        if cs > cs + num[i]:
            if cs > cm:
                cm = cs
                a = m
            cs = -2000
            m = []
        else:
            cs += num[i]
            m.append(i)

cm = 0
print(a)
if len(a) == 0:
    cm = max(num)
else:
    for i in a:
        if num[i] < 0:
            continue
        cm += num[i]

print(cm)
