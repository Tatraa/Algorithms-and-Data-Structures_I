#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cassert>

template <typename T>
struct SingleNode
{
    T value;
    SingleNode *next;
    SingleNode() : value(T()), next(nullptr) {}
    SingleNode(const T& item, SingleNode *ptr=nullptr) : value(item), next(ptr) {}
    ~SingleNode() {}
};

template <typename T>
class Queue
{
    SingleNode<T> *head, *tail;
    int size2;
public:
    Queue() : head(nullptr), tail(nullptr) { size2 = 0; }
    ~Queue()
    {
        while(!empty())
            pop();
    }
    Queue(const Queue& other)
    {
        head = tail = nullptr;
        SingleNode<T> *node = other.head;
        while(node)
        {
            push(node -> value);
            node = node -> next;
        }
    }
    Queue& operator=(const Queue& other)
    {
        if(this != &other)
        {
            clear();
            if(other.head==nullptr)
                head = nullptr;
            else
            {
                SingleNode<T> *p1,*p2;
                head = new SingleNode<T>;
                head -> value = other.head -> value;
                p1 = head;
                p2 = other.head -> next;
                while(p2)
                {
                    p1 -> next = new SingleNode<T>;
                    p1 = p1 -> next;
                    p1 -> value = p2 -> value;
                    p2 = p2 -> next;
                }
                p1 -> next = nullptr;
                size2 = other.size2;
            }
        }
        return *this;
    }
    bool empty() const { return head == nullptr; }
    int size() const { return size2; }
    void push(const T& item)
    {
        if (!empty())
        {
            tail -> next = new SingleNode<T>(item);
            tail = tail -> next;
        }
        else
        {
            head = tail = new SingleNode<T>(item);
        }
        size2++;
    }
    void push(T&& item)
    {
        if (!empty())
        {
            tail -> next = new SingleNode<T>(std::move(item));
            tail = tail -> next;
        }
        else
        {
            head = tail = new SingleNode<T>(std::move(item));
        }
        size2++;
    }
    T& front() const { return head -> value; }
    T& back() const { return tail -> value; }
    T pop()
    {
        assert(!empty());
        SingleNode<T> *node = head;
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head -> next;
        }
        size2--;
        T val;
        val = node -> value;
        delete node;
        return val;
    }
    void clear()
    {
        while(!empty())
            pop();
    }
    void display()
    {
        SingleNode<T> *node = head;
        while (node != nullptr){
            std::cout << node -> value << " ";
            node = node -> next;
        }
        std::cout << std::endl;
    }
};
#endif