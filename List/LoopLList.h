//
// Created by baqkqpfhv on 2018/10/13.
//

#ifndef DSLAB1_LOOPLLIST_H
#define DSLAB1_LOOPLLIST_H

#include "LList.h"

template <typename T>
class LoopLList : public LList<T>
{
public:
    typedef typename LList<T>::iterator iterator;
    LoopLList() : LList<T>() {}
    LoopLList(const LoopLList &rhs) : LList<T>(rhs) {}
    LoopLList &operator=(const LoopLList &rhs) { if (this != &rhs) LList<T>::operator=(rhs); return *this; }
    virtual ~LoopLList();

    LoopLList(const LList<T> &rhs) : LList<T>(rhs) {}
    LoopLList &operator=(const LList<T> &rhs) { LList<T>::operator=(rhs); return *this; }

    void link(iterator pos);
    iterator find_loop() const;
};

template <typename T>
LoopLList<T>::~LoopLList()
{
    iterator it = LList<T>::end();
    --it;
    it.p->next = LList<T>::end().p;
}

template <typename T>
void LoopLList<T>::link(LoopLList<T>::iterator pos)
{
    iterator it = LList<T>::end();
    --it;
    it.p->next = pos.p;
}

template <typename T>
typename LoopLList<T>::iterator LoopLList<T>::find_loop() const
{
    iterator it1 = LList<T>::begin(), it2 = LList<T>::begin();
    do
    {
        if (it1 != LList<T>::end())
            ++it1;
        if (it2 != LList<T>::end())
            ++it2;
        if (it2 != LList<T>::end())
            ++it2;
    } while (it1 != LList<T>::end() && it2 != LList<T>::end() && it1 != it2);
    if (it2 != LList<T>::end())
    {
        iterator it0 = it1;
        for (it2 = LList<T>::begin(); it2 != it1; ++it2)
        {
            for (++it1; it1 != it0 && it2 != it1; ++it1)
                ;
            if (it2 == it1)
                break;
        }
    }
    return it2;
}

#endif //DSLAB1_LOOPLLIST_H

