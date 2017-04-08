#include <stdio.h>
#include <stdlib.h>
struct product
{
	int ID;
	char *name;
	int num;
	float price;
};
void Creatdat()//初始化100条记录存放在community
{
	FILE *fPtr = NULL;
	struct product blankpro = { 0,"",0,0.0 };
	if (fPtr=fopen("E:\\commodity.dat", "wb"))
	{
		int i = 0;
		for (; i < 100; i++)
			fwrite(&blankpro, sizeof(struct product), 1, fPtr);
		fclose(fPtr);
		printf("100条空记录创建完毕\n");
	}
	else
		printf("can't open the file!\n");
	return;
}

void First_Write()//初始化录入
{
	struct product npro;
	FILE *fPtr = NULL;
	if (fPtr = fopen("E:\\commodity.dat", "rb+"))
	{
			printf("请输入商品信息[ID为-1代表输入结束]：\n");
			char info[50]; char *p = info;
			scanf("%[^\n]", info);
			while (*p != '-')
			{
				for (p = info; (*p)>'9' || (*p)<'1'; p++);
				npro.ID = atoi(++p);//ID
				getchar();
				scanf("%[^\n]", info);
				for (p = info; (*p) > 'Z' || (*p) < 'A'; p = p + 2);
				npro.name = p;//name
				getchar();
				scanf("%[^\n]", info);
				for (p = info; (*p)>'9' || (*p)<'1'; p++);
				npro.num = atoi(p);//数量
				getchar();
				scanf("%[^\n]", info);
				for (p = info; (*p)>'9' || (*p)<'1'; p++);
				npro.price = atof(++p);
				getchar();
				//一条信息录入完毕
				printf("请输入商品信息[ID为-1代表输入结束]：\n");
				scanf("%[^\n]", info);
				p = info;
			}	
		printf("商品信息输入结束\n");
	}
	else
		printf("can't open the file\n");
	return;
}
void Output_record(int list)
{
	//printf("记录号（商品ID）\t\t商品名\t\t数量\t\t价格\n");
	FILE *fPtr;
	struct product pro;
	if (fPtr = fopen("E:\\commodity.dat", "wr"))
	{
		fPtr = fseek(fPtr, (list - 1) * sizeof(struct product), SEEK_SET);//找到当前记录
		fread(&pro, sizeof(struct product), 1, fPtr);
		printf("%-10d%-10s%-10d%-10f\n", pro.ID, pro.name, pro.num, pro.price);
	}
	else
		printf("can't");
}
int main()
{
	//Creatdat();
	//First_Write();
	Output_record(1);
	system("pause");
	return 0;
}