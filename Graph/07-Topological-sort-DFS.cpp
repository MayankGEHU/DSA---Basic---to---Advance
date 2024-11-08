/*
it is use in  Directed Acyclic Graph
a topological sort or topological ordering of a directed graph is a linear ordering 
of its vertices such that for every directed edge from vertex u to vertex v, u comes before 
v in the ordering.
 */

void DFS(vector<vector<int>>& adj, int u, vector<bool>& visited, stack<int>& st) {
    visited[u] = true;
  // first push the v in the stack    
    for(int &v : adj[u]) {
        if(!visited[v]) {
            DFS(adj, v, visited, st);
        }
    }

    // then push u in the stack
    st.push(u);
}


vector<int> topologicalSort(vector<vector<int>>& adj) {
    int V = adj.size(); // Set V to the number of vertices in adj
    vector<bool> visited(V, false);
    stack<int> st;
    
    for(int i = 0; i < V; i++) {
        if(!visited[i]) { 
            DFS(adj, i, visited, st);
        }
    }

    vector<int> result;
    while(!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    
    return result;
}
