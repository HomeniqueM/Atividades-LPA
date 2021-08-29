#include <iostream>

using namespace std;

/**
    Função que vai calcular o facotorial 

 **/
long int factorial(int input)
{
    long int rFactprial = 1; // Varial que resposavel por armazer o resultado começa em um para que as multiplicações não resulte em 0

    for (int i =input ; i > 1; i = i -1)
    {
        //printf(" N: %d\n", i);
        rFactprial = rFactprial * i;
    }

    return rFactprial;
}



int main(int argc, char const *argv[])
{
    int inputM, inputN;
    string str;
    int i = 0;

    // Ler a primeira linha do arquivo
    getline(cin, str);
    // caso a primeira linha já possua EOF o programa acaba caso não continua 
    while (!cin.eof())
    {
        // Divide a linha para receber o primeiro valor
        inputM = stoi(str.substr(0, str.find(" ")));
        // Recebe o segundo valor 
        inputN = stoi(str.substr(str.find(" ") + 1, -1));
        // Mostra o resultado 
        cout << (factorial(inputM) + factorial(inputN) ) <<endl;
        // Ler novamente a linha
        getline(cin, str);
    }

   

    return 0;
}
