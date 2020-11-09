// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// Function to find inversion count in the array

// arr[]: Input Array
// N : Size of the Array arr[]

long long merge(long long arr[], long long low, long long mid, long long high)
{
    long long l[mid - low + 1], r[high - mid], inversion = 0;
    int i1 = 0, i2 = 0;

    while (i1 <= mid - low)
    {
        l[i1] = arr[low + i1];
        i1++;
    }

    while (i2 < high - mid)
    {
        r[i2] = arr[mid + i2 + 1];
        i2++;
    }

    int i = 0, j = 0, ind = low;

    while (i < i1 && j < i2)
    {
        if (l[i] > r[j])
        {
            inversion += (i1 - i);
            arr[ind++] = r[j];
            j++;
        }
        else
        {
            arr[ind++] = l[i];
            i++;
        }
    }

    while (i < i1)
    {
        arr[ind++] = l[i++];
    }

    while (j < i2)
    {
        arr[ind++] = r[j++];
    }
    return inversion;
}
long long mergeSort(long long arr[], int low, int high)
{
    long long ans = 0;
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        ans =  mergeSort(arr, low, mid);
        ans += mergeSort(arr, mid + 1, high);
        ans += merge(arr, low, mid, high);
    }
    return ans;
}
long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    long long int ans = mergeSort(arr, 0, N - 1);
    return ans;
}


// { Driver Code Starts.

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    long long T;
    cin >> T;

    while (T--) {
        long long N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++) {
            cin >> A[i];
        }

        cout << inversionCount(A, N) << endl;
    }

    return 0;
}
// } Driver Code Ends