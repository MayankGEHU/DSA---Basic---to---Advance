/*
    Company Tags                : Apple, Twitter, Meta, Accolite, Amazon, Flipkart, Microsoft, Moonfrog Labs, OYO Rooms
    Leetcode Link               : https://leetcode.com/problems/course-schedule/
 */


//Approach-1 (Using BFS Cycle Check - Kahn's Algorithm (Topological Sort)

class Solution {
public:

    bool topologicalSortForCycleCheck(unordered_map<int, vector<int>>& adj, int n, vector<int>& indegree) {
        queue<int>que;
        int count = 0;

        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                count++;
                que.push(i);
            }
        }

        while(!que.empty()) {
            int u = que.front();
            que.pop();

            for(int &v: adj[u]) {
                indegree[v]--;

                if(indegree[v] == 0) {
                    count++;
                    que.push(v);
                }
            }
        }   
        if(count == n) {  //I was able to visit all nodes (course)
            return true;
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        unordered_map<int, vector<int>> adj;

        for(auto &vec :prerequisites) {
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);

            indegree[a]++;
        }
        return topologicalSortForCycleCheck(adj, numCourses,indegree);
    }
};