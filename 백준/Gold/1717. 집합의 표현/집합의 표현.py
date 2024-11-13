import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)
parent = list(range(1000001))

def find(x):
    if x == parent[x]:
        return x
    parent[x] = find(parent[x])
    return parent[x]

def merge(x,y):
    px = find(x)
    py = find(y)
    if px > py:
        px, py = py, px
    parent[py] = px

n, m = map(int, input().split())
for _ in range(m):
    x, a, b = map(int, input().split())
    if x == 0:
        merge(a, b)
    elif x == 1: 
        if find(a) == find(b):
            print("YES")
        else:
            print("NO")