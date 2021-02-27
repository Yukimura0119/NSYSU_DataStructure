#include <iostream>
using namespace std;
// Author:蔡明軒 B093040044
// Date:Sep.8.2020
//製作1~5階魔方陣
int arr[105][105];
int exist[105][105];
int cnt = 0;  //重置exist用
int main() {
    for (int i = 0; i < 5; i++) {
        cnt++;  //重置exist
        arr[0][i] = 1;
        exist[0][i] = cnt;  //標記[0][i]已存在
        int sideleng = i * 2 + 1;
        int nowX = 0, nowY = i;  //初始位置
        for (int j = 2; j <= sideleng * sideleng; j++) {
            int tempX = nowX, tempY = nowY;
            //往左上移動
            nowX--;
            nowY--;
            //判斷越界
            if (nowX < 0) {
                nowX = nowX + sideleng;
            }
            if (nowY < 0) {
                nowY = nowY + sideleng;
            }

            //填上數字
            if (exist[nowX][nowY] == cnt)  //左上的格子已存在
            {
                //向下移動
                nowX = tempX + 1;
                nowY = tempY;

                //判斷越界
                if (nowX > i * 2) {
                    nowX = nowX - sideleng;
                }

                arr[nowX][nowY] = j;
                exist[nowX][nowY] = cnt;
            } else {
                arr[nowX][nowY] = j;
                exist[nowX][nowY] = cnt;
            }
        }
        // output
        for (int j = 0; j < sideleng; j++) {
            for (int k = 0; k < sideleng; k++) {
                cout << arr[j][k] << " ";
            }
            cout << endl;
        }
    }
}