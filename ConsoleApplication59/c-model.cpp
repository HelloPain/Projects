#include <stdio.h>
#include <stdlib.h>
void writeFileFromKeyboard(char * filename){	char s[100];	FILE * fPtr = NULL;	if ((fPtr = fopen(filename, "w")) != NULL)	{//打开文件 		fgets(s, sizeof(s), stdin); // 从键盘读取一行字符 //读回车		while (!feof(stdin) )		{			fputs(s, fPtr); //将一行字符写入文件中 			fgets(s, sizeof(s), stdin);		}		fclose(fPtr);	} //end of if}
int main()
{
	writeFileFromKeyboard("E:\\test2.txt");
	system("pause");
	return 0;
}