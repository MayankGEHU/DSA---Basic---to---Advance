// --------------------------------------- Khan's Algorithm

/*
Kahn's algorithm is a topological sorting algorithm that efficiently sorts directed acyclic graphs (DAGs)
The first vertex in the Topological Sorting of graphs is decided because the node has the In-Degree zero
(i.e. the node has zero incoming nodes)
*/
/*
 indegree of a vertex is the number of incoming edges to that vertex
*/

 vector<int> topologicalSort(vector<vector<int>>& adj) {
        
        int N = adj.size();
        queue<int>que;
        vector<int> indegree(N, 0);
        
        // populate the indegree
        for(int i = 0; i < N; i++) {
            for(int& v: adj[i]) {
                indegree[v]++;
            }
        }

        // if we found indegree as 0 then push it into the queue
        for(int i = 0; i < N; i++) {
            if(indegree[i] == 0) {
                que.push(i);
            }
        }
        
        vector<int>res;
        
        // now BFS
        while(!que.empty()) {

            //u initilize the element which is front of the queue
            int u = que.front();

            // push the element on the result
            res.push_back(u);

            // pop that element
            que.pop();
            
            // now check for another element 
            for(int &v : adj[u]) {

                // if u have a incoming v edges then decrease the indgree by one 
                indegree[v]--;

                // if the indegree get 0 push it on the queue
                if(indegree[v] == 0) {
                    que.push(v);
                }
            }
        }
        return res;
    }