#include <iostream>
#include <unistd.h>
#include "doublelist.h"

void test1()
{
    DoubleList <int> L;

    L.push_front(5);
    L.push_back(2);
    DoubleList <int> M(L);
    M.pop_front();
    M.push_back(7);
    M.push_back(8);
    M.push_front(3);
    std::cout<<"Wynik: "<<std::endl;
    M.display();
    std::cout<<"Oczekiwany:"<<std::endl<<"3 2 7 8"<<std::endl;
    std::cout << std::endl;
}

void test2()
{
    DoubleList <int> L;
    L.push_back(7);
    L.push_back(23);
    DoubleList <int> M;
    M = L;
    L.clear();
    L.push_back(54);
    M.push_back(21);
    std::cout<<"Wynik: "<<std::endl;
    L.display();
    M.display();
    std::cout<<"Oczekiwany:"<<std::endl<<"54" << std::endl << "7 23 21"<<std::endl;
    std::cout << std::endl;
}

void test3()
{
    DoubleList <int> L;
    L.push_back(5);
    L.push_back(2);
    L.push_front(8);
    L.push_back(1);
    L.pop_front();
    L.pop_back();
    L.pop_back();
    L.pop_front();
    std::cout<<"Wynik: "<<std::endl;
    std::cout<<L.size()<<std::endl;
    std::cout<<"Oczekiwany:"<<std::endl<<"0"<<std::endl;
    std::cout << std::endl;
}

void test4()
{
    DoubleList <int> L;
    L.push_front(5);
    L.push_back(32);
    L.push_front(2);
    L.push_back(87);
    L.push_back(31);
    std::cout<<"Wynik: "<<std::endl;
    L.display();
    std::cout<<"Oczekiwany:"<<std::endl<<"2 5 32 87 31"<<std::endl;
    std::cout << std::endl;
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    return 0;
}