#include <iostream>
#include "singlelist.h"

void test1()
{
    SingleList <int> L;
    L.push_front(5);
    L.push_front(2);
    SingleList <int> M(L);
    M.push_front(6);
    M.push_back(3);
    std::cout << "Wynik: " << std::endl;
    L.display();
    M.display();
    std::cout << "Oczekiwany:" << std::endl << "2 5" << std::endl << "6 2 5 3" << std::endl;
    std::cout << std::endl;
}

void test2()
{
    SingleList <int> L;
    L.push_back(3);
    L.push_front(4);
    L.push_back(5);
    L.push_front(3);
    L.push_back(32);
    L.push_back(22);
    L.push_back(35);
    L.push_back(87);
    L.push_front(4);
    L.pop_back();
    std::cout << "Wynik: " << std::endl;
    std::cout << L.size() << std::endl;
    std::cout << "Oczekiwany:" << std::endl << "8" << std::endl;
    std::cout << std::endl;
}

void test3()
{
    SingleList <int> L;
    SingleList <int> M;
    L.push_back(12);
    L.push_back(7);
    L.push_front(8);
    L.push_back(1223);
    L.push_back(43);
    L.push_front(766);
    M = L;
    std::cout << "Wynik: " << std::endl;
    M.display();
    std::cout << "Oczekiwany:" << std::endl << "8 12 7" << std::endl;
    std::cout << std::endl;
}



void test4()
{
    SingleList <std::string> L;
    L.push_front("test1");
    L.push_front("test2");
    L.clear();
    L.push_back("test3");
    L.push_back("test4");
    L.push_back("test5");
    L.push_front("test6");
    L.push_back("test7");
    std::cout << "Wynik: " << std::endl;
    std::cout << L.front() << " " << L.back() << std::endl;
    std::cout << "Oczekiwany:" << std::endl << "test6 test7" << std::endl;
    std::cout << std::endl;
}
void test5()
{
    SingleList <int> L;
    L.push_back(2);
    L.push_front(4);
    L.push_front(7);
    L.push_back(2);
    L.push_front(5);
    L.push_back(3);
    L.push_front(2);
    L.reverse();
    L.push_front(3);
    L.push_front(9);
    std::cout << "Wynik: " << std::endl;
    L.display();
    std::cout << "Oczekiwany:" << std::endl << "9 3 3 2 2 4 7 5 2" << std::endl;
    std::cout << std::endl;
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}