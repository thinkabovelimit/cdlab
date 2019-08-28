n=input()
n=str(n)
lis1=list(n)
lis1=map(int,lis1)
lis2=list(lis1)
sum=0
for i in range(len(lis2)):
    sum=sum+lis2[i]

print(sum)