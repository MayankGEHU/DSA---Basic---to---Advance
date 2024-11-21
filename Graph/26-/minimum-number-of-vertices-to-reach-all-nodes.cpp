class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> indegree(n, false);

        for(auto &edgs : edges) {
            int u = edgs[0];
            int v = edgs[1];

            indegree[v] = true;
        }

        vector<int> result;

        for(int i = 0; i < n; i++) {
            if(indegree[i] == false) {
                result.push_back(i);
            }
        }
        return result;
    }
};