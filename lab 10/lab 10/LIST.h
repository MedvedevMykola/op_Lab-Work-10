#pragma once
#include "stdafx.h"
#include <stdio.h>
#include <conio.h>

struct List
{
	char data;
	List *next;
	List *previous;
};


void create();
void output();
char fmax();
void change();