#include <iostream>
using namespace std;
//Author:蔡明軒 B093040044
//Date:Sep.10.2020
//階乘
int arr[55][105]; //儲存各階乘的數字
int leng[55];     //儲存各階乘的長度
int main()
{
    //1!長度為一 大小為1
    leng[1] = 1;
    arr[1][1] = 1;

    //製作2!~50!的表
    for (int i = 2; i <= 50; i++)
    {
        for (int j = 1; j <= leng[i - 1]; j++)
        {
            //此階乘的第j位=上一階乘的第j位乘以i
            arr[i][j] = arr[i - 1][j] * i;
        }
        for (int j = 1; j < leng[i - 1]; j++)
        {
            //進位至上一階乘的位數
            arr[i][j + 1] = arr[i][j + 1] + arr[i][j] / 10;
            arr[i][j] = arr[i][j] % 10;
        }
        leng[i] = leng[i - 1]; //長度至少為上一階乘的長度

        //將剩餘未進位完成的進行進位
        int temp = arr[i][leng[i]];
        while (temp / 10 != 0)
        {
            arr[i][leng[i] + 1] = temp / 10;
            arr[i][leng[i]] = temp % 10;
            temp /= 10;
            leng[i]++;
        }
    }
    //IO
    int data;
    while (cin >> data)
    {
        if (data == 0)
        {
            break;
        }
        for (int i = 1; i <= data; i++)
        {
            cout << i << "!=";
            for (int j = 1; j <= leng[i]; j++)
            {
                cout << arr[i][leng[i] - j + 1];
            }
            cout << endl;
        }
    }
    return 0;
}