#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0, r = n - 1;
    long long sumL = a[l], sumR = a[r];
    int ops = 0;

    while (l < r) {
        if (sumL == sumR) {
            l++;
            r--;
            if (l < r) {
                sumL = a[l];
                sumR = a[r];
            }
        }
        else if (sumL < sumR) {
            l++;
            sumL += a[l];
            ops++;
        }
        else {
            r--;
            sumR += a[r];
            ops++;
        }
    }

    cout << ops << endl;
    return 0;
}
