//
// Created by baqkqpfhv on 2018/10/26.
//

#ifndef DSLAB3_PROB_SOLVE_H
#define DSLAB3_PROB_SOLVE_H

#include <iostream>

void problem_11(int *be, int *en);
//void problem_12(int *be, int *en);
//void probelm_21(int *be, int *en);
void problem_22(int *be, int *en);
//void problem_c1(int *be, int *en);
void problem_c2(int *be, int *en);

int prob_11_func(int *be, int *en);
int prob_22_func(int *br, int *er, int *bs, int *es);
void prob_c2_func(int *br, int *er, int *bs, int *es);
void _swap_(int *a, int *b) { int t = *a; *a = *b; *b = t; }

void problem_11(int *be, int *en) { std::cout << prob_11_func(be, en) << std::endl; }

void problem_22(int *be, int *en)
{
    int *t = new int[en - be];
    for (int *p = be, *q = t; p < en; p++, q++)
        *q = *p;
    std::cout << prob_22_func(be, en, t, t + (en - be)) << std::endl;
    delete[] t;
}

void problem_c2(int *be, int *en)
{
    int n = en - be;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    prob_c2_func(be, en, a, a + n);
    for (int *p = be; p < en; p++)
        std::cout << *p << ' ';
    std::cout << std::endl;
    for (int i = 0; i < n; i++)
        std::cout << a[i] << ' ';
    std::cout << std::endl;
}

int prob_11_func(int *be, int *en)
{
    if (be + 1 == en)
        return *be;
    int n = en - be, half = n / 2, tot = 0;
    for (int *p = be; p <= en; p++)
        if (*p == *be)
            tot++;
    if (tot > half)
        return *be;
    int *mid = be, *left = be + 1, *right = en - 1;
    while (left <= right)
    {
        while (*mid >= *left)
            left++;
        while (*mid < *right)
            right--;
        if (left < right)
            _swap_(left, right);
    }
    _swap_(be, right);
    int ln = be < right ? right - be : 0, rn = left < en ? en - left : 0;
    return ln > rn ? prob_11_func(be, right) : prob_11_func(left, en);
}

int prob_22_func(int *br, int *er, int *bs, int *es)
{
    if (es - bs == 1)
        return 0;
    int *mis = bs + (es - bs) / 2, *mir = br + (er - br) / 2;
    int ans = 0;
    ans += prob_22_func(bs, mis, br, mir);
    ans += prob_22_func(mis, es, mir, er);
    for (int *r = br, *p = bs, *q = mis; r < er; r++)
    {
        if (q == es || (p < mis && (*p <= *q)))
        {
            *r = *(p++);
            ans += q - mis;
        }
        else
            *r = *(q++);
    }
    return ans;
}

void prob_c2_func(int *br, int *er, int *bs, int *es)
{
    if (bs + 1 >= es)
        return;
    int *mid = bs, *lef_r = br + 1, *rig_r = er - 1;
    int *p = br;
    while (*p != *mid)
        p++;
    _swap_(br, p);
    while (lef_r <= rig_r)
    {
        while (*mid > *lef_r)
            lef_r++;
        while (*mid < *rig_r)
            rig_r--;
        if (lef_r < rig_r)
            _swap_(lef_r, rig_r);
    }
    mid = br;
    int *lef_s = bs + 1, *rig_s = es - 1;
    while (lef_s <= rig_s)
    {
        while (*mid > *lef_s)
            lef_s++;
        while (*mid < *rig_s)
            rig_s--;
        if (lef_s < rig_s)
            _swap_(lef_s, rig_s);
    }
    _swap_(br, rig_r);
    _swap_(bs, rig_s);
    prob_c2_func(br, rig_r, bs, rig_s);
    prob_c2_func(lef_r, er, lef_s, es);
}

#endif //DSLAB3_PROB_SOLVE_H
