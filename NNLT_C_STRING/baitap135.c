//Input: 2 xâu và 2 kí tự
//VD: papa, p , m -> output: mama (tìm kí tự thứ nhất trong xâu thay bằng kí tự số 2)
#include <stdio.h>
#include <string.h>

void thayThe(char *str, char a, char b) {
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == a) {
			str[i] = b;
		}
	}
}

int main() {
	char str[100];
	char a;
	char b;
	fgets(str, 100, stdin);
	str[strlen(str) - 1] = '\0';
	scanf("%c", &a);
	getchar();
	scanf("%c", &b);
	thayThe(str, a, b);
	printf("%s\n", str);
	return 0;
}
