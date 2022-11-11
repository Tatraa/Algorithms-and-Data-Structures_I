#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <iostream>     // deklaracje strumieni cout, cin, cerr
#include <cassert>    // assert()

template <typename T>
struct DoubleNode {
// the default access mode and default inheritance mode are public
    T value;
    DoubleNode *next, *previous;
    // konstruktor domyslny (niepotrzebny)
    DoubleNode() : value(T()), next(nullptr), previous(nullptr) {}
    DoubleNode(const T& item, DoubleNode *nptr=nullptr, DoubleNode *pptr=nullptr)
            : value(item), next(nptr), previous(pptr) {} // konstruktor
    ~DoubleNode() {} // destruktor
};


template <typename T>
class DoubleList
{
    DoubleNode<T> *head, *tail;
public:
    DoubleList() : head(nullptr), tail(nullptr) {}
    ~DoubleList()
    {
        while(!empty())
            pop_front();
    } // tu trzeba wyczyscic wezly

    DoubleList(const DoubleList& other)
    {
        DoubleNode <T> *node = other.head;
        head = nullptr;
        tail = nullptr;
        while(node)
        {
            push_back(node -> value);    // copy constructor
            node = node -> next;
        }
    }
    // usage:   DoubleList<int> list2(list1);
    DoubleList(DoubleList&& other); // move constructor NIEOBOWIAZKOWE
    // usage:   DoubleList<int> list2(std::move(list1));
    DoubleList& operator=(const DoubleList& other)
    {
        if(this!=&other)
        {
            if(other.head == nullptr)
                head = nullptr;
            else
            {
                clear();
                DoubleNode <T> *p1, *p2;
                head = new DoubleNode<T>;
                head -> value = other.head -> value;
                p1 = head;
                p1 -> previous = nullptr;
                p2 = other.head -> next;
                while(p2)
                {
                    p1 -> next = new DoubleNode<T>;
                    p1 -> next -> previous = p1;
                    p1 = p1 -> next;
                    p1 -> value = p2 -> value;
                    p2 = p2 -> next;
                }
                p1 -> next = nullptr;
                tail = p1;
            }
        }
        return *this;
    } // copy assignment operator, return *this
    // usage:   list2 = list1;
    DoubleList& operator=(DoubleList&& other); // move assignment operator, return *this
    // usage:   list2 = std::move(list1); NIEOBOWIAZKOWE
    bool empty() const { return head == nullptr; }
    int size() const
    {
        DoubleNode <T> *node = head;
        int x = 0;
        while(node)
        {
            x++;
            node = node -> next;
        }
        return x;
    } // O(n) bo trzeba policzyc
    void push_front(const T& item); // O(1)
    void push_front(T&& item); // O(1) NIEOBOWIAZKOWE
    void push_back(const T& item)
    {
        if(!empty())
        {
            tail -> next = new DoubleNode <T> (item, head);
            tail -> next -> previous = tail;
            tail -> next -> next = nullptr;
            tail = tail -> next;
        }
        else
            head = tail = new DoubleNode <T> (item,head);
    } // O(1)
    void push_back(T&& item)
    {
        if(!empty())
        {
            tail -> next= new DoubleNode <T> (std::move(item), head);
            tail -> next -> previous = tail;
            tail -> next -> next = nullptr;
            tail = tail -> next;
        }
        else
            head = tail = new DoubleNode <T> (std::move(item),head);
    } // O(1) NIEOBOWIAZKOWE
    T& front() const { return head->value; } // zwraca poczatek, nie usuwa
    T& back() const { return tail->value; } // zwraca koniec, nie usuwa

    void pop_front()
    {
        assert(!empty());
        DoubleNode<T>* temp = head;
        if(head==tail){
            head = tail = nullptr;
        }
        else
        {
            head = head -> next;
            head -> previous = nullptr;
        }
        delete temp;
    } // usuwa poczatek O(1)

    void pop_back()
    {
        assert(!empty());
        DoubleNode<T>* temp = tail;
        if(head==tail)
            head = tail=nullptr;
        else
        {
            tail = tail -> previous;
            tail -> next = nullptr;
        }
        delete temp;
    } // usuwa koniec O(n)

    void clear()
    {
        while(!empty())
            pop_front();
    } // czyszczenie listy z elementow O(n)

    void display()
    {
        DoubleNode <T> *node = head;
        while(node)
        {
            std::cout<<node->value<<" ";
            node = node -> next;
        }
        std::cout<<std::endl;
    } // O(n)

    void display_reversed()
    {
        DoubleNode <T> *node = tail;
        while(node)
        {
            std::cout<<node->value<<" ";
            node = node -> previous;
        }
        std::cout<<std::endl;
    } // O(n)

    // Operacje z indeksami. NIEOBOWIAZKOWE
    T& operator[](int pos); // podstawienie L[pos]=item
    const T& operator[](int pos) const; // odczyt L[pos]
    void erase(int pos);
    int index(const T& item); // jaki index na liscie (-1 gdy nie ma) O(n)
    void insert(int pos, const T& item); // inserts item before pos,
    void insert(int pos, T&& item); // inserts item before pos,
    // Jezeli pos=0, to wstawiamy na poczatek.
    // Jezeli pos=size(), to wstawiamy na koniec.
};

template <typename T>
void DoubleList<T>::push_front(const T& item)
{
    if (!empty())
    {
        head = new DoubleNode<T>(item, head);
        head -> next -> previous = head;
    }
    else
    {
        head = tail = new DoubleNode<T>(item);
    }
}

template <typename T>
void DoubleList<T>::push_front(T&& item)
{
    if (!empty())
    {
        head = new DoubleNode<T>(std::move(item), head);
        head -> next -> previous = head;
    } else
    {
        head = tail = new DoubleNode<T>(std::move(item));
    }
}

#endif