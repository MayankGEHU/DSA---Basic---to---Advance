/*
Leetcode Link                : https://leetcode.com/problems/number-of-provinces/

*/

//--- using DFS
class Solution {
public:
    int n;
    void dfs(vector<vector<int>> &adj, int u, vector<bool>& visited) {
        visited[u] = true;
        
        //Visit neighbours  where it connected
        for(int v = 0; v < n; v++) {
            if(adj[u][v] == 1 && !visited[v]) {
                dfs(adj, v, visited);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        
        vector<bool> visited(n, false);
        int count = 0;
        
        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                count++;
                dfs(isConnected, i, visited);
            }
        }
        return count; 
    }
};




//--- using BFS
class Solution {
public:
    int n;
    void BFS(vector<vector<int>>& isConnected, int u, vector<bool>& visited) {
        queue<int> que;

        que.push(u);
        visited[u] = true;

        while(!que.empty()) {
            int curr = que.front();
            que.pop();
            
            // visit neighbour
            for(int v = 0; v < n; v++) {
                if(!visited[v] && isConnected[u][v] == 1) {
                    BFS(isConnected, v, visited);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        vector<bool> visited(n,false);
        int count = 0;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                BFS(isConnected, i ,visited);
                count++;
            }
        }
        return count;
    }
};