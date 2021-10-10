#include <iostream>
#include <map>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>

  

using namespace std;

int subwarray[410];



struct Subway {
  
    int source, destiny, weight;
    
    bool operator<(const Subway &point) const
    {
        return weight < point.weight;
    }
};


vector<Subway> sub;

int findset(int r)
{
    if (subwarray[r] == r)
    {
        return r;
    }

    return findset(subwarray[r]);
}

int main(int argc, char const *argv[])
{
    int vertex, edge;
    int k = 1;

    string subSource;
    string subway01;
    string subway02;

    map<string, int> mapOfSubway;

    cin >> vertex;
    cin >> edge;

    while (vertex > 0 && edge > 0)
    {
        for (int i = 0; i < vertex; i++)
        {

            cin >> subSource;
            mapOfSubway[subSource] = k++;
        }

        sub.clear();

        for (int i = 0; i < edge; i++)
        {
            int tmpWeight;

            cin >> subway01 >> subway02 >> tmpWeight;

            Subway data;

            data.source = mapOfSubway[subway01];
            data.destiny = mapOfSubway[subway02];
            data.weight = tmpWeight;

            sub.push_back(data);
        }
        cin >> subSource;

        for (int i = 1; i <= vertex; i++)
        {
            subwarray[i] = i;
        }

        sort(sub.begin(), sub.end());

        int cot = vertex - 1, sum = 0;

        for (int i = 0; i < (int)sub.size(); i++)
        {

            int u = findset(sub[i].source);
            int v = findset(sub[i].destiny);

            if (u != v)
            {
                subwarray[u] = v;
                cot--;
                // cout<<cot<<endl;
                sum += sub[i].weight;
            }
        }

        if (cot)
        {
            cout << "Impossible" << endl;
        }
        else
        {
            cout << sum << endl;
        }

        cin >> vertex;
        cin >> edge;

    }

    return 0;
}
