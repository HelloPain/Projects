#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void copy_fliter(char *c1, char *c2)//c1 ���Ƶ�c2,���ҹ��˵�ע��
{
	FILE *c1p = NULL, *c2p = NULL;
	c1p = fopen(c1, "r");
	if (!c1p)//c1p�򲻿�
	{
		printf("can't open file\n");
		return;
	}
	c2p = fopen(c2, "w");
	if (!c2p)
	{
		printf("can't open file\n");
		return;
	}

	int find = 0;//����Ƿ��ҵ�һ��������ע�Ϳ�
	int print = 0;//����Ƿ����printf
	while (!feof(c1p))
	{
		find = 0;
		char c = fgetc(c1p);
		if (c == 'p')//������p,����Ƿ���printf
		{
			char s[5];
			fgets(s, 5, c1p);//���4���ַ�
			fputc(c, c2p);
			fputs(s,c2p);
			c = fgetc(c1p);
		    if (!strcmp("rint", s))//��������strcmp����0
				print = 1;
		}
		if (print&&c == ';')//printf�����ս�
			print = 0;
		if (c == '/'&&!print)//����/����û�г���printf
		{
			c = fgetc(c1p);
			if (c == '/')//������//
			{
				for (; c != '\r'; c = fgetc(c1p));//�ҵ�\r
				find = 1;
			}
			if (c == '*')//������/*
			{
				while (!feof(c1p) && !find)
				{
					for (c = fgetc(c1p); c != '*'&&c != EOF; c = fgetc(c1p));
					if ((c = fgetc(c1p)) == '/')
					{
						c = fgetc(c1p);
						find = 1;//�ҵ�*/��
					}
				}
			}
		}
		if (c >= 0)//c��EOF�����
		{
			if (find == 0)
				fputc(c, c2p);
			else if (c != '\r')//��ֹ��������/r
				fputc(c, c2p);
		}
	}
	fclose(c1p); fclose(c2p);
}
int main()
{
	copy_fliter("C:\\c1.c", "C:\\c2.c");
	system("pause");
	return 0;
}