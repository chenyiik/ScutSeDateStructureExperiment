//
// Created by baqkqpfhv on 2018/10/18.
//

#ifndef DSLAB2_BINARYTREE_H
#define DSLAB2_BINARYTREE_H

#include <cstring>
#include <iostream>

struct Node { int data, lef, rig; };

template <int N>
class BinaryTree
{
private:
    int _root, _size;
    Node *_nodes;
protected:
    int &size() { return _size; }
    int &root() { return _root; }
    Node &nodes(int i) { return _nodes[i]; }

    int size() const { return _size; }
    int root() const { return _root; }
    const Node &nodes(int i) const { return _nodes[i]; }

    void _preorder_(int i) const;
    void _inorder_(int i) const;
    void _postorder_(int i) const;
    int _build_by_pre_in_(int a[], int b[], int n);
public:
    BinaryTree() : _root(-1), _size(0), _nodes(new Node[N]) {}
    BinaryTree(const BinaryTree &rhs) : BinaryTree() { *this = rhs; }
    BinaryTree &operator=(const BinaryTree &rhs);
    virtual ~BinaryTree() { delete[] _nodes; }

    void preorder() const { if (_root != -1) _preorder_(_root); }
    void inorder() const { if (_root != -1) _inorder_(_root); }
    void postorder() const { if (_root != -1) _postorder_(_root); }

    void clear() { *this = BinaryTree(); }

    virtual void build(int n, int root = 0);
    void build_by_preorder_inorder(int n);
};

template <int N>
void BinaryTree<N>::_preorder_(int i) const
{
    std::cout << _nodes[i].data << ' ';
    if (_nodes[i].lef != -1)
        _preorder_(_nodes[i].lef);
    if (_nodes[i].rig != -1)
        _preorder_(_nodes[i].rig);
}

template <int N>
void BinaryTree<N>::_inorder_(int i) const
{
    if (_nodes[i].lef != -1)
        _inorder_(_nodes[i].lef);
    std::cout << _nodes[i].data << ' ';
    if (_nodes[i].rig != -1)
        _inorder_(_nodes[i].rig);
}

template <int N>
void BinaryTree<N>::_postorder_(int i) const
{
    if (_nodes[i].lef != -1)
        _postorder_(_nodes[i].lef);
    if (_nodes[i].rig != -1)
        _postorder_(_nodes[i].rig);
    std::cout << _nodes[i].data << ' ';
}

template <int N>
int BinaryTree<N>::_build_by_pre_in_(int a[], int b[], int n)
{
    int i = _size++;
    _nodes[i].data = a[0];
    int j = 0;
    while (a[0] != b[j])
        j++;
    _nodes[i].lef = (j == 0 ? -1 : _build_by_pre_in_(a + 1, b, j));
    _nodes[i].rig = (n - 1 - j == 0 ? -1 : _build_by_pre_in_(a + 1 + j, b + j + 1, n - 1 - j));
    return i;
}

template <int N>
BinaryTree<N> &BinaryTree<N>::operator=(const BinaryTree &rhs)
{
    if (this == &rhs)
        return *this;
    _root = rhs._root;
    _size = rhs._size;
    std::memcpy(_nodes, rhs._nodes, sizeof(Node) * _size);
    return *this;
}

template <int N>
void BinaryTree<N>::build(int n, int root)
{
    clear();
    _root = root;
    for (int i = 0; i < n; i++)
    {
        int d = 0, l = 0, r = 0;
        std::cin >> d >> l >> r;
        _nodes[i] = {d, l, r};
    }
}
template <int N>
void BinaryTree<N>::build_by_preorder_inorder(int n)
{
    clear();
    int *a = new int[n], *b = new int[n];
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
        std::cin >> b[i];
    _root = _build_by_pre_in_(a, b, n);
    delete[] a;
    delete[] b;
}

#endif //DSLAB2_BINARYTREE_H
