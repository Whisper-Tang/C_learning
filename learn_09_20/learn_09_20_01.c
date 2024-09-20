//#define _CRT_SECURE_NO_WARNINGS //让scanf函数可用不报错
////#pragma warning(disable:4996)
//#pragma warning(disable:6031)//禁用警告提示:" C6031 返回值被忽略："scanf" "#
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//定义一个静态的顺序表
#define MaxSize 10
typedef struct
{
	int data[MaxSize];
	int length;
} SqList;

//初始化顺序表
bool InitSqList(SqList* L)
{
	for (int i = 0; i < MaxSize; i++)
	{
		L->data[i] = 0;
	}
	L -> length = 0;
	return true;
}

//线性表(a), a2, as,"…", an)中的元素递增有序且按顺序存储于计算机内,
//要求设计一个算法，完成用最少时间在表中查找数值为x的元素，
//若找到，则将其与后继元素位置相交换，
//若找不到，则将其插入表中并使表中元素仍递增有序。

//1.在顺序表第i个元素后(下标为i)插入一个元素x
bool IsertNextSqlist(SqList *L,int i,int x)	
{
	if (i < 0 || i > L->length || L->length == MaxSize)//i=0时为第一个位置插入；i=表长时为在最末尾插入；表满时无法插入
		return false;			
	//for (int k=0; k <= L->length - 1 - i; k++)	////将顺序表从末尾开始依次向后移动一位，直到第i+1（下标为i）个元素，
	//{
	//	L->data[L->length-k] = L->data[L->length - 1 - k];	//将顺序表从末尾开始依次向后移动一位，直到第i+1个元素，
	//}
	for (int k = L->length - 1; k >= i; k--)	////将顺序表从末尾开始依次向后移动一位，直到第i+1（下标为i）个元素，
	{
		L->data[k+1] = L->data[k];	//将顺序表从末尾开始依次向后移动一位，直到第i+1个元素，
	}
	L->data[i] = x;
	L->length += 1;
	return true;
}

//2.查找数值为x的元素，若找到返回其为第n个元素，若找不到则n为最接近x的数
bool SeachElem(SqList L, int x ,int *n)
{	
	if (0 == L.length)
		return false;
	int mid = 0, left = 0;
	int right = L.length - 1;
	while (left <= right)							//二分查找
	{
		mid = left + (right - left) / 2;
		if (L.data[mid] < x)	//中间的数比x小，x在右边。
		{
			left = mid + 1;		//移动左指针到右边
		}
		else if (L.data[mid] > x)	//中间的数比x小，x在左边。
		{
			right = mid - 1;	//移动右指针到左边
		}
		else
		{
			*n = mid + 1;	//输出x位置
			return true;
		}

	}
	*n = mid + 1;		//输出接近x的位置
	return false;
}

//3.找到若找到，则将其与后继元素位置相交换，
//若找不到，则将其插入表中并使表中元素仍递增有序。
bool findx(SqList* L, int x)
{
	if (L->length == 0)
		return false;
	int n = 0;
	if (SeachElem(*L, x, &n))	//找到若找到,，则将其与后继元素位置相交换，
	{
		if (n = L->length) return true;	//若x为最后一个元素，则无需交换。
		int k = L->data[n - 1];
		L->data[n - 1] = L->data[n];
		L->data[n] = k;
		return true;
	}
	else ////若找不到，则将其插入表中并使表中元素仍递增有序。
	{
		if (L->data[n - 1] < x)	//最相近x的元素（位置n）若比x小，x应插入到他(位置n)之后
		{
			IsertNextSqlist(L, n, x);	//引用后插函数，在n位后插入
			return true;
		}
		else if (L->data[n - 1] > x)	//最相近x的元素（位置n）若比x大，x应插入到他前驱(位置n-1)之后
		{
			IsertNextSqlist(L, n - 1, x);	////引用后插函数，在n-1位后插入
			return true;

		}
		else return false;
	}

}


//bool insertSqList(SqList *L)
//{
//	if (L->length == MaxSize)
//		return false;
//	int i = L-> length;
//	int a = 0;
//	while (i < MaxSize)
//	{
//		sacnf("%d ", a);
//		L->data[i++] = a;
//		L->length++;
//	}	
//	return true;
//}
//	

