/*
Include the original index along with the weight because sorting edges by weight may cause the index to be lost.

Steps:
1. Push original index 
2. sort based on weight
3. Find MST_wEIGHT -----> Kruskal's Algo
4. Check each edge ----> i) skip ith edge and calculate MST_WEIGHT and check 
                            if(new_weight > MST_WEIGHT) --> edges is critical
                            if the edge is not critical then include that edges
                            and check if(New_weight == MST_WEIGHT) then it is Pseudo-Critical Edge.
*/
//T.C : ElogE + E*@ + E*E*@
class Solution {
public:
    int N;
    class UnionFind {
        public:
            vector<int> parent;
            vector<int> rank;

            UnionFind(int n) {
                parent.resize(n);
                rank.resize(n, 0);
                for (int i = 0; i < n; i++) {
                    parent[i] = i;
                }
            }    
        
            int find (int x) {
                if (x == parent[x]) 
                    return x;

                return parent[x] = find(parent[x]);
            }

            void Union (int x, int y) {
                int x_parent = find(x);
                int y_parent = find(y);

                if (x_parent == y_parent) 
                    return;

                if(rank[x_parent] > rank[y_parent]) {
                    parent[y_parent] = x_parent;
                } else if(rank[x_parent] < rank[y_parent]) {
                    parent[x_parent] = y_parent;
                } else {
                    parent[x_parent] = y_parent;
                    rank[y_parent]++;
                }
            }
    };
    
    int Kruskal(vector<vector<int>> &vec, int skip_edge, int include_edge) {
        int sum = 0;
        UnionFind uf(N);
        
        if(include_edge != -1) {
            uf.Union(vec[include_edge][0], vec[include_edge][1]);
            sum += vec[include_edge][2];
        }
        
        for(int i = 0; i < vec.size(); i++) {
            
            if(i == skip_edge) {
                continue;
            }
 
            int u  = vec[i][0];
            int v  = vec[i][1];
            int wt = vec[i][2];
            
            int parent_u = uf.find(u);
            int parent_v = uf.find(v);
            
            if(parent_u != parent_v) {
                uf.Union(u, v);
                sum += wt;
            }
        }

        //Check if all vertices are included in MST
        for(int i = 0; i < N; i++) {
            if(uf.find(i) != uf.find(0)) {
                return INT_MAX;
            }
        }
        return sum;
    }
     vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        N = n;
        //since for kruskal's algo, we will sort our input by edge weight.
        //But since we need to return the index in the last
        for(int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }
        
        auto comparator = [&](auto &v1, auto &v2) {
            return v1[2] < v2[2];
        };
        //Now sort based on weight
        //O(ElogE)
        sort(edges.begin(), edges.end(), comparator);
        
        // find the MST_Weight
        int MST_WEIGHT = Kruskal(edges, -1, -1);
        
        vector<int> critical, pseudo_critical;


      //O(E*E*@)
        for(int i = 0; i < edges.size(); i++) {
          
            if(Kruskal(edges, i, -1) > MST_WEIGHT) {
                critical.push_back(edges[i][3]); 
            } else if(Kruskal(edges, -1, i) == MST_WEIGHT) {
                pseudo_critical.push_back(edges[i][3]);
            }
        }
        return {critical, pseudo_critical};
    }
};



/*
in the Kruskal's Function, in the end we checked if the graph was connected and wrote a for loop to check that as shown below : 
for(int i = 0; i<N; i++) {   
            if(uf.find(i) != uf.find(0))
                return INT_MAX;
 }

BUT BUT BUT, we can also directly check if the total edges we made from Union is equal to (V-1). 
Remember, in MST, there must be V vertices and must have (V-1) edges.
So, in Kruskal's function, whenever you do Union, just count the edges you draw.

So, simply replace the for loop with : 
if(edgesConnected != N-1) return INT_MAX;

*/
class Solution {
public:
    int N;
    class UnionFind {
        public:
            vector<int> parent;
            vector<int> rank;

            UnionFind(int n) {
                parent.resize(n);
                rank.resize(n, 0);
                for (int i = 0; i < n; i++) {
                    parent[i] = i;
                }
            }    
        
            int find (int x) {
                if (x == parent[x]) 
                    return x;

                return parent[x] = find(parent[x]);
            }

            bool Union (int x, int y) {
                int x_parent = find(x);
                int y_parent = find(y);

                if (x_parent == y_parent) 
                    return false;

                if(rank[x_parent] > rank[y_parent]) {
                    parent[y_parent] = x_parent;
                } else if(rank[x_parent] < rank[y_parent]) {
                    parent[x_parent] = y_parent;
                } else {
                    parent[x_parent] = y_parent;
                    rank[y_parent]++;
                }
                return true;
            }
    };
    
    int Kruskal(vector<vector<int>> &vec, int skip_edge, int add_edge) {
        int sum = 0;
        
        UnionFind uf(N);
        int edgesConnected = 0;
        
        if(add_edge != -1) {
            uf.Union(vec[add_edge][0], vec[add_edge][1]);
            sum += vec[add_edge][2];
            edgesConnected++;
        }
        
        //E
        
        for(int i = 0; i<vec.size(); i++) {
            
            if(i == skip_edge) {
                continue;
            }
            
            int u  = vec[i][0];
            int v  = vec[i][1];
            int wt = vec[i][2];
            //O(@)
            int parent_u = uf.find(u);
            int parent_v = uf.find(v);
            
            if(parent_u != parent_v) {
                uf.Union(u, v);
                edgesConnected++;
                sum += wt;
            }
        }

        if(edgesConnected != N-1) {
            return INT_MAX;
        }
        return sum;
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        N = n;
        for(int i = 0; i<edges.size(); i++) {
            edges[i].push_back(i);  
        }
        
        auto lambda = [&](vector<int>& vec1, vector<int>& vec2) {
            return vec1[2] < vec2[2];
        };
        //ElogE
        sort(begin(edges), end(edges), lambda);
        
        int MST_WEIGHT = Kruskal(edges, -1, -1);

        vector<int> critical;
        vector<int> pseudo_critical;
        
        //E*E*@
        for(int i = 0; i<edges.size(); i++) {
            
            if(Kruskal(edges, i, -1) > MST_WEIGHT) { 
                critical.push_back(edges[i][3]);
            } else if(Kruskal(edges, -1, i) == MST_WEIGHT) { 
                pseudo_critical.push_back(edges[i][3]);
            }   
        }
        return {critical, pseudo_critical};
    }
};
