from math import factorial as fact

def comb(x, y):
  return fact(x) // (fact(y) * fact(x - y))

n, m, t = map(int, input().split())
ans = 0

for i in range(4, min(t, n + 1)):
  if (t - i > m):
    continue
  ans += comb(m, t - i) * comb(n, i)

print(ans)
