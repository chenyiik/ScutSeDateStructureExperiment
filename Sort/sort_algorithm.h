//
// Created by baqkqpfhv on 2018/10/25.
//

#ifndef DSLAB3_SORT_ALGORITHM_H
#define DSLAB3_SORT_ALGORITHM_H

template <typename T>
bool _cmp_(const T &a, const T &b) { return a < b; }

template <typename T, typename F = bool (*)(const T &, const T &)>
void insert_sort(T *be, T *en, F cmp = &_cmp_);
template <typename T, typename F = bool (*)(const T &, const T &)>
void bubble_sort(T *be, T *en, F cmp = &_cmp_);
template <typename T, typename F = bool (*)(const T &, const T &)>
void select_sort(T *be, T *en, F cmp = &_cmp_);
template <typename T, typename F = bool (*)(const T &, const T &)>
void quick_sort(T *be, T *en, F cmp = &_cmp_);
template <typename T, typename F = bool (*)(const T &, const T &)>
void merge_sort(T *be, T *en, F cmp = &_cmp_);

template <typename T, typename F>
void _merge_sort_(T *br, T *er, T *bs, T *es, F cmp);
template <typename T>
void _swap_(T *a, T *b) { T t = *a; *a = *b; *b = t; }


template <typename T, typename F>
void insert_sort(T *be, T *en, F cmp)
{
    int *_next_ = new int[en - be + 1], *next = _next_ + 1;
    next[-1] = 0, next[0] = -1;
    for (T *p = be + 1; p < en; p++)
    {
        int i = -1;
        while (next[i] != -1 && !cmp(*p, be[next[i]]))
            i = next[i];
        next[p - be] = next[i];
        next[i] = p - be;
    }
    T *a = new T[en - be], *p = a;
    for (int i = next[-1]; i != -1; i = next[i])
        *(p++) = be[i];
    p = a;
    for (T *q = be; q != en; q++)
        *q = *(p++);
    delete[] _next_;
    delete[] a;
}

template <typename T, typename F>
void bubble_sort(T *be, T *en, F cmp)
{
    for (T *p = en - 1; p > be; p--)
        for (T *q = be; q != p; q++)
            if (!cmp(*q, *(q + 1)))
                _swap_(q, q + 1);
}

template <typename T, typename F>
void select_sort(T *be, T *en, F cmp)
{
    for (T *p = be; p < en - 1; p++)
    {
        T *t = p;
        for (T *q = p + 1; q < en; q++)
            if (!cmp(*t, *q))
                t = q;
        _swap_(p, t);
    }
}

template <typename T, typename F>
void quick_sort(T *be, T *en, F cmp)
{
    if (be + 1 >= en)
        return;
    T &mid_value = *be, *left = be + 1, *right = en - 1;
    while (left <= right)
    {
        while (!cmp(mid_value, *left))
            left++;
        while (cmp(mid_value, *right))
            right--;
        if (left < right)
            _swap_(left, right);
    }
    _swap_(be, right);
    quick_sort(be, right, cmp);
    quick_sort(left, en, cmp);
}

template <typename T, typename F>
void merge_sort(T *be, T *en, F cmp)
{
    T *t = new T[en - be];
    for (T *p = be, *q = t; p < en; p++, q++)
        *q = *p;
    _merge_sort_(be, en, t, t + (en - be), cmp);
    delete[] t;
}

template <typename T, typename F>
void _merge_sort_(T *br, T *er, T *bs, T *es, F cmp)
{
    if (es - bs == 1)
        return;
    T *mis = bs + (es - bs) / 2, *mir = br + (er - br) / 2;
    _merge_sort_(bs, mis, br, mir, cmp);
    _merge_sort_(mis, es, mir, er, cmp);
    for (T *r = br, *p = bs, *q = mis; r < er; r++)
        *r = q == es || (p < mis && cmp(*p, *q)) ? *(p++) : *(q++);
}

#endif //DSLAB3_SORT_ALGORITHM_H
