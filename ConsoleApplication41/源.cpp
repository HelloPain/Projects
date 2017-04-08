#include <stdio.h>
#include <stdlib.h>
void writeFileFromKeyboard(char * filename){	int account;	char name[30];	float balance;	FILE * fPtr = NULL;	if ((fPtr = fopen(filename, "w")) != NULL)	{//打开文件 		scanf("%d%s%f", &account, name, &balance);		while (!feof(stdin))		{  //组合键ctrl+Z表示文件结束符 			fprintf(fPtr, "%5d%13s%10.2f\n", account, name, balance);			scanf("%d%s%f", &account, name, &balance);		}		fclose(fPtr);  /*关闭文件*/	}//end of if }
int main()
{
	/*FILE *fPtr=NULL;
	char name[30];
	int num = 0;
	if (fPtr = fopen("C:\\text.txt", "w"))
	{
	scanf("%d%s", &num, name);
	while (!feof(stdin))
	{
	fprintf(fPtr, "%5d%13s\n", num, name);
	scanf("%d%s", &num, name);
	}
	}
	fclose(fPtr);*/
	writeFileFromKeyboard("C:\\test.txt");
	system("pause");
	return 0;
}