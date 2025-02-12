#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef>
#include <utility>

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
        Queue &operator=(const Queue &) = delete;    Queue(IMemory &_memory) : memory{_memory} {}    Queue(Queue &&that) noexcept : memory(that.memory), count(that.count), head(that.head), tail(that.tail)
        {
            that.head = nullptr;
            that.tail = nullptr;
            that.count = 0;
        }    

        Queue &operator=(Queue &&that) noexcept
        {
            if (this != &that)
            {
                clear();
                head = that.head;
                tail = that.tail;
                count = that.count;
                that.head = nullptr;
                that.tail = nullptr;
                that.count = 0;
            }
            return *this;
        }    

        bool enqueue(const T &item)
        {
            node_t *newNode = static_cast<node_t *>(memory.malloc(sizeof(node_t)));
            if (!newNode)
                return false;
            new (newNode) node_t{item, nullptr};
            if (tail)
                tail->next = newNode;
            else
                head = newNode;
            tail = newNode;
            ++count;
            return true;
        }    bool dequeue(T &item)
        {
            if (!head)
                return false;
            node_t *temp = head;
            item = head->data;
            head = head->next;
            if (!head)
                tail = nullptr;
            memory.free(temp);
            --count;
            return true;
        }    size_t size(void) const { return count; }    
        void clear(void)
        {
            while (head)
            {
                node_t *temp = head;
                head = head->next;
                memory.free(temp);
            }
            tail = nullptr;
            count = 0;
        }    ~Queue()
        {
            clear();
        }
};

#endif //QUEUE_H