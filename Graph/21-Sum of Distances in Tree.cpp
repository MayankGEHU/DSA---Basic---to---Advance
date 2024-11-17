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


//Time : O(n), Space : O(n)
class Solution {
public:
    //store count of subtrees of each node
    long result_base_node = 0;
    vector<int> count;
    int N;
    int dfsBase(unordered_map<int, vector<int>> &adj, int curr_node, int prev_node, int curr_depth) {
        int total_node = 1;
        
        result_base_node += curr_depth;
        
        for(int &child : adj[curr_node]) {
            if(child == prev_node)
                continue;
            
            total_node += dfsBase(adj, child, curr_node, curr_depth+1);
        }
        
        //store count of subtrees of each node
        count[curr_node] = total_node;
        
        return total_node;
    }
    
    void DFS(unordered_map<int, vector<int>> &adj, int parent_node, int prev_node, vector<int>& result) {
        
        for(int &child : adj[parent_node]) {
            if(child == prev_node)
                continue;
            
            result[child] = result[parent_node] - count[child] + (N - count[child]);
            DFS(adj, child, parent_node, result);
        }
        
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        N = n;
        count.resize(n, 0);
        for(auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        result_base_node = 0;
        
        dfsBase(adj, 0, -1, 0);
        
        vector<int> result(n, 0);
        
        result[0] = result_base_node;
        
        DFS(adj, 0, -1, result);
        
        return result;
    }
};