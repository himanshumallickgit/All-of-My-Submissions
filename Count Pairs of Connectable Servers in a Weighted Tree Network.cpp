class Solution {
public:
    unordered_map<int, vector<pair<int, int>>> gr;
    int sum = 0;
    int cnt = 0;
    void dfs(int u, int par, int d, int ss) {
        if (d % ss == 0) {
            cnt++;
        }
        for (auto it : gr[u]) {
            if (it.first != par) {
                dfs(it.first, u, d + it.second, ss);
            }
        }
    }
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1;
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int dis = edge[2];
            gr[u].emplace_back(v, dis);
            gr[v].emplace_back(u, dis);
        }
        vector<int> ans(n, 0);
        for (int root = 0; root < n; root++) {
            int sum = 0;
            vector<int> tmp;
            for (auto it : gr[root]) {
                int u = it.first;
                int d = it.second;
                cnt = 0;
                dfs(u, root, d, signalSpeed);
                sum += cnt;
                tmp.push_back(cnt);
            }
            int count = 0;
            for (auto it : tmp) {
                count += (it * (sum - it));
            }
            ans[root] = count/2;
        }        
        return ans;
    }
};