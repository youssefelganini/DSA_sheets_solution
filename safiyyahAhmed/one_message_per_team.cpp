#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
count number of connected components whos tasks total is even
pure dfs
*/
 vector<vector<int>>adj;
 vector<int>vis;
void dfs(int node,vector<int>& tasks,int& ans)
{
    vis[node]=1;
    ans+=(tasks[node]%2);
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it,tasks,ans);
        }
    }
    return;
}

int countBalancedTeams(vector<int> tasks, vector<vector<int>> relationships) {
    int n=tasks.size();
    int answer=0,x;
    adj.resize(n,vector<int>());
    vis.resize(n);
    for(int i=0;i<relationships.size();i++)
    {
        
        adj[relationships[i][0]].push_back(relationships[i][1]);
        adj[relationships[i][1]].push_back(relationships[i][0]);
    }
    
    for(int i=0;i<n;i++)
    {
        if (!vis[i])
        {
            x=0;
            dfs(i,tasks,x);
            if(x%2==0)answer++;
        }
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

    string tasks_temp_temp;
    getline(cin, tasks_temp_temp);

    vector<string> tasks_temp = split(rtrim(tasks_temp_temp));

    vector<int> tasks(n);

    for (int i = 0; i < n; i++) {
        int tasks_item = stoi(tasks_temp[i]);

        tasks[i] = tasks_item;
    }

    vector<vector<int>> relationships(m);

    for (int i = 0; i < m; i++) {
        relationships[i].resize(2);

        string relationships_row_temp_temp;
        getline(cin, relationships_row_temp_temp);

        vector<string> relationships_row_temp = split(rtrim(relationships_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int relationships_row_item = stoi(relationships_row_temp[j]);

            relationships[i][j] = relationships_row_item;
        }
    }

    int result = countBalancedTeams(tasks, relationships);

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
