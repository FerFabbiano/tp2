#ifndef COUNTER_THREAD_H
#define COUNTER_THREAD_H

#include "thread.h"
#include "resultProtected.h"

class CharCounter : public Thread {
public:
    CharCounter(const char* filename, char countChar, ResultProtected &result);
    void run();
    void printResult() const;
    int getResult() const;
private:
    std::string filename;
    char countChar;
    ResultProtected &result; 
};

#endif