////测试上述函数是否工作
//int main()
//{
//	SqList L;
//	InitSqList(&L);
//	int x = 0;
//	//scanf("%d %d %d %d %d %d %d ", L.data);
//	for (int i = 0; i < 8; i++)	//在顺序表中存储一些数据
//	{
//		int j = i * 3 + 5;
//		IsertNextSqlist(&L, i, j);
//	}
//
//	for (int i = 0; i < L.length; i++)
//	{
//		printf("%d ", L.data[i]);
//	}
//
//	printf("\n输入x\n");
//	scanf("%d", &x);
//
//	findx(&L, x);	//执行函数测试
//	for (int i = 0; i < L.length; i++)
//	{
//		printf("%d ", L.data[i]);
//	}
//	return 0;
//}







//查找三个均为有序递增无重复序列ABC，中的相同元素，
//二分查找
bool SeachElemX(SqList L, int x )
{
	if (0 == L.length)
		return false;
	int mid = 0, left = 0;
	int right = L.length - 1;
	while (left <= right)							//二分查找
	{
		mid = left + (right - left) / 2;
		if (L.data[mid] < x)
			left = mid + 1;

		else if (L.data[mid] > x)
			right = mid - 1;
		else
			return true;
	}
	return false;
}

//查找三个均为有序递增无重复序列ABC，中的相同元素，
bool TripleSame(SqList A, SqList B, SqList C)
{
	if (0 == A.length|| 0 ==B.length||0 ==C.length)
		return false;
	for (int i = 0; i < A.length; i++)
	{
		if( SeachElemX(B, A.data[i]) )
			if (SeachElemX(C, A.data[i]))
				printf("%d\n", A.data[i]);
	}
	return true;
}
//二分查找的时间复杂度为 O(log n)
//
//总的时间复杂度
//遍历 A 中的元素：O(n)
//每次二分查找在 B 和 C 中查找：O(log n) + O(log n) = O(log n)
//因此，总的时间复杂度为：
//O(n⋅2⋅logn) = O(nlogn)


//双指针（又称为三路归并）的方式来查找相同的元素，将时间复杂度降至O(n)

//**双指针法的思路：**
//	我们可以依次从三个有序数组中取值，通过比较三个数组的当前元素，来决定指针如何移动：
//* 如果当前三个数组的元素相等，说明找到了一个相同的元素，打印并将三个指针都向前移动一位。
//* 如果当前的某一个数组元素小于另一个数组的元素，那么将该数组的指针向前移动一位（因为数组有序，较小的值不可能出现在其它数组的后续部分）。
//* 重复上述步骤，直到某一个数组的指针走到末尾为止。
//实现代码：
void FindCommonElements(int A[], int B[], int C[], int n)
{
	int i = 0, j = 0, k = 0;  // 初始化三个指针

	while (i < n && j < n && k < n) 
	{
		// 如果 A[i], B[j], C[k] 相等，说明找到相同元素
		if (A[i] == B[j] && B[j] == C[k]) {
			printf("%d\n", A[i]);
			i++;
			j++;
			k++;
		}
		// 如果 A[i] 较小，移动 A 数组的指针
		else if (A[i] < B[j]) {
			i++;
		}
		// 如果 B[j] 较小，移动 B 数组的指针
		else if (B[j] < C[k]) {
			j++;
		}
		// 否则移动 C 数组的指针
		else {
			k++;
		}
	}
}

////测试函数
//int main() 
//{
//	int A[] = { 1, 5, 10, 20, 40, 80 };
//	int B[] = { 6, 7, 20, 80, 100 };
//	int C[] = { 3, 4, 15, 20, 30, 70, 80, 120 };
//	int nA = sizeof(A) / sizeof(A[0]);
//	int nB = sizeof(B) / sizeof(B[0]);
//	int nC = sizeof(C) / sizeof(C[0]);
//
//	FindCommonElements(A, B, C, nA < nB ? (nA < nC ? nA : nC) : (nB < nC ? nB : nC)); // 取最小长度
//	return 0;
//}



//现在有两个等长升序序列A和B，试设计一个尽可能高效的算法,
// 找出两个序列A和B的中位数。
//bool FindMid(SqList A, SqList B)
int FindMid(int A[], int B[],int n)
{
	//中位数位于两组数组数据排序后的中间位置，AB等长
	int mid = n/2-1;
	int i, j, k ,mid_count;
	//遍历AB，每记录前mid_count个最小数字
	for (i = j = k = mid_count = 0; i <= mid; i++)
	{
		if (j < n && k < n)
		{
			if (A[j] <= B[k])
				mid_count = A[j++];
			else mid_count = B[k++];
		}		
	}
	return mid_count;
}
//i只遍历一次，时间复杂度O(n)
//辅助空间为定值，空间复杂度O(1)


//寻找数组中的最小正整数（时间复杂度尽可能低）
int FindMin(int A[], int n)
{
	
	/*int min = 0;
	int B[] = {0};
	for (int i = 0; i <= n; i++)
	{
		B[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		if(A[i]>0&& A[i]<=n)
			B[A[i] - 1] = A[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (B[i] == 0)
			return i + 1;
	}
	return n + 1;*/
}


// 函数用于找出数组中的最小缺失正整数
int FindMinGPT(int A[], int n) 
{
	// 进行原地哈希，使得每个 A[i] 处于它应该在的位置 A[i] - 1
	for (int i = 0; i < n; i++) 
	{
		// 当 A[i] 在 1 到 n 的范围内，并且不在正确位置上时，进行交换
		while (A[i] > 0 && A[i] <= n && A[i] != A[A[i] - 1])
		{
			// 交换 A[i] 和 A[A[i] - 1]，把 A[i] 放到它正确的位置上
			int temp = A[A[i] - 1];
			A[A[i] - 1] = A[i];
			A[i] = temp;
		}
	}

	// 再次遍历数组，找到第一个不符合 A[i] == i + 1 的位置
	for (int i = 0; i < n; i++) 
	{
		if (A[i] != i + 1)
		{
			return i + 1; // i + 1 就是缺失的最小正整数
		}
	}

	// 如果数组中的数字恰好是 1 到 n，则缺失的最小正整数是 n + 1
	return n + 1;
}
//该算法不使用额外的数组或递归，只是在原数组 A 上进行操作，因此 空间复杂度为O(1)
//每个元素最多只会被交换一次，因此交换操作的总次数为O(n)
//两次遍历数组的时间复杂度都是O(n)。
//因此，整个算法的 时间复杂度为O(n)。



//// 测试用例
//int main() {
//	int A[] = { 3, 4, -1, 1 }; // 测试用例
//	int n = sizeof(A) / sizeof(A[0]);
//
//	int min_missing = FindMin(A, n);
//	printf("最小缺失的正整数是: %d\n", min_missing); // 输出 2
//
//	return 0;
//}



//从ABC中各取一个数，组成三元数组，
//所有三元数组中两两之间距离之和最小为多少？对应三元数组为？

//计算绝对值
int Abs(int a)
{
	/*if (a < 0)
		return -a;
	else return a;*/
	return a < 0 ? -a : a;
}

// 寻找最小的三元组距离和
int min_a_b_c(int A[], int B[], int C[], int a, int b, int c, int D[])
{
	int i, j, k, d, min_D;
	i = j = k = d = 0;
	// 初始化最小距离
	min_D = Abs(A[i] - B[j]) + Abs(B[j] - C[k]) + Abs(C[k] - A[i]);

	// 遍历三个数组，更新最小距离
	while(i<a && j<b && k<c)
	{
		d = Abs(A[i] - B[j]) + Abs(B[j] - C[k]) + Abs(C[k] - A[i]);

		// 更新最小距离
		if (d < min_D)
		{
			min_D = d;
			D[0] = A[i];
			D[1] = B[j];
			D[2] = C[k];
		}
			
		
		// 根据当前数值大小，移动对应的指针
		if (A[i] < B[j])
			if (A[i] < C[k])	//A<B,A<C,更新A
				i++;
			else k++;	//C<=A<B,更新C
		else if (B[j] < C[k])	//B<=A,B<C,更新B
			j++;
		else k++;	//C<=B<=A,更新C
	}
	return min_D;
}

// 测试函数
int main()
{
	int A[] = { 1, 4, 10 };
	int B[] = { 2, 15, 20 };
	int C[] = { 10, 12 };

	int a = sizeof(A) / sizeof(A[0]);
	int b = sizeof(B) / sizeof(B[0]);
	int c = sizeof(C) / sizeof(C[0]);

	int D[3] = { 0,0,0 };
	int min_D = min_a_b_c(A, B, C, a, b, c, D);

	printf("最小三元数组距离和为：%d\n", min_D);
	printf("对应三元数组为：{ %d，%d，%d }\n", D[0],D[1],D[2]);

	return 0;
}


//int main()
//{
//	return 0;
//}












