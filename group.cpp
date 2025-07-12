#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

// Binary Search Function
int binarySearch(const vector<int>& arr, int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;  
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;  
}

// Exponential Search Function
int exponentialSearch(const vector<int>& arr, int key) {
    if (arr[0] == key)
        return 0;

    int i = 1;
    int n = arr.size();
    while (i < n && arr[i] <= key)
        i *= 2;

    return binarySearch(arr, i / 2, min(i, n - 1), key);
}

int main() {
    
    int n, key, choice;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> data(n);
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i)
        cin >> data[i];

    // Sorting in ascending order
    sort(data.begin(), data.end());
   
    cout << "\nSorted List:\n";
    for (int num : data)
        cout << num << " ";
    cout << "\n";

    cout << "Enter the number to search: ";
    cin >> key;

    cout << "\nChoose Search Algorithm:\n";
    cout << "1. Binary Search\n";
    cout << "2. Exponential Search\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;
    clock_t before, after;
    double time_taken;
    
    int result = -1;
    if (choice == 1) {
        before = clock();
        result = binarySearch(data, 0, n - 1, key);
        after = clock();
        time_taken = 1000 * ( double(after - before) / CLOCKS_PER_SEC);
        cout << "Binary search Time: " << time_taken << " milliseconds" << endl;
    }
    else if (choice == 2) {
        before = clock();
        result = exponentialSearch(data, key);
        after = clock();
        time_taken = 1000 * (double(after - before) / CLOCKS_PER_SEC);
        cout << "Exponential search Time: " << time_taken << " milliseconds" << endl;
    }
    else {
        cout << "Invalid choice.\n";
        return 1;
    }
   
    
    if (result != -1)
        cout << "Element " << key << " found at index " << result << ".\n";
    else
        cout << "Element " << key << " not found.\n";

    return 0;
}
