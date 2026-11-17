#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n < 2) {
        cout << "At least two elements are required";
        return 0;
    }

    int largest = INT_MIN, secondLargest = INT_MIN;
    int smallest = INT_MAX, secondSmallest = INT_MAX;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x > largest) {
            secondLargest = largest;
            largest = x;
        } else if (x < largest && x > secondLargest) {
            secondLargest = x;
        }

        if (x < smallest) {
            secondSmallest = smallest;
            smallest = x;
        } else if (x > smallest && x < secondSmallest) {
            secondSmallest = x;
        }
    }

    if (secondLargest == INT_MIN) cout << "Second largest does not exist\\n";
    else cout << "Second largest: " << secondLargest << "\\n";

    if (secondSmallest == INT_MAX) cout << "Second smallest does not exist\\n";
    else cout << "Second smallest: " << secondSmallest << "\\n";

    return 0;
}
