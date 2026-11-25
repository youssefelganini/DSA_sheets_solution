#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
pure dfs , since we want the whole subtree whos root is the broken package 
*/

 vector<vector<int>>adj;
 vector<int>vis;
void dfs(int node)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it);
        }
    }
    return;
}

vector<int> blockedPackages(int n, vector<vector<int>> dependencies, int broken) {
    vector<int>answer;
    adj.resize(n,vector<int>());
    vis.resize(n);
    for(int i=0;i<dependencies.size();i++)
    {
        adj[dependencies[i][1]].push_back(dependencies[i][0]);
    }
    dfs(broken);
    for(int i=0;i<n;i++)
    {
        if (vis[i])
        {
            answer.push_back(i);
        }
    }
    sort(answer.begin(),answer.end());
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

    int broken = stoi(first_multiple_input[2]);

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

    vector<int> result = blockedPackages(n, dependencies, broken);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
