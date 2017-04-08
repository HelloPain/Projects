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
void Creatdat(char *s)//初始化100条空记录存放在community
{
	FILE *fPtr = NULL;
	struct product blankpro = { 0,"",0,0.0 };//空记录
	if (fPtr = fopen(s, "wb"))
	{
		int i = 0;
		for (; i < 100; i++)
			fwrite(&blankpro, sizeof(struct product), 1, fPtr);
		fclose(fPtr);
		printf("100条空记录创建完毕\n\n");
	}
	else
		printf("can't open the file!\n");

}
void Outputalllist(char *s)//输出所有记录
{
	FILE *f = NULL;
	printf("商品信息如下：\n");
	printf("%-20s%-20s%-10s%-10s\n", "记录号（商品ID）", "商品名", "数量", "价格");
	if (f = fopen(s, "rb"))
	{
		struct product pro;
		while (!feof(f))
		{
			fread(&pro, sizeof(struct product), 1, f);
			if (pro.ID != 0)//不为空记录
				printf("%-20d%-20s%-10d%-10.2f\n", pro.ID, pro.name, pro.num, pro.price);

		}
		fclose(f);
	}
	else
		printf("can't open the file!\n");
}
void outputlist(int list, char *s)//输出第list条信息
{
	FILE *f = NULL;
	struct product pro;
	if (f = fopen(s, "rb"))
	{
		//rewind(f);
		fseek(f, sizeof(struct product)*(list - 1), SEEK_SET);
		fread(&pro, sizeof(struct product), 1, f);
		fclose(f);
		printf("%-10s%-20s%-10s%-10.2s\n", "记录号（商品ID）", "商品名", "数量", "价格");
		printf("%-10d%-20s%-10d%-10.2f\n", pro.ID, pro.name, pro.num, pro.price);
	}
	else
		printf("can't open the file!\n");
}
void First_Write(char *s)//初始化录入
{
	struct product npro;
	FILE *fPtr = NULL;
	if (fPtr = fopen(s, "rb+"))
	{
		printf("\n请输入商品信息[ID为-1代表输入结束]：\n");
		char info[50]; char *p = info;
		getchar();//吞上一句回车
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
			fseek(fPtr, (npro.ID - 1) * sizeof(struct product), SEEK_SET);//找到写入位置
			fwrite(&npro, sizeof(struct product), 1, fPtr);
			//写入文件
			printf("请输入商品信息[ID为-1代表输入结束]：\n");
			scanf("%[^\n]", info);
			p = info;
		}
		fclose(fPtr);
		printf("商品信息输入结束\n");
		Outputalllist(s);
	}
	else
		printf("can't open the file\n");
	return;
}
void Update_record(char *s)//更新记录
{
	int ID = -1;
	printf("请输入待更新商品ID[ID为 - 1代表结束更新]:\n");
	scanf("%d", &ID);
	while (ID != -1)//-1结束更新
	{
		FILE *f;
		if ((f = fopen(s, "r+b")) == NULL)
		{
			printf("can't open the file!\n");
			return;
		}
		struct product npro;
		fseek(f, sizeof(struct product)*(ID - 1), SEEK_SET);//找到记录
		fread(&npro, sizeof(struct product), 1, f);
		if (npro.ID)//不为0，有记录
		{
			printf("原商品信息如下：\n");
			outputlist(ID, s);
			printf("请输入更新信息[如某项不更新请直接按回车键]：\n");
			char info[50]; char *p = info;
			getchar();
			scanf("%[^\n]", info);
			for (p = info; (*p) > 'Z' || (*p) < 'A'; p = p + 2);
			if ((*p) >= 'A' && (*p) <= 'Z')
				strcpy(npro.name, p);
			getchar();
			//name更新
			scanf("%[^\n]", info);
			for (p = info; (*p) > '9' || (*p) < '1'; p++);
			if ((*p) <= '9' && (*p) >= '0')
				npro.num = atoi(p);
			getchar();
			//数量更新
			scanf("%[^\n]", info);
			for (p = info; (*p) > '9' || (*p) < '1'; p++);
			if ((*p) <= '9' && (*p) >= '0')
				npro.price = atof(p);
			getchar();//价格更新
					  //一条信息更改完毕
			fseek(f, sizeof(struct product)*(ID - 1), SEEK_SET);//重新找到录入位置
			fwrite(&npro, sizeof(struct product), 1, f);
			fclose(f);//需要关闭文件才能从缓冲区写到文件里
			printf("更新后商品信息如下：\n");
			outputlist(ID, s);
		}
		else
		{
			printf("对不起，记录号为%d的商品不存在，无法更新\n", ID);
		}
		printf("请输入待更新商品ID[ID为 - 1代表结束更新]:\n");
		scanf("%d", &ID);
	}
	printf("更新工作结束\n\n");
}
void Delete_record(char *s)//删除一个记录
{
	int ID;
	struct product pro;
	struct product black = { 0,"",0,0.0 };
	printf("请输入待删除商品ID[记录号为-1代表结束删除]:\n");
	scanf("%d", &ID);
	while (ID != -1)
	{
		FILE *fPtr;
		if (fPtr = fopen(s, "r+b"))
		{
			fseek(fPtr, sizeof(struct product)*(ID - 1), SEEK_SET);
			fread(&pro, sizeof(struct product), 1, fPtr);
			if (!pro.ID)//空记录
			{
				printf("对不起，记录号为%d的商品不存在，无法进行删除操作\n", ID);
			}
			else
			{
				char fla;
				printf("该商品信息如下：\n");
				outputlist(ID, s);
				printf("是否确实删除（确认按Y，取消按N)？\n");
				getchar();//吞回车
				scanf("%c", &fla);
				if (fla == 'Y')
				{
					fseek(fPtr, sizeof(struct product)*(ID - 1), SEEK_SET);//找到记录
					fwrite(&black, sizeof(struct product), 1, fPtr);//用空白覆盖
					fclose(fPtr);//需要关闭文件才能从缓冲区写到文件里
					printf("记录号为%d的商品成功删除\n", ID);
					Outputalllist(s);//显示删除结果
				}
				else//选择N
				{
					printf("您选择不删除记录号为%d的商品\n", ID);
				}
			}
			printf("请输入待删除商品ID[记录号为-1代表结束删除]:\n");
			scanf("%d", &ID);
		}
		else
			printf("can't open the file!\n");
	}
	printf("删除工作结束\n");
}
int main()
{
	int flag = 6;
	char *s;
	s = "E:\\commodity.dat";
	printf("请输入您的选择：\n1--创建一个100条空记录的文件\n2--输入商品记录\n3--更新商品记录\n4--删除商品记录\n5--输出全部商品记录\n6--退出程序\n");
	scanf("%d", &flag);
	while (flag != 6)
	{
		switch (flag)
		{
		case 1: {Creatdat(s);  break; }
		case 2: {First_Write(s); break; }
		case 3: {Update_record(s); break; }
		case 4: {Delete_record(s); break; }
		case 5: {Outputalllist(s);  break; }
		}
		printf("请输入您的选择：\n1--创建一个100条空记录的文件\n2--输入商品记录\n3--更新商品记录\n4--删除商品记录\n5--输出全部商品记录\n6--退出程序\n");
		scanf("%d", &flag);
	}
	printf("程序运行结束，再见！\n");
	system("pause");
	return 0;
}