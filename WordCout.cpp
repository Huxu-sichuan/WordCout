#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {

	char ch;
	char fh = ' ';
	int count = 0;

	FILE *pt;

	if ((pt = fopen(argv[2], "r")) == NULL) {

		printf("���ļ� %s ʧ�ܣ�", argv[2]);

		exit(1);
	}

	if (strcmp(argv[1], "-c") == 0) {
		while ((ch = getc(pt)) != EOF) {
			count++;//ͳ���ַ���
		}
		printf("�ַ���%d��\n", count);
	} else {
		while ((ch = getc(pt)) != EOF) {
			if ((ch >= 33 && ch <= 43) || (ch >= 45 && ch <= 126) && ((fh == ' ') || (fh == ','))) {
				count++;//ͳ�Ƶ�����
			}
			fh = ch;
		}
		printf("������%d��\n", count);
	}

	fclose(pt);
	return 0;
}