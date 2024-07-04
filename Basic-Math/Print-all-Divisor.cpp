#include<bits/stdc++.h>
using namespace std;
/*
time complexity --- o(n)
bool print_all_division(int n) {
    for(int i = 1; i <= n; i++){
        if(n%i == 0) {
            cout<< i << " ";
        }
    }
}
*/
// tc = o(sqrt(n))
void print_all_division(int n) {
    vector<int> ls;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            ls.push_back(i);
            if (i != n / i) { // Avoid duplicating the square root if n is a perfect square
                ls.push_back(n / i);
            }
        }
    }
    sort(ls.begin(), ls.end());
    for (auto it : ls) cout << it << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    print_all_division(n);
    return 0;
}
