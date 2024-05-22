#include <iostream>

using namespace std;

int main(int argc, char **argv){
    int numOfInputs;
    cin >> numOfInputs;

    int numArray[numOfInputs];

    for (int i = 0; i < numOfInputs; i++)
    {
        int addNum = 0;
        cin >> addNum;
        numArray[i] = addNum;
    }

    for (int i = 1; i < numOfInputs; i++)
    {
        int key = numArray[i];
        int j = i - 1;
        while (j > -1 && numArray[j] > key)
        {
            numArray[j+1] = numArray[j];
            j = j-1;
        }
        numArray[j+1] = key;

        for (int k = 0; k < i+1; k++)
        {
            cout << numArray[k] << ";";
        }
        cout << endl;
    }
    return 0;
}