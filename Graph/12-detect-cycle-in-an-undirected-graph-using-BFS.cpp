    // using BFS
    
    bool isCyclic(int V, vector<vector<int>> adj) {
        queue<int>que;
        vector<int> indegree(V, 0);
        int count = 0;
        
        // populate the indegree
        for(int i = 0; i < V; i++) {
            for(int &v : adj[i]) {
                indegree[v]++;
            }
        }
        

        // which has indegree as 0 push that element in the queue
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) {
                que.push(i);
                count++;
            }
        }
        
        // now BFS
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            
            // if we go to some node then decrese the indegree of that element by one
            for(int &v: adj[u]) {
                indegree[v]--;
                
                // if we found indegree as 0 then push that element int the queue
                if(indegree[v] == 0) {
                    que.push(v);
                    count++;
                }
            }
        }
        
        if(count == V) {
            return false;
        }
        return true;
    }