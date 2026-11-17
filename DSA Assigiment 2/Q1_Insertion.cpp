#include <iostream>
using namespace std;

int main() {
    int n, arr[100], pos, value;
    cin >> n;

    if (n < 0 || n >= 100) return 0;

    for (int i = 0; i < n; i++) cin >> arr[i];

    cin >> pos >> value;

    if (pos < 0 || pos > n) {
        cout << "Invalid position";
        return 0;
    }

    for (int i = n; i > pos; i--) arr[i] = arr[i - 1];

    arr[pos] = value;
    n++;

    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    return 0;
}
