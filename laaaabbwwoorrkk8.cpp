#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include<iostream>
#include <conio.h>



int compare(char** str, int k, int j);
int sum(char** str, int k);

int compare(char** str, int k, int j)
{

	while (*(*(str + k - 1) + j) == *(*(str + k) + j) && *(*(str + k - 1) + j) != '\0' && *(*(str + k) + j) != '\0')
	{
		j++;
	}

	return(*(*(str + k - 1) + j) - *(*(str + k) + j));
}


int sum(char** str, int k)
{
	int j = 0;
	int f = 0;
	int s = 0;
	int p = 0;
	while (*(*(str + k) + j) != '\0' || *(*(str + k) + j) > 57 || (*(*(str + k) + j) == ' '))
	{
		j++;
	}
	while (*(*(str + k) + j) != '\0')
	{
		while (*(*(str + k) + j) != ' ' && *(*(str + k) + j) != '\0')
		{
			s = s * 10 + *(*(str + k) + j);
			j++;
		}
		p = p + s;
		s = 0;

		while (*(*(str + k) + j) == ' ' && *(*(str + k) + j) != '\0')
			j++;

	}


	return(p);
}


int main()
{
	
	int n, m, i, j;
	char** str;
	char* temp;
	printf("Enter amount of lines: ");
	scanf_s("%d", &n);
	printf("Enter lenght of lines: ");
	scanf_s("%d", &m);

	str = (char**)calloc(n, sizeof(char*));
	if (str == NULL)
	{
		printf("/nThere is no free memory");
		return 0;
	}


	for (int i = 0; i < n; i++)
	{
		*(str + i) = (char*)malloc(m * sizeof(char));
		fflush(stdin);

		printf("\n\tEnter line:", i);
		gets_s(*(str + i), m);

	}
	printf("\n\tEnter values:");

	for (int i = 1; i < n; i++)
	{
		printf("\n\n\t%s", *(str + i));
	}


	for (i = 1; i < n - 1; i++) 
	{
		for (int k = n - 1; k > i; k--)
		{
			j = 0;
			if (compare(str, k, j) > 0)
			{
				temp = *(str + k);
				*(str + k) = *(str + k - 1);
				*(str + k - 1) = temp;
			}

		}

	}
	printf("\n\tConclusion results:");

	for (int i = 0; i < n; i++)
	{
		printf("\n\n\t%s", *(str + i));
	}

	printf("\n\tSorting wages:");
	for (i = 1; i < n - 1; i++) 
	{
		for (int k = n - 1; k > i; k--)
		{
			if (sum(str, k) < sum(str, k - 1))
			{
				temp = *(str + k);
				*(str + k) = *(str + k - 1);
				*(str + k - 1) = temp;
			}


		}

	}
	printf("\n\tConclusion of sorting wages:");

	for (int i = 0; i < n; i++)
	{
		printf("\n\n\t%s", *(str + i));
	}
	return (0);

}
