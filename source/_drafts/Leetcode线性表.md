---
layout: post
title: "Leetcode线性表"
comments: true
tags: 
	- 数据结构
---

#数组
##Remove Duplicates from Sorted Array**题目1：**
给定一个已经排序好的数组，删除重复出现的元素，返回新的数组长度。不要定义新的数组，在原来的数组上完成。
**代码：**

```c++
class Solution{
public:
	int removeDuplicates(int A[], int n){
		if (n < 0)	return -1;
		if (n <= 1) return n;
		
		int index = 0; //记录数组的下标号
		for (int i = 1; i < n; i++){
			if (A[index] != A[i])
				A[++index] = A[i];
		}
		return index;
	}
};
```


**题目2：**

在上题的基础上，加上一条件：重复次数最多两次。

**分析：**

这题因为是已经排序的数组,所以一个变量即可解决。如果是没有排序的数组,则需要引入一个 hashmap 来记录出现次数。

**代码：**

```c++
class Solution{
public:
	int removeDuplicates(int A[], int n){
		if (n < 0)	return -1;
		if (n <= 2 ) return n;
		
		int index = 2;
		for (int i = 2; i < n; i++){
			if (A[index-2] != A[i])
				A[index++] = A[i];//执行完这行后 index自加1；
		}
		return index;
	}
};
```        

##Search in Rotated Sorted Array                                                              


