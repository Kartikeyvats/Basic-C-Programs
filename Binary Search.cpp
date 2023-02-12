#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    int x;
    cout << "Enter the element to be searched: ";
    cin >> x;
    int result = binarySearch(arr, n, x);
    if (result == -1)
        cout << "Element not found in the array." << endl;
    else
        cout << "Element found at index " << result << "." << endl;
    return 0;
}
