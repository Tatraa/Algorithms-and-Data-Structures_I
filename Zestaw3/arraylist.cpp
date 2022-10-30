#include <iostream>
#include "arraylist.h"

void test1()
{
    ArrayList <int> L;
    L.push_back(32);
    L.push_front(3);
    L.push_back(6);
    L.push_front(7);
    L.push_front(12);
    std::cout << "Wynik: " << std::endl << L << std::endl;
    std::cout << "Oczekiwano: " << std::endl << "12 7 3 32 6" << std::endl;
    std::cout << std::endl;
}

void test2()
{
    ArrayList <int> L(5);
    L.push_back(5);
    L.push_back(3);
    L.push_back(76);
    L.push_back(13);
    L.push_back(-5);
    L.push_back(23);
    L.sort();
    L.reverse();
    std::cout << "Wynik: " << std::endl << L << std::endl;
    std::cout << "Oczekiwano: " << std::endl << "76 13 5 3 -5" << std::endl;
    std::cout << std::endl;
}

void test3()
{
    ArrayList <std::string> L;
    L.push_back("string1");
    L.push_back("string2");
    L.push_front("string3");
    L.push_back("string4");
    L.push_front("string5");
    std::cout << "Wynik: " << std::endl << L << std::endl;
    std::cout << "Oczekiwano: " << std::endl << "string5 string3 string1 string2 string4" << std::endl;
    std::cout << std::endl;
}

void test4()
{
    ArrayList <char> L;
    L.push_back('x');
    L.push_front('x');
    L.clear();
    L.push_front('i');
    L.push_front('m');
    L.push_back('d');
    L.push_back('o');
    L.push_back('r');
    L.push_back('o');
    L.push_front('o');
    L.push_front('p');
    L.push_back('w');
    L.push_back('a');
    std::cout << "Wynik: " << std::endl << L << std::endl;
    std::cout << "Oczekiwano: " <<std::endl << "p o m i d o r o w a" << std::endl;
    std::cout << std::endl;
}

void test5()
{
    ArrayList <int> L;
    L.push_back(33);
    L.push_back(123);
    L.push_back(0);
    L.push_front(3453);
    L.insert(1,12);
    L.erase(2);
    std::cout << "Wynik: " << std::endl << L << std::endl;
    std::cout << "Oczekiwano: " <<std::endl << "3453 12 123 0" << std::endl;
    std::cout << std::endl;
}
int main()
{
    ArrayList <int> L(5);
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}