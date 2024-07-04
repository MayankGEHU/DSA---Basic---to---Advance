//  A number which have excetly two factor one and itself
#include<bits/stdc++.h>
using namespace std;
/*
//--- brute force 
tc--------> o(n)
bool isPrimeNumber(int n) {
    if (n <= 1) {
        return false; // 1 and numbers <= 1 are not prime by definition
    }
    int divisorCount = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            divisorCount++;
        }
    }
    if (divisorCount == 2) {
        return true;
    } else {
        return false;
    }
}
*/
bool isPrimeNumber(int n) {
    if (n <= 1) {
        return false; // 1 and numbers <= 1 are not prime by definition
    }
    int divisorCount = 0;
    for (int i = 1; i * i<= n; i++) {
        if (n % i == 0) {
            divisorCount++;
            if((n/i) != i) divisorCount++;
        } 
    }
    if (divisorCount == 2) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    
    if (isPrimeNumber(n)) {
        cout << n << " is a Prime Number" << endl;
    } else {
        cout << n << " is not a Prime Number" << endl;
    }
    
    return 0;
}
