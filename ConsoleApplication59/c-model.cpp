#include <stdio.h>
#include <stdlib.h>
void writeFileFromKeyboard(char * filename){	char s[100];	FILE * fPtr = NULL;	if ((fPtr = fopen(filename, "w")) != NULL)	{//���ļ� 		fgets(s, sizeof(s), stdin); // �Ӽ��̶�ȡһ���ַ� //���س�		while (!feof(stdin) )		{			fputs(s, fPtr); //��һ���ַ�д���ļ��� 			fgets(s, sizeof(s), stdin);		}		fclose(fPtr);	} //end of if}
int main()
{
	writeFileFromKeyboard("E:\\test2.txt");
	system("pause");
	return 0;
}