#include <stdio.h>
#include <stdlib.h>
void Task1(char *s)//统计大写字母，小写字母，数字，其他
{
	FILE *f = NULL;
	char ch;
	int cap=0,  low=0,  dig=0,  oth=0;
	if (f = fopen(s, "r"))
	{
		while (!feof(f))
		{
			ch = fgetc(f);
			if (ch <= 'Z'&&ch >= 'A')
				cap++;
			else if (ch <= 'z'&&ch >= 'a')
				low++;
			else if (ch <= '9'&&ch >= '0')
				dig++;
			else
				oth++;
		}
		//扫描完成
		printf("Task1:\ncapital:%d\nlowercase:%d\ndigit:%d\nothers:%d\n\n",cap,low,dig,oth);
	}
	else
	{
		printf("the file can't be opened!\n");
	}
}

void Task2(char *s)//统计行数，行最大长度，行最小长度
{
	FILE *f = NULL;
	int now = 0, max = -1, min = 1e6, line =0;//当前行长度, 行最大，行最小，行数
	char ch;
	if (f = fopen(s, "r"))
	{
		while (!feof(f))
		{
			ch = fgetc(f);
			if (ch != '\n')
				now++;
			else
			{
				line++;
				max = now > max ? now : max;
				min = now < min ? now : min;
				now = 0;
			}
		}
		//扫描完成
		printf("Task2:\nline:%d\n%d characters in max line.\n%d characters in min line.\n\n",line,max,min);
	}
	else
		printf("the file can't be opened!\n");
}

void Task3(char *s)//统计具体英文字符的数量
{
	FILE *f = NULL;
	char ch;
	int cap[26] = { 0 }, low[26] = { 0 };//存储字符的个数
	if (f = fopen(s, "r"))
	{
		while (!feof(f))
		{
			ch = fgetc(f);
			if (ch <= 'Z'&&ch >= 'A')
				cap[ch - 'A']++;
			else if (ch <= 'z'&&ch >= 'a')
				low[ch = 'a']++;
		}
		//扫描完成
		printf("CAPITAL:\n");
		for (int i = 0; i < 26; i++)
			printf("%c:%d%c", 'A' + i, cap[i],(i+1)%4?'\t':'\n');
		printf("\n");
		printf("LOWERCASE:\n");
	    for (int i = 0; i < 26; i++)
			printf("%c:%d%c", 'a' + i, cap[i], (i + 1) % 4 ? '\t' : '\n');
		printf("\n");
	}
	else
		printf("the file can't be opened!\n");
}
int main()
{
	char *s;
	s = "E:\\test.txt";
	Task1(s);
	Task2(s);
	Task3(s);
	system("pause");
	return 0;
}