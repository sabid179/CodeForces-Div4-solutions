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

map<llint, vector<llint>> mp;
vector<vector<llint>> nod;

void nods(llint N)
{
    nod.assign(N + 1, vector<llint>());

    for (llint i = 2; i <= N; i++)
    {
        for (llint j = i; j <= N; j += i)
        {
            nod[j].push_back(i);
        }
    }
}

llint f(llint k, llint l, llint r)
{
    // llint ans = 0;
    // for (int i = l; i <= r; i++)
    // {
    // 	while (k % a[i] == 0)
    // 	{
    // 		k = k / a[i];
    // 	}
    // 	ans += k;
    // }
    // return ans;

    pair<llint, llint> final_min = {LLONG_MAX, LLONG_MAX};

    for (auto &x : nod[k])
    {
        vector<llint> &s = mp[x];
        llint lo = 0, hi = s.size() - 1;

        auto min_idx = lower_bound(s.begin(), s.end(), l);

        if (min_idx != s.end() && *(min_idx) < final_min.first && *(min_idx) <= r)
        {
            final_min = {*(min_idx), x};
        }
    }

    if (final_min.first != LLONG_MAX)
    {
        llint temp = k;
        while (not(temp % final_min.second))
        {
            temp /= final_min.second;
        }
        return k * (final_min.first - l) + f(temp, final_min.first, r);
    }
    else
    {
        return k * (r - l + 1);
    }
}

void soln(int cn)
{
    llint n, q;
    cin >> n >> q;

    llint arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]].push_back(i);
    }

    while (q--)
    {
        llint k, l, r;
        cin >> k >> l >> r;
        l--, r--;

        llint res = f(k, l, r);
        cout << res << '\n';
    }

    mp.clear();
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif

    nods(stdlen);

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