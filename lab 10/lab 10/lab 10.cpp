#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
struct List
{
	char data;
	List *next;
	List *previous;
}*head;

List *p;
List *tail;
void create()
{
	char ch;
	int i = 0;
	puts("Enter list of symbols");
	do
	{
		if (i == 0)
		{
			ch = _getch();

			if (ch != 26)
			{
				if (ch == '\r')
					ch = '\n';
				else {
					List *p = new List;
					p->data = ch;
					p->next = NULL;
					p->previous = NULL;
					head = p;
					tail = p;
				}
				printf("%c", ch);
			}
			i = 1;
		}
		else
		{
			ch = _getch();

			if (ch != 26)
			{
				if (ch == '\r' || ch == ' ' || ch == '\t')
					ch = '\n';

				else {

					List *p = new List;
					p->data = ch;
					p->next = NULL;
					p->previous = tail;
					tail->next = p;
					tail = p;
				}
				printf("%c", ch);
			}
			else break;
		}
	} while (true);
	printf("\n");
}
void output()
{
	printf("\n");
	p = head;
	while (p)
	{
		printf("%c\n", p->data);
		p = p->next;
	}

}
char fmax()
{
	char max = 0;
	p = head;
	while (p)
	{
		if (p->data > max)max = p->data;
		p = p->next;
	}
	return max;
}
void change()
{
	char max = fmax();
	p = head;
	if (p->data==max && p->previous == NULL)
		return;
	while (p)
	{		
		if (p->data == max)
		{
			p->previous->next = p->next;
			p->next->previous = p->previous;
			p->next = head;
			p->previous = NULL;
			head->previous = p;
			head = p;
		}
		p = p->next;
	}
}

int main()
{
	create();
	output();
	change();
	output();
	_getch();
}

