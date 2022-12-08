#include <iostream>
#include "prioqueue.h"

void test1()
{
    SingleList <int> L;
    std::cout << std::string(40, '=') << std::endl;
    std::cout << "TEST1" << std::endl;
    L.push(5,8);
    L.push(2,2);
    L.push(3,6);
    int x;
    x = L.pop();
    std::cout << x << ", " << L.top() << std::endl;
}

void test2()
{
    std::cout << std::string(40, '=') << std::endl;
    std::cout << "TEST2" << std::endl;
    SingleList <int> L;
    L.push(8,2);
    L.push(4,4);
    L.push(7,7);
    L.display();
}

void test3()
{
    std::cout << std::string(40, '=') << std::endl;
    std::cout << "TEST3" << std::endl;
    SingleList <int> L;
    L.push(9,5);
    L.clear();
    L.push(2,2);
    L.push(5,6);
    L.display();
}

int main()
{
    test1();
    test2();
    test3();
    std::cout << std::string(40, '=') << std::endl;
    return 0;
}
