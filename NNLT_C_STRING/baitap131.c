// Viết một chương trình nhập vào một dòng kí tự,
// viết một hàm để đếm số kí tự dấu cách của xâu
// và hiển thị ra màn hình số kí tự trắng của xâu.
#include <stdio.h>
#include <string.h>

int demKhoangTrang(char str[]){
	int dem = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == ' ') {
			dem++;
		}
	}
	return dem;
}

int main(){
	char str[100];
	fgets(str, 100, stdin);
	str[strlen(str) - 1] = '\0';
	int dem = demKhoangTrang(str);
	printf("%d\n", dem);
	return 0;
}
