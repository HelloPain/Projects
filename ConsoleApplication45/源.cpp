#include <stdio.h>
#include <stdlib.h>
struct product
{
	int ID;
	char *name;
	int num;
	float price;
};
void Creatdat()//��ʼ��100����¼�����community
{
	FILE *fPtr = NULL;
	struct product blankpro = { 0,"",0,0.0 };
	if (fPtr=fopen("E:\\commodity.dat", "wb"))
	{
		int i = 0;
		for (; i < 100; i++)
			fwrite(&blankpro, sizeof(struct product), 1, fPtr);
		fclose(fPtr);
		printf("100���ռ�¼�������\n");
	}
	else
		printf("can't open the file!\n");
	return;
}

void First_Write()//��ʼ��¼��
{
	struct product npro;
	FILE *fPtr = NULL;
	if (fPtr = fopen("E:\\commodity.dat", "rb+"))
	{
			printf("��������Ʒ��Ϣ[IDΪ-1�����������]��\n");
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
				npro.num = atoi(p);//����
				getchar();
				scanf("%[^\n]", info);
				for (p = info; (*p)>'9' || (*p)<'1'; p++);
				npro.price = atof(++p);
				getchar();
				//һ����Ϣ¼�����
				printf("��������Ʒ��Ϣ[IDΪ-1�����������]��\n");
				scanf("%[^\n]", info);
				p = info;
			}	
		printf("��Ʒ��Ϣ�������\n");
	}
	else
		printf("can't open the file\n");
	return;
}
void Output_record(int list)
{
	//printf("��¼�ţ���ƷID��\t\t��Ʒ��\t\t����\t\t�۸�\n");
	FILE *fPtr;
	struct product pro;
	if (fPtr = fopen("E:\\commodity.dat", "wr"))
	{
		fPtr = fseek(fPtr, (list - 1) * sizeof(struct product), SEEK_SET);//�ҵ���ǰ��¼
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