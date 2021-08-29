
#include <iostream>
#include <string>

using namespace std;
/**
 * recebe duas string uma que vai ser a base da busca e a outra que devemos 
 * localicar se a sequencia de caracteres existe dentro da string base
 */
string containsTheSubString(string source, string comparation)
{
    int sizeSource = source.size();
    int sizeComparation = comparation.size();

    int interation = 0;

    for (int i = 0; i < sizeSource; i++)
    {
        if (source[i] == comparation[interation])
        {

            interation++;

            if (interation >= sizeComparation)
            {

                return "Yes";
            }
        }
    }

    return "No";
}

/**
 * Recebe a String base e todas as possiveis subString 
 * e intera entra entre ela para manda ao metodo 
 * reposavel 
 */
void checkForSubstring(string sequencias, string possiveis[], short n, unsigned int q)
{

    for (size_t j = 0; j < q; j++)
    {

        cout << containsTheSubString(sequencias, possiveis[j]) << endl;
    }
}

int main(int argc, char const *argv[])
{

    short n;
    unsigned int q;
    string sequencias;
    cin >> n;
    cin.ignore();
    // Iniciação do array das palavra a serem usadas como base da comparação

    /**
     * leitura
     * 
     */ 
    for (size_t i = 0; i < n; i++)
    {
        cin >> sequencias;
        cin.ignore();
        cin >> q;
        cin.ignore();
        string possiveis[q];
        for (size_t i = 0; i < q; i++)
        {
            cin >> possiveis[i];
            cin.ignore();
        }
        checkForSubstring(sequencias, possiveis, n, q);
    }

    return 0;
}
