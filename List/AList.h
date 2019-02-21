//
// Created by baqkqpfhv on 2018/10/8.
//

#ifndef DSLAB1_ALIST_H
#define DSLAB1_ALIST_H

#include "List.h"
#include <cstring>

template <typename T>
class AIerator
{
private:
    T *p;
public:
    AIerator(T *ptr) : p(ptr) {}
    T &operator*() { return *p; }
    T *operator->() { return &(operator*()); }
    bool operator==(const AIerator &rhs) const { return p == rhs.p; }
    bool operator!=(const AIerator &rhs) const { return p != rhs.p; }
    AIerator &operator++() { return ++p, *this; }
    AIerator &operator--() { return --p, *this; }
    AIerator operator+(int back) const { return AIerator(p + back); }
    AIerator operator-(int front) const { return AIerator(p - front); }
};

template <typename T, int N>
class AList : public List<T, AIerator<T>>
{
private:
    T *_arr;
public:
    typedef AIerator<T> iterator;

    AList() : List<T, iterator>(), _arr(new T[N]) {}
    AList(const AList &rhs) : AList() { *this = rhs; }
    AList &operator=(const AList &rhs);
    virtual ~AList() { delete[] _arr;}

    virtual iterator begin() const { return iterator(_arr); }
    virtual iterator end() const { return iterator(_arr + List<T, iterator>::size()); }
    virtual iterator find(const T &rhs) const;
    virtual iterator insert(iterator pos, const T &rhs);
    virtual iterator erase(iterator pos);
    virtual void clear() { List<T, iterator>::reset_size(0); }

    const T &operator[](int index) const { return _arr[index]; }
    T &operator[](int index) { return _arr[index]; }

    void sort();
    AList merge(const AList<T, N> &b) const;
};

template <typename T, int N>
AList<T, N> &AList<T, N>::operator=(const AList &rhs)
{
    if (this == &rhs)
        return *this;
    List<T, iterator>::reset_size(rhs.size());
    std::memcpy(_arr, rhs._arr, sizeof(T) * N);
    return *this;
}

template <typename T, int N>
typename AList<T, N>::iterator AList<T, N>::find(const T &rhs) const
{
    for (iterator it = begin(); it != end(); ++it)
    {
        if (*it == rhs)
            return it;
    }
    return end();
}

template <typename T, int N>
typename AList<T, N>::iterator AList<T, N>::insert(AList<T, N>::iterator pos, const T &rhs)
{
    for (iterator it = end(); it != pos; --it)
        *it = *(it - 1);
    *pos = rhs;
    List<T, iterator>::up_size();
    return pos;
}

template <typename T, int N>
typename AList<T, N>::iterator AList<T, N>::erase(iterator pos)
{
    for (iterator it = pos; it != end() - 1; ++it)
        *it = *(it + 1);
    List<T, iterator>::down_size();
    return pos;
}

template <typename T, int N>
void AList<T, N>::sort()
{
    for (int i = 0; i < List<T, iterator>::size() - 1; i++)
    {
        for (iterator it = begin(); it != end() - i - 1; ++it)
        {
            if (!(*it < *(it + 1)))
            {
                T t = *it;
                *it = *(it + 1);
                *(it + 1) = t;
            }
        }
    }
}

template <typename T, int N>
AList<T, N> AList<T, N>::merge(const AList<T, N> &b) const
{
    AList<T, N> ans;
    iterator ita = this->begin(), itb = b.begin();
    for (int i = 0; i < this->size() + b.size(); i++)
    {
        if (itb == b.end() || *ita < *itb)
        {
            ans.insert(ans.end(), *ita);
            ++ita;
        }
        else
        {
            ans.insert(ans.end(), *itb);
            ++itb;
        }
    }
    return ans;
}

#endif //DSLAB1_ALIST_H
