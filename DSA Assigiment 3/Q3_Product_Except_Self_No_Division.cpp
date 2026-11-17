#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n), ans(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    long long leftProduct = 1;
    for (int i = 0; i < n; i++) {
        ans[i] = leftProduct;
        leftProduct *= arr[i];
    }

    long long rightProduct = 1;
    for (int i = n - 1; i >= 0; i--) {
        ans[i] *= rightProduct;
        rightProduct *= arr[i];
    }

    for (long long x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
