l=[]
n=int(input("Enter a number: "))
r=int(input("Enter range: "))
for i in range(r):
    subN=int(input("Enter list:  "))
    l.append(subN)
print(l)
print(n in l)