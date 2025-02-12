#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>

struct IMemory
{
    virtual void *malloc(size_t size) = 0;
    virtual void free(void *ptr) = 0;
    virtual ~IMemory() = default;
};

template <typename T>
class queue
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
    queue(const queue &) = delete;
    queue &operator=(const queue &) = delete;
    
    queue(IMemory &_memory) : memory{_memory} {};

    queue(queue &&that) noexcept {};
    queue &operator=(queue &&that) noexcept {};

    bool enqueue(const T &item) {};
    bool dequeue(T &item) {};

    size_t size(void) {return count;}

    void clear(void) {};
    ~queue() {};
};

#endif //QUEUE_H