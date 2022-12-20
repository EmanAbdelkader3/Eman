#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void InsertionSort(int arr[],int n)
{
    int k,j;
    for(int i = 1; i < n; i++)
    {
        k = arr[i];
        j = i - 1;
        while ( j >= 0 && arr[j] > k)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = k;
    }
}
void print(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int arr[] = { 31 , 41 , 59 , 26 , 41 , 58 };
    int nam = sizeof(arr) / sizeof(arr[0]);
    InsertionSort(arr, nam);
    print(arr,nam);
return 0 ;
}