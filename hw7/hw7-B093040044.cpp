#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;
//Author:蔡明軒 B093040044
//Date:Dec.2.2020
//Sort Compare
//有10組測資 分別為100 500 1000 5000 10000 50000 100000 500000 1000000 5000000
int arr[5000005];

//Qsort的比較函式
int cmp(const void *a, const void *b)
{
    int a1 = *(int *)a;
    int b1 = *(int *)b;
    if (a1 < b1)
    {
        return -1;
    }
    else if (a1 == b1)
    {
        return 0;
    }
    else
        return 1;
}
void SelectionSort(int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}
void QuickSort(int left, int right)
{
    if (left < right)
    {
        int pivot = arr[(left + right) / 2];
        int i = left - 1, j = right + 1;
        while (i < j)
        {
            do
                ++i;
            while (arr[i] < pivot);
            do
                --j;
            while (arr[j] > pivot);
            if (i < j)
                swap(arr[i], arr[j]);
        }
        QuickSort(left, i - 1);
        QuickSort(j + 1, right);
    }
}
void Heapify(int n, int i)
{
    int big = i;
    int lc = 2 * i + 1;
    int rc = 2 * i + 2;

    if (lc < n && arr[lc] > arr[big])
        big = lc;

    if (rc < n && arr[rc] > arr[big])
        big = rc;

    if (big != i)
    {
        swap(arr[i], arr[big]);
        Heapify(n, big);
    }
}

void HeapSort(int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        Heapify(i, 0);
    }
}
int main()
{
    //input
    ifstream ifile;

    //output
    fstream file;

    clock_t start, end;
    ifile.open("input.txt", ios::in);

    //選擇一種sort
    cout << "SelectionSort:1\nHeapSort:2\nQuickSort:3\nqsort:4\nSTL sort:5\n";
    int mode;
    cin >> mode;
    if (mode == 1)
    {
        file.open("outputA.txt", ios::out);
        file << "SelectionSort\n";
    }
    else if (mode == 2)
    {
        file.open("outputB.txt", ios::out);
        file << "HeapSort\n";
    }
    else if (mode == 3)
    {
        file.open("outputC.txt", ios::out);
        file << "QuickSort\n";
    }
    else if (mode == 4)
    {
        file.open("outputD.txt", ios::out);
        file << "Qsort\n";
    }
    else if (mode == 5)
    {
        file.open("outputE.txt", ios::out);
        file << "C++ STL Sort\n";
    }

    for (int i = 0; i < 10; i++)
    {
        int amount;
        ifile >> amount;
        for (int j = 0; j < amount; j++)
        {
            ifile >> arr[j];
        }
        double time;
        start = clock();
        if (mode == 1)
            SelectionSort(amount);
        else if (mode == 2)
            HeapSort(amount);
        else if (mode == 3)
            QuickSort(0, amount - 1);
        else if (mode == 4)
            qsort((void *)arr, amount, sizeof(arr[0]), cmp);
        else if (mode == 5)
            sort(arr, arr + amount);
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        printf("%d datas, Run Time:%.4lfs\n", amount, time);
        for (int j = 0; j < amount; j++)
        {
            file << arr[j] << '\n';
        }
    }
    file.close();
    ifile.close();
    return 0;
}