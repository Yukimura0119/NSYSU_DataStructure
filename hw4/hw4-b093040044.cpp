#include <iostream>
#include <string.h>
using namespace std;

//Author:蔡明軒 B093040044
//Date:Sep.24.2020
//recursion & knight move

int used[10][10];
int jump[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

//確認先前是否有找到至少一組解
bool found = 0;

//判斷是否越界
bool OutBoardJudge(int x, int y, int sideleng)
{
    return (x < 1 || y < 1 || x > sideleng || y > sideleng);
}

void DFS(int x, int y, int depth, int sideleng)
{
    //以找到一組解 不必繼續搜索
    if (found)
    {
        return;
    }

    //棋盤填滿 輸出解
    if (depth == sideleng * sideleng)
    {
        found = 1;
        for (int i = 1; i <= sideleng; i++)
        {
            for (int j = 1; j <= sideleng; j++)
            {
                cout << used[i][j] << ' ';
            }
            cout << endl;
        }
        return;
    }

    //移動騎士
    for (int i = 0; i < 8; i++)
    {
        int tempX = x + jump[i][0], tempY = y + jump[i][1];
        if (used[tempX][tempY] == 0 && !OutBoardJudge(tempX, tempY, sideleng))
        {
            used[tempX][tempY] = depth + 1;
            DFS(tempX, tempY, depth + 1, sideleng);
            used[tempX][tempY] = 0;
        }
        else if (i == 7)
        {
            return;
        }
    }
}
int main()
{
    for (int i = 1; i <= 6; i++)
    {
        //reset
        found = 0;
        memset(used, 0, sizeof(used));

        int startX = 1, startY = 1;
        used[startX][startY] = 1;
        DFS(startX, startY, 1, i);

        //未找到解
        if (!found)
        {
            cout << "no solution" << endl;
        }
    }
    return 0;
}