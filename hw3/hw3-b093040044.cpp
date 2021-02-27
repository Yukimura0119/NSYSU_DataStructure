#include <string.h>

#include <iostream>

using namespace std;
// Author:蔡明軒 B093040044
// Date:Sep.17.2020
// stack & knight move
template <class Type>
class stack {
    Type* arr;
    int top;
    int capacity;

   public:
    //建構子
    stack(int size = 50);

    //堆上一層資料
    void push(Type);

    //拿出最上層資料
    Type pop();

    //回傳stack高度
    int size();

    //確認stack是否為空
    bool empty();

    //輸出stack最上層
    Type back();

    //隨機存取此stack(但好像用不到QAQ)
    Type access(int);

    //解構子
    ~stack() { delete[] arr; }
};

template <class Type>
stack<Type>::stack(int size) {
    arr = new Type[size];
    capacity = size;
    top = -1;
}

template <class Type>
void stack<Type>::push(Type x) {
    arr[++top] = x;
}

template <class Type>
Type stack<Type>::pop() {
    return arr[top--];
}

template <class Type>
bool stack<Type>::empty() {
    if (top == -1) {
        return true;
    } else {
        return false;
    }
}

template <class Type>
Type stack<Type>::back() {
    return arr[top];
}

template <class Type>
int stack<Type>::size() {
    return top + 1;
}

template <class Type>
Type stack<Type>::access(int index) {
    return arr[index];
}

struct data {
    int x;
    int y;
    int direction;
};
//判斷是否越界
bool IsOut(int x, int y, int lmt) {
    return (x < 1 || y < 1 || x > lmt || y > lmt);
}

int arr[10][10];
int jump[8][2] = {{-2, 1}, {-1, 2}, {1, 2},   {2, 1},
                  {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

int main() {
    for (int i = 1; i <= 6; i++) {
        stack<data> st(36);
        //重設arr
        memset(arr, 0, sizeof(arr));

        //標記初始位置
        int nowX = 1, nowY = 1;
        arr[1][1] = 1;

        //將起點放入stack
        data temp;
        temp.x = 1;
        temp.y = 1;
        temp.direction = -1;
        st.push(temp);

        while (1) {
            //若stack為空 表示無解
            if (st.empty()) {
                cout << "no solution" << endl;
                break;
            }

            //若stack高度=總元素和 表示有結果
            if (st.size() == i * i) {
                for (int j = 1; j <= i; j++) {
                    for (int k = 1; k <= i; k++) {
                        cout << arr[j][k] << " ";
                    }
                    cout << endl;
                }
                break;
            }

            //確認是否有路可走
            bool flag = 1;

            for (int j = 0; j < 8; j++) {
                //跳過先前走過的
                if (st.back().direction >= j) {
                    continue;
                }

                int tempX = nowX + jump[j][0], tempY = nowY + jump[j][1];
                if (!IsOut(tempX, tempY, i) && arr[tempX][tempY] == 0) {
                    //將stack的top填上方向
                    flag = 0;
                    st.pop();
                    temp.x = nowX;
                    temp.y = nowY;
                    temp.direction = j;
                    st.push(temp);

                    //將要前往的點放入stack
                    temp.x = tempX;
                    temp.y = tempY;
                    temp.direction = -1;
                    st.push(temp);
                    nowX = tempX;
                    nowY = tempY;

                    //標記已走過
                    arr[nowX][nowY] = st.size();
                    break;
                }
            }

            //若無路可走 跳回上一點
            if (flag) {
                st.pop();
                arr[nowX][nowY] = 0;
                nowX = st.back().x;
                nowY = st.back().y;
            }
        }
    }
    return 0;
}