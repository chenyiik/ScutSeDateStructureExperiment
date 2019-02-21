//
// Created by baqkqpfhv on 2018/10/19.
//

#ifndef DSLAB2_BINARYSEARCHTREE_H
#define DSLAB2_BINARYSEARCHTREE_H

#include "BinaryTree.h"

#include <iostream>

template <int N>
class BinarySearchTree : public BinaryTree<N>
{
public:
    BinarySearchTree() : BinaryTree<N>() {}
    BinarySearchTree(const BinarySearchTree &rhs) : BinaryTree<N>(rhs) {}
    BinarySearchTree &operator=(const BinarySearchTree &rhs);
    virtual ~BinarySearchTree() = default;

    bool find(int x) const;

    virtual void build(int n, int root = 0);
};

template <int N>
BinarySearchTree<N> &BinarySearchTree<N>::operator=(const BinarySearchTree<N> &rhs)
{
    if (this != &rhs)
        BinaryTree<N>::operator=(rhs);
    return *this;
}

template <int N>
bool BinarySearchTree<N>::find(int x) const
{
    for (int i = this->root(); i != -1; i = x < this->nodes(i).data ? this->nodes(i).lef : this->nodes(i).rig)
    {
        if (x == this->nodes(i).data)
            return true;
    }
    return false;
}

template <int N>
void BinarySearchTree<N>::build(int n, int root)
{
    this->clear();
    if (n == 0)
        return;
    this->size() = 0;
    int d = 0;
    std::cin >> d;
    this->nodes(this->root() = 0) = {d, -1, -1};
    for (int i = 1; i < n; i++)
    {
        std::cin >> d;
        for (int nod = this->root(); nod != i; )
        {
            int &chd = d < this->nodes(nod).data ? this->nodes(nod).lef : this->nodes(nod).rig;
            if (chd == -1)
                this->nodes(chd = i) = {d, -1, -1};
            nod = chd;
        }
    }
}

#endif //DSLAB2_BINARYSEARCHTREE_H
