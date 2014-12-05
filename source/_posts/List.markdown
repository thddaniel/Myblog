---
layout: post
title: "链表"
date: 2014-12-05 9:18
comments: true
tags: 
	- 数据结构
---
打算重新学下数据结构和算法。
**时间**：12月底初步完成。
**目标**：当面临数据结构和算法时，能立马想到特定的行为或者操作以及一些属性。例如，链表,立马想到插入、移除、遍历和计算元素个数等操作，和指针域、数据域等属性。
**资源**：书籍《算法精解》,《leetcode-C++》 网站：[hackerRank](https://www.hackerrank.com/)

最常用的**数据结构**有：链表、栈、队列、集合、哈希表、树、堆、优先级队列和图。
**算法**分类：
1. 随机法：依赖于随机数的统计特性。例如：快速排序。
2. 分治法：分解、求解、合并。例如：归并排序。
3. 动态规划：与分治法类似，将大问题分解为子问题最后将结果合并。在动态规划中，子问题之间并不是独立的，是相关联的。
4. 贪心法：不是从整体最优上考虑， 而仅仅是在某种意义上的**局部最优解**。例如：霍夫曼编码。
5. 近似法：只计算出“足够好”的解，并不计算出最优解。 例如：推销员问题

使用数据结构和算法的原因：1.效率 2.抽象 3.重用率
开发应用软件的良好准则：1.模块化 2.可读性 3.简洁性 4.一致性 

##链表##
分类：单链表、双向链表、循环链表
应用：邮件列表、滚动列表、内存管理、以及其他数据结构等

```c
typedef struct ListElmt_ 
{   /*链表元素数据结构*/
	void *data;
	struct ListElmt_ *next;	
	//双向链表多一个指向前结点的指针（*prev）
}ListElmt;

typedef struct List_ 
{   /*链表数据结构*/
	int size; //链表中元素个数
	ListElmt *head; //指向链表中头结点元素的指针
	ListElmt *tail; //指向链表中末尾结点元素的指针,若是循环链表删除这个。
	
	/*封装之后传递给list_init函数的析构函数,如果链表包含采用malloc动态分配的数据，当链表被销毁时，destroy应该设置为free 用来释放数据。*/
	void (*destroy)(void *data);
}List;
```

```c
void list_init(List *list, void (*destroy)(void *data))
{   /*初始化链表*/

	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	list->destroy = destroy;
}

int list_ins_next(List *list, ListElmt *element, const void *data)
{   /*将一个元素插入element元素之后*/
	ListElmt *new_element;
	if ((new_element =(ListElmt *)malloc(sizeof(ListElmt)))==NULL)//动态分配链表元素（结点）
		return -1;

	new_element->data = (void *)data; 
	
	if (element == NULL){ //增加头结点
		new_element->next = list->head;
		list->head = new_element;

		if(list->size == 0)
			list->tail = list->head;
	}
	else{
	    /*插入其他位置*/
		new_element->next = element->next;
		element->next = new_element;

		if(element->next == NULL)
			list->tail = new_element;
	}

	list->size++;
	return 0;
}

int list_rem_next(List *list, ListElmt *element, void **data)	
{   /*移除element之后的那个结点，data将指向已移除结点的数据域*/
	ListElmt *old_element;
	if (list->size == 0)
		return -1;
	if (element == NULL){//移除头结点
		*data = list->head->data; 
		old_element = list->head;
		list->head = list->head->next;

		if(list->size == 1)
			list->tail = NULL;
	}
	else{ 
		if (element->next == NULL) //element如果是尾结点，返回-1.
			return -1;
		//删除其他位置结点
		*data = element->next->data;
		old_element = element->next;
		element->next = old_element->next;
		if(element->next == NULL)//更新尾结点
			list->tail = element;
	}

	free(old_element);//释放掉链表元素（结点），但是结点指向的数据域还没释放掉（如果该数据是动态分配的话）
	list->size--;
	return 0;
}

void list_destroy(List *list)
{   /*移除链表中所有的元素*/
	void *data;

	while(list->size > 0){
		if(list_rem_next(list,NULL,(void **)&data)==0 && list->destroy != NULL){
            /*list_rem_next函数调用返回后，data将指向已移除结点的数据域，如果当初那个数据域是动态分配的，那么应该用free释放掉*/
			list->destroy(data);
		}
	}

	memset(list,0,sizeof(List));
}

```