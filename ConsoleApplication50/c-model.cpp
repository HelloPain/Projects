#include <stdio.h>
#include <stdlib.h>
struct product
{
	int ID;
	char *name;
	int num;
	float price;
};
void outputList()
{
	FILE *fPtr = NULL;
	struct product pro;
	if ((fPtr = fopen("E:\\commodity.dat", "rb")) == NULL)
	}
}
void Creatdat()//��ʼ��100����¼�����community
{
	FILE *fPtr = NULL;
	struct product blankpro = { 1,"",0,0.0 };
	if (fPtr = fopen("E:\\commodity.dat", "r+b"))
	{
		int i = 0;
		for (; i < 100; i++)
			fwrite(&blankpro, sizeof(struct product), 1, fPtr);
		fclose(fPtr);
		printf("100���ռ�¼�������\n");
	}
	else
		printf("can't open the file!\n");

}
int main()
{
	Creatdat();
	FILE *f;
	struct product pro = { 2,"11",1,1 };
	struct product npro;
	f = fopen("E:\\commodity.dat", "r+b");
	fseek(f, sizeof(struct product)*(pro.ID - 1), SEEK_SET);
	fwrite(&pro, sizeof(struct product), 1, f);
	fread(&npro, sizeof(struct product), 1, f);
	fclose(f);
	outputList();
	printf("%d", npro.ID);
	system("pause");
	return 0;
}