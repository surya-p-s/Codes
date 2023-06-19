import threading
import time
# def m1():
#     for i in range(1,10):
#         print(i)
#         time.sleep(0.5)
# def m2():
#     for i in range(25,35):
#         print(i)
#         time.sleep(0.5)
# t=threading.Thread(target=m1)
# t1=threading.Thread(target=m2)
# t.start()
# t1.start()
# t.join()
# t1.join()
# print("end")


# #***************Using Class*******************

class thread1(threading.Thread):
    def run(self):
        for i in range(1,10):
            print(i)
            time.sleep(0.5)

class thread2(threading.Thread):
    def run(self):
        for i in range(15,30):
            print(i)
            time.sleep(0.5)
t=thread1()
t1=thread2()
t.start()
t1.start()