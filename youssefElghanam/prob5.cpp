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

ll dijkstra(ll start)
{
    dist.assign(n + 2, oo);
    par.assign(n + 2, -1);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (u == y)
        {
            return d;
        }
        if (d > dist[u])
            continue;
        for (auto [v, w] : adjW[u])
        {
            ll next_risk = max(dist[u], w);
            if (next_risk < dist[v])
            {
                dist[v] = next_risk;
                par[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    return -1;
}

int main()
{
    cin >> n >> m >> x >> y;
    adjW.assign(n, vector<pair<ll, ll>>());
    for (ll i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        adjW[a].push_back({b, w});
        adjW[b].push_back({a, w});
    }
    if (x == y)
    {
        cout << 0 << '\n';
        return 0;
    }
    cout << dijkstra(x) << '\n';
}
