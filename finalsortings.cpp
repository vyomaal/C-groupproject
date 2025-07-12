#include <iostream>
#include <ctime> 
using namespace std;

// Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {  
        if (arr[j] < pivot) {  
            i++;  
            int temp = arr[i];  
            arr[i] = arr[j];  
            arr[j] = temp;  
        }  
    }  

    int temp = arr[i + 1];  
    arr[i + 1] = arr[high];  
    arr[high] = temp;  

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int partIndex = partition(arr, low, high);
        quickSort(arr, low, partIndex - 1);
        quickSort(arr, partIndex + 1, high);
    }
}

// Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int size1 = mid - left + 1;
    int size2 = right - mid;

    int leftArr[size1], rightArr[size2];  

    for (int i = 0; i < size1; i++)  
        leftArr[i] = arr[left + i];  
    for (int j = 0; j < size2; j++)  
        rightArr[j] = arr[mid + 1 + j];  

    int i = 0, j = 0, k = left;  

    while (i < size1 && j < size2) {  
        if (leftArr[i] <= rightArr[j]) {  
            arr[k] = leftArr[i];  
            i++;  
        } else {  
            arr[k] = rightArr[j];  
            j++;  
        }  
        k++;  
    }  

    while (i < size1) {  
        arr[k] = leftArr[i];  
        i++;  
        k++;  
    }  

    while (j < size2) {  
        arr[k] = rightArr[j];  
        j++;  
        k++;  
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    int quickArray[size], mergeArray[size];  

    cout << "Enter " << size << " numbers:" << endl;  
    for (int i = 0; i < size; i++) {  
        cin >> quickArray[i];  
        mergeArray[i] = quickArray[i];  
    }

    clock_t before, after;
    double time_taken;

    before = clock();
    quickSort(quickArray, 0, size - 1);  
    after = clock();
    time_taken = double(after - before) / CLOCKS_PER_SEC;

    cout << endl << "Sorted using Quick Sort:" << endl;  
    for (int i = 0; i < size; i++) {  
        cout << quickArray[i] << " ";  
    }  
    cout << endl << "Quick Sort Time: " << time_taken << " seconds" << endl;

    before = clock();
    mergeSort(mergeArray, 0, size - 1);  
    after = clock();
    time_taken = double(after - before) / CLOCKS_PER_SEC;

    cout << endl << "Sorted using Merge Sort:" << endl;  
    for (int i = 0; i < size; i++) {  
        cout << mergeArray[i] << " ";  
    }  
    cout << endl << "Merge Sort Time: " << time_taken << " seconds" << endl;
    return 0;
}
   