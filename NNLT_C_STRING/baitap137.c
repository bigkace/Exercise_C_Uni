// Mã hoá dịch trái dịch phải
//VD: hello -> dịch trái -> elloh
//dịch phải -> ohell
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void chonLoaiMaHoa(int *k) {
	bool flag = true;
	do {
		printf("Nhập 1. Mã hoá dịch phải\n");
		printf("Nhập -1. Mã hoá dịch trái\n");
		scanf("%d", k);
		if (*k == 1 || *k == -1) {
			flag = false;
		}
	} while(flag);
}

void maHoa(char *str, int k) {
	if (k == 1) {
		char temp = str[strlen(str) - 1];
		for (int i = strlen(str) - 1; i >= 1; i--) {
			str[i] = str[i-1];
		}
		str[0] = temp;
	} else {
		char temp = str[0];
		for (int i = 0; i < strlen(str) - 1; i++) {
			str[i] = str[i+1];
		}
		str[strlen(str) - 1] = temp;
	}
}

int main() {
	char str[100];
	int k;
	fgets(str, 100, stdin);
	str[strlen(str) - 1] = '\0';
	chonLoaiMaHoa(&k);
	maHoa(str, k);
	printf("%s\n", str);
	return 0;
}
