

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define par pair<int, int>

class Rede
{
private:
  vector<pair<int, par>> Rd;  // Rede
  vector<pair<int, par>> mst; // mst
  int *parent;
  int V; // Numero de Vertice

public:
  Rede(int V);
  void AddRoteadorComCusto(int u, int v, int w);
  int find_set(int i);
  void union_set(int u, int v);
  void kruskal();
  void CalcularCustoTotal();
};

// Iniciar a classe de Rede
Rede::Rede(int V)
{
  parent = new int[V];

  for (int i = 0; i < V; i++)
    parent[i] = i;

  Rd.clear();
  mst.clear();
}
// Adicionar roteador com o custo
void Rede::AddRoteadorComCusto(int u, int v, int w)
{
  Rd.push_back(make_pair(w, par(u, v)));
}

int Rede::find_set(int i)
{
  if (i == parent[i])
  {
    return i;
  }
  else
  {

    return find_set(parent[i]);
  }
}

void Rede::union_set(int u, int v)
{
  parent[u] = parent[v];
}

void Rede::kruskal()
{
  int i, uRep, vRep;
  int size = Rd.size();

  sort(Rd.begin(), Rd.end());

  for (int i = 0; i < size; i++)
  {
    uRep = find_set(Rd[i].second.first);
    vRep = find_set(Rd[i].second.second);
    if (uRep != vRep)
    {
      mst.push_back(Rd[i]); // Adiciona a mst
      union_set(uRep, vRep);
    }
  }
}

void Rede::CalcularCustoTotal()
{
  int total = 0;

  for (int i = 0; i < mst.size(); i++)
  {

    total += mst[i].first;
  }
  cout << total << endl;
}

int main()
{
  int roteadorA, roteadorB, cabo;
  int R, C; // Roteadores, cabos
  cin >> R;
  cin >> C;

  Rede Rede(R);

  for (int i = 0; i < C; i++)
  {
    // Entrada de dado
    cin >> roteadorA;
    cin >> roteadorB;
    cin >> cabo;

    // Criancao de uma coneção
    Rede.AddRoteadorComCusto(roteadorA, roteadorB, cabo);
  }

  Rede.kruskal();
  Rede.CalcularCustoTotal();

  return 0;
}