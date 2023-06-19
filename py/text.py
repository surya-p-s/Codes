arr=[]
def insert():
       i=int(input())
       v=int(input())
       arr.insert(i,v)
def remove(i):
        arr.remove(i)
def pop():
       arr.remove(arr[-1])
def reverse():
        ls=arr[::-1]
        print(ls)
def append():
       v=int(input())
       arr.append(v)
def sort():
       arr.sort()
def cmmd(cmd):
    match cmd:
        case "insert":
                insert()
        case "print":
                print(arr)
        case "remove":
                i=int(input())
                remove(i)
        case "pop":
                pop()
        case "reverse":
                reverse()
        case "append":
                append()
        case "sort":
                sort()

if __name__ == '__main__':
    n=int(input())
    for i in range(0,n):
        cmd=input()
        cmmd(cmd)