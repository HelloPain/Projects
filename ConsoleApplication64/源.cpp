#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct n
{
	int a;
};
int main()
{
	FILE *f = NULL;
	f = fopen("E:\\test.dat", "wb");
	struct n N;
	N.a = 1;
	fwrite(&(N.a), sizeof(struct n), 1, f);
	fclose(f);
	//写入一条记录
	f = fopen("E:\\test.dat", "rb");
	fread(&(N.a), sizeof(struct n), 1, f);
	fread(&(N.a), sizeof(struct n), 1, f);
	if (feof(f))
		printf("end");
	else
		printf("not the end");
	system("pause");
	return 0;
}