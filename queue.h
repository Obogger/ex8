#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef>

struct IMemory
{
    virtual void *malloc(size_t size) = 0;
    virtual void free(void *ptr) = 0;
    virtual ~IMemory() = default;
};

template <typename T>
class Queue
{
    struct node_t
    {
        T data;
        node_t *next;
    };
    
IMemory &memory;
size_t count{0};
node_t *head{nullptr};
node_t *tail{nullptr};

public:
    Queue(const Queue &) = delete;
    Queue &operator=(const Queue &) = delete;
    
    Queue(IMemory &_memory) : memory{_memory} {};

    Queue(Queue &&that) noexcept {};
    Queue &operator=(Queue &&that) noexcept {};

    bool enqueue(const T &item) {};
    bool dequeue(T &item) {};

    size_t size(void) {return count;}

    void clear(void) {};

    ~Queue() {};
};

#endif //QUEUE_H