#ifndef PRIOQUEUE_H
#define PRIOQUEUE_H

#include <iostream>
#include <cassert>

template <typename T>
struct SingleNode
{
    T value;
    int priority;
    SingleNode *next;
    SingleNode() : value(T()),priority(1), next(nullptr) {}
    SingleNode(const T& item, const int priority,SingleNode *ptr=nullptr) : value(item), priority(priority),next(ptr) {}
    ~SingleNode() {}
};

template <typename T>
class SingleList
{
    SingleNode<T> *head;
    int tab_size;
public:

    SingleList() : head(nullptr) { tab_size = 0; }

    ~SingleList()
    {
        while(!empty())
            pop();
    }

    SingleList(const SingleList& other)
    {
        head = nullptr;
        SingleNode<T> *node = other.head;
        while(node)
        {
            push(node -> value, node -> priority);
            node = node -> next;
        }
    }
    SingleList& operator=(const SingleList& other)
    {
        if(this != &other)
        {
            clear();
            if(other.head == nullptr)
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
                tab_size = other.tab_size;
            }
        }
        return *this;
    }

    bool empty() const { return head == nullptr; }

    int size() const { return tab_size; }

    void push(const T& item, int priority)
    {
        if (!empty())
        {
            if(priority >= head -> priority)
                head = new SingleNode<T>(item, priority, head);
            else
            {
                SingleNode <T> *insert = new SingleNode <T> (item, priority);
                SingleNode <T> *temp = head;

                if(temp -> next == nullptr)
                {
                    head -> next = insert;
                    return;
                }
                while(insert -> priority <= temp -> next -> priority)
                {
                    temp = temp -> next;
                    if(temp -> next == nullptr)
                        break;
                }
                insert -> next = temp -> next;
                temp -> next = insert;
            }
        }
        else
        {
            head = new SingleNode<T>(item, priority);
        }
        tab_size++;
    }

    void push(T&& item, int priority)
    {
        if (!empty())
        {
            if(priority >= head -> priority)
                head = new SingleNode<T>(std::move(item), priority, head);

            else
            {
                SingleNode <T> *insert = new SingleNode <T> (std::move(item),priority);
                SingleNode <T> *temporary = head;
                if(temporary -> next == nullptr)
                {
                    head -> next = insert;
                    return;
                }
                while(insert -> priority <= temporary -> next -> priority)
                {
                    temporary = temporary -> next;
                    if(temporary -> next == nullptr)
                        break;
                }
                insert -> next = temporary -> next;
                temporary -> next = insert;
            }
        }
        else
        {
            head = new SingleNode<T>(std::move(item),std::move(priority));
        }
        tab_size++;
    }
    T top() { return head->value; }
    T pop()
    {
        assert(!empty());
        SingleNode<T> *node = head;
        if (head -> next == nullptr)
        {
            head = nullptr;
        }
        else
        {
            head = node -> next;
        }
        tab_size--;
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
            std::cout << node->value;
            node = node->next;
            if(node!=nullptr)
                std::cout<<", ";
        }
        std::cout << std::endl;
    }
};
#endif