#include <iostream>
#include <list>

using namespace std;

int number;

int hashFunction (int k)
{
    return (k % number);
}

void hashInsert(list<int> intListT[], int k)
{
    int i = 0, j = hashFunction(k);
    if(number != 0)
    {
        intListT[j].push_front(k);
    }
}

void hashPrint(list<int> intListT[])
{ 
    list<int> :: iterator iter;
    for(int i = 0; i < number; i++)
    {
        cout << i << ":";
        for(iter = intListT[i].begin(); iter != intListT[i].end(); ++iter)
        {
            cout << *iter << "->";
        }
        cout << ";" << endl;
    }
}

void hashSearch(list<int> intListT[], int k)
{ 
    list<int> :: iterator iter;
    bool found = false;
    int j = hashFunction(k), i = 0;
    for(iter = intListT[j].begin(); iter != intListT[j].end(); ++iter, i++)
    {
        if(*iter == k)
        {
            cout << k << ":FOUND_AT" << j << "," << i << ";" << endl;
            found = true;
        }
    }
    if(!found)
    {
        cout << k << ":NOT_FOUND;" << endl;
    }
}

void hashDelete(list<int> intListT[], int k)
{
    list<int> :: iterator iter;
    bool removed = false;
    int j = hashFunction(k), i = 0;
    for(iter = intListT[j].begin(); iter != intListT[j].end(); ++iter, i++)
    {
        if(*iter == k)
        {
            intListT[i].erase(iter);
            cout << k << ":DELETED;" << endl;
            removed = true;
            break;
        }
    }
    if(!removed)
    {
        cout << k << ":DELETE_FAILED;" << endl;
    }
}

int main(int argc, const char* argv[])
{
    cin >> number;
    list<int>intListT[number];
    char command;
    int k;

    while(number != 0)
    {
        cin >> command;
        if(command == 'i')
        {
            cin >> k;
            hashInsert(intListT, k);
        }
        if(command == 'd')
        {
            cin >> k;
            hashDelete(intListT, k);
        }
        if(command == 's')
        {
            cin >> k;
            hashSearch(intListT, k);
        }
        if(command == 'o')
        {
            hashPrint(intListT);
        }
        if(command == 'e')
        {
            break;
        }
    }
    return 0;
}