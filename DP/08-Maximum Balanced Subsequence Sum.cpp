//Approach-1 (Using LIS) - Recursion + Memoization (TLE) ---> 341 / 345 testcases passed
//T.C : O(n^2) - prev index for every i
class Solution {
public:
    unordered_map<string, long long> mp; //For memoization
    long long solve(int i, int prev, vector<int>& nums) {
        if(i >= nums.size()) {
            return 0;
        }

        string key = to_string(i) + "_" + to_string(prev);
        if(mp.find(key) != mp.end()) {
            return mp[key];
        }

        long long taken = INT_MIN;

        if(prev == -1 || nums[i] - i >= nums[prev] - prev) {
            taken = nums[i] + solve(i+1, i, nums);
        }
        
        long long not_taken = solve(i+1, prev, nums);
        return mp[key] = max<long long>(taken, not_taken);
    }

    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int maxEl = *max_element(begin(nums), end(nums));
        if(maxEl <= 0) {
            return maxEl;
        }
        return solve(0, -1, nums);
    }
};

//Approach-2 (Using LIS Bottom Up) - TLE (341/345 Test cases passed)
//Time : O(n^2)
class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        
        int maxEl = *max_element(begin(nums), end(nums));
        if(maxEl <= 0) {
            return maxEl;
        }

        vector<long long> t(n);
        for(int i = 0; i<n; i++) {
            t[i] = nums[i];
        }

        long long maxSum = INT_MIN;
        for(int i = 0; i<n; i++) {

            for(int j = 0; j<i; j++) {

                if(nums[i] - i >= nums[j] - j) {
                    t[i] = max<long long>(t[i], t[j] + nums[i]);
                    maxSum = max<long long>(maxSum, t[i]);
                }

            }
        }

        return maxSum > maxEl ? maxSum : maxEl;
    }
};


//Approach-3 (Using Optimal LIS - Similar to Patience Sorting) - Accepted
//Time : O(nlogn)
class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        map<int, long long> mp;

        long long ans = INT_MIN;
        
        for(int i = 0; i < n; i++){
            auto it = mp.upper_bound(nums[i]-i); //Find the element just greater than nums[i]-i;

            long long cur_ans = nums[i];

            if(it != mp.begin()) {
                it--;
                cur_ans += (*it).second;
            }
            mp[nums[i]-i] = max(mp[nums[i]-i], cur_ans);

            it = mp.upper_bound(nums[i]-i);

            while(it != mp.end() && (*it).second <= cur_ans) {
                 mp.erase(it++);
            }

            ans = max(ans, cur_ans);
        }

        return ans;
    }
};

