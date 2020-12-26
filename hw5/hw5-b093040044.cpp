#include <bits/stdc++.h>
using namespace std;

//Author:�����a B093040044
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

//�N��Ʃ�JLinked List��
//�ڪ�Linked List���Ĥ@�Ӹ`�I�O���ʪ�,�ťժ�
//���Ƴ̤j���|��b�ĤG��
void push(node *hd, int co, int ex)
{

    //�q�Y�}�lŪ�� ���n���J����l
    for (node *ptr = hd; ptr != NULL; ptr = ptr->next)
    {
        //���Ƥ�Ҧ�Linked List����Ƥp ��J�̫�@��
        if (ptr->next == NULL)
        {
            node *tmp = new node;
            tmp->next = NULL;
            tmp->coef = co;
            tmp->exp = ex;
            ptr->next = tmp;
            break;
        }

        //���Ƥ�Ҧ�Linked List����Ƥp ��J�Ĥ@�Ӹ`�I���U�@��
        else if (ptr == hd && (ex > ptr->next->exp))
        {
            node *tmp = new node;
            tmp->next = ptr->next;
            tmp->coef = co;
            tmp->exp = ex;
            hd->next = tmp;
            break;
        }

        //���Ƭ۵� �Y�Ƭۥ[
        else if (ex == ptr->next->exp)
        {
            //�ۥ[����s �R���`�I
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

        //���Ƥ�o�@�Ӥp����U�@�Ӥj ���J��Ӹ`�I����
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

//new�@�ӷs��linked List
//�N���LinkedList���Ҧ�����push�i�h �o��ۥ[�����G
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

//new�@�ӷs��linked List
//�N���LinkedList���Ҧ������Y�Ƭۭ�,���Ƭۥ[��push�i�h �o��ۭ������G
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
        //�����{�b���ĴX������
        cnt++;

        //�}�Ҩ��Linked List
        node *headA = new node;
        node *headB = new node;

        int coef, exp;
        headA->next = NULL;
        headB->next = NULL;

        //�N�h����A�s��LinkedList
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

        //�N�h����B�s��LinkedList
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