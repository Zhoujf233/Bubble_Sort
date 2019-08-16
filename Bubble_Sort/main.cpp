//
//  main.cpp
//  Bubble_Sort
//
//  Created by JF Zhou on 2019/8/15.
//  Copyright © 2019 JF Zhou. All rights reserved.
//

#include <iostream>
using namespace std;

//冒泡排序
//void bobble_sort(int* arr,int size)
//{
//    int i,j,temp;
//    for(i = 0;i < size - 1;i++)//一共要排序size-1次
//    {
//        for(j = 0;j < size - 1 - i;j++)//选出该趟排序的最大值往后移
//        {
//            if(arr[j] > arr[j + 1])
//            {
//                temp = arr[j];arr[j] = arr[j + 1];arr[j + 1] = temp;
//            }
//        }
//    }
//}

//冒泡排序优化1
//void bobble_sort(int* arr, int size)
//{
//    int i,j,temp;
//    for(i = 0; i < size - 1; i++)//一共要排序size-1次
//    {
//        //每次遍历标志位都要先置为0，才能判断后面的元素是否发生了交换
//        int flag = 0;
//        for(j = 0; j < size - 1 -i; j++)//选出该趟排序的最大值往后移
//        {
//            if(arr[j] > arr[j + 1])
//            {
//                temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//                flag = 1;//只要有发生了交换，flag就置为1
//            }
//        }
//        if(flag == 0)//判断标志位是否为0，如果为0，说明后面的元素已经有序，就直接return回到主函数
//        {
//            return;
//        }
//    }
//}

//冒泡排序优化2
void bobble_sort(int* arr,int size)
{
    int i,j,temp,k = size - 1,pos = 0;//pos变量用来标记循环里最后一次交换的位置
    for (i = 0; i < size - 1; i++)  //一共要排序size-1次
    {
        //每次遍历标志位都要先置为0，才能判断后面的元素是否发生了交换
        int flag = 0;
        for (j = 0; j < k; j++)//选出该趟排序的最大值往后移动
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;   //只要有发生了交换，flag就置为1
                pos = j;    //循环里最后一次交换的位置 j 赋给pos
            }
        }
        k = pos;
        //判断标志位是否为0，如果为0，说明后面的元素已经有序，就直接return
        if (flag == 0)
        {
            return;
        }
    }
}

int main(int argc, const char * argv[])
{
    int arr[] = {89,22,3,32,82,55,22,50,37,5,64,35,9,70};
    int size = (int) sizeof(arr)/sizeof(*arr);
    int i;
    cout<<"初始顺序为: ";
    for(i = 0;i < size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    bobble_sort(arr, size);
    
    cout << "冒泡排序后顺序为：";
    for(i = 0;i < size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
