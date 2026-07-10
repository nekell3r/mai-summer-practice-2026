#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum = 0;
        int mx = -1000;
        for (int i = 0; i < 7; i++) {
            int a;
            cin >> a;
            sum += a;
            if (a > mx) mx = a;
        }
        cout << 2 * mx - sum << '\n';
    }
}
