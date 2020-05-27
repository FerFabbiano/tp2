#ifndef BLOCKING_QUEUE_H
#define BLOCKING_QUEUE_H

#include <condition_variable>
#include <queue>
#include <mutex>

class BlockingQueue {
private:
    bool isClosed;
    std::mutex m;
    std::queue<char> queue;
    std::condition_variable cv;
public: 
    BlockingQueue();
    void push(const char material);
    char pop();
    void close();
    ~BlockingQueue();
};

#endif
