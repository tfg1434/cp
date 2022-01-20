/*
ID: toronto4
TASK: sort3
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int N;
int swaps = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(vector<int>& arr, int size) {
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray 
    for (i = 0; i < size-1; i++){
        // Find the minimum element in unsorted array 
        min_idx = i;
        for (j = i+1; j < size; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element 
        swap(&arr[min_idx], &arr[i]);
        swaps++;
    }
}

int main() {
//    freopen("sort3.in", "r", stdin);
//    freopen("sort3.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    selectionSort(arr, N);
    cout << swaps / 2 << endl;
    
    return 0;
}
