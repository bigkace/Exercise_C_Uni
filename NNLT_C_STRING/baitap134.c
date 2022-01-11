// Nhập một xâu (câu) in ra câu đó có bao nhiêu từ
#include <stdio.h>
#include <string.h>

//Nếu là một xâu chuẩn (đầu cuối không có khoảng trẳng và mỗi từ cách như bởi một dấu cách)
int demSoTuStandard(char str[]) {
	int dem = 0;
	for (int i = 0; i < strlen(str) - 1; i++) {
		if (str[i] == ' ') {
			dem++;
		}
	}
	return dem+1;
}

//Nếu là một xâu không chuẩn
int demSoTuNotStandard(char str[]) {
	int dem = 0;
	for (int i = 0; i < strlen(str); i++) {
		if ((i == 0 && str[i] != ' ') || (str[i] != ' ' && str[i-1] == ' ')) {
			dem++;
		}
	}
	return dem;
}

int main() {
	char str[100];
	fgets(str, 100, stdin);
	str[strlen(str) - 1] = '\0';
	int dem = demSoTuNotStandard(str);
	printf("%d\n", dem);
	return 0;
}
