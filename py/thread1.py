import threading
import time
class bank(threading.Thread):
    bal=1000
    def __init__(self,name,amt):
        super().__init__()
        self.name = name
        self.amt = amt
    def run(self):
        transact(self.amt)

def transact(amt):
        print("Accessing account")
        p1.acquire()
        k=getbal()
        time.sleep(.5)
        bank.bal=k+amt
        time.sleep(.5)
        p1.release()
def getbal():
    return bank.bal
p1=threading.Lock()
t=bank("Raj",2000)
t1=bank("Ram",10000)
t.start()
t1.start()
t.join()
t1.join()
print(bank.bal)