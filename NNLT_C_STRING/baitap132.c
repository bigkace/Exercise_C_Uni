// Loại bỏ khoảng trắng thừa
// Thu    do Ha  Noi -> Thu do Ha Noi
#include <stdio.h>
#include <string.h>

void xoaKhoangTrangThua(char str[], char *strRes) {
	int j = 0;
	for (int i = 0; i < strlen(str); i++) {
		if ((i == 0 && str[i] == ' ') || (str[i] == ' ' && str[i-1] == ' ')) {
			continue;
		} else if (str[i] != ' ' || (str[i] == ' ' && str[i-1] != ' ')) {
			strRes[j] = str[i];
			j++;
		}
	}
}

int main() {
	char str[100];
	fgets(str, 100, stdin);
	str[strlen(str) - 1] = '\0';
	char strRes[100];
	xoaKhoangTrangThua(str, strRes);
	printf("%s\n", strRes);
	return 0;
}
