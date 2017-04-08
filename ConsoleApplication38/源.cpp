#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void copy_fliter(char *c1, char *c2)//c1 复制到c2,并且过滤掉注释
{
	FILE *c1p = NULL, *c2p = NULL;
	c1p = fopen(c1, "r");
	if (!c1p)//c1p打不开
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

	int find = 0;//标记是否找到一个完整的注释块
	int print = 0;//标记是否出现printf
	while (!feof(c1p))
	{
		find = 0;
		char c = fgetc(c1p);
		if (c == 'p')//若出现p,检测是否是printf
		{
			char s[5];
			fgets(s, 5, c1p);//获得4个字符
			fputc(c, c2p);
			fputs(s,c2p);
			c = fgetc(c1p);
		    if (!strcmp("rint", s))//如果相等则strcmp返回0
				print = 1;
		}
		if (print&&c == ';')//printf语句的终结
			print = 0;
		if (c == '/'&&!print)//出现/并且没有出现printf
		{
			c = fgetc(c1p);
			if (c == '/')//遇到了//
			{
				for (; c != '\r'; c = fgetc(c1p));//找到\r
				find = 1;
			}
			if (c == '*')//遇到了/*
			{
				while (!feof(c1p) && !find)
				{
					for (c = fgetc(c1p); c != '*'&&c != EOF; c = fgetc(c1p));
					if ((c = fgetc(c1p)) == '/')
					{
						c = fgetc(c1p);
						find = 1;//找到*/了
					}
				}
			}
		}
		if (c >= 0)//c是EOF则不输出
		{
			if (find == 0)
				fputc(c, c2p);
			else if (c != '\r')//防止输出多余的/r
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