  bool isCycleDFS(vector<vector<int>>& adj, int node, vector<bool>& visited, int parent) {
    visited[node] = true;
    
    for (int &v : adj[node]) {
        if (v == parent) continue; 

        if (isCycleDFS(adj, v, visited, node) == true)
            return true;
    }
    return false;
}
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        vector<bool> visited(V, false);
        
        for(int i = 0; i < V; i++) {
            if(!visited[i] && isCycleDFS(adj, i , visited, -1)) {
                return true;
            }
        }
        return false;
    }