// Lấy ra tên của xâu nhập vào (họ tên)
// Vu Nam Khanh -> Khanh
#include <stdio.h>
#include <string.h>

void layTen(char str[], char *strRes) {
	//Lấy dấu cách cuối cùng trước tên
	int i;
	for (i = strlen(str) - 1 ; i >= 0; i--) {
		//Loại trừ kí tự cách cuối cùng (nếu có) vì kí tự cuối cùng của xâu là '\0'
		if (i == strlen(str)-1 && str[i] == ' ') {
			continue;
		} else if (str[i] == ' ' && str[i+1] != ' ') {
			break;
		}
	}
	//Lấy tên cho vào xâu strRes
	i += 1;
	int j = 0;
	do {
		strRes[j] = str[i];
		j++;
		i++;
	} while (i < strlen(str));
}

int main() {
	char str[100];
	fgets(str, 100, stdin);
	str[strlen(str) - 1] = '\0';
	char strRes[100];
	layTen(str, strRes);
	printf("%s\n", strRes);
	return 0;
}
