#define _CRT_SECURE_NO_WARNINGS //让scanf函数可用不报错
//#pragma warning(disable:4996)
#pragma warning(disable:6031)//禁用警告提示:" C6031 返回值被忽略："scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#include <stdio.h>
#include <stdbool.h>

#define N 4  // 矩阵的维度

// Z字形查找目标元素
bool searchMatrixZ(int matrix[N][N], int n, int target) 
{
    int row = 0;
    int col = n - 1;

    // 从右上角开始遍历
    while (row < n && col >= 0) 
    {
        if (matrix[row][col] == target)
        {
            return true;  // 找到目标元素
        }
        else if (matrix[row][col] > target)
        {
            col--;  // 向左移动
        }
        else {
            row++;  // 向下移动
        }
    }

    return false;  // 没有找到目标元素
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




// 稳定选择排序
void stableSelectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) 
    {
        int minIndex = i;

        // 找到当前范围内的最小元素
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // 如果找到的最小元素不是当前位置的元素，则插入
        if (minIndex != i)
        {
            int minValue = arr[minIndex];

            // 将最小值插入到当前位置，移动其他元素
            for (int j = minIndex; j > i; j--) 
            {
                arr[j] = arr[j - 1];  // 中间元素后移
            }

            arr[i] = minValue;  // 插入最小值
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