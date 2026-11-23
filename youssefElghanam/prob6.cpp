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
vector<vector<pair<ll, ll>>> adjW;
vector<ll> dist;
vector<ll> par;

ll bellmanFord(ll start)
{
    dist.assign(n + 2, oo);
    par.assign(n + 2, -1);
    dist[start] = 0;
    for (ll i = 1; i <= n; i++)
    {
        bool relaxed = false;
        for (ll u = 1; u <= n; u++)
        {
            if (dist[u] == oo)
                continue;
            for (auto [v, w] : adjW[u])
            {
                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    par[v] = u;
                    relaxed = true;
                }
            }
        }
        if (!relaxed)
            break;
        if (i == n) // still relaxing on the n-th pass -> negative cycle
            return -oo;
    }
    return dist[y + 1] == oo ? -1 : dist[y];
}

int main()
{
    cin >> n >> m;
    adjW.assign(n + 1, vector<pair<ll, ll>>());
    for (ll i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        adjW[a + 1].push_back({b + 1, w});
    }
    bellmanFord(1);
    vector<string> ans;
    for (ll i = 1; i <= n; i++)
    {
        if (dist[i] == oo)
        {
            ans.push_back("INF");
        }
        else
        {
            ans.push_back(to_string(dist[i]));
        }
    }
    for (ll i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << '\n';
    }
}