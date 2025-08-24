#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

using llint = long long;
using lld = long double;
using ullint = unsigned long long;

#ifndef ONLINE_JUDGE
#define dbg(...)                          \
    cerr << "(" << #__VA_ARGS__ << "): "; \
    _print(__VA_ARGS__);                  \
    cerr << '\n'
#define timer_start auto st = high_resolution_clock::now()
#define timer_stop                                      \
    auto en = high_resolution_clock::now();             \
    auto time = (duration_cast<milliseconds>(en - st)); \
    cerr << "\ntime: " << time.count() << " ms" << '\n'
#else
#define dbg(...)
#define timer_start
#define timer_stop
#endif

template <typename T>
void _print(T x) { cerr << x; }

template <typename T, typename... Ts>
void _print(T x, Ts... y)
{
    cerr << x;
    ((cerr << ", ", _print(y)), ...);
}

template <typename T1, typename T2>
void _print(const pair<T1, T2> &p)
{
    cerr << "{";
    _print(p.first);
    cerr << ", ";
    _print(p.second);
    cerr << "}";
}

template <typename T>
void _print(const vector<T> &v)
{
    cerr << "[ ";
    for (auto x : v)
    {
        _print(x);
        cerr << ", ";
    }
    cerr << "]";
}

template <typename T1, typename T2>
void _print(const map<T1, T2> &mp)
{
    cerr << "[ ";
    for (auto x : mp)
    {
        _print(x);
        cerr << ", ";
    }
    cerr << "]";
}

template <typename T1, typename T2>
void _print(const unordered_map<T1, T2> &ump)
{
    cerr << "[ ";
    for (auto x : ump)
    {
        _print(x);
        cerr << ", ";
    }
    cerr << "]";
}

template <typename T>
void _print(const set<T> &st)
{
    cerr << "{ ";
    for (auto x : st)
    {
        _print(x);
        cerr << ", ";
    }
    cerr << "}";
}

template <typename T>
void _print(const unordered_set<T> &ust)
{
    cerr << "{ ";
    for (auto x : ust)
    {
        _print(x);
        cerr << ", ";
    }
    cerr << "}";
}

template <typename T>
void _print(const multiset<T> &ms)
{
    cerr << "{ ";
    for (auto x : ms)
    {
        _print(x);
        cerr << ", ";
    }
    cerr << "}";
}

const llint mod = 1e9 + 7;
const llint stdlen = 1e5 + 3;
const lld pi = acos(-1);

void soln(int cn)
{
    string p;
    cin >> p;

    string s;
    cin >> s;

    llint x = 0, y = 0;
    llint lenp = p.size(), lens = s.size();

    bool ok = true;

    while (x < lenp && y < lens)
    {
        if (p[x] != s[y])
        {
            ok = not ok;
            break;
        }

        llint cnt1 = 0, cnt2 = 0;
        char ch = p[x];

        while (p[x] == ch)
        {
            x++;
            cnt1++;
        }

        while (s[y] == ch)
        {
            y++;
            cnt2++;
        }

        if (cnt2 < cnt1 || cnt2 > (2 * cnt1))
        {
            ok = not ok;
            break;
        }
    }

    if ((x == lenp && y != lens) || (x != lenp && y == lens))
    {
        ok = false;
    }

    if (ok)
    {
        cout << "YES" << '\n';
    }
    else
    {
        cout << "NO" << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif

    int tc = 1;
    cin >> tc;

    timer_start;
    for (int cn = 1; cn <= tc; cn++)
    {
        soln(cn);
    }
    timer_stop;

    return 0;
}