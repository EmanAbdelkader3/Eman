#include <iostream>
#include <algorithm>
using namespace std;
void Merge( int arr[], int left, int m, int right )
{
    int i, j, k;
    int n1 = m - left + 1;
    int n2 = right - m;
    int *L = new int[n1], *R = new int[n2];
    for ( i = 0; i < n1; i++ )
        L[i] = arr[left + i];
    for ( j = 0; j < n2; j++ )
        R[j] = arr[m + 1 + j];
    i = j = 0;
    k = left;
    while ( i < n1 && j < n2 )
    {
        if ( L[i] <= R[j] )
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while ( i < n1 )
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while ( j < n2 )
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void MergeSort( int arr[], int left, int right )
{
    if ( left < right )
    {
        int m = left + ( right - left ) / 2;
        MergeSort(arr, left, m);
        MergeSort(arr, m + 1, right);
        Merge(arr, left, m, right);
    }
}
void print( int arr[], int nam )
{
    for ( int i = 0; i < nam; i++ )
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = { 31, 41, 59, 26, 41, 58 };
    int nam = sizeof(arr) / sizeof(arr[0]);
    MergeSort( arr, 0, nam - 1 );
    print( arr, nam );
return 0 ;
}
