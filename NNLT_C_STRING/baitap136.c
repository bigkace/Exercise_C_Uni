//Mã hoá
//Dịch ký tự sang k bước trong bảng chữ cái, và xoay vòng tròn. Ví dụ: a -> c, b->d, z ->b. 
//Việc giải mã được thực hiện ngược lại.
#include <stdio.h>
#include <string.h>

void nhapSoBuocDichChuyen(int *k) {
	do {
		scanf("%d", k);
	} while (*k <= 0);
}

void maHoa(char *str, int k) {
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] >= 97 && str[i] <= (122 - k)) {
			str[i] += k;
		} else if (str[i] > (122 - k) && str[i] <= 122) {
			str[i] -= (26 - k);
		}
	}
}

void giaiMa(char *str, int k) {
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] <= 122 && str[i] >= (97 + k)) {
			str[i] -= k;
		} else if (str[i] < (97 + k) && str[i] >= 97) {
			str[i] += (26 - k);
		} 
	}
}

int main() {
	char str[100];
	int k;
	fgets(str, 100, stdin);
	str[strlen(str) - 1] = '\0';
	nhapSoBuocDichChuyen(&k);
	maHoa(str, k);
	printf("%s\n", str);
	giaiMa(str, k);
	printf("%s\n", str);
	return 0;
}
