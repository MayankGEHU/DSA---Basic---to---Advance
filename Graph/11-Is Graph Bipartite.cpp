/*
a bipartite graph is a graph whose vertices can be divided into two disjoint and 
independent sets and, that is, every edge connects a vertex in to one in. 
Vertex sets and are usually called the parts of the graph.
 */


// using DFS
class Solution {
public:

    bool CheckIsGraphBipartite(vector<vector<int>>& graph, int currNode, vector<int>& color, int currColor) {

        // set the current node as current color
        color[currNode] = currColor;

        // now explore the other edges of the graph
        for(int &v: graph[currNode]) {

            // if node of color is equal to current color then it is not a Bipartite graph so return false
            if(color[v] == currColor) return false; 

            // if the node is not visited then check it adjecent node color and call the DFS and if it is false then return false
            if(color[v] == -1) {
                int ColorOfV = 1 - currColor;
                if(CheckIsGraphBipartite(graph, v, color, ColorOfV) == false) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();

        // create a vector of color
        vector<int> color(V, -1);

        // check for evrey edge in graph
        for(int i = 0; i < V; i++) {

            // if color of i is not colored then call the DFS function it it return false then the graph is not Bipartite so return false;
            if(color[i] == -1) {
                if(CheckIsGraphBipartite(graph, i, color, 1) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};





// using BFS

class Solution {
public:

    bool CheckIsGraphBipartiteBFS(vector<vector<int>>& graph, int currNode, vector<int>& color, int currColor) {
        queue<int> que;

        // push the current node in que 
        que.push(currNode);

        // and then color that node
        color[currNode] = currColor;

        while(!que.empty()) {
            int u = que.front();
            que.pop();

            for(int &v: graph[u]) {
                //if any node has maching color then return false
                if(color[v] == color[u]) {
                    return false;

                    // if node have no color 
                } else if(color[v] == -1){

                    // then color it according to it adjecent node
                    color[v] = 1 - color[u];

                    // and then push it into the que;
                    que.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);

        for(int i = 0; i < V; i++) {
            if(color[i] == -1) {
                if(CheckIsGraphBipartiteBFS(graph, i, color, 1) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};