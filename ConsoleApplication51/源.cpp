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
void Creatdat()//��ʼ��100����¼�����commodity
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
			fseek(fPtr, (npro.ID - 1) * sizeof(struct product), SEEK_SET);
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
void outputlist(int list)
{
	FILE *f = NULL;
	struct product pro;
	if (f = fopen("E:\\commodity.dat", "r+b"))
	{
		//rewind(f);
		fseek(f, sizeof(struct product)*(list - 1), SEEK_SET);
		fread(&pro, sizeof(struct product), 1, f);
		fclose(f);
		printf("%-10s%-20s%-10s%-10.2s\n", "��¼�ţ���ƷID��", "��Ʒ��", "����", "�۸�");
		printf("%-10d%-20s%-10d%-10.2f\n", pro.ID, pro.name, pro.num, pro.price);
	}
	else
		printf("can't open the file!\n");
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
			printf("can't open the file!\n");
			return;
		}
		struct product npro;
		fseek(f, sizeof(struct product)*(ID - 1), SEEK_SET);
		fread(&npro, sizeof(struct product), 1, f);
		fclose(f);
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
			f = fopen("E:\\commodity.dat", "r+b");
			fwrite(&npro, sizeof(struct product), 1, f);
			fclose(f);
			printf("���º���Ʒ��Ϣ���£�\n");
			outputlist(ID);
		}
		else
		{
			printf("�Բ��𣬼�¼��Ϊ%d����Ʒ�����ڣ��޷�����\n", ID);
		}
		printf("�������������ƷID[IDΪ - 1�����������]:\n");
		scanf("%d", &ID);
	}
	printf("���¹�������\n");
}
void Delete_record()//ɾ��һ����¼
{
	int ID;
	struct product pro;
	struct product black = { 0,"",0,0.0 };
	printf("�������ɾ����ƷID[��¼��Ϊ-1�������ɾ��]:\n");
	scanf("%d", &ID);
	while (ID != -1)
	{
		FILE *fPtr;
		if (fPtr = fopen("E:\\commodity.dat", "r+b"))
		{
			fseek(fPtr, sizeof(struct product)*(ID - 1), SEEK_SET);
			fread(&pro, sizeof(struct product), 1, fPtr);
			fclose(fPtr);
			if (!pro.ID)
			{
				printf("�Բ��𣬼�¼��Ϊ%d����Ʒ�����ڣ��޷�����ɾ������\n", ID);
			}
			else
			{
				char fla;
				printf("����Ʒ��Ϣ���£�\n");
				outputlist(ID);
				printf("�Ƿ�ȷʵɾ����ȷ�ϰ�Y��ȡ����N)��\n");
				getchar();
				scanf("%c", &fla);
				if (fla == 'Y')
				{
					fPtr = fopen("E:\\commodity.dat", "r+b");
					fseek(fPtr, sizeof(struct product)*(ID - 1), SEEK_SET);
					fwrite(&black, sizeof(struct product), 1, fPtr);
					fclose(fPtr);
					printf("��¼��Ϊ8����Ʒ�ɹ�ɾ��\n");
					Outputalllist();
				}
				else
				{
					printf("��ѡ��ɾ����¼��Ϊ10����Ʒ\n");
				}
			}
			printf("�������ɾ����ƷID[��¼��Ϊ-1�������ɾ��]:\n");
			scanf("%d", &ID);
		}
		else
			printf("can't open the file!\n");
	}
		printf("ɾ����������\n");
	
}
int main()
{

	//Creatdat();
	Outputalllist();
	//First_Write();
	outputlist(5);
	Update_record();
	Delete_record();
	system("pause");
	return 0;
}