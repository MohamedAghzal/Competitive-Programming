import sys

n, m = map(int, input().split())
s = str(input())
t = str(input())

if '*' not in s:
    if s == t:
        print('YES')
    else:
        print('NO')
    sys.exit(0)

l, r = s.split('*')

if t.startswith(l) and t.endswith(r) and len(t) >= len(l) + len(r):
    print('YES')
else:
    print('NO')
