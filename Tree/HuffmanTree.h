//
// Created by baqkqpfhv on 2018/10/19.
//

#ifndef DSLAB2_HUFFMANTREE_H
#define DSLAB2_HUFFMANTREE_H

#include "BinaryTree.h"

#include <iostream>

template <int N>
class HuffmanTree : public BinaryTree<N>
{
private:
    static const int bit31 = 0x7fffffff;
protected:
    void heap_insert(long long a[], int n, long long val);
    long long heap_pop(long long a[], int n);
    void _code_(int i, char *s, int n) const;
public:
    HuffmanTree() : BinaryTree<N>() {}
    HuffmanTree(const HuffmanTree &rhs) : HuffmanTree() { *this = rhs; }
    HuffmanTree &operator=(const HuffmanTree &rhs);
    virtual ~HuffmanTree() = default;

    virtual void build(int n, int root = 0);
    void code() const;
};

template <int N>
void HuffmanTree<N>::heap_insert(long long a[], int n, long long val)
{
    a[n] = val;
    for (int i = n; i != 0; )
    {
        int j = (i - 1) / 2;
        if ((a[i] & bit31) < (a[j] & bit31))
            a[i] ^= a[j] ^= a[i] ^= a[j];
        else
            break;
        i = j;
    }
}

template <int N>
long long HuffmanTree<N>::heap_pop(long long int a[], int n)
{
    long long tt = a[0];
    if (n == 1)
        return tt;
    a[0] = a[n - 1];
    for (int i = 0; ; )
    {
        int chd[2] = {i * 2 + 1, i * 2 + 2}, j = i;
        for (int ii = 0; ii < 2; ii++)
        {
            int k = chd[ii];
            if (k < n - 1 && ((a[j] & bit31)) > (a[k] & bit31))
                j = k;
        }
        if (j == i)
            break;
        else
            a[i] ^= a[j] ^= a[i] ^= a[j];
        i = j;
    }
    return tt;
}

template <int N>
void HuffmanTree<N>::_code_(int i, char *s, int n) const
{
    int l = this->nodes(i).lef, r = this->nodes(i).rig;
    if (l == -1 || r == -1)
        std::cout << static_cast<char>(this->nodes(i).data) << ' ' << s << std::endl;
    else
    {
        s[n] = '0';
        _code_(l, s, n + 1);
        s[n] = '1';
        _code_(r, s, n + 1);
        s[n] = '\0';
    }
}

template <int N>
HuffmanTree<N> &HuffmanTree<N>::operator=(const HuffmanTree &rhs)
{
    if (this != &rhs)
        BinaryTree<N>::operator=(rhs);
    return *this;
}

template <int N>
void HuffmanTree<N>::build(int n, int root)
{
    this->clear();
    if (n == 0)
        return;
    long long *a = new long long[n];
    for (int i = 0; i < n; i++)
    {
        char ch[5];
        int tot = 0;
        std::cin >> ch >> tot;
        this->nodes(i) = {ch[0], -1, -1};
        heap_insert(a, i, (static_cast<long long>(i) << 32) | tot);
    }
    for (int i = n; i < n * 2 - 1; i++)
    {
        long long l = heap_pop(a, 2 * n - i), r = heap_pop(a, 2 * n - i - 1);
        this->nodes(i) = {-1, static_cast<int>((l >> 32) & bit31), static_cast<int>((r >> 32) & bit31)};
        heap_insert(a, 2 * n - i - 2, (static_cast<long long>(i) << 32) | ((l & bit31)+(r & bit31)));
    }
    this->root() = n * 2 - 2;
    this->size() = n * 2 - 1;
    delete[] a;
}

template <int N>
void HuffmanTree<N>::code() const
{
    if (this->size() == 0)
        return;
    if(this->size() == 1)
    {
        std::cout << char(this->nodes(0).data) << " 0" << std::endl;
        return;
    }
    char s[N + 5];
    memset(s, 0, sizeof(s));
    _code_(this->root(), s, 0);
}

#endif //DSLAB2_HUFFMANTREE_H
