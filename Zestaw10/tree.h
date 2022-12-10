#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <queue>

// Szablon dla węzła drzewa binarnego i drzewa BST.
template <typename T>
struct BSTNode
{
// the default access mode and default inheritance mode are public
    T value;
    BSTNode *left, *right;
    //BSTNode *parent;   // używane w pewnych zastosowaniach
    // kostruktor domyślny
    BSTNode() : value(T()), left(nullptr), right(nullptr) {}
    BSTNode(const T& item, BSTNode *le=nullptr, BSTNode *ri=nullptr) :
            value(item), left(le), right(ri) {} // konstruktor
    ~BSTNode() {} // destruktor
};

// Szablon dla przypadkowego drzewa binarnego.
template <typename T>
class RandomBinaryTree
{
public:
    BSTNode<T> *root;
    RandomBinaryTree() : root(nullptr) {} // konstruktor domyślny
    ~RandomBinaryTree() { clear(); } // trzeba wyczyścić
    bool empty() const { return root == nullptr; }
    T& top() { assert(root != nullptr); return root -> value; } // podgląd korzenia
    void insert(const T& item) { root = insert(root, item); }
    //void remove(const T& item); // na razie nie usuwamy elementów
    // Szukając element dostajemy wskaźnik do elementu lub nullptr.
    T* search(const T& item) const
    {
        auto ptr = search(root, item);
        return ((ptr == nullptr) ? nullptr : &(ptr -> value));
    }
    void preorder() { preorder(root); }
    void inorder() { inorder(root); }
    void postorder() { postorder(root); }
    void iter_preorder();
    void iter_inorder(); // trudne
    void iter_postorder(); // trudne
    void bfs(); // przejście poziomami (wszerz)
    void clear() { clear(root); root = nullptr; }
    void display() { display(root, 0); }
    int calc_leafs_iter(BSTNode <T> *node)
    {
        if(node == nullptr)
            return 0;
        std::queue <BSTNode <T>*> q;
        int count = 0;
        q.push(node);
        while(!q.empty())
        {
            BSTNode <T> *temp = q.front();
            q.pop();
            if(temp -> left != nullptr)
                q.push(temp -> left);
            if(temp -> right != nullptr)
                q.push(temp -> right);
            if(temp -> left == nullptr && temp -> right == nullptr)
                count++;
        }
        return count;
    }
    int calc_leafs_recur(BSTNode <T> *node)
    {
        if(node == nullptr)
            return 0;
        else if(node -> left == nullptr && node -> right==nullptr)
            return 1;
        else
        {
            int left = calc_leafs_recur(node -> left);
            int right = calc_leafs_recur(node -> right);
            return left + right;
        }
    }
    T helper() { return root -> left -> value; }

    // Metody bezpośrednio odwołujące się do node.
    // Mogą działać na poddrzewie.
    void clear(BSTNode<T> *node) { }
    BSTNode<T> * insert(BSTNode<T> *node, const T& item); // zwraca nowy korzeń
    BSTNode<T> * search(BSTNode<T> *node, const T& item) const;
    void preorder(BSTNode<T> *node);
    void inorder(BSTNode<T> *node);
    void postorder(BSTNode<T> *node);
    void display(BSTNode<T> *node, int level);
    virtual void visit(BSTNode<T> *node) {
        assert(node != nullptr);
        std::cout << "visiting " << node -> value << std::endl;
    }
};

// Wyświetlanie obróconego (counterclockwise) drzewa binarnego.
template <typename T>
void RandomBinaryTree<T>::display(BSTNode<T> *node, int level)
{
    if (node == nullptr) return;
    display(node -> right, level + 1);
    std::cout << std::string(3 * level, ' ') << node -> value << std::endl;
    display(node -> left, level + 1);
}

#include <cstdlib>   // std::rand(), RAND_MAX, std::srand()

template <typename T>
BSTNode<T> * RandomBinaryTree<T>::insert(BSTNode<T> *node, const T& item)
{
    if (node == nullptr)
    {
        return new BSTNode<T>(item);
    }
    if (std::rand() % 2)
    { // można lepiej
        node -> left = insert(node -> left, item);
    } else {
        node -> right = insert(node -> right, item);
    }
    return node; // zwraca nowy korzen
}

template <typename T>
BSTNode<T> * RandomBinaryTree<T>::search(BSTNode<T> *node, const T& item) const
{
    if (node == nullptr || node -> value == item)
    {
        return node;
    }
    T* ptr;
    ptr = search(node -> left, item);
    if (ptr == nullptr)
    {
        ptr = search(node -> right, item);
    }
    return ptr;
}

#endif