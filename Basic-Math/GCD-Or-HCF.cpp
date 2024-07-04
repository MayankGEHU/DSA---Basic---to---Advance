//GCD--- gretest common divisior , HCF--- heighst commen fector
#include <iostream>
using namespace std;

int gcd_hcf(int n1, int n2) {
    int gcd = 1;
    for (int i = 1; i <= n1 && i <= n2; ++i) {
        if (n1 % i == 0 && n2 % i == 0) {
            gcd = i;
        }
    }
    return gcd;
}

int main() {
    int n1, n2;
    cout << "Enter two numbers: ";
    cin >> n1 >> n2;
    int result = gcd_hcf(n1, n2);
    cout << "GCD of " << n1 << " and " << n2 << " is: " << result << endl;
    return 0;
}
