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
void Creatdat()//��ʼ��100����¼�����community
{
	FILE *fPtr = NULL;
	struct product blankpro = { 0,"",0,0.0 };
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
void First_Write()//��ʼ��¼��
{
	struct product npro;
	FILE *fPtr = NULL;
	if (fPtr = fopen("E:\\commodity.dat", "r+b"))
	{
		printf("��������Ʒ��Ϣ[IDΪ-1�����������]��\n");
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
			npro.num = atoi(p);//����
			getchar();
			scanf("%[^\n]", info);
			for (p = info; (*p)>'9' || (*p)<'1'; p++);
			npro.price = atof(p);
			getchar();
			//һ����Ϣ¼�����
			fseek(fPtr, (npro.ID-1) * sizeof(struct product), SEEK_SET);
			fwrite(&npro, sizeof(struct product), 1, fPtr);
			//д���ļ�
			printf("��������Ʒ��Ϣ[IDΪ-1�����������]��\n");
			scanf("%[^\n]", info);
			p = info;
		}
		fclose(fPtr);
		printf("��Ʒ��Ϣ�������\n");
		Outputalllist();
	}
	else
		printf("can't open the file\n");
	return;
}
void Outputalllist()
{
	FILE *f = NULL;
	printf("��Ʒ��Ϣ���£�\n");
	printf("%-10s%-20s%-10s%-10.2s\n", "��¼�ţ���ƷID��", "��Ʒ��", "����", "�۸�");
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
void outputlist(int list)//�����list����¼
{
	struct product pro;
	FILE *f = NULL;
	if (f = fopen("E:\\commodity", "rb"))
	{
		fseek(f, sizeof(struct product)*(list - 1), SEEK_SET);
		fread(&pro, sizeof(struct product), 1, f);
		fclose(f);
		printf("%-10s%-20s%-10s%-10s\n", "��¼�ţ���ƷID��", "��Ʒ��", "����", "�۸�");
		printf("%-10d%-20s%-10d%-10.2f\n", pro.ID, pro.name, pro.num, pro.price);
	}
}
void Update_record()
{
	int ID = -1;
	printf("�������������ƷID[IDΪ - 1�����������]:\n");
	scanf("%d", &ID);
	while (ID != -1)//-1��������
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
			printf("ԭ��Ʒ��Ϣ���£�\n");
			outputlist(ID);
			printf("�����������Ϣ[��ĳ�������ֱ�Ӱ��س���]��\n");
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
			//һ����Ϣ�������
			fwrite(&npro, sizeof(struct product), 1, f);
			printf("���º���Ʒ��Ϣ���£�\n");
			outputlist(ID);
		}
		else
		{
			printf("�Բ��𣬼�¼��Ϊ%d����Ʒ�����ڣ��޷�����\n",ID);
		}
		printf("�������������ƷID[IDΪ - 1�����������]:\n");
		scanf("%d", &ID);
	}
	printf("���¹�������\n");
}
int main()
{

	Creatdat();
	First_Write();
	Update_record();
	
	
	system("pause");
	return 0;
}