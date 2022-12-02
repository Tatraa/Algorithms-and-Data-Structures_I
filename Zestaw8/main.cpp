#include <iostream>
#include "queue.h"

void test1()
{
    Queue <int> L;
    L.push(8);
    L.push(44);
    L.push(14);
    L.push(52);
    std::cout << "Otrzymane: ";
    L.display();
    std::cout << "Oczekiwane: 8 44 14 52" << std::endl;
    std::cout << std::endl;
}

void test2()
{
    Queue <int> L;
    int popTest;
    L.push(42);
    L.push(65);
    L.push(7);
    L.push(23);
    popTest = L.pop();
    std::cout << "Otrzymane: " << popTest << std::endl;
    std::cout << "Oczekiwane: 42" << std::endl;
    std::cout << std::endl;
}

void test3()
{
    Queue <int> L;
    L.push(2);
    L.push(0);
    Queue <int> M(L);
    M.push(2);
    M.push(3);
    std::cout << "Otrzymane: " << std::endl;
    L.display();
    M.display();
    std::cout << "Oczekiwane: " << std::endl;
    std::cout << "2 0" << std::endl;
    std::cout << "2 0 2 3" << std::endl;
    std::cout << std::endl;
}

void test4()
{
    Queue <std::string> L;
    L.push("error");
    L.clear();
    L.push("litwo");
    L.push("ojczyzno");
    L.push("moja");
    std::cout <<"Otrzymane: " << L.front() << " " << L.back() << std::endl;
    std::cout <<"Oczekiwane: litwo moja" << std::endl;
    std::cout << std::endl;
}

int main()
{
    std::cout << std::endl;
    test1();
    test2();
    test3();
    test4();
    return 0;
}