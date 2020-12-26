#include <iostream>
#include <string.h>
using namespace std;

//Author:蔡明軒 B093040044
//Date:Sep.16.2020
//set&operator overloading

struct Set
{

    bool element[256];

    //聯集
    Set operator+(const Set &a)
    {
        Set result;
        for (int i = 0; i < 256; i++)
        {
            result.element[i] = this->element[i] | a.element[i];
        }
        return result;
    }

    //差集
    Set operator-(const Set &a)
    {
        Set result;
        for (int i = 0; i < 256; i++)
        {
            result.element[i] = this->element[i] & !a.element[i];
        }
        return result;
    }

    //交集
    Set operator*(const Set &a)
    {
        Set result;
        for (int i = 0; i < 256; i++)
        {
            result.element[i] = this->element[i] & a.element[i];
        }
        return result;
    }

    //一集合是否包含另一集合
    bool operator>=(const Set &a)
    {
        bool flag = true;
        for (int i = 0; i < 256; i++)
        {
            if (a.element[i] == true)
            {
                if (this->element[i] == false)
                {
                    flag = false;
                    break;
                }
            }
        }
        return flag;
    }
};

//建立A,B兩集合
Set setA, setB;

int main()
{
    //輸入測資數
    int datanum;
    cin >> datanum;
    for (int i = 1; i <= datanum; i++)
    {
        //重製A,B集合
        memset(setA.element, false, sizeof(setA.element));
        memset(setB.element, false, sizeof(setB.element));
        //讀入資料
        string dataA, dataB;
        char target;
        getchar();
        getline(cin, dataA);
        getline(cin, dataB);
        cin >> target;
        //將資料輸入集合
        for (int j = 0; j < dataA.size(); j++)
        {
            setA.element[dataA[j]] = true;
        }
        for (int j = 0; j < dataB.size(); j++)
        {
            setB.element[dataB[j]] = true;
        }
        //輸出此為第i筆測資
        cout << "Test Case " << i << ":" << endl;

        //輸出A集合
        cout << "A: {";
        for (int j = 0; j < 256; j++)
        {
            if (setA.element[j] == true)
            {
                cout << char(j);
            }
        }
        cout << "}" << endl;

        //輸出B集合
        cout << "B: {";
        for (int j = 0; j < 256; j++)
        {
            if (setB.element[j] == true)
            {
                cout << char(j);
            }
        }
        cout << "}" << endl;

        //輸出A,B之聯集
        Set unions = (setA + setB);
        cout << "A+B: {";
        for (int j = 0; j < 256; j++)
        {
            if (unions.element[j] == true)
            {
                cout << char(j);
            }
        }
        cout << "}" << endl;

        //輸出A,B之交集
        Set intersects = (setA * setB);
        cout << "A*B: {";
        for (int j = 0; j < 256; j++)
        {
            if (intersects.element[j] == true)
            {
                cout << char(j);
            }
        }
        cout << "}" << endl;

        //輸出A對B的差集
        Set AsubB = (setA - setB);
        cout << "A-B: {";
        for (int j = 0; j < 256; j++)
        {
            if (AsubB.element[j] == true)
            {
                cout << char(j);
            }
        }
        cout << "}" << endl;

        //輸出B對A的差集
        Set BsubA = (setB - setA);
        cout << "B-A: {";
        for (int j = 0; j < 256; j++)
        {
            if (BsubA.element[j] == true)
            {
                cout << char(j);
            }
        }
        cout << "}" << endl;

        //輸出A是否包含B
        if (setA >= setB)
        {
            cout << "A contains B";
        }
        else
        {
            cout << "A does not contain B";
        }
        cout << endl;

        //輸出B是否包含A
        if (setB >= setA)
        {
            cout << "B contains A";
        }
        else
        {
            cout << "B does not contain A";
        }
        cout << endl;

        //輸出A是否包含target
        cout << "'" << target << "' is ";
        if (setA.element[target] == true)
        {
            cout << "in A";
        }
        else
        {
            cout << "not in A";
        }
        cout << endl;

        //輸出B是否包含target
        cout << "'" << target << "' is ";
        if (setB.element[target] == true)
        {
            cout << "in B";
        }
        else
        {
            cout << "not in B";
        }
        cout << endl;

        cout << endl;
    }
    return 0;
}