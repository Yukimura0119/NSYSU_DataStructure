#include <iostream>
#include <fstream>
#include <random>
using namespace std;

int main()
{
    int arr[10] = {100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000, 5000000};
    random_device rd;
    mt19937_64 mt_rand(rd());
    fstream f;
    f.open("input.txt", ios::out);
    for (int i = 0; i < 10; i++)
    {
        f << arr[i] << '\n';
        for (int j = 0; j < arr[i]; j++)
        {
            f << mt_rand() % 2147483646 << '\n';
        }
    }
    f.close();
    return 0;
}