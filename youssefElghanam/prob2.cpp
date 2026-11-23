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
vector<vector<vector<ll>>> adj_list;
vector<vector<bool>> vis;

vector<ll> levels;
vector<ll> leaves;
ll target;

ll bfs(ll start)
{
    queue<tuple<ll, ll, ll>> q;

    q.push({start, 0, 0});
    q.push({start, 1, 0});
    vis[start][0] = true;
    vis[start][1] = true;
    while (!q.empty())
    {
        auto &[node, last_type, dis] = q.front();
        q.pop();
        ll next_type = 1 - last_type;
        for (ll v : adj_list[node][next_type])
        {
            if (v == target)
            {
                return dis + 1;
            }
            if (!vis[v][next_type])
            {
                vis[v][next_type] = true;
                q.push({v, next_type, dis + 1});
            }
        }
    }
    return -1;
}

int main()
{
    fastt;
    cin >> n >> m >> target;
    adj_list.assign(n + 2, vector<vector<ll>>(2));
    for (ll i = 0; i < m; i++)
    {
        cin >> a >> b >> t;
        adj_list[a][t].push_back(b);
    }
    if (target == 0)
    {
        cout << 0 << '\n';
        return 0;
    }
    vis.assign(n + 2, vector<bool>(2, false));
    cout << bfs(0) << '\n';
}