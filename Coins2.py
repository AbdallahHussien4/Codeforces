num=int(input())
out=[num]
i=num//2
current=num
while i>0:
    if current % i ==0:
        out.append(i)
        current=i
        i=i//2
    else:
        i-=1
print(*out,sep=" ")
