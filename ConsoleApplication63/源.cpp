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
void Creatdat(char *s)//��ʼ��100���ռ�¼�����community
{
	FILE *fPtr = NULL;
	struct product blankpro = { 0,"",0,0.0 };//�ռ�¼
	if (fPtr = fopen(s, "wb"))
	{
		int i = 0;
		for (; i < 100; i++)
			fwrite(&blankpro, sizeof(struct product), 1, fPtr);
		fclose(fPtr);
		printf("100���ռ�¼�������\n\n");
	}
	else
		printf("can't open the file!\n");

}
void Outputalllist(char *s)//������м�¼
{
	FILE *f = NULL;
	printf("��Ʒ��Ϣ���£�\n");
	printf("%-20s%-20s%-10s%-10s\n", "��¼�ţ���ƷID��", "��Ʒ��", "����", "�۸�");
	if (f = fopen(s, "rb"))
	{
		struct product pro;
		while (!feof(f))
		{
			fread(&pro, sizeof(struct product), 1, f);
			if (pro.ID != 0)//��Ϊ�ռ�¼
				printf("%-20d%-20s%-10d%-10.2f\n", pro.ID, pro.name, pro.num, pro.price);

		}
		fclose(f);
	}
	else
		printf("can't open the file!\n");
}
void outputlist(int list, char *s)//�����list����Ϣ
{
	FILE *f = NULL;
	struct product pro;
	if (f = fopen(s, "rb"))
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
void First_Write(char *s)//��ʼ��¼��
{
	struct product npro;
	FILE *fPtr = NULL;
	if (fPtr = fopen(s, "rb+"))
	{
		printf("\n��������Ʒ��Ϣ[IDΪ-1�����������]��\n");
		char info[50]; char *p = info;
		getchar();//����һ��س�
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
			fseek(fPtr, (npro.ID - 1) * sizeof(struct product), SEEK_SET);//�ҵ�д��λ��
			fwrite(&npro, sizeof(struct product), 1, fPtr);
			//д���ļ�
			printf("��������Ʒ��Ϣ[IDΪ-1�����������]��\n");
			scanf("%[^\n]", info);
			p = info;
		}
		fclose(fPtr);
		printf("��Ʒ��Ϣ�������\n");
		Outputalllist(s);
	}
	else
		printf("can't open the file\n");
	return;
}
void Update_record(char *s)//���¼�¼
{
	int ID = -1;
	printf("�������������ƷID[IDΪ - 1�����������]:\n");
	scanf("%d", &ID);
	while (ID != -1)//-1��������
	{
		FILE *f;
		if ((f = fopen(s, "r+b")) == NULL)
		{
			printf("can't open the file!\n");
			return;
		}
		struct product npro;
		fseek(f, sizeof(struct product)*(ID - 1), SEEK_SET);//�ҵ���¼
		fread(&npro, sizeof(struct product), 1, f);
		if (npro.ID)//��Ϊ0���м�¼
		{
			printf("ԭ��Ʒ��Ϣ���£�\n");
			outputlist(ID, s);
			printf("�����������Ϣ[��ĳ�������ֱ�Ӱ��س���]��\n");
			char info[50]; char *p = info;
			getchar();
			scanf("%[^\n]", info);
			for (p = info; (*p) > 'Z' || (*p) < 'A'; p = p + 2);
			if ((*p) >= 'A' && (*p) <= 'Z')
				strcpy(npro.name, p);
			getchar();
			//name����
			scanf("%[^\n]", info);
			for (p = info; (*p) > '9' || (*p) < '1'; p++);
			if ((*p) <= '9' && (*p) >= '0')
				npro.num = atoi(p);
			getchar();
			//��������
			scanf("%[^\n]", info);
			for (p = info; (*p) > '9' || (*p) < '1'; p++);
			if ((*p) <= '9' && (*p) >= '0')
				npro.price = atof(p);
			getchar();//�۸����
					  //һ����Ϣ�������
			fseek(f, sizeof(struct product)*(ID - 1), SEEK_SET);//�����ҵ�¼��λ��
			fwrite(&npro, sizeof(struct product), 1, f);
			fclose(f);//��Ҫ�ر��ļ����ܴӻ�����д���ļ���
			printf("���º���Ʒ��Ϣ���£�\n");
			outputlist(ID, s);
		}
		else
		{
			printf("�Բ��𣬼�¼��Ϊ%d����Ʒ�����ڣ��޷�����\n", ID);
		}
		printf("�������������ƷID[IDΪ - 1�����������]:\n");
		scanf("%d", &ID);
	}
	printf("���¹�������\n\n");
}
void Delete_record(char *s)//ɾ��һ����¼
{
	int ID;
	struct product pro;
	struct product black = { 0,"",0,0.0 };
	printf("�������ɾ����ƷID[��¼��Ϊ-1�������ɾ��]:\n");
	scanf("%d", &ID);
	while (ID != -1)
	{
		FILE *fPtr;
		if (fPtr = fopen(s, "r+b"))
		{
			fseek(fPtr, sizeof(struct product)*(ID - 1), SEEK_SET);
			fread(&pro, sizeof(struct product), 1, fPtr);
			if (!pro.ID)//�ռ�¼
			{
				printf("�Բ��𣬼�¼��Ϊ%d����Ʒ�����ڣ��޷�����ɾ������\n", ID);
			}
			else
			{
				char fla;
				printf("����Ʒ��Ϣ���£�\n");
				outputlist(ID, s);
				printf("�Ƿ�ȷʵɾ����ȷ�ϰ�Y��ȡ����N)��\n");
				getchar();//�̻س�
				scanf("%c", &fla);
				if (fla == 'Y')
				{
					fseek(fPtr, sizeof(struct product)*(ID - 1), SEEK_SET);//�ҵ���¼
					fwrite(&black, sizeof(struct product), 1, fPtr);//�ÿհ׸���
					fclose(fPtr);//��Ҫ�ر��ļ����ܴӻ�����д���ļ���
					printf("��¼��Ϊ%d����Ʒ�ɹ�ɾ��\n", ID);
					Outputalllist(s);//��ʾɾ�����
				}
				else//ѡ��N
				{
					printf("��ѡ��ɾ����¼��Ϊ%d����Ʒ\n", ID);
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
	int flag = 6;
	char *s;
	s = "E:\\commodity.dat";
	printf("����������ѡ��\n1--����һ��100���ռ�¼���ļ�\n2--������Ʒ��¼\n3--������Ʒ��¼\n4--ɾ����Ʒ��¼\n5--���ȫ����Ʒ��¼\n6--�˳�����\n");
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
		printf("����������ѡ��\n1--����һ��100���ռ�¼���ļ�\n2--������Ʒ��¼\n3--������Ʒ��¼\n4--ɾ����Ʒ��¼\n5--���ȫ����Ʒ��¼\n6--�˳�����\n");
		scanf("%d", &flag);
	}
	printf("�������н������ټ���\n");
	system("pause");
	return 0;
}