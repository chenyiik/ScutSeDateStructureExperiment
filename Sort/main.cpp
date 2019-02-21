#include "sort_algorithm.h"
#include "prob_solve.h"
#include <iostream>

using namespace std;

int init(int *a)
{
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    return n;
}

void prob_a(int *be, int *en)
{
    //insert_sort(be, en);
    //bubble_sort(be, en);
    //select_sort(be, en);
    //merge_sort(be, en);
    quick_sort(be, en);
    for (int *p = be; p < en; p++)
        cout << *p << ' ';
    cout << endl;

}

void prob_bc(int *be, int *en)
{
    //problem_11(be, en);
    //problem_22(be, en);
    //problem_c2(be, en);
}

int main()
{
    static int a[1000];
    int n = init(a);
    prob_a(a, a + n);
    //prob_bc(a, a + n);
    return 0;
}