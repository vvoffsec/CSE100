#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int> arrayA[], vector<int> arrayB[], int k, int n)
{
    int arrayC[10];
    
    for(int i = 0; i < 10; i++)
    {
        arrayC[i] = 0;  
    }
    for(int j = 0; j < n; j++)
    {
        arrayC[arrayA[j][k]]=arrayC[arrayA[j][k]]+1;
    }
    for(int i = 1; i < 10; i++)
    { 
        arrayC[i] = arrayC[i] + arrayC[i-1];
    }
    for(int j = n-1; j >= 0; j--)
    {
        arrayB[arrayC[arrayA[j][k]]-1] = arrayA[j];
        arrayC[arrayA[j][k]] = arrayC[arrayA[j][k]] - 1;
    }
}

void radixSort(vector<int> arrayA[], vector<int> arrayB[], int n)
{
    for(int i = 9; i >= 0; i--)
    {
        countingSort(arrayA, arrayB, i, n);
        for(int i = 0; i < n; i++)
        {
            arrayA[i] = arrayB[i];
        }
    }
}

int main(){
    int amountNum;
    int countNum;
    cin >> amountNum;
    vector<int>arrayA[amountNum];
    vector<int>arrayB[amountNum];
    
    for(int i = 0; i < amountNum; i++){ 
        for(int j = 0; j < 10; j++){
            cin >> countNum;
            arrayA[i].push_back(countNum);
        }
    }
    radixSort(arrayA, arrayB, amountNum);

    for(int i = 0; i < amountNum; i++){
        for(int j = 0; j < 10; j++){
            cout << arrayB[i][j] << ";";
        }
        cout << "\n";
    }
    return 0;
    
}