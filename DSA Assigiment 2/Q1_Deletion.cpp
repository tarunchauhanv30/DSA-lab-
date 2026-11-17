#include <iostream>
using namespace std;

int main() {
    int n, arr[100], pos;
    cin >> n;

    if (n <= 0 || n > 100) return 0;

    for (int i = 0; i < n; i++) cin >> arr[i];

    cin >> pos;

    if (pos < 0 || pos >= n) {
        cout << "Invalid position";
        return 0;
    }

    for (int i = pos; i < n - 1; i++) arr[i] = arr[i + 1];

    n--;

    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    return 0;
}
