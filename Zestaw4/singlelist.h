#ifndef SINGLELIST_H
#define SINGLELIST_H

#include <iostream>     // deklaracje strumieni cout, cin, cerr
#include <cassert>    // assert()

template <typename T>
struct SingleNode 
{
// the default access mode and default inheritance mode are public
    T value;
    SingleNode *next;
    SingleNode() : value(T()), next(nullptr) {} // domyślny constructor
    SingleNode(const T& item, SingleNode *ptr=nullptr) : value(item), next(ptr) {}
    ~SingleNode() {} // destruktor
};


template <typename T>
class SingleList 
{
    SingleNode<T> *head, *tail;
    int length;
public:
    SingleList() : head(nullptr), tail(nullptr) 
    {
        length = 0;
    }
    ~SingleList(); // tu trzeba wyczyscic wezly
    SingleList(const SingleList& other)
    {
        head = tail = nullptr;
        SingleNode<T> *node = other.head;
        
        while(node)
        {
            push_back(node->value);
            node = node -> next;
        }
    } // copy constructor

    // usage:   SingleList<int> list2(list1);
    SingleList(SingleList&& other); // move constructor NIEOBOWIAZKOWE
    // usage:   SingleList<int> list2(std::move(list1));
    SingleList& operator=(const SingleList& other)
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
                length = other.length;
            }
        }
        return *this;
    } // copy assignment operator, return *this
    // usage:   list2 = list1;
    SingleList& operator=(SingleList&& other);  // move assignment operator, return *this
    // usage:   list2 = std::move(list1); NIEOBOWIAZKOWE
    bool empty() const { return head == nullptr; }

    int size() const { return length; } // O(n) bo trzeba policzyc

    void push_front(const T& item); // O(1), L.push_front(item)

    void push_front(T&& item)
    {
        if (!empty())   
        {
            head = new SingleNode<T>(std::move(item), head);
        }

        else 
        {
            head = tail = new SingleNode<T>(std::move(item));
        }
        length++; 
    } // O(1), L.push_front(std::move(item)) NIEOBOWIAZKOWE
    void push_back(const T& item); // O(1), L.push_back(item)
    void push_back(T&& item)
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
        length++;        
    } // O(1), L.push_back(std::move(item)) NIEOBOWIAZKOWE
    T& front() const { return head -> value; } // zwraca poczatek, nie usuwa
    T& back() const { return tail -> value; } // zwraca koniec, nie usuwa
    void pop_front(); // usuwa poczatek O(1)
    void pop_back(); // usuwa koniec O(n)
    void clear()
    {
        while(!empty())
        pop_back();
    } // czyszczenie listy z elementow O(n)
    void display(); // O(n)
    void reverse()
    {
        SingleNode <T> *temporary = NULL;
        SingleNode <T> *previous = NULL;
        SingleNode <T> *current = head;
        while(current != NULL)
        {
            temporary = current -> next;
            current -> next = previous;
            previous = current;
            current = temporary;
        }
        head = previous;
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
SingleList<T>::~SingleList() 
{
    // I sposob.
    for (SingleNode<T> *node; !empty();) 
    {
        node = head -> next; // zapamietujemy
        delete head;
        head = node; // kopiowanie wskaznika
    }
    // II sposob.
    // while (!empty()) { pop_front(); }
}

template <typename T>
void SingleList<T>::push_front(const T& item) 
{
    if (!empty()) 
    {
        head = new SingleNode<T>(item, head);
    } 

    else 
    {
        head = tail = new SingleNode<T>(item);
    }
    length++;
}

template <typename T>
void SingleList<T>::push_back(const T& item) 
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
    length++;
}

template <typename T>
void SingleList<T>::display() 
{
    SingleNode<T> *node = head;
    while (node != nullptr)
    {
        std::cout << node -> value << " ";
        node = node -> next;
    }
    std::cout << std::endl;
}

template <typename T>
void SingleList<T>::pop_front() 
{
    assert(!empty());
    SingleNode<T> *node = head; // zapamietujemy
    if (head == tail) 
    {         
        head = tail = nullptr;  // jeden wezel na liscie
    } 
    else 
    { 
        head = head->next;      // wiecej niz jeden wezel na liscie
    }
    length--;
    delete node;
}

template <typename T>
void SingleList<T>::pop_back() 
{
    assert(!empty());
    SingleNode<T> *node = tail; // zapamietujemy
    if (head == tail)           // jeden wezel na liscie
    {
        head = tail = nullptr;
    } 
    else // wiecej niz jeden wezel na liscie
    {                                    
       
        SingleNode<T> *before = head;     // Szukamy poprzednika ogona.
        while (before -> next != tail) 
        {
            before = before->next;
        }
        tail = before;
        tail -> next = nullptr;
    }
    length--;
    delete node;
}

#endif