#include <iostream>
#include <cmath>
using namespace std;

/** 
 * Aluno: Homenique Vieira Martins  
 * Custo: (o)N
 */


class NotasMoedas
{
private:
    double value;

    double notesAndCoins[12] = {100.0, 50.0, 20.0, 10.0, 5.0, 2.0, 1.0, 0.50, 0.25, 0.10, 0.05, 0.01};
    int quantity[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

public:
    NotasMoedas(double value)
    {
        this->value = value;
       
    }
    // ~NotasMoedas();

    void calculateQuantity()
    {
        double tmpvalue = this->value;

        for (int i = 0; i < 12; i++)
        {
            if (tmpvalue > 0)
            {
                this->quantity[i] = (int)(tmpvalue / this->notesAndCoins[i]);
              
                
            //    cout << "Value:  " << tmpvalue << "  | note or coin "  << this->notesAndCoins[i] << endl;
            //    cout << "result " << (int)(tmpvalue / this->notesAndCoins[i]) << "\n" << endl;

                tmpvalue = tmpvalue - (this->notesAndCoins[i] * (double)this->quantity[i]);
            }
            else
            {
                i = 12;
            }
        }
    }

    void printQuantity()
    {
        cout << "NOTAS:" << endl;
        cout << this->quantity[0] << " nota(s) de R$ 100.00" << endl;
        cout << this->quantity[1] << " nota(s) de R$ 50.00" << endl;
        cout << this->quantity[2] << " nota(s) de R$ 20.00" << endl;
        cout << this->quantity[3] << " nota(s) de R$ 10.00" << endl;
        cout << this->quantity[4] << " nota(s) de R$ 5.00" << endl;
        cout << this->quantity[5] << " nota(s) de R$ 2.00" << endl;

        cout << "MOEDAS:" << endl;
        cout << this->quantity[6] << " moeda(s) de R$ 1.00" << endl;
        cout << this->quantity[7] << " moeda(s) de R$ 0.50" << endl;
        cout << this->quantity[8] << " moeda(s) de R$ 0.25" << endl;
        cout << this->quantity[9] << " moeda(s) de R$ 0.10" << endl;
        cout << this->quantity[10] << " moeda(s) de R$ 0.05" << endl;
        cout << this->quantity[11] << " moeda(s) de R$ 0.01" << endl;
    }
};

int main(int argc, char const *argv[])
{
    double input = 0;

    cin >> input;

    NotasMoedas notesCoins = NotasMoedas(input);

    notesCoins.calculateQuantity();
    notesCoins.printQuantity();

    return 0;
}
