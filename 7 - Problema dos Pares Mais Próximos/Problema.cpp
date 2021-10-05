#include <iostream>
#include <cmath>



using namespace std;


double distanceBetweenTwoPoints(int a[], int b[])
{

    double dx = pow((b[0] - a[0]), 2);
    double dy = pow((b[1] - a[1]), 2);

    return sqrt(dx + dy);
}



double searchForTheShortestDistance(int x[], int y[], int size)
{
    int A[2];
    int B[2];
    double shortestDistance = 9007199254740991; // atribuo um valor abitrario a variavel poderia ser 10000 que não mudaria o resultado 
    double distance = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i != j)
            {

                A[0] = x[i];
                A[1] = y[i];

                B[0] = x[j];
                B[1] = y[j];

                distance = distanceBetweenTwoPoints(A, B);

                if (shortestDistance > distance)
                {
                    shortestDistance = distance;
                }
            }
        }
    }
    return shortestDistance;
}


void printShorterDistance(double distance)
{

    if (distance > 10000)
    {
        std::cout << "INFINITY" << std::endl;
    }
    else
    {
        printf("%.4f\n", distance);
    }
}


int main(int argc, char const *argv[])
{
    int cases;
    int points;

    cin >> cases;

    // Execulta o numero de teste
    while (cases > 0)
    {
        int x[cases], y[cases];
        for (int i = 0; i < cases; i++)
        {
            cin >> x[i];
            cin >> y[i];
        }
        printShorterDistance(searchForTheShortestDistance(x, y, cases));

        cin >> cases;
    }

    return 0;
}
