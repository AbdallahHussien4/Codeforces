lines = list()
abc={'A':0,'B':0,'C':0}

lines.append(input())
lines.append(input())
lines.append(input())

for line in lines:
    if line[1]=='>':
        abc[line[0]]+=1
    else:
        abc[line[2]]+=1
values=list(abc.values())
values.sort()
if values==[0,1,2]:
    inv_abc={v:k for k,v in abc.items()}
    print(inv_abc[0],inv_abc[1],inv_abc[2],sep="")   
else:
    print("Impossible")         
           