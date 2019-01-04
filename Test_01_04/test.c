/*
date：2019/01/04
author:BetterMe1
program:杨氏矩阵、调整数组使奇数全部位于偶数前面
compiler:Visual Studio 2013
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
1.调整数组使奇数全部都位于偶数前面。
题目：
输入一个整数数组，实现一个函数，
来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
所有偶数位于数组的后半部分。
*/

//分析：将数组的第一个数作为基数，其后遇到奇数插在其前面;并记住这个奇数插入的坐标，下次遇到奇数插在上一个奇数的前面
//void Font_odd(int arr[],int n){
//	int t = 0;
//	int t2 = 0;
//	int j = 0;
//	for (int i = 1; i < n;i++){//将第一个数作为基数，遇到奇数插在其前面，
//		t = arr[i];//带插入的数
//		if (t % 2){
//			for (j = i; j>t2; j--){
//				arr[j] = arr[j - 1];//前一个元素往后移
//				arr[j - 1] = t;//插入新元素
//			}
//			t2 = j;//记录此时的下标
//		}
//	}
//}
//int main(){
//	int n = 0;
//	int arr[1000] = { 0 };
//	printf("请输入需要调整的数的长度：");
//	scanf("%d", &n);
//	printf("请输入数据：");
//	for (int i = 0; i < n; i++){
//		scanf("%d", &arr[i]);
//	}
//	Font_odd(arr,n);//调整顺序
//	//打印数组内容
//	printf("调整后的数据为：");
//	for (int i = 0; i < n; i++){
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//    system("pause");
//    return 0;
//}


/*
2.
杨氏矩阵
有一个二维数组.
数组的每行从左到右是递增的，每列从上到下是递增的.
在这样的数组中查找一个数字是否存在。
时间复杂度小于O(N);
数组：
1 2 3
2 3 4
3 4 5
*/


/*
分析：
Step - wise线性搜索算法：
从数组的右上角开始比较，若搜索值大于右上角的值，则排除一行，若搜索值小于右上角的值，则排除一列，等于便返回该值，
此算法的额时间复杂度为O(N)，最坏情况下从右上角查询到左下角。
如下图在数组中查询15，右上角17大于15，因此排除右边一列，在对比10,10小于15，排除上边一行，再次对比12，依次下去。
*/
int StepWise(int arr[100][100],int row,int col,int target){
	//判断是否小于数组中最小的值或大于数组中最大的值
	if (target <arr[0][0]||target > arr[row - 1][col - 1]){
		return 0;
	}
	int i = 0;//从第0行开始
	int j = col - 1;//从最后一列开始
	while (i < row && j >= 0){
		if (target > arr[i][j]){
			i++;//排除前一行
		}
		else if (target < arr[i][j]){
			j--;//排除后一列
		}
		else{
			return 1;
		}
	}
	return 0;//循环执行完毕仍没找到
}
int main(){
	int row = 0;
	int col = 0;
	int target = 0;
	printf("请输入数组的行长度、列长度：");
	scanf("%d %d", &row, &col);
	int arr[100][100] = { 0 };
	printf("请输入数组内容：\n");
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	printf("请输入需要搜索的值：");
	scanf("%d", &target);
	if (StepWise(arr, row, col, target)){
		printf("%d存在于数组中。\n", target);
	}
	else{
		printf("%d不存在于数组中。\n", target);
	}
    system("pause");
	return 0;
}