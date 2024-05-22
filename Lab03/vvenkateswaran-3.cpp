#include <iostream>

using namespace std;

int findMaxCrossingSubarray(int arr[], int low, int mid, int high)
{
    int subArray, sumLeft = arr[mid], sumRight = arr[mid + 1], sum = 0;
    for (int i = mid; i > low; i--)
    {
        sum += arr[i];
        if(sum > sumLeft) 
        {
            sumLeft = sum;
        }
    }
    sum = 0;
    for (int i = mid + 1; i <= high; i++)
    {
        sum += arr[i];
        if(sum > sumRight) 
        {
            sumRight = sum;
        }
    }
    subArray = sumLeft + sumRight;
    return subArray;
}

int findMaximumSubarray(int arr[], int low, int high)
{
    if(low == high) 
    {
        return arr[low];
    }
    int left = findMaximumSubarray(arr, low, (low+high)/2), center = findMaxCrossingSubarray(arr, low, (low+high)/2, high), right = findMaximumSubarray(arr, ((low+high)/2) + 1, high);
    if(left > center && left > right) 
    {
        return left;
    }
    else if(center > right && center > left)
    {
        return center;
    }
    else 
    {
        return right;
    }
}

int main(){
    int input;
    cin >> input;
    int arr[input];
    for(int i = 0; i < input; i++) 
    {
        cin >> arr[i];
    }
    cout << findMaximumSubarray(arr, 0, input - 1);
    return 0;
}