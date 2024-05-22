#include<iostream>
#include<vector>

using namespace std;

int* primInt(vector<int> G[], int **weights);
int findMinV(vector<int> Q, int *keysInt);
bool search(vector<int> Q, int v);

int V, E;



int* primInt(vector<int> G[], int **weights)
{
    int u, min, *parentsInt = (int*)malloc(V * sizeof(int)), *keysInt = (int*)malloc(V * sizeof(int));
    vector<int> Q;
    for(int i = 0; i < V; i++)
    {
        parentsInt[i] = -1;
        keysInt[i] = INT32_MAX;
        Q.push_back(i);
    }
    keysInt[0] = 0;
    while(Q.empty() == false)
    {
        min = findMinV(Q, keysInt);
        u = Q[min];
        Q.erase(Q.begin() + min);
        for(int i = 0; i < G[u].size(); i++)
        {
            if((search(Q, G[u][i]) == true) && weights[u][G[u][i]] < keysInt[G[u][i]])
            {
                parentsInt[G[u][i]] = u;
                keysInt[G[u][i]] = weights[u][G[u][i]];
            }
        }
    }
    return parentsInt;
}

int findMinV(vector<int> Q, int *keysInt)
{
    int m = 0, num = keysInt[Q.front()];
    for(int i = 0; i < Q.size(); i++)
    {
        if(keysInt[Q[i]] < num)
        {
            num = keysInt[Q[i]];
            m = i;
        }
    }
    return m;
}

bool search(vector<int> Q, int v)
{
    for(int i = 0; i < Q.size(); i++)
        if(v == Q[i]) return true;
    return false;
}

int main()
{
    cin >> V;
    cin >> E;
    int u, v, w, *parentsInt;
    vector<int> G[V];
    int **weights = (int**)malloc(V * sizeof(int*));
    for(int i = 0; i < V; i++)
    {
        weights[i] = (int*)malloc(V * sizeof(int));
        for(int j = 0; j < V; j++)
            weights[i][j] = -1;
    }
    for(int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        G[u].push_back(v);
        G[v].push_back(u);
        weights[u][v] = w; 
        weights[v][u] = w;
    }
    parentsInt = primInt(G, weights);
    for(int i = 1; i < V; i++) cout << parentsInt[i] << endl;
    return 0;
}