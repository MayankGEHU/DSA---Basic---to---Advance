// Brute - force
//  tc - O(2^n) 
class Solution {
public:
    int solve(int n) {
        if(n < 0) 
            return 0;
        
        if(n == 0) 
            return 1;
        
        int one_step = solve(n - 1);
        int two_step = solve(n - 2);

        return one_step + two_step;
    }
    int climbStairs(int n) {
        return solve(n);
    }
};

// optimization of above approch
//  (Recursion with Memo) : Top Down

class Solution {
public:
    int t[46];
    int solve(int n){
        if(n == 0 || n == 1 || n == 2)
            return n;
        
        if(t[n] != -1)
            return t[n];
        
        int one_step = solve(n-1);
        int two_step = solve(n-2);
        
        return t[n] = one_step + two_step;
        
    }
    int climbStairs(int n) {
        memset(t, -1, sizeof(t));
        return solve(n);
    }
};


// (Using Bottom Up DP)
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2)
            return n;
        
        vector<int> t(n+1);
        
        //t[i] = total ways to climb i stairs
        t[0] = 0;
        t[1] = 1;
        t[2] = 2;
        
        for(int i = 3; i<=n; i++) {
            t[i] = t[i-1] + t[i-2];
        }
        
        return t[n];
    }
};



//(Improving approach-2) -
//See that it looks nothing but a fibonacci sequence. You just have to store last 2 values (t[i-1] & t[i-2]) to find current value (t[i])
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2 || n == 3)
            return n;
        
        int a = 1;
        int b = 2;
        int c = 3;
        
        for(int i = 3; i<=n; i++) {
            c = a + b;
            
            int temp_b = b;
            b = c;
            a = temp_b;
            
        }
        return c;
    }
};