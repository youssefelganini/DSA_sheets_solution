#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
Honestly couldnt get the right solution from first try , since i missed that 
there could be back edges to go through and not only forward paths
-so this meant that a node has to have 2 visited states , one for when we reach it with a
 long jump and the other with a short jump
- so its just bfs but with pairs of node & type of jump to reach it
*/

vector<vector<pair<int,int>>>adj;
vector<vector<int>>vis,levels; 

int minimumJumps(int n, vector<vector<int>> jumps, int target) {
  if (target==0)return 0;
  adj.resize(jumps.size(),vector<pair<int,int>>());
  vis.resize(n,{0,0});
  levels.resize(n,{0,0});
  for(int i=0;i<jumps.size();i++)
  {
    adj[jumps[i][0]].push_back({jumps[i][1],jumps[i][2]});
  }  
  queue<pair<int,int>>q;
  int node,type;
  q.push({0,0});
  q.push({0,1});
  vis[0][0]=1,vis[0][1]=1;
  levels[0][0],levels[0][1]=0;
  while(!q.empty())
  {
        node=q.front().first;
        type=q.front().second;
        q.pop();
        if (node==target)
        {
            return levels[node][type];
        }
        for (auto it:adj[node])
        {
            if (!vis[it.first][it.second] && it.second!=type)
            {
                vis[it.first][it.second]=1;
                levels[it.first][it.second]=levels[node][type]+1;
                q.push({it.first,it.second});
            }
        }
        
  }
  return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    int target = stoi(first_multiple_input[2]);

    vector<vector<int>> jumps(m);

    for (int i = 0; i < m; i++) {
        jumps[i].resize(3);

        string jumps_row_temp_temp;
        getline(cin, jumps_row_temp_temp);

        vector<string> jumps_row_temp = split(rtrim(jumps_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int jumps_row_item = stoi(jumps_row_temp[j]);

            jumps[i][j] = jumps_row_item;
        }
    }

    int result = minimumJumps(n, jumps, target);

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
