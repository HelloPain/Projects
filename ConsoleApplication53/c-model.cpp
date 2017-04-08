#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct love
{
	char A[30];
	char B[30];
};
int main()
{
	FILE *f;
	f = fopen("E:\\test.dat", "wb");
	f = fopen("E:\\test.dat", "r+b");
	if (f)
	{
		struct love Mine;
		struct love Mine1;
		strcpy(Mine.A, "zj");
		strcpy(Mine.B, "wpj");
		fwrite(&Mine, sizeof(struct love)*(1-1), 1, f);
		fseek(f, sizeof(struct love)*(1 - 1), SEEK_SET);
		fread(&Mine, sizeof(struct love), 1, f);
		printf("%s love %s\n", Mine.A, Mine.B);
		fclose(f);
		strcpy(Mine1.A, "wpj");
		strcpy(Mine1.B, "zj");
		f = fopen("E:\\test.dat", "wb");
		fseek(f, sizeof(struct love)*(1-1), SEEK_SET);
		fwrite(&Mine1, sizeof(struct love)*(1 - 1), 1, f);
		fclose(f);
		f = fopen("E:\\test.dat", "r+b");
		fseek(f, sizeof(struct love)*(1 - 1), SEEK_SET);
		fread(&Mine, sizeof(struct love), 1, f);
		printf("%s love %s", Mine.A, Mine.B);
	}
	system("pause");
	return 0;
}