
#include <iostream>
using namespace std;



int ledCost[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
/**
     * [codigo]
     * 0 [6]
     * 1 [2] 
     * 2 [5]
     * 3 [5] 
     * 4 [4]
     * 5 [5]
     * 6 [6]
     * 7 [3]
     * 8 [7]
     * 9 [6]
     * difente disso [-1]
     */


int getCost(int number)
{

    if (number > 9 || number < 0)
    {
        return 0;
    }

    return ledCost[number];
}


  
int calculateTotalLEDNeeded(string str)
{
    int total = 0;

    for (char i : str)
    {

        total += getCost(i - 48);
    }

    return total;
}

int main(int argc, char const *argv[])
{

    string str;
    short interaction = 0;

    scanf("%hd", &interaction);
    for (short i = 0; i < interaction; i++)
    {
        cin >> str;

        cout << calculateTotalLEDNeeded(str) << " leds" << endl;
    }

    return 0;
}
