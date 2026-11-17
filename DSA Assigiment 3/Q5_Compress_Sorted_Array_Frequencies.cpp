#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int i = 0;
    while (i < n) {
        int value = arr[i];
        int frequency = 0;

        while (i < n && arr[i] == value) {
            frequency++;
            i++;
        }

        cout << value << " " << frequency << endl;
    }

    return 0;
}
