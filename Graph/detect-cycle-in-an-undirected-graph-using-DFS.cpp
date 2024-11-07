  bool isCycleDFS(vector<vector<int>>& adj, int node, vector<bool>& visited, int parent) {
    // mark the node as visited
    visited[node] = true;

    // this is for where we go
    for (int &v : adj[node]) {

        //check if v is equal to parent  
        if (v == parent) continue; 

        // if v is already visited then it will be a cycle then return true
        if(visited[v]) return true;

        if (isCycleDFS(adj, v, visited, node) == true)
            return true;
    }
    return false;
}

    bool isCycle(vector<vector<int>>& adj) {
        vector<bool> visited(V, false);
        
        // this for loop for if we have a un-connected graph
        for(int i = 0; i < V; i++) {
            if(!visited[i] && isCycleDFS(adj, i , visited, -1)) {
                return true;
            }
        }
        return false;
    }