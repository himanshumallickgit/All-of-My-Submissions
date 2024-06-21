class Solution {
public:
    void dfs(int u, vector<vector<pair<int, int>>>& gr, unordered_map<int, int>& component, vector<bool>& vis, int comp){
        vis[u] = true;
        component[u] = comp;
        for(auto& it : gr[u]){
            int v = it.first;
            int weight = it.second;
            if(!vis[v]){
                dfs(v, gr, component, vis, comp); 
            }
        }
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        unordered_map<int, int> component;
        vector<bool> vis(n, false);
        vector<vector<pair<int, int>>> gr(n);
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int dis = edge[2];
            gr[u].emplace_back(v, dis);
            gr[v].emplace_back(u, dis);
        }
        
        int comp = 1;
        for(int i = 0; i < n; ++i){
            if(!vis[i]){
                dfs(i, gr, component, vis, comp);
                ++comp;
            }
        }
        vector<int> compCost(n, pow(2, 31) - 1);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int dis =  edge[2];
            int uComp = component[u];
            compCost[uComp] = compCost[uComp] & dis;
        }
        
        vector<int> ans;
        for(auto& query : queries){
            int u = query[0];
            int v = query[1];
            if(component[u] != component[v]){
                ans.push_back(-1);
            } else if(u == v){
                ans.push_back(0);
            } else {
                ans.push_back(compCost[component[u]]);
            }
        }
        
        return ans;
    }
};