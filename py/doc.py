def add(*args):
    '''Function returns the sum of values passed to it'''
    sum=0
    for i in args:
        sum+=i
    return sum
print(add.__doc__) # to print anything written in ('''  ''') documentation
print("Sum = ",add(25,30,45,50))