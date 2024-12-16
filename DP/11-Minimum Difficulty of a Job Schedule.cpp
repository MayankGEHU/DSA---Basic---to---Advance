// Recursion
class Solution {
public:
    int solve(vector<int>& jobDifficulty, int n, int idx, int d) {
        /*
            if there is only 1 day left , then you have do all remaining jobs 
            in that one day and find the maximum Difficulty of that day and return it.
            // Base Case 
        */
        if(d == 1) {
            int maxD = jobDifficulty[idx];

            for(int i = idx; i < n; i++) {
                maxD = max(maxD,jobDifficulty[i]);
            }
            return maxD;
        }
        int maxD = jobDifficulty[idx];
        int finalResult = INT_MAX;

        for(int i = idx; i <= n - d; i++) {
            maxD = max(maxD, jobDifficulty[i]);

            int result = maxD + solve(jobDifficulty, n, i + 1, d - 1);
            
            finalResult = min(finalResult, result);
        }
        return finalResult;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        
        if (n < d) {
            return -1;
        }

        return solve(jobDifficulty, n, 0, d);
    }
};

// Recur + Memo

class Solution {
public:
    int dp[301][1001];
    int solve(vector<int>& jobDifficulty, int n, int idx, int d) {
        /*
            if there is only 1 day left , then you have do all remaining jobs 
            in that one day and find the maximum Difficulty of that day and return it.
            // Base Case 
        */
        if(d == 1) {
            int maxD = jobDifficulty[idx];

            for(int i = idx; i < n; i++) {
                maxD = max(maxD,jobDifficulty[i]);
            }
            return maxD;
        }
        int maxD = jobDifficulty[idx];
        int finalResult = INT_MAX;
        
        if(dp[idx][d] != -1) {
            return dp[idx][d];
        }
        for(int i = idx; i <= n - d; i++) {
            maxD = max(maxD, jobDifficulty[i]);

            int result = maxD + solve(jobDifficulty, n, i + 1, d - 1);
            
            finalResult = min(finalResult, result);
        }

        return dp[idx][d] = finalResult;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        memset(dp,-1, sizeof(dp));
        
        if (n < d) {
            return -1;
        }
        return solve(jobDifficulty, n, 0, d);
    }
};