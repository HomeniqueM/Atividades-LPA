

#include <iostream>
#include <vector>
using namespace std;

class Bolha
{
private:
    int movements = 0;
    vector<int> sequence;
    vector<int> merge(vector<int> left, vector<int> right);
    vector<int> mergeSort(vector<int> &elements);

public:
    void startGame(int size);
    void loadValues(int size);
    void printArray();
};

void Bolha::startGame(int size)
{
    loadValues(size);
    //cout << "Entrada: " << endl;
    //printArray();

    mergeSort(sequence);

    // cout << "saida: " << endl;
    // printArray();

    if (movements % 2 == 0)
    {
        cout << "Carlos" << endl;
    }
    else
    {
        cout << "Marcelo" << endl;
    }
}

void Bolha::printArray()
{
    for (int i = 0; i < sequence.size(); i++)
    {
        cout << sequence[i] << " ";
    }
    cout << endl;
}

void Bolha::loadValues(int size)
{
    int element;
    // cout << "loadValues ( " << size << ")" << endl;

    for (int i = 0; i < size; i++)
    {
        cin >> element;
        //cout << "[" << element << "] ";

        sequence.push_back(element);
    }

  //  cout << endl;
}

vector<int> Bolha::merge(vector<int> left, vector<int> right)
{
    int i = 0;
    int j = 0;

    vector<int> join;

    while (i < left.size() && j < right.size())
    {

        if (left[i] < right[j])
        {
            join.push_back(left[i++]);
        }
        else
        {
            join.push_back(right[j++]);
            movements = movements + left.size() - i;
        }
    }

    while (i < left.size())
        join.push_back(left[i++]);

    while (j < right.size())
        join.push_back(right[j++]);

    return join;
}

vector<int> Bolha::mergeSort(vector<int> &elements)
{

    if (elements.size() <= 1)
    {
        return elements;
    }

    int pivot = elements.size() / 2;

    vector<int> left(elements.begin(), elements.begin() + pivot);
    vector<int> right(elements.begin() + pivot, elements.end());

    return merge(mergeSort(left), mergeSort(right));
}

int main(int argc, char const *argv[])
{
    int value; // Varoavel onde vai ser armazenado os casos de teste

    cin >> value;

    while (value != 0)
    {
        Bolha bolha;

        bolha.startGame(value);

        cin >> value;
    }

    return 0;
}
