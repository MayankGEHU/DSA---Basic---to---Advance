//Time Limit Exceeded
/*
class Solution {
public:
    int Helper(vector<int>& subarray, int count, int i, int k) {
        if(count == 0) {
            return 0;
        }

        if(i >= subarray.size()) {
            return INT_MIN;
        }

        int take = subarray[i] + Helper(subarray, count-1, i+k, k);
        int not_take = Helper(subarray, count, i+1, k);

        return max(take, not_take);
    }
    void solve(vector<int>& subarray, int count, int i, int k, vector<int>& result) {
        if(count == 0) {
            return;
        }
        if(i >= subarray.size()) {
            return;
        }

        int take_index_i = subarray[i] + Helper(subarray, count-1, i+k, k);
        int not_take_index_i = Helper(subarray, count, i+1,k);

        if(take_index_i >= not_take_index_i) {
            result.push_back(i);
            solve(subarray, count-1, i+k, k, result);
        } else {
            solve(subarray, count, i+1, k, result);
        }
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> subarray;
        int i = 0;
        int j = 0;
        int windSum = 0;

        while(j < nums.size()) {
            windSum += nums[j];
            
            if(j - i + 1 == k) {
                subarray.push_back(windSum);
                windSum -= nums[i];
                i++;
            }
            j++;
        }

        vector<int> result;

        solve(subarray, 3, 0, k, result);

        return result;
    }
}; 

*/

class Solution {
public:
    int dp[20001][4];
    int Helper(vector<int>& subarray, int count, int i, int k) {
        if(count == 0) {
            return 0;
        }

        if(i >= subarray.size()) {
            return INT_MIN;
        }

        if(dp[i][count] != -1) {
            return dp[i][count];
        }

        int take = subarray[i] + Helper(subarray, count-1, i+k, k);
        int not_take = Helper(subarray, count, i+1, k);

        return dp[i][count] =  max(take, not_take);
    }
    void solve(vector<int>& subarray, int count, int i, int k, vector<int>& result) {
        if(count == 0) {
            return;
        }
        if(i >= subarray.size()) {
            return;
        }

        int take_index_i = subarray[i] + Helper(subarray, count-1, i+k, k);
        int not_take_index_i = Helper(subarray, count, i+1,k);

        if(take_index_i >= not_take_index_i) {
            result.push_back(i);
            solve(subarray, count-1, i+k, k, result);
        } else {
            solve(subarray, count, i+1, k, result);
        }
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        memset(dp, -1, sizeof(dp));

        vector<int> subarray;
        int i = 0;
        int j = 0;
        int windSum = 0;

        while(j < nums.size()) {
            windSum += nums[j];
            
            if(j - i + 1 == k) {
                subarray.push_back(windSum);
                windSum -= nums[i];
                i++;
            }
            j++;
        }

        vector<int> result;

        solve(subarray, 3, 0, k, result);

        return result;
    }
}; 