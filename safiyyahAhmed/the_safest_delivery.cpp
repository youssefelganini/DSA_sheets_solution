#include <bits/stdc++.h>

using namespace std;
#define ll long long

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
dijkstra , path with least maximum road cost
[private testcases in the sheet were pretty weak for this , so it accepted solutions that
didnt cover all edge cases]
 */
vector<vector<pair<int,int>>>adj;
vector<ll>vis,level;
ll minimumRisk(int n, vector<vector<int>> roads, int start, int target) {
    adj.resize(n,vector<pair<int,int>>());
    if(start==target)return 0;
    level.resize(n,-1);
    vis.resize(n,0);
    for(int i=0;i<roads.size();i++)
    {
        adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
        adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
    }
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
    q.push({0,start});
    int node,mx;
    level[start]=0;
    while(!q.empty())
    {
        node=q.top().second;
        mx=q.top().first;
        q.pop();
        vis[node]=1;
        if(level[node]<mx)continue;
        if(node==target)break;
        for(auto it:adj[node])
        {
            if(vis[it.first])continue;
            if(level[it.first]<max(mx,it.second) && level[it.first]!=-1)continue;
            level[it.first]=max(mx,it.second);
            q.push({max(mx,it.second),it.first});
        }
    }
    return level[target];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    int start = stoi(first_multiple_input[2]);

    int target = stoi(first_multiple_input[3]);

    vector<vector<int>> roads(m);

    for (int i = 0; i < m; i++) {
        roads[i].resize(3);

        string roads_row_temp_temp;
        getline(cin, roads_row_temp_temp);

        vector<string> roads_row_temp = split(rtrim(roads_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int roads_row_item = stoi(roads_row_temp[j]);

            roads[i][j] = roads_row_item;
        }
    }

    int result = minimumRisk(n, roads, start, target);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
