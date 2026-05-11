import threading;

semaphore: threading.Semaphore
mutex: threading.Lock
counter: int
thread_number: int

def createBarrier(n: int): 
    global mutex, semaphore, counter, thread_number

    mutex = threading.Lock()
    semaphore = threading.Semaphore(0)
    thread_number = n
    counter = 0

def reach_barrier():
    global mutex, semaphore, counter, thread_number

    mutex.acquire()
    counter += 1
    if counter == thread_number:
        for i in range(thread_number):
            semaphore.release()

        mutex.release()
    else:
        mutex.release()
        semaphore.acquire()

def worker():
    print("Started worker")
    print("Worker achieved the barrier")
    reach_barrier()
    print("Worker finished its job")

x = 50
createBarrier(x)
thread_list = []
for i in range(x):
    thread = threading.Thread(target=worker)
    thread.start()
    thread_list.append(thread)

for thread in thread_list:
    thread.join()