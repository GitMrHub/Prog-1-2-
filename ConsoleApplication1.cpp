//﻿#include "pch.h"
#include <iostream>
#include <string.h>
#define   MAX 100
#pragma warning(disable : 4996)
using namespace std;

struct Obl {
	char  name[40];
	char  date[12];
	double price;
};

struct Node {
	Obl   a;
	Node *next;
};

Node  *create_list(char name[], char date[], double price);
Node  *add_to_head(Node *h, char name[], char date[], double price);
void   print_list(Node *h);
int    counting(Node *h);
void   delete_element(Node **h);
void   swap_elements(Node **h, int k, int j);
void   create_txt_file(Node*h);

int main() {
	Node  *h = 0;
	int    choice, k, j;
	char   name[40], date[11];
	double  price;
	while (1) {
		printf("1 -> Add to head.\n");
		printf("2->  Print list.\n");
		printf("3 -> Counting the number of items with one delivery date.\n");
		printf("4 -> Delete items with a value higher than specified.\n");
		printf("5 -> Swap places k-th and j-th elements.\n");
		printf("6 -> Create dat-file \n");
		printf("7 -> END.\n");
		printf("Your choice is: ");
		scanf("%d", &choice);
		switch (choice) {
		case(1):
			printf("Enter a name: ");
			scanf("%s", &name);
			printf("Enter a date(xx.xx.xxxx): ");
			scanf("%s", &date);
			printf("Enter a price: ");
			scanf("%lf", &price);
			h = add_to_head(h, name, date, price);
			break;
		case(2):
			print_list(h);
			break;
		case(3):
			printf("Counting the number of items with one delivery date: %d\n", counting(h));
			break;
		case(4):
			delete_element(&h);
			break;
		case(5):
			printf("Enter k and j: \n");
			scanf("%d%d", &k, &j);
			swap_elements(&h, k, j);
			break;
		case(6):
			create_txt_file(h);
			break;
		case(7):
			return 0;
		default:
			return 0;
		}
	}
	return 0;
}

Node *create_list(char name[], char date[], double price) {
	Node *curr = new Node;
	strcpy(curr->a.name, name);
	strcpy(curr->a.date, date);
	curr->a.price = price;
	curr->next = NULL;
	return curr;
}

Node *add_to_head(Node *h, char name[], char date[], double price) {
	if (!h) {
		h = create_list(name, date, price);
		return h;
	}
	Node *curr = new Node;
	curr = create_list(name, date, price);
	curr->next = h;
	return curr;
}

void print_list(Node *h) {
	Node  *curr = h;
	if (!curr) {
		printf("List is empty!\n");
		return;
	}
	while (curr) {
		printf("%s(%s) - %0.2lf\n", curr->a.name, curr->a.date, curr->a.price);
		curr = curr->next;
	}
	return;
}

int counting(Node *h) {
	char  x[MAX], a[] = " ", *t, *b[MAX], *pov[MAX], count=0;
	int   size = 0, j = 0, n, sk, k,  f, d, z=0, pov_count[MAX];
	Node *curr = h, *curr_2 = h;
	if (!curr) {
		printf("List is empty!\n");
		return 0 ;
	}
	if (!curr->next) {
		printf("Only one element!\n");
		return 0;
	}
	while (curr_2) {
		size++;
		curr_2 = curr_2->next;
	}
	strcpy(x, curr->a.date);
	curr = curr->next;
	for (int i = 0; i < size-1; i++) {
		strcat(x, a);
		strcat(x, curr->a.date);
		curr = curr->next;
	}
	t = strtok(x, " ");
	while (t != NULL) {
		b[j] = t;
		j++;
		t = strtok(NULL, " ");
	}
	for (n = 0; n < j; n++) {                                   
		sk = 0;
		f = 0;
		for (k = 0; k < j; k++) {
			if (strcmp(b[n], b[k]) == 0) {
				sk++;
			}
		}
		for (d = 0; d < z; d++) {
			if (strcmp(b[n], pov[d]) == 0) {
				f++;
			}
		}
		if (sk > 1 && f == 0) {
		pov[z] = b[n];
		pov_count[z] = sk;
		z++;
		}
	}
	for (n = 0; n < z; n++) {
		count = count + pov_count[n];
	}
	if (!count) {
		return 0;
	}
	return count;
}

void delete_element(Node **h){
	double  price_2;
	Node  *curr = *h, *prev = *h;
	if (*h==NULL) {
		printf("List is empty!\n");
		return;
	}
	printf("Please, enter a price_max: ");
	scanf("%lf", &price_2);
	while (curr!=NULL) {
		if (curr->a.price > price_2) {
			if (curr == *h) {
				curr = curr->next;
				free(*h);
				*h = curr;
				prev = curr;
			}
			else {
				prev->next = curr->next;
				free(curr);
				curr = prev->next;
			}
		}
		else {
			prev = curr;
			curr = curr->next;
		}
	}
	return;
}

void swap_elements(Node **h, int k, int j) {
	int  i_1=0, i_2=0;
	Node *curr_1 = *h, *curr_2 = *h, *prev_1 = NULL, *prev_2 = NULL;
	if (k == j) {
		return;
	}
	while (curr_1 && (i_1 < k)) {
		prev_1 = curr_1;
		curr_1 = curr_1->next;
		i_1++;
	}
	while (curr_2 && ( i_2 < j)) {
		prev_2 = curr_2;
		curr_2 = curr_2->next;
		i_2++;
	}
	if (curr_1 == NULL || curr_2 == NULL) {
		return;
	}
	if (prev_1 != NULL) {
		prev_1->next = curr_2;
	}
	else {
		*h = curr_2;
	}
	if (prev_2 != NULL) {
		prev_2->next = curr_1;
	}
	else {
		*h = curr_1;
	}
	Node *temp = curr_2->next;
	curr_2->next = curr_1->next;
	curr_1->next = temp;
	return;
}

void   create_txt_file(Node*h) {
	char name_dat[20];
	Node *curr = h;
	FILE * file;
	printf("Enter a name of txt-file(Name.dat): \n");
	scanf("%s", name_dat);
	if (!(file = fopen(name_dat, "wb+"))){
		printf("CANNOT OPEN THE FiLE\n");
		return;
	}
	while (curr) {
		fprintf(file, "%s(%s)- %0.2lf\n", curr->a.name, curr->a.date, curr->a.price);
		curr = curr->next;
	}
	fclose(file);
	return;
}
