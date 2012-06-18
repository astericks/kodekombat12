#!/usr/bin/python

import threading
import time
import sys
b1='U' #bot1s current move
b2='R' #bot2s current move

bot1_move_lock=threading.Lock() #lock to provide synchronisation to b1
bot2_move_lock=threading.Lock() #lock ot provide syncrhonisation to b2


exitFlag = 0

class thread_to_read_bot1_move_from_file (threading.Thread):

    def __init__(self, threadID,filename):
        self.threadID = threadID
        threading.Thread.__init__(self)

    def run(self):
        global b1
        print "Starting " + str(self.threadID)
        bot1_move_lock.acquire()
        print "Before" +  b1
        b1='L'
        print "After" +  b1
        bot1_move_lock.release()
        print "Exiting " + str(self.threadID)

class thread_to_read_bot2_move_from_file (threading.Thread):

    def __init__(self, threadID,filename):
        self.threadID = threadID
        threading.Thread.__init__(self)

    def run(self):
        global b1
        print "Starting " + str(self.threadID)
        bot2_move_lock.acquire()
        print "Before" +  b1
        b2='L'
        print "After" +  b1
        bot2_move_lock.release()
        print "Exiting " + str(self.threadID)


bot1_move_file=open("files/bot1_move","r")
bot2_move_file=open("files/bot2_move","r")
thread1 = thread_to_read_bot1_move_from_file(1,bot1_move_file)
thread2 = thread_to_read_bot2_move_from_file(1,bot2_move_file)




thread1.start()
thread2.start()

while(True):
    if ( thread1.isAlive() or thread2.isAlive()):
        continue
    if( bot1_move_lock.acquire(False)):
        print b1,b2
        break
    else:
        pass
                

print "Exiting main thread"
