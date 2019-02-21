#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::string;
using std::swap;

void problem_a();
void problem_b();

void problem_b_1_2();
void problem_b_2_1();

void self_organize_list_count(const string &str);
void self_organize_list_move_to_front(const string &str);
void self_organize_list_transpose(const string &str);

const int M = 17;
int h(int key) { return key % M; }

struct P { char c; int i; };

int main() {
    for (int i = 0; i < 4; i++)
        problem_a();
    problem_b();
    return 0;
}

void problem_a()
{
    string str;
    cin >> str;
    self_organize_list_count(str);
    self_organize_list_move_to_front(str);
    self_organize_list_transpose(str);
}

void self_organize_list_count(const string &str)
{
    list<P> L({{'A', 0}, {'B', 0}, {'C', 0}, {'D', 0}, {'E', 0}, {'F', 0}, {'G', 0}, {'H', 0}});
    int ans = 0;
    for (char c : str)
    {
        auto it = L.begin();
        while (it != L.end() && ++ans && c != it->c)
            ++it;
        (it->i)++;
        while (it != L.begin())
        {
            auto ir = it--;
            if (ir->i > it->i)
                swap(*it, *ir);
        }
    }
    for (auto i : L)
        cout << i.c;
    cout << ' ' << ans << endl;
}

void self_organize_list_move_to_front(const string &str)
{
    list<char> L({'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'});
    int ans = 0;
    for (char c : str)
    {
        auto it = L.begin();
        while (it != L.end() && ++ans && c != *it)
            ++it;
        char f = *it;
        L.erase(it);
        L.push_front(f);
    }
    for (auto i : L)
        cout << i;
    cout << ' ' << ans << endl;
}

void self_organize_list_transpose(const string &str)
{
    list<char> L({'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'});
    int ans = 0;
    for (char c : str)
    {
        auto it = L.begin();
        while (it != L.end() && ++ans && c != *it)
            ++it;
        if (it != L.begin())
        {
            auto ir = it--;
            swap(*ir, *it);
        }
    }
    for (auto i : L)
        cout << i;
    cout << ' ' << ans << endl;
}

void problem_b()
{
    problem_b_1_2();
    problem_b_2_1();
}

void problem_b_1_2()
{
    list<int> L[M];
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        cin >> x;
        int y = h(x);
        auto it = L[y].begin();
        while (it != L[y].end() && *it != x)
            it++;
        if (it == L[y].end())
            L[y].push_back(x);
    }
    for (int i = 0; i < M; i++)
    {
        cout << i << ":\t";
        for (auto x : L[i])
            cout << x << ' ';
        cout << endl;
    }

}

void problem_b_2_1()
{
    list<char> L0[M], L1[M];
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        char &x = s[i];
        int y = h(static_cast<int>(x));
        auto it = L0[y].begin();
        while (it != L0[y].end() && *it != x)
            it++;
        if (it == L0[y].end())
        {
            L0[y].push_back(x);
            continue;
        }
        it = L1[y].begin();
        while (it != L1[y].end() && *it != x)
            it++;
        if (it == L1[y].end())
            L1[y].push_back(x);
    }
    for (int i = 0; i < s.size(); i++)
    {
        char &x = s[i];
        char y = h(x);
        auto it = L1[y].begin();
        while (it != L1[y].end() && *it != x)
            it++;
        if (it == L1[y].end())
        {
            cout << x << endl;
            break;
        }
    }
}
