#define _CRT_SECURE_NO_WARNINGS //��scanf�������ò�����
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//���þ�����ʾ:" C6031 ����ֵ�����ԣ�"scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#include <stdio.h>
#include <stdbool.h>

#define N 4  // �����ά��

// Z���β���Ŀ��Ԫ��
bool searchMatrixZ(int matrix[N][N], int n, int target) 
{
    int row = 0;
    int col = n - 1;

    // �����Ͻǿ�ʼ����
    while (row < n && col >= 0) 
    {
        if (matrix[row][col] == target)
        {
            return true;  // �ҵ�Ŀ��Ԫ��
        }
        else if (matrix[row][col] > target)
        {
            col--;  // �����ƶ�
        }
        else {
            row++;  // �����ƶ�
        }
    }

    return false;  // û���ҵ�Ŀ��Ԫ��
}

int main()
{
    //int matrix[N][N] = 
    //{
    //    {1, 3, 5, 7},
    //    {2, 4, 8, 9},
    //    {6, 10, 12, 13},
    //    {11, 14, 16, 17}
    //};

    //int target = 8;
    //if (searchMatrixZ(matrix, N, target)) 
    //{
    //    printf("Found %d\n", target);
    //}
    //else 
    //{
    //    printf("Not found %d\n", target);
    //}

    return 0;
}




// �ȶ�ѡ������
void stableSelectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) 
    {
        int minIndex = i;

        // �ҵ���ǰ��Χ�ڵ���СԪ��
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // ����ҵ�����СԪ�ز��ǵ�ǰλ�õ�Ԫ�أ������
        if (minIndex != i)
        {
            int minValue = arr[minIndex];

            // ����Сֵ���뵽��ǰλ�ã��ƶ�����Ԫ��
            for (int j = minIndex; j > i; j--) 
            {
                arr[j] = arr[j - 1];  // �м�Ԫ�غ���
            }

            arr[i] = minValue;  // ������Сֵ
        }
    }
}

void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//int main() {
//    int arr[] = { 4, 3, 2, 1, 2 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    printf("Original array: ");
//    printArray(arr, n);
//
//    stableSelectionSort(arr, n);
//
//    printf("Sorted array: ");
//    printArray(arr, n);
//
//    return 0;
//}