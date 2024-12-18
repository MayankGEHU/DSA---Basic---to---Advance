//  it give TLE
// Recur + MEMO
/*
class Solution {
public: 
    int n;
    int dp[101][101];
    int solve(vector<vector<int>>& matrix, int row, int col) {
        if(row == n-1) {
            return matrix[row][col];
        }
        
        if(dp[row][col] != -1) {
            return dp[row][col];
        }

        int sum = matrix[row][col];
        int minSum = INT_MAX;

        // if we not add the condition then it will go out of bound 
        if(row + 1 < n && col - 1 >= 0) {
            minSum = min(minSum, sum + solve(matrix, row + 1, col - 1)); 
        }
        
        if(row + 1 < n) {
            minSum = min(minSum, sum + solve(matrix, row + 1, col));
        }
        
        if(row + 1 < n && col + 1 < n) {
            minSum = min(minSum, sum + solve(matrix, row + 1, col + 1));
        }

        return dp[row][col] = minSum;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        int row = 0;
        int result = INT_MAX;

        memset(dp, -1, sizeof(dp));

        for(int i = 0; i < n; i++) {
            result = min(result, solve(matrix, row, i));
        }
        return result;
    }
};
*/

/*
//This is just reducing the line 
class Solution {
public: 
    int n;
    int dp[101][101];
    int solve(vector<vector<int>>& matrix, int row, int col) {
        if(row == n-1) {
            return matrix[row][col];
        }
        
        if(dp[row][col] != -1) {
            return dp[row][col];
        }

        int sum = matrix[row][col];
        int minSum = INT_MAX;

        for(int shift = -1; shift <= 1; shift++) {
            if(row + 1 < n && col + shift < n && col + shift >= 0) {
                minSum = min(minSum, sum + solve(matrix, row + 1, col + shift));
            }
        }
        return dp[row][col] = minSum;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        int row = 0;
        int result = INT_MAX;

        memset(dp, -1, sizeof(dp));

        for(int i = 0; i < n; i++) {
            result = min(result, solve(matrix, row, i));
        }
        return result;
    }
};
*/
//TC - o(n^2)
//SC - o(n^2)
class Solution {
public: 
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>>t(n, vector<int>(n));

        //populate first row
        for(int col = 0; col < n; col++) {
            t[0][col] = matrix[0][col];
        }

        for(int row = 1; row < n; row++) {
            for(int col = 0; col < n; col++) {  

                int a = INT_MAX;
                int b = INT_MAX;

                if(col - 1 >= 0) {
                    a = t[row - 1][col - 1];
                }
                
                if(col + 1 < n) {
                    b = t[row - 1][col + 1]; 
                }

                t[row][col] = matrix[row][col] +  min({t[row-1][col], a, b});
            }
        }

        int result = INT_MAX;
        int lastRow = n - 1; 

        for(int col = 0; col < n; col++) {
            result = min(result, t[lastRow][col]);
        }
        return result;
    }
};
