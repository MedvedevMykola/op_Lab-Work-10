#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
struct List
{
	char data;
	List *next;
}*head;

List *p;
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
					head = new List;
					head->data = ch;
					head->next = NULL;
					p = head;
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
				if (ch == '\r')
					ch = '\n';

				else {
					p->next = new List;
					p = p->next;
					p->data = ch;
					p->next = NULL;
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
	p = head;
	while (p)
	{
		printf("%c\n", p->data);
		p = p->next;
	}

}

int main()
{
	create();
	output();
	_getch();
}

