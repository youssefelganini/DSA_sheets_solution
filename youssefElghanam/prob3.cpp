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
vector<ll> ans;
void bfs(ll start)
{
    levels.assign(n + 2, -1);
    queue<ll> q;

    q.push(start);
    levels[start] = 0;

    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (ll v : adj[u])
        {
            if (levels[v] == -1)
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
    cin >> n >> m >> x;
    adj.assign(n, vector<ll>());
    for (ll i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[b].push_back(a);
    }
    bfs(x);
    ans.push_back(x);
    sort(all(ans));
    for (ll i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << '\n';
    }
}