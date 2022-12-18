#include <iostream>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include "tree.h"

int main()
{
    RandomBinaryTree<int> tree;
    //std::srand(time(NULL));
    int count = 10;
    for(int i = 0 ; i < count ; i++)
    {
        tree.insert(i);
    }

    std::cout << "Drzewo:\n\n";
    tree.display();

    std::cout << std::endl;
    std::cout << "Liscie wyliczone metoda rekurencyjna: \n";
    std::cout << tree.calc_leafs_recur(tree.root);

    std::cout << std::endl;
    std::cout << "Liscie wyliczone metoda iteracyjna: \n";
    std::cout << tree.calc_leafs_iter(tree.root);
    std::cout << std::endl;
    
    std::cout << std::endl;
    std::cout << "Wyczysczenie drzewa..." << std::endl;
    tree.clear();
    tree.display();
}
