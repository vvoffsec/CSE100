#include <iostream>

#define MAX_INT 2147483647

using namespace std;

int main(int argc, char **argv){

    int* Sequence;
    int arraySize = 1;

    // get size of sequence;

    cin >> arraySize;
    Sequence = new int[arraySize];

    // read the sequence;
    for (int i = 0; i < arraySize; i++){
        cin >> Sequence[i];
    }
    
    // initializing max and min numbers
    int max_num = Sequence[0];
    int min_num = Sequence[0];

    // updating max and min numbers
    for (int i = 1 ; i < arraySize; i++){
        if (Sequence[i] > max_num){
            max_num = Sequence[i];
        }
        if (Sequence[i] <  min_num){
            min_num = Sequence[i];
        }
    }

    // output
    cout << max_num << ";" << min_num;

    // free allocated space
    delete[] Sequence;

    return 0;
}