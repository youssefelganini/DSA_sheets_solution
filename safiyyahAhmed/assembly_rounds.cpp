#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
start bfs from nodes with zero in-degree , then if any node isnt reached , its levels value
would be -1 just like initialization
Then to get number of rounds , we need the longest path , which is the maximum level value
 */
 vector<vector<int>>adj;
 vector<int>vis,levels;


int minimumRounds(int n, vector<vector<int>> dependencies) {
    adj.resize(n,vector<int>());
    vis.resize(n,0);
    levels.resize(n,-1);
    map<int,int>mp;
    for(int i=0;i<dependencies.size();i++)
    {
        adj[dependencies[i][0]].push_back(dependencies[i][1]);
        mp[dependencies[i][1]]++;
    }
    int answer=0;
    queue<int>q;
    int node;
    for(int i=0;i<n;i++)
    {
        
        if (!mp[i])
        {
            
            q.push(i);
            vis[i]=1;
            levels[i]=1;
        } 
    }
     while(!q.empty())
        {
                node=q.front();
                q.pop();

                for (auto it:adj[node])
                {
                    if (!vis[it])
                    {
                        vis[it]=1;
                        levels[it]=levels[node]+1;
                        q.push(it);
                    }
                }
                
        }
    for(auto it:levels)
    {
        if(it==-1)return -1;
        answer=max(answer,it);
    }
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> dependencies(m);

    for (int i = 0; i < m; i++) {
        dependencies[i].resize(2);

        string dependencies_row_temp_temp;
        getline(cin, dependencies_row_temp_temp);

        vector<string> dependencies_row_temp = split(rtrim(dependencies_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int dependencies_row_item = stoi(dependencies_row_temp[j]);

            dependencies[i][j] = dependencies_row_item;
        }
    }

    int result = minimumRounds(n, dependencies);

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
