#include <bits/stdc++.h>
using namespace std;

//Author:蔡明軒 B093040044
//Date:Oct.22.2020
//Poly ADD & MULTIPLY

//LinkedList
struct node
{
    int coef;
    int exp;
    node *next = NULL;

    node *operator+(node *b);
    node *operator*(node *b);
};

//將資料放入Linked List中
//我的Linked List的第一個節點是不動的,空白的
//指數最大的會放在第二個
void push(node *hd, int co, int ex)
{

    //從頭開始讀取 找到要插入的位子
    for (node *ptr = hd; ptr != NULL; ptr = ptr->next)
    {
        //指數比所有Linked List的資料小 放入最後一個
        if (ptr->next == NULL)
        {
            node *tmp = new node;
            tmp->next = NULL;
            tmp->coef = co;
            tmp->exp = ex;
            ptr->next = tmp;
            break;
        }

        //指數比所有Linked List的資料小 放入第一個節點的下一個
        else if (ptr == hd && (ex > ptr->next->exp))
        {
            node *tmp = new node;
            tmp->next = ptr->next;
            tmp->coef = co;
            tmp->exp = ex;
            hd->next = tmp;
            break;
        }

        //指數相等 係數相加
        else if (ex == ptr->next->exp)
        {
            //相加等於零 刪除節點
            if ((co + ptr->next->coef) == 0)
            {
                delete ptr->next;
                ptr->next = ptr->next->next;
            }
            else
            {
                ptr->next->coef += co;
            }
            break;
        }

        //指數比這一個小但比下一個大 插入兩個節點中間
        else if (ex < ptr->exp && ex > ptr->next->exp)
        {
            node *tmp = new node;
            tmp->next = ptr->next;
            tmp->coef = co;
            tmp->exp = ex;
            ptr->next = tmp;
            break;
        }
    }
}

//new一個新的linked List
//將兩個LinkedList的所有元素push進去 得到相加的結果
node *node::operator+(node *b)
{
    node *res = new node;
    for (node *ptr = this->next; ptr != NULL; ptr = ptr->next)
    {
        push(res, ptr->coef, ptr->exp);
    }
    for (node *ptr = b->next; ptr != NULL; ptr = ptr->next)
    {
        push(res, ptr->coef, ptr->exp);
    }
    return res;
}

//new一個新的linked List
//將兩個LinkedList的所有元素係數相乘,指數相加後push進去 得到相乘的結果
node *node::operator*(node *b)
{
    node *res = new node;
    for (node *ptr = this->next; ptr != NULL; ptr = ptr->next)
    {
        for (node *ptr2 = b->next; ptr2 != NULL; ptr2 = ptr2->next)
        {
            push(res, ptr->coef * ptr2->coef, ptr->exp + ptr2->exp);
        }
    }
    return res;
}

int main()
{
    int P, Q, cnt = 0;
    while (cin >> P)
    {
        //紀錄現在為第幾筆測資
        cnt++;

        //開啟兩個Linked List
        node *headA = new node;
        node *headB = new node;

        int coef, exp;
        headA->next = NULL;
        headB->next = NULL;

        //將多項式A存至LinkedList
        for (int i = 0; i < P; i++)
        {
            cin >> coef >> exp;
            push(headA, coef, exp);
        }

        cin >> Q;
        if (P == 0 && Q == 0)
        {
            break;
        }

        //將多項式B存至LinkedList
        for (int i = 0; i < Q; i++)
        {
            cin >> coef >> exp;
            push(headB, coef, exp);
        }
        node *plus = (*headA + headB);
        node *star = (*headA * headB);

        //Output
        printf("Case%d:\nADD\n", cnt);
        if (plus->next == NULL)
        {
            printf("0 0\n");
        }
        else
        {
            for (node *ptr = plus->next; ptr != NULL; ptr = ptr->next)
            {
                printf("%d %d\n", ptr->coef, ptr->exp);
            }
        }
        printf("MULTIPLY\n");
        if (star->next == NULL)
        {
            printf("0 0\n");
        }
        else
        {
            for (node *ptr = star->next; ptr != NULL; ptr = ptr->next)
            {
                printf("%d %d\n", ptr->coef, ptr->exp);
            }
        }
    }
    return 0;
}