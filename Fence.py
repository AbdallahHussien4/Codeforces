t = int(input())
out = []
while t:
    inp = list(map(int, input().split()))
    inp.sort()
    out.append(inp[0] + inp[2] - inp[1])
    t -= 1

for i in out:
    print(i)    