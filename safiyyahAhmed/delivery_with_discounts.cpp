#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
bellman ford since theres negative edges and we want shortest paths
-n loops here didnt matter eventhough bellman only needs n-1 , since we werent checking for negative cycles ,
only unreachable nodes, and unreachable nodes wont be reachable ever
 */

vector<string> string_vec(vector<long long>dis)
{
    vector<string> vc;
    for(auto it:dis)
    {
        if(it==1e18)
        {
            vc.push_back("INF");
            continue;
        }
        vc.push_back(to_string(it));
    }
    return vc;
}
vector<string> minimumCosts(int n, vector<vector<int>> routes) {
    vector<long long>dist;
    dist.resize(n,1e18);
    dist[0]=0;
    for(int i=0;i<n;i++)
    {
        int flag=0;
        for(auto it:routes)
        {
            if(dist[it[0]]!=1e18 && dist[it[0]]+it[2]<dist[it[1]])
            {
                flag=1;
                dist[it[1]]=dist[it[0]]+it[2];
            }
        }
        if(!flag)return string_vec(dist);
    }
    return string_vec(dist);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> routes(m);

    for (int i = 0; i < m; i++) {
        routes[i].resize(3);

        string routes_row_temp_temp;
        getline(cin, routes_row_temp_temp);

        vector<string> routes_row_temp = split(rtrim(routes_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int routes_row_item = stoi(routes_row_temp[j]);

            routes[i][j] = routes_row_item;
        }
    }

    vector<string> result = minimumCosts(n, routes);

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
