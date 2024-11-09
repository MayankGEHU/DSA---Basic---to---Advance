/*
a bipartite graph is a graph whose vertices can be divided into two disjoint and 
independent sets and, that is, every edge connects a vertex in to one in. 
Vertex sets and are usually called the parts of the graph.
 */


// using DFS
class Solution {
public:

    bool CheckIsGraphBipartite(vector<vector<int>>& graph, int currNode, vector<int>& color, int currColor) {
        color[currNode] = currColor;

        for(int &v: graph[currNode]) {
            if(color[v] == currColor) return false; 

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
        vector<int> color(V, -1);

        for(int i = 0; i < V; i++) {
            if(color[i] == -1) {
                if(CheckIsGraphBipartite(graph, i, color, 1) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};