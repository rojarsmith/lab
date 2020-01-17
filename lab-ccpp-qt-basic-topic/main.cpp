#include <QCoreApplication>
#include <condition_variable>
#include <thread>
#include <iostream>
#include <vector>
#include <mutex>
#include <deque>
#include <rwlock.h>

using namespace std;

struct QueueBuffer {
    deque<int> deq;
    int capacity;
    mutex lock;
    condition_variable not_full; //producer thread.
    condition_variable not_empty; //consumer thread.
    QueueBuffer(int capacity) : capacity(capacity){}
    void deposit(int data){
        unique_lock<mutex> lk(lock);
        while(deq.size() == capacity){
            not_full.wait(lk);
        }
        deq.push_back(data);
        lk.unlock();
        not_empty.notify_one();
    }
    int fetch(){
        unique_lock<mutex> lk(lock);
        while(deq.size() == 0){
            not_empty.wait(lk);
        }
        int ret = deq.front();
        deq.pop_front();
        lk.unlock();
        not_full.notify_one();
        return ret;
    }
};

void consumer(int id, QueueBuffer& buffer){
    for(int i = 0; i < 20; ++i){
        int value = buffer.fetch();
        cout << "Consumer " << id << " fetched " << value << endl;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

void producer(int id, QueueBuffer& buffer){
    for(int i = 0; i < 30; ++i){
        buffer.deposit(i);
        cout << "Produced " << id << " produced " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

int result = 0;

void func(RWLock &rw, int i){
    if(i % 2 == 0){
        rw.WriteLock();
        result += 1;
        rw.WriteUnlock();
        rw.ReadLock();
        rw.ReadUnlock();
    }else{
        rw.ReadLock();
        rw.ReadUnlock();
        rw.WriteLock();
        result += 2;
        rw.WriteUnlock();
    }
}

void not_safe(int i){
    if(i%2 == 0){
        result += 1;
    }else{
        result += 2;
    }
}

int main(int argc, char *argv[])
{    
    RWLock rw;
    std::vector<std::thread> threads;
    for(int i = 0; i < 1000; i++){
        //threads.push_back(std::thread(func, ref(rw), i));
        threads.push_back(std::thread(not_safe, i));
    }
    for(int i = 0; i < threads.size() ; i++)
    {
        threads[i].join();
    }
    cout << result << endl;


    QueueBuffer buffer(4);

    thread c1(consumer, 0, ref(buffer));
    thread c2(consumer, 1, ref(buffer));
    thread c3(consumer, 2, ref(buffer));
    thread p1(producer, 0, ref(buffer));
    thread p2(producer, 1, ref(buffer));

    c1.join();
    c2.join();
    c3.join();
    p1.join();
    p2.join();

    return 0;
}
