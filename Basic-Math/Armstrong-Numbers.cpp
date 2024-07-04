#include<bits/stdc++.h>
using namespace std;
bool isArmstrong(int X) {
    int original = X;
    int sum = 0;
    while (X > 0) {
        int digit = X % 10;
        sum += digit * digit * digit;
        X /= 10;
    }
    return (sum == original);
}

int main() {
    int X;
    cout << "Enter the number you want to check if it is Armstrong or not: ";
    cin >> X;
    if (isArmstrong(X)) {
        cout << "It is an Armstrong Number";
    } else {
        cout << "It is not an Armstrong Number";
    }
    return 0;
}
