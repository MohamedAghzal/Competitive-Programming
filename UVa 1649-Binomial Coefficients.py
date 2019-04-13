from math import factorial as fact

def f(n, k):
    ans = 1
    for i in range(n - k + 1, n + 1):
        ans *= i
    return ans

def search(l, r, m, k, ans):
    if l > r: return
    n = (l + r) // 2
    res = f(n, k) // fact(k) 
    if res == m:
        ans.append((n, k))
        ans.append((n, n - k))
        return
    if res > m:
        search(l, n - 1, m, k, ans)
    else:
        search(n + 1, r, m, k, ans)

T = int(input())
while T > 0:
    m = int(input())
    ans = []
    for k in range(1, 100):
        search(1, m + 1, m, k, ans)
        
    ans = set(ans)
    l = []
    for p in ans:
        l.append(p)
    l.sort()
    ans = []
    for i in l:
        s = '(' + str(i[0]) + ',' + str(i[1]) +')'
        ans.append(s)
    print(len(ans))
    for i in range(0, len(ans)):
        print(ans[i], end = '')
        if(i < len(ans) - 1): print(' ', end = '')
    print()
    T -= 1
#print()
                   

