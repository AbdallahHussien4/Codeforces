x = int(input())
steps = x // 5 
if x % 5:
    steps += 1

print(steps)