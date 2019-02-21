//
// Created by baqkqpfhv on 2018/10/8.
//

#ifndef DSLAB1_LLIST_H
#define DSLAB1_LLIST_H

#include "List.h"

template <typename T>
struct Node { T data; Node *pre, *next; };

template <typename T>
struct LIerator
{
    Node<T> *p;

    LIerator(Node<T> *ptr) : p(ptr) {}
    T &operator*() { return p->data; }
    T *operator->() { return &(operator*()); }
    bool operator==(const LIerator &rhs) const { return p == rhs.p; }
    bool operator!=(const LIerator &rhs) const { return p != rhs.p; }
    LIerator &operator++() { return p = p->next, *this; }
    LIerator &operator--() { return p = p->pre, *this; }
};

template <typename T>
class LList : public List<T, LIerator<T>>
{
private:
    Node<T> *head, *tail;
public:
    typedef LIerator<T> iterator;

    LList() : List<T, iterator>(), head(new Node<T>()), tail(new Node<T>()) { head->next = tail; tail->pre = head; }
    LList(const LList &rhs) : LList() { *this = rhs; }
    LList &operator=(const LList &rhs);
    virtual ~LList() { clear(); delete head; delete tail; }

    virtual iterator begin() const { return iterator(head->next); }
    virtual iterator end() const { return iterator(tail); }
    virtual iterator find(const T &rhs) const;
    virtual iterator insert(iterator pos, const T &rhs);
    virtual iterator erase(iterator pos);
    virtual void clear() { while (begin() != end()) erase(begin()); }

    LList add_by_bit(const LList &b) const;
    void erase_back_n(int n);
};


template <typename T>
LList<T> &LList<T>::operator=(const LList &rhs)
{
    if (this == &rhs)
        return *this;
    clear();
    for (iterator it = rhs.begin(); it != rhs.end(); ++it)
        insert(end(), *it);
    return *this;
}

template <typename T>
typename LList<T>::iterator LList<T>::find(const T &rhs) const
{
    for (iterator it = begin(); it != end(); ++it)
    {
        if (*it == rhs)
            return it;
    }
    return end();
}

template <typename T>
typename LList<T>::iterator LList<T>::insert(LList<T>::iterator pos, const T &rhs)
{
    Node<T> *pnode(new Node<T>({T(rhs), pos.p->pre, pos.p->pre->next}));
    pnode->pre->next = pnode->next->pre = pnode;
    return iterator(pnode);
}

template <typename T>
typename LList<T>::iterator LList<T>::erase(LList<T>::iterator pos)
{
    pos.p->next->pre = pos.p->pre;
    iterator it(pos.p->pre->next = pos.p->next);
    delete pos.p;
    return it;
}

template <typename T>
LList<T> LList<T>::add_by_bit(const LList<T> &b) const
{
    LList<T> ans;
    const LList<T> *pa = this, *pb = &b;
    iterator ita = pa->begin(), itb = pb->begin();
    T sum(0);
    while (ita != pa->end() || itb != pb->end())
    {
        if (ita != pa->end())
        {
            sum += *ita;
            ++ita;
        }
        if (itb != pb->end())
        {
            sum += *itb;
            ++itb;
        }
        ans.insert(ans.end(), sum % 10);
        sum /= 10;
    }
    if (sum > 0)
        ans.insert(ans.end(), sum);
    return ans;
}

template <typename T>
void LList<T>::erase_back_n(int n)
{
    iterator it1 = begin(), it2 = begin();
    while (n--)
        ++it1;
    while (it1 != end())
    {
        ++it1;
        ++it2;
    }
    erase(it2);
}

#endif //DSLAB1_LLIST_H
