#ifndef RWLOCK_H
#define RWLOCK_H

#include <iostream>
#include <cstdlib>
#include <thread>
#include <mutex>
#include <vector>
#include <functional>
#include <condition_variable>

//A multiple-read/single-write lock.

class RWLock
{
public:
    RWLock():
        shared(),
        readerQ(),
        writerQ(),
        active_readers(0),
        waiting_writers(0),
        active_writers(0){}

    bool no_one_writing(){
        return active_readers > 0 || active_writers == 0;
        //return waiting_writers == 0 && active_writers == 0;
    }
    bool no_one_read_and_no_one_write(){
        return active_readers == 0 && active_writers == 0;
    }
    void ReadLock() {
        std::unique_lock<std::mutex> lk(shared);
        readerQ.wait(lk, std::bind(&RWLock::no_one_writing, this));
        ++active_readers;
        lk.unlock();
    }

    void ReadUnlock() {
        std::unique_lock<std::mutex> lk(shared);
        --active_readers;
        lk.unlock();
        writerQ.notify_one();
    }

    void WriteLock() {
        std::unique_lock<std::mutex> lk(shared);
        ++waiting_writers;
        writerQ.wait(lk, std::bind(&RWLock::no_one_read_and_no_one_write, this));
        --waiting_writers;
        ++active_writers;
        lk.unlock();
    }

    void WriteUnlock() {
        std::unique_lock<std::mutex> lk(shared);
        --active_writers;
        if(waiting_writers > 0)
            writerQ.notify_one();
        else
            readerQ.notify_all();
        lk.unlock();
    }

private:
    std::mutex              shared;
    std::condition_variable readerQ;
    std::condition_variable writerQ;
    int                     active_readers;
    int                     waiting_writers;
    int                     active_writers;
};

#endif // RWLOCK_H
