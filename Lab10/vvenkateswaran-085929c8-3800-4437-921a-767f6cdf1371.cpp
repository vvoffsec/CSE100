#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

string HuffmanEncodings[0];

struct Node 
{
    Node* leftChild;
    Node* rightChild;
    int frequencyInt;
    int unique_id;
    string letterString;
    
    Node(string letterString, int frequencyInt)
    {
        leftChild = NULL; 
        rightChild = NULL;
        this->letterString = letterString;
        this->frequencyInt = frequencyInt;
        this->unique_id = 0;
    }
    
    Node(string letterString, int frequencyInt, int unique_id)
    {
        leftChild = NULL;
        rightChild = NULL;
        this->letterString = letterString;
        this->frequencyInt = frequencyInt;
        this->unique_id = unique_id;
    }
};

struct compare 
{
    bool operator() (Node* leftChild, Node* rightChild)
    {
        if(leftChild->frequencyInt == rightChild->frequencyInt)
        {
            return (leftChild->unique_id > rightChild->unique_id);
        }
        else
        {
            return (leftChild->frequencyInt > rightChild->frequencyInt);
        }
    }
};

void print(Node* minHeapRoot, string encondings, string alphabet[], int size)
{
    if(minHeapRoot == NULL)
    {
        return;
    }
    else
    {
        if(minHeapRoot->letterString.compare("!") != 0)
        {
            for (int i = 0; i < size; i++)
            {
                if(minHeapRoot->letterString.compare(alphabet[i]) == 0)
                {
                    HuffmanEncodings[i] = encondings;
                }
            }
        }
        if(minHeapRoot->letterString.compare("!") == 0)
        {
            print(minHeapRoot->leftChild, encondings + "0", alphabet, size);
            print(minHeapRoot->rightChild, encondings + "1", alphabet, size);
        }
    }
}

void Huffman(int size, string A[], vector<int>& C) 
{
    priority_queue<Node*, vector<Node*>, compare> HuffmanHeap;
    Node* root = NULL;
    Node* leftChild = NULL;
    Node* rightChild = NULL;
    
    for (int i = 0; i < size; i++) 
    {
        Node* temp = new Node(A[i], C[i], i + 1);
        HuffmanHeap.push(temp);
    }

    while(HuffmanHeap.size() > 1) 
    {
        leftChild = HuffmanHeap.top();
        HuffmanHeap.pop();
        rightChild = HuffmanHeap.top();
        HuffmanHeap.pop();
        
        Node* newParent = new Node("!", (leftChild->frequencyInt + rightChild->frequencyInt));
        root = newParent;
        if(leftChild->frequencyInt == rightChild->frequencyInt && leftChild->unique_id > rightChild->unique_id)
        {
            root->leftChild = rightChild;
            root->rightChild = leftChild;
            root->unique_id = rightChild->unique_id;
        }
        else
        {
            root->leftChild = leftChild;
            root->rightChild = rightChild;
            root->unique_id = leftChild->unique_id;
        }

        HuffmanHeap.push(root);
    }
    print(HuffmanHeap.top(), "", A, size); 
    
    char j = 'A';
    for (int i = 0; j <= 'F'; i++, j++) 
    {
        cout << j << ":" << HuffmanEncodings[i] << endl;
    }
}

int main(int argc, char** argv) 
{ 
    int size = 6;
    int value = 0;
    vector<int> C;
    string A[size];
    
    for (int i = 0; i < size; i++) 
    {
        cin >> value;
        C.push_back(value);
        A[i] = "K" + to_string(i);
    }
    
    Huffman(size, A, C);
    return 0;
}