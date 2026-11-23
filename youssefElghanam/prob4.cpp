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
vector<ll> levels;
vector<ll> inDegree;
vector<ll> ans;
void bfs()
{
    levels.assign(n + 2, -1);
    queue<ll> q;
    for (ll i = 0; i < inDegree.size(); i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
            levels[i] = 0;
        }
    }
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (ll v : adj[u])
        {
            inDegree[v]--;
            if (inDegree[v] == 0)
            {
                levels[v] = levels[u] + 1;
                ans.push_back(v);
                q.push(v);
            }
        }
    }
}

int main()
{
    fastt;
    cin >> n >> m;
    adj.assign(n, vector<ll>());
    inDegree.assign(n, 0);
    for (ll i = 0; i < m; i++)
    {
        cin >> a >> b;
        inDegree[b]++;
        adj[a].push_back(b);
    }
    bfs();
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        if (levels[i] == -1)
        {
            ans = oo;
        }
        ans = max(ans, levels[i]);
    }
    if (ans == oo)
    {
        cout << -1 << '\n';
        return 0;
    }
    cout << ans + 1 << '\n';
}