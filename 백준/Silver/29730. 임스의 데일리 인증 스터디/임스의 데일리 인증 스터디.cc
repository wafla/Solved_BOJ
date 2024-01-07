#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Study
{
	char name[101];
	int BJ;
	int BJnum;
}Study;

int compare(const void* num1, const void* num2)
{
	return ((Study*)num1)->BJ - ((Study*)num2)->BJ;
}

int compare0(const void* num1, const void* num2)
{
	if (strlen(((Study*)num1)->name) == strlen(((Study*)num2)->name))
	{
		return strcmp(((Study*)num1)->name, ((Study*)num2)->name);
	}
	else
	{
		return strlen(((Study*)num1)->name) - strlen(((Study*)num2)->name);
	}
}

int compare1(const void* num1, const void* num2)
{
	return ((Study*)num1)->BJnum - ((Study*)num2)->BJnum;
}
int main(void)
{
	int num = 0, count0 = 0, count1 = 0;
	scanf("%d", &num);
	getchar();
	Study* ary = (Study*)malloc(sizeof(Study) * (num + 1));
	for (int i = 0; i < num; i++)
	{
		fgets(ary[i].name, 102, stdin);
		ary[i].name[strcspn(ary[i].name, "\n")] = '\0';
		ary[i].BJ = 0; ary[i].BJnum = 0;
		if (strncmp(ary[i].name, "boj.kr/", 7) == 0)
		{
			int count = 0;
			for (int j = 7; ary[i].name[j] != '\0'; j++)
			{
				if (!isdigit((unsigned char)ary[i].name[j]))
				{
					count++;
					break;
				}
			}
			if (count == 0)
			{
				if (atoi(ary[i].name + 7) >= 1 && atoi(ary[i].name + 7) <= 30000)
				{
					ary[i].BJ = 1;
					ary[i].BJnum = atoi(ary[i].name + 7);
				}
				else
				{
					ary[i].BJ = 0;
				}
			}
			else
			{
				ary[i].BJ = 0;
			}
		}
		if (ary[i].BJ == 0)
		{
			count0++;
		}
		else if (ary[i].BJ == 1)
		{
			count1++;
		}
	}
	qsort(ary, num, sizeof(Study), compare);
	qsort(ary, count0, sizeof(Study), compare0);
	qsort(ary + count0, count1, sizeof(Study), compare1);
	for (int i = 0; i < num; i++)
	{
		printf("%s\n", ary[i].name);
	}
	free(ary);
}
// 제출번호 71303663 테스트