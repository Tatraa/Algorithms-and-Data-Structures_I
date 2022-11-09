// arraylist.h

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>     // deklaracje strumieni cout, cin, cerr
#include <cassert>    // assert()

template <typename T>
class ArrayList {
    T* tab;
    int msize; // najwieksza mozliwa liczba elementow
    int last; // pierwsza wolna pozycja
public:
    ArrayList(int s=10) : msize(s), last(0) {
        assert( s > 0 );
        tab = new T[s];
        assert( tab != nullptr );
    } // default constructor
    ~ArrayList() { delete [] tab; }
    ArrayList(const ArrayList& other) // copy constructor
    {
        msize = other.msize;
        last = other.last;
        tab = nullptr;
        if(msize > 0)
        {
            tab = new T[msize];
            for(int i = 0; i < last; i++)
            {
                tab[i] = other.tab[i];
            }
        }
    }
    // usage:   ArrayList<int> list2(list1);
    ArrayList(ArrayList&& other); // move constructor NIEOBOWIAZKOWE
    // usage:   ArrayList<int> list2(std::move(list1));
    ArrayList& operator=(const ArrayList& other) // copy assignment operator, return *this
    {
        if(&other == this)
        {
            return *this;
        }else{
            msize = other.msize;
            last = other.last;
            delete[] tab;
            tab = nullptr;
            if(msize > 0)
            {
                tab = new T[msize];
                for(int i = 0; i < last; i++)
                {
                    tab[i] = other.tab[i];
                }
            }
            return *this;
        }
    }
    // usage:   list2 = list1; NIEOBOWIAZKOWE
    ArrayList& operator=(ArrayList&& other); // move assignment operator, return *this
    // usage:   list2 = std::move(list1);
    bool empty() const { return last == 0; } // checks if the container has no elements
    bool full() const { return last == msize; } // checks if the container is full
    int size() const { return last; } // liczba elementow na liscie
    int max_size() const { return msize; } // najwieksza mozliwa liczba elementow
    void push_front(const T& item) // dodanie na poczatek
    {
        if(full())
        {
            std::cout << "Lista jest pelna!\n";
        }else{
            for(int i = last; i > 0; i--)
            {
                tab[i] = std::move(tab[i - 1]);
            }
            tab[0] = std::move(item);
            std::cout << " " << tab;
            last++;
        }
    }
    void push_front(T&& item) // dodanie na poczatek NIEOBOWIAZKOWE
    {
        if(full())
        {
            std::cout << "Lista jest pelna!\n";
        }else{
            for(int i = last; i > 0; i--)
            {
                tab[i] = std::move(tab[i - 1]);
            }
            tab[0] = std::move(item);
            last++;
        }
    }
    void push_back(const T& item) // dodanie na koniec
    {
        if(full())
        {
            std::cout << "Lista jest pelna!\n";
        }else{
            tab[last] = std::move(item);
            last++;
        }
    }
    void push_back(T&& item) // dodanie na koniec NIEOBOWIAZKOWE
    {
        if(full())
        {
            std::cout << "Lista jest pelna!\n";
        }else{
            tab[last] = std::move(item);
            last++;
        }
    }
    T& front() // zwraca poczatek, nie usuwa, error dla pustej listy
    {
        if(last == 0)
        {
            std::cout << "Lista jest pusta!\n";
        }
        return tab[0];
    }
    T& back() // zwraca koniec, nie usuwa, error dla pustej listy
    {
        if(last == 0)
        {
            std::cout << "Lista jest pusta!\n";
        }
        return tab[last - 1];
    }
    void pop_front() // usuwa poczatek, error dla pustej listy
    {
        if(empty())
        {
            std::cout << "Lista jest pusta!\n";
        }else{
            for(int i = 0; i < size(); i++)
            {
                tab[i] = tab[i + 1];
            }
            last--;
        }
    }
    void pop_back() // usuwa koniec, error dla pustej listy
    {
        if(empty())
        {
            std::cout << "Lista jest pusta!\n";
        }else{
            last--;
        }
    }
    void clear() // czyszczenie listy z elementow
    {
        for(int i = 0; i < last; i++)
        {
            tab[i] = 0;
        }
        last = 0;
    }
    void display() // lepiej zdefiniowac operator<<
    {
        for(int i = 0; i < size(); i++)
        {
            std::cout << tab[i] << " ";
        }
        std::cout<<"\n";
    }
    void reverse() // odwracanie kolejnosci
    {
        for(int i = 0; i < size()/2; i++)
        {
            T temp = tab[i];
            tab[i] = tab[last - i - 1];
            tab[last - i - 1] = temp;
        }
    }
    void sort() // sortowanie listy
    {
        int index = 0;
        for(int i = 0; i < size(); i++)
        {
            index = 0;
            for(int j = 0; j < size() - i; j++)
            {
                if(tab[j] > tab[index])
                {
                    index = j;
                }
            }
            T temp = tab[last - i - 1];
            tab[last - i - 1] = tab[index];
            tab[index] = temp;
        }
    }
    void merge(ArrayList& other) //  merges two sorted lists into one
    {
        if(size() + other.size() - 2 > msize)
        {
            std::cout<<"Brak miejsca na liscie!\n";
        }else{
            int a = 0;
            for(int i = 0; i < last; i++)
            {
                if(a == other.last)
                {
                    break;
                }else{
                    if(other.tab[a] < tab[i])
                    {
                        insert(i,other.tab[a]);
                        a++;
                    }
                }
            }
        }
    }
    // Operacje z indeksami. NIEOBOWIAZKOWE
    // https://en.cppreference.com/w/cpp/language/operators
    // Array subscript operator
    T& operator[](int pos) // podstawienie L[pos]=item
    {
        if(pos >= last)
        {
            std::cout << "Index poza tablica!\n";
        }
        return tab[pos];
    }
    const T& operator[](int pos) const // odczyt L[pos]
    {
        if(pos >= last)
        {
            std::cout << "Index poza tablica!\n";
        }
        return tab[pos];
    }
    int erase(int pos) // usuniecie elementu na pozycji pos
    {
        if(size() == 0)
        {
            return -1;
        }else{
            for(int i = pos; i < last; i++)
            {
                tab[i] = tab[i+1];
            }
            last--;
            return pos;
        }
    }
    int index(const T& item) // jaki index na liscie (-1 gdy nie ma)
    {
        for(int i = 0; i < size(); i++)
        {
            if(tab[i] == item)
            {
                return i;
            }
        }
        return -1;
    }
    int insert(int pos, const T& item) // inserts item before pos
    {
        if(size() == msize)
        {
            std::cout << "Lista jest pelna!\n";
            return -1;
        }
        else if(pos == 0)
        {
            push_front(item);
            return 0;
        }
        else if(pos == size())
        {
            push_back(item);
            return last - 1;
        }
        else
        {
            for(int i = size(); i > pos; i--)
            {
                tab[i] = std::move(tab[i - 1]);
            }
            tab[pos] = std::move(item);
            last++;
            return pos - 1;
        }
    }
    int insert(int pos, T&& item) // inserts item before pos
    {
        if(size() == msize)
        {
            std::cout << "Lista jest pelna!\n";
            return -1;
        }
        else if(pos == 0)
        {
            push_front(item);
            return 0;
        }
        else if(pos == size())
        {
            push_back(item);
            return last - 1;
        }
        else
        {
            for(int i = size(); i > pos; i--)
            {
                tab[i] = std::move(tab[i - 1]);
            }
            tab[pos] = std::move(item);
            last++;
            return pos;
        }
    }
    // Jezeli pos=0, to wstawiamy na poczatek.
    // Jezeli pos=size(), to wstawiamy na koniec.
    friend std::ostream& operator<<(std::ostream& os, const ArrayList& L) {
        for (int i=0; i < L.last; ++i) { // odwolanie L.last
            os << L.tab[i] << " ";   // odwolanie L.tab
        }
        return os;
    } // usage:   std::cout << L << std::endl;
};

#endif

// EOF
