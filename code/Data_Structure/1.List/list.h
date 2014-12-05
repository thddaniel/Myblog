#ifndef LIST_H
#define LIST_H

typedef struct ListElmt_ {

	void *data;
	struct ListElmt_ *next;	
}ListElmt;

typedef struct List_ {

	int size;
	ListElmt *head;
	ListElmt *tail;
	int (*match)(const void *key1, const void *key2);
	void (*destroy)(void *data);
}List;

#endif