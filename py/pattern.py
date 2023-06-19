if __name__ == '__main__':
    def pattern(c='%',n=6,r=1):
        for i in range(r):
            print()
            for j in range(n):
                print(c,end=' ')
    
    c=input("Enter the charecter to display:")
    n=int(input("Enter number of column:"))
    m=int(input("Enter number of row:"))
    pattern()
    pattern(c)
    pattern(c,n)
    pattern(c,n,m)
    print(end='\n')