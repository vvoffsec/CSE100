#include <iostream>

using namespace std;


void merge(int A[], int p, int q, int r){
    int j = 0, k = 0, n1 = q - p + 1, n2 = r - q;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) 
    {
        L[i] = A[p + i];
    }

    for(int i = 0; i < n2; i++) 
    {
        R[i] = A[i + q + 1];
    }

    for (int i = p; i <= r; i++)
    {
	    if (j < n1 && k < n2)
        {
            if(L[j] < R[k]) A[i] = L[j++];
            else A[i] = R[k++];
	    }
	    else if (j == n1)
        {
            A[i] = R[k++];
        }
	    else 
        {
            A[i] = L[j++];
        }
    }
}

void mergeSort(int A[], int a, int b)
{
    if (a < b)
    {
        int q = (a+b)/2;
        mergeSort(A, a, q);
        mergeSort(A, q + 1, b);
        merge(A, a, q, b);
    }
}

int main(int argc, char **argv){
    int userInput;
    cin >> userInput;
    int A[userInput];
    for (int i = 0; i < userInput; i++)
    {
        cin >> A[i];
    }
    mergeSort(A, 0, userInput-1);
    for (int i = 0; i < userInput; i++)
    {
        cout << A[i] << ";";
    }
    return 0;
}