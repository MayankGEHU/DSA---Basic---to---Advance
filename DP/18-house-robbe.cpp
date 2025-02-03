/*
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        
        vector<int> t(n+1);
        
        t[0] = 0;
        t[1] = nums[0];
        
        for(int i = 2; i<=n; i++) {
            
            int skip  = t[i-1];
            int steal = nums[i-1] + t[i-2];
          
            t[i] = max(skip, steal);
        }
        return t[n];
    }
};
*/

class Solution {
public:
    int dp[102];
    int solve(vector<int>& nums, int i) { 
        if (i >= nums.size()) {
            return 0;
        } 

        if(dp[i] != -1) {
            return dp[i];
        }

        int take = nums[i] + solve(nums, i + 2); 
        int not_take = solve(nums, i + 1); 

        return dp [i] = max(take, not_take);
    }

    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0);
    }
};
