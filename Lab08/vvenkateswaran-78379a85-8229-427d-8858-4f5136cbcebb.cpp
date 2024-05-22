#include<iostream>

using namespace std;

void cutRod(int* priceInt, int n){
    int max, rev[n+1], slices[n+1];
    rev[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        max = priceInt[0];
        for(int j = 1; j <= i; j++)
        {
            if(max < (priceInt[j] + rev[i - j]))
            {
                max = (priceInt[j] + rev[i - j]);
                slices[i] = j;
            }
        }
        rev[i] = max;
    }
    cout << rev[n] << endl;
    while(n > 0)
    {
        cout << slices[n] << " ";
        n -= slices[n];
    }
    cout << "-1" << endl;
}

int main()
{
	int n;
	cin >> n;
    int priceInt[n+1];
	priceInt[0] = 0; 
	for(int i = 1; i <= n; i++)
    {
        cin >> priceInt[i];
    } 
    cutRod(priceInt, n);
    return 0;
}