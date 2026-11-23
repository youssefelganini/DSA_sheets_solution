// ﷽
#include <bits/stdc++.h>
using namespace std;

#define fastt                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define endl '\n'

const ll oo = 1e18; // Standardized infinity
const ll MOD = 1e9 + 7;
const int N = 2e5 + 5; // Adjust based on problem constraints

// ==========================================
// GLOBALS
// ==========================================
ll w, n, a, b, c, d, m, q, r1, r2, x, y, k, t, l, r, p, h, u, v;
string s, s1, s2;
vector<ll> arr, val, pref, arr2;
vector<vector<ll>> adj;
vector<bool> vis;

// ==========================================
// DSU (DISJOINT SET UNION)
// ==========================================
vector<ll> parent, sz, scores;

void initDSU(ll n)
{
    parent.assign(n + 2, 0);
    sz.assign(n + 2, 1);
    scores.assign(n + 2, 0);
    for (ll i = 1; i <= n; i++)
    {
        scores[i] = arr[i - 1];
    }
    for (ll i = 1; i <= n; i++)
        parent[i] = i;
}

ll findSet(ll node)
{
    if (parent[node] == node)
        return node;
    return parent[node] = findSet(parent[node]); // Path compression
}

bool unionSet(ll u, ll v)
{
    ll rootU = findSet(u);
    ll rootV = findSet(v);
    if (rootU != rootV)
    {
        if (sz[rootU] < sz[rootV])
            swap(rootU, rootV); // Union by size
        parent[rootV] = rootU;
        sz[rootU] += sz[rootV];
        scores[rootU] += scores[rootV];
        return true;
    }
    return false;
}

int main()
{
    fastt;
    cin >> n >> m;
    arr.assign(n, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    initDSU(n);
    for (ll i = 0; i < m; i++)
    {
        cin >> x >> y;
        x++;
        y++;
        unionSet(x, y);
    }
    ll evenCounts = 0;
    for (ll i = 0; i < n; i++)
    {
        if (findSet(i + 1) == i + 1)
        {
            if (scores[i + 1] % 2 == 0)
            {
                evenCounts++;
            }
        }
    }
    cout << evenCounts << '\n';
}