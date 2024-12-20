bool isCycleDFS(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& inRecursion) {
    visited[u] = true;
    inRecursion[u] = true;
    
    for(int &v : adj[u]) {
        // if node is not visited then we check for cycle call dfs further
        if(!visited[v] && isCycleDFS(v, adj, visited, inRecursion)) {
            return true;

            // if node already visited and inRecursion is also true then it is cycle
        } else if(inRecursion[v]) {
            return true;
        }
    }

    // dfs recursion is end then mark the current node false
    inRecursion[u] = false;
    return false;
}

bool isCyclic(int V, vector<vector<int>> adj) {
    vector<bool> visited(V, false);
    vector<bool> inRecursion(V, false);
    
    for(int i = 0; i < V; i++) {
        if(!visited[i] && isCycleDFS(i, adj, visited, inRecursion)) {
            return true;
        }
    }
    return false;
}
