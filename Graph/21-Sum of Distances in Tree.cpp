//Time Complexity: O(n^2)
//Space Complexity: O(n)
class Solution {
public:
    int DFS(int node, int parent, unordered_map<int, vector<int>>& adj, int depth) {
        int sum = depth; 
        for (int neighbor : adj[node]) { 
            if (neighbor != parent) {
                sum += DFS(neighbor, node, adj, depth + 1); 
            }
        }
        return sum;
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (const auto& edge : edges) {
            int u = edge[0]; 
            int v = edge[1]; 

            adj[u].push_back(v);
            adj[v].push_back(u);           
        }

        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = DFS(i, -1, adj, 0); 
        }
        return result;
    }
};
