#include "AList.h"
#include "LList.h"
#include "LoopLList.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void test_alist();
void test_llist();
void test_rerase();
void test_lllist();

int main() {
    test_alist();
    test_llist();
    test_rerase();
    test_lllist();
    return 0;
}

void test_alist()
{
    cout << "Test array list." << endl;
    AList<int, 1000> A0;

    cout << "1. Make a new list." << endl;
    cout << "Input the number of these number: ";
    int n = 0;
    cin >> n;
    cout << "Input n number: ";
    while (n--)
    {
        int x = 0;
        cin >> x;
        A0.insert(A0.end(), x);
    }
    cout << endl;

    cout << "2. Output the list." << endl;
    for (int i : A0)
        cout << i << ' ';
    cout << endl << endl;

    cout << "3. Find a element" << endl;
    while (true)
    {
        cout << "a.find    b.exit and next" << endl;
        cout << "Input 'a' or 'b': ";
        char c = '\0';
        cin >> c;
        if (c == 'a')
        {
            cout << "Input a number: ";
            int x = 0;
            cin >> x;
            if (A0.find(x) != A0.end())
                cout << "Find successfully." << endl;
            else
                cout << "Find failed." << endl;
        }
        else if (c == 'b')
            break;
        cout << endl;
    }
    cout << endl;

    cout << "4. Delete or insert element." << endl;
    while (true)
    {
        cout << "a. delete by value    b.delete by position" << endl;
        cout << "c. insert by value    d.insert by position" << endl;
        cout << "e. exit and next" << endl;
        cout << "Input a character to choose: ";
        char c = '\0';
        cin >> c;
        if (c == 'a')
        {
            cout << "Input existing value: ";
            int x = 0;
            cin >> x;
            int i = -1;
            while (++i < A0.size())
            {
                if (A0[i] == x)
                {
                    A0.erase(A0.begin() + i);
                    break;
                }
            }
        }
        else if (c == 'b')
        {
            cout << "Input position: " << endl;
            int x = 0;
            cin >> x;
            if (x < A0.size())
                A0.erase(A0.begin() + x);
        }
        else if (c == 'c')
        {
            cout << "Input existing value and inserting value: ";
            int x = 0, y = 0;
            cin >> x >> y;
            int i = -1;
            while (++i < A0.size() && A0[i] != x)
                ;
            A0.insert(A0.begin() + i, y);
        }
        else if (c == 'd')
        {
            cout << "Input position and inserting value: ";
            int x = 0, y = 0;
            cin >> x >> y;
            A0.insert(A0.begin() + x, y);
        }
        else if (c == 'e')
            break;
        cout << "Now the list is: ";
        for (int i : A0)
            cout << i << ' ';
        cout << endl << endl;
    }
    cout << endl;

    cout << "5. Make two array list and merge them." << endl;
    cout << "Input the number of first list: ";
    cin >> n;
    cout << "Input n numbers of first list: ";
    AList<int, 1000> A1;
    while (n--)
    {
        int x = 0;
        cin >> x;
        A1.insert(A1.end(), x);
    }
    cout << "Input the number of second list: ";
    cin >> n;
    cout << "Input n numbers of second list: ";
    AList<int, 1000> A2;
    while (n--)
    {
        int x = 0;
        cin >> x;
        A2.insert(A2.end(), x);
    }
    A1.sort();
    A2.sort();
    AList<int, 1000> A3(A1.merge(A2));
    cout << "The merged list is: ";
    for (int i : A3)
        cout << i << ' ';
    cout << endl << endl;
}

void test_llist()
{
    cout << "Test linked list." << endl;
    LList<int> L0;

    cout << "1. Make a new list." << endl;
    cout << "Input the number of these number: ";
    int n = 0;
    cin >> n;
    cout << "Input n number: ";
    while (n--)
    {
        int x = 0;
        cin >> x;
        L0.insert(L0.end(), x);
    }
    cout << "The list is: ";
    bool b = false;
    for (int i : L0)
    {
        if (b)
            cout << " -> ";
        cout << i;
        b = true;
    }
    cout << endl << endl;

    cout << "2. Add two list with bit." << endl;
    cout << "Input the number of first list: ";
    cin >> n;
    cout << "Input n numbers of first list: ";
    LList<int> L1;
    while (n--)
    {
        int x = 0;
        cin >> x;
        L1.insert(L1.end(), x);
    }
    cout << "Input the number of second list: ";
    cin >> n;
    cout << "Input n numbers of second list: ";
    LList<int> L2;
    while (n--)
    {
        int x = 0;
        cin >> x;
        L2.insert(L2.end(), x);
    }
    LList<int> L3(L1.add_by_bit(L2));
    b = false;
    for (int i : L3)
    {
        if (b)
            cout << " -> ";
        cout << i;
        b = true;
    }
    cout << endl << endl;
}

void test_rerase()
{
    cout << "Test erase reverse n_nd element of linked list." << endl;
    LList<int> L0;

    cout << "Make a new list." << endl;
    cout << "Input the number of these number: ";
    int n = 0;
    cin >> n;
    cout << "Input n number: ";
    while (n--)
    {
        int x = 0;
        cin >> x;
        L0.insert(L0.end(), x);
    }
    cout << "Input a number where will be erase: ";
    cin >> n;
    L0.erase_back_n(n);
    cout << "The list is: ";
    bool b = false;
    for (int i : L0)
    {
        if (b)
            cout << " -> ";
        cout << i;
        b = true;
    }
    cout << endl << endl;
}

void test_lllist() {
    cout << "Test loop linked list." << endl;
    LoopLList<int> L0;

    cout << "1. Make a new list." << endl;
    cout << "Input the number of these number: ";
    int n = 0;
    cin >> n;
    cout << "Input n number: ";
    while (n--) {
        int x = 0;
        cin >> x;
        L0.insert(L0.end(), x);
    }
    cout << "The list is: ";
    bool b = false;
    for (int i : L0) {
        if (b)
            cout << " -> ";
        cout << i;
        b = true;
    }
    cout << endl << endl;

    cout << "2. Make loop." << endl;
    while (true)
    {
        cout << "a. link    b.don't link" << endl;
        cout << "Input a character to choose: ";
        char c = '\0';
        cin >> c;
        if (c == 'a') {
            cout << "Input a position linked by tail: ";
            int n = 0;
            cin >> n;
            auto it = L0.begin();
            while (n--)
                ++it;
            L0.link(it);
            break;
        }
        else if (c == 'b')
            break;
    }
    cout << "Find loop -----------" << endl;
    auto it = L0.find_loop();
    if (it == L0.end())
        cout << "No found loop." << endl;
    else
        cout << *it << endl;
}
