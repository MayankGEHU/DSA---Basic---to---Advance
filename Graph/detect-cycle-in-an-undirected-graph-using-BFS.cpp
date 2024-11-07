  // TC - o(v + e)  
    
    bool isCycleBFS(vector<int>adj, int u, vector<bool> & visited) {
        queue<pair<int, inr>> que;
        // push node and parent in queue
        que.push({u, -1});
        // mark that node as visited
        visited[u] = true;

        // now BFS
        while(!que.empty()) {
            // pop the element which is front of the queue
            pair<int, int> P = que.front();
            que.pop();

            // pair first element
            int source = P.first;

            // pair second element
            int parent = P.second;
            
            // now ham v se kha kha ja skte hai
            for(int &v : adj[source]) {

                //if v is not visited then mark it visited and push into queue
                if(visited[v] == false) {
                    visited[v] = true;
                    que.push({v, source});

                    // if visited or v is parent then the cycle is found then return truel\;
                } else if(v != parent) {
                    return true;
                } 
            }
        }
         return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
        vector<bool> visited(V, false);
        
        // this for loop for if we have a un-connected graph
        for(int i = 0; i < V; i++) {
            if(!visited[i] && isCycleBFS(adj, i , visited)) {
                return true;
            }
        }
        return false;
    }