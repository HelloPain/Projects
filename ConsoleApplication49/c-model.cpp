#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct product
{
	int ID;
	char name[50];
	int num;
	float price;
};
void Outputalllist();
void Creatdat()//初始化100条记录存放在community
{
	FILE *fPtr = NULL;
	struct product blankpro = { 0,"",0,0.0 };
	if (fPtr = fopen("E:\\commodity.dat", "r+b"))
	{
		int i = 0;
		for (; i < 100; i++)
			fwrite(&blankpro, sizeof(struct product), 1, fPtr);
		fclose(fPtr);
		printf("100条空记录创建完毕\n");
	}
	else
		printf("can't open the file!\n");
	
}
void First_Write()//初始化录入
{
	struct product npro;
	FILE *fPtr = NULL;
	if (fPtr = fopen("E:\\commodity.dat", "r+b"))
	{
		printf("请输入商品信息[ID为-1代表输入结束]：\n");
		char info[50]; char *p = info;
		scanf("%[^\n]", info);
		while (*p != '-')
		{
			for (p = info; (*p)>'9' || (*p)<'1'; p++);
			npro.ID = atoi(p);//ID
			getchar();
			scanf("%[^\n]", info);
			for (p = info; (*p) > 'Z' || (*p) < 'A'; p = p + 2);
			strcpy(npro.name, p);
			getchar();
			scanf("%[^\n]", info);
			for (p = info; (*p)>'9' || (*p)<'1'; p++);
			npro.num = atoi(p);//数量
			getchar();
			scanf("%[^\n]", info);
			for (p = info; (*p)>'9' || (*p)<'1'; p++);
			npro.price = atof(p);
			getchar();
			//一条信息录入完毕
			fseek(fPtr, (npro.ID-1) * sizeof(struct product), SEEK_SET);
			fwrite(&npro, sizeof(struct product), 1, fPtr);
			//写入文件
			printf("请输入商品信息[ID为-1代表输入结束]：\n");
			scanf("%[^\n]", info);
			p = info;
		}
		fclose(fPtr);
		printf("商品信息输入结束\n");
		Outputalllist();
	}
	else
		printf("can't open the file\n");
	return;
}
void Outputalllist()
{
	FILE *f = NULL;
	printf("商品信息如下：\n");
	printf("%-10s%-20s%-10s%-10.2s\n", "记录号（商品ID）", "商品名", "数量", "价格");
	if (f = fopen("E:\\commodity.dat", "rb"))
	{
		struct product pro;
		while (!feof(f))
		{
			fread(&pro, sizeof(struct product), 1, f);
			if (pro.ID != 0)
				printf("%-10d%-20s%-10d%-10.2f\n", pro.ID, pro.name, pro.num, pro.price);
		}
		fclose(f);
	}
	else
		printf("can't");
}
void outputlist(int list)//输出第list条记录
{
	struct product pro;
	FILE *f = NULL;
	if (f = fopen("E:\\commodity", "rb"))
	{
		fseek(f, sizeof(struct product)*(list - 1), SEEK_SET);
		fread(&pro, sizeof(struct product), 1, f);
		fclose(f);
		printf("%-10s%-20s%-10s%-10s\n", "记录号（商品ID）", "商品名", "数量", "价格");
		printf("%-10d%-20s%-10d%-10.2f\n", pro.ID, pro.name, pro.num, pro.price);
	}
}
void Update_record()
{
	int ID = -1;
	printf("请输入待更新商品ID[ID为 - 1代表结束更新]:\n");
	scanf("%d", &ID);
	while (ID != -1)//-1结束更新
	{
		FILE *f;
		if ((f = fopen("E:\\commodity.dat", "r+b")) == NULL)
		{
			printf("  ");
			return;
		}
		struct product npro;
		fseek(f, sizeof(struct product)*(ID - 1), SEEK_SET);
		fread(&npro, sizeof(struct product), 1, f);
		if (npro.ID)
		{
			printf("原商品信息如下：\n");
			outputlist(ID);
			printf("请输入更新信息[如某项不更新请直接按回车键]：\n");
			char info[50]; char *p = info;
			npro.ID = ID;
			scanf("%[^\n]", info);
			if (info[0] != '\n')
			{
				for (p = info; (*p) > 'Z' || (*p) < 'A'; p = p + 2);
				strcpy(npro.name, p);
				getchar();
			}
			scanf("%[^\n]", info);
			if (info[0] != '\n')
			{
				for (p = info; (*p) > '9' || (*p) < '1'; p++);
				npro.num = atoi(p);
				getchar();
			}
			scanf("%[^\n]", info);
			if (info[0] != '\n')
			{
				for (p = info; (*p) > '9' || (*p) < '1'; p++);
				npro.price = atof(p);
				getchar();
			}
			//一条信息更改完毕
			fwrite(&npro, sizeof(struct product), 1, f);
			printf("更新后商品信息如下：\n");
			outputlist(ID);
		}
		else
		{
			printf("对不起，记录号为%d的商品不存在，无法更新\n",ID);
		}
		printf("请输入待更新商品ID[ID为 - 1代表结束更新]:\n");
		scanf("%d", &ID);
	}
	printf("更新工作结束\n");
}
int main()
{

	Creatdat();
	First_Write();
	Update_record();
	
	
	system("pause");
	return 0;
}