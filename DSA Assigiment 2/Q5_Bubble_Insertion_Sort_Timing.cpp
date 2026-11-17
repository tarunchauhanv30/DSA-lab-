#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

void bubbleSort(vector<int>& a) {
    int n = static_cast<int>(a.size());
    for (int i = 0; i < n - 1; i++) {
        bool changed = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                changed = true;
            }
        }
        if (!changed) break;
    }
}

void insertionSort(vector<int>& a) {
    for (int i = 1; i < static_cast<int>(a.size()); i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

int main() {
    int n;
    cin >> n;

    if (n < 0) return 0;

    vector<int> original(n);
    for (int i = 0; i < n; i++) cin >> original[i];

    vector<int> bubble = original;
    vector<int> insertion = original;

    auto start1 = high_resolution_clock::now();
    bubbleSort(bubble);
    auto end1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();
    insertionSort(insertion);
    auto end2 = high_resolution_clock::now();

    cout << "Bubble Sort Output:\\n";
    for (int x : bubble) cout << x << " ";
    cout << "\\nTime: "
         << duration_cast<microseconds>(end1 - start1).count()
         << " microseconds\\n";

    cout << "Insertion Sort Output:\\n";
    for (int x : insertion) cout << x << " ";
    cout << "\\nTime: "
         << duration_cast<microseconds>(end2 - start2).count()
         << " microseconds\\n";

    return 0;
}
