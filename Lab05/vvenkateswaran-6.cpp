#include <iostream>
#include <vector>

using namespace std;

void quickSort(int* arr, int p, int r)
{
    if ((r - p) > 1) {
        int randNum = arr[(rand() % (r - p) + p)];
        int leftNum = p;
        int rightNum = r;
        rightNum--;

        while (leftNum < rightNum) {
            while (leftNum < rightNum && arr[rightNum] > randNum) rightNum--;
            while (leftNum < r + 1 && arr[leftNum] < randNum) leftNum++;

            if (leftNum < rightNum) {
                arr[leftNum] = arr[leftNum] + arr[rightNum];
                arr[rightNum] = arr[leftNum] - arr[rightNum];
                arr[leftNum] = arr[leftNum] - arr[rightNum];
                leftNum++;
            }
        }
        quickSort(arr, p, leftNum);
        quickSort(arr, rightNum, r);
    }
}


int main() {
	int size;
    cin >> size;

    int arr[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, size);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ";";
    }
}