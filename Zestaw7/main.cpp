#include <iostream>
#include <vector>
#include <cassert>
#include <stdlib.h>

bool isnumber(std::string input)
{
    bool temp = false;
    for(char &t : input)
    {
        if(t == 46 && temp == false)
            temp = true;
        else if(t == 46 && temp == true)
            return false;
        else if(t < 48 || t > 57)
            return false;
    }
    return true;
}

void push(double stack[],int &count,double &x)
{
    stack[count] = x;
    count++;
}

double pop(double stack[],int &count)
{
    double x = stack[count-1];
    count--;
    stack[count] = 0;
    return x;
}

int onp(std::vector<std::string> input)
{
    double array[64];
    double a;
    double b;
    double c;
    for(int i = 0 ; i < 50 ; i++)
        array[i] = 0;
    int count = 0;
    for(unsigned int i = 0 ; i < input.size() ; i++)
    {
        if(isnumber(input[i]))
        {
            a = stod(input[i]);
            push(array,count,a);
        }
        else if(input[i]=="+")
        {
            a = pop(array,count);
            b = pop(array,count);
            c = a + b;
            push(array,count,c);
        }
        else if(input[i]=="-")
        {
            a = pop(array,count);
            b = pop(array,count);
            c = b - a;
            push(array,count,c);
        }
        else if(input[i]=="*")
        {
            a = pop(array,count);
            b = pop(array,count);
            c = a * b;
            push(array,count,c);
        }
        else if(input[i]=="/")
        {
            a = pop(array,count);
            b = pop(array,count);
            assert(a != 0);
            c = b / a;
            push(array,count,c);
        }
    }
    return array[count - 1];
}

int main()
{
    std::vector<std::string> input = {"4","4","/"};
    double result = onp(input);
    std::cout << "Poprawny wynik: 1" << std::endl;
    std::cout << "Wynik algorytmu ONP: " << result << std::endl;
    std::cout << std::endl;

    std::vector<std::string> input2 = {"5","7","+"};
    int result1 = onp(input2);
    std::cout << "Poprawny wynik: 12" << std::endl;
    std::cout << "Wynik algorytmu ONP: "<< result1 << std::endl;
    std::cout << std::endl;

    std::vector<std::string> input3 = {"9","8","*","7","6","-","*"};
    int result2 = onp(input3);
    std::cout <<"Poprawny wynik: 72" << std::endl;
    std::cout <<"Wynik algorytmu ONP: " << result2 << std::endl;
    std::cout << std::endl;

    std::vector<std::string> input4 = {"645","4","*","2","/"};
    int result3 = onp(input4);
    std::cout <<"Poprawny wynik: 1290" << std::endl;
    std::cout <<"Wynik algorytmu ONP: "<< result3 << std::endl;
    std::cout << std::endl;

    std::vector<std::string> input5 = {"17","3","*","3","5","*","-"};
    int result4 = onp(input5);
    std::cout << "Poprawny wynik: 36" << std::endl;
    std::cout << "Wynik algorytmu ONP: " << result4 << std::endl;
    std::cout << std::endl;
    return 0;
}
