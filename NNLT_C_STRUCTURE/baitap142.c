//Lập chương trình quản lí điểm thi môn C cho một lớp học n học sinh n <= 10
//Thông tin tên học sinh : không quá 20 kí tự
//mã học sinh : số nguyên
//điểm tổng kết: số thực
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct Student {
	char fullName[20];
	int id;
	float score;
} student;

// Phần nhập
void inputAStudentInformation();
void inputMultipleStudentInformation();

// Phần xuất
void outputAStudentInformation();
void outputMultipleStudentInformation();
void outputLine();
void outputHeader();
void outputWithFormat();

// Dummy data
void dummyData();

// Sắp xêp theo điểm
void scoreSorting();

// Sắp xếp theo tên
void getName();
void nameSorting();

// Xử lý menu
void processMenu();

int main() {
	int n;
	student st[n];
	processMenu(st, n);
	return 0;
}

void printMenu() {
	printf("===================== Menu Chương Trình =====================\n");
	printf("|| Nhập 1. Chạy chương trình theo dummy data               ||\n");
	printf("|| Nhập 2. Chạy chương trình theo nhập thông thường        ||\n");
	printf("|| Nhập 3. Hiển thị danh sách                              ||\n");
	printf("|| Nhập 4. Sắp xếp danh sách theo thứ tự điểm thi giảm dần ||\n");
	printf("|| Nhập 5. Sắp xếp danh sách theo thứ tự tên ABC           ||\n");
	printf("|| Nhập 0. Thoát chương trình                              ||\n");
	printf("=============================================================\n");
}

void processMenu(student st[], int n) {
	bool flag = true;
	do{
		printMenu();
		int choose; printf("Lựa chọn >> "); scanf("%d", &choose); getchar();
		switch(choose) {
			case 1: 
				dummyData(st);
				n = 6;
				break;
			case 2: 
				do {
					printf("Nhập số lượng học sinh: ");
					scanf("%d", &n);
				} while(n <= 0 || n > 10);
				getchar();
				inputMultipleStudentInformation(st, n);
				break;
			case 3: 
				outputWithFormat(st, n);
				break;
			case 4: 
				scoreSorting(st, n);
				break;
			case 5: 
				nameSorting(st, n);
				break;
			case 0: 
				flag = false;
				break;
			default: 
				printf("Lựa chọn không hợp lệ! Chọn từ 0->5\n");
				break;
		}
	} while(flag);
}

// Phần nhập
void inputAStudentInformation(student *st) {
	printf("Nhập họ tên: ");
	fgets(st->fullName, 20, stdin);
	st->fullName[strlen(st->fullName) - 1] = '\0';
	printf("Nhập mã: ");
	scanf("%d", &st->id);
	printf("Nhập điểm: ");
	scanf("%f", &st->score);
	getchar();
}

void inputMultipleStudentInformation(student *st, int n) {
	for (int i = 0; i < n; i++) {
		inputAStudentInformation(&st[i]);
	}
}

//Phần xuất
void outputAStudentInformation(student st, int i) {
	//printf("%s\t%d\t%.2f\n", st.fullName, st.id, st.score);
	char chr = ' ';
	printf("|%2c%02d%3c|", chr, i, chr);
	printf("%3c%02d%4c|", chr, st.id, chr);
	printf("%2c%-24s|", chr, st.fullName);
	printf("%2c%-6.2f|\n", chr, st.score);
}

void outputMultipleStudentInformation(student st[], int n) {
	for (int i = 0; i < n; i++) {
		outputAStudentInformation(st[i], i+1);
	}
}

void outputLine() {
	printf("+-------+---------+--------------------------+--------+\n");
}

void outputHeader() {
	char chr = ' ';
	printf("|%2c%-5s|", chr, "STT");
	printf("%2c%-8s|", chr, "Mã HS");
	printf("%10c%-19s|", chr, "Họ Tên");
	printf("%2c%-9s|\n", chr, "Điểm");
}

void outputWithFormat(student st[], int n) {
	outputLine();
	outputHeader();
	outputLine();
	outputMultipleStudentInformation(st, n);
	outputLine();
}

// Dummy data
void dummyData(student *st) {
	student st1 = {"Vu Nam Khanh", 1, 7.5};
	st[0] = st1;
	student st2 = {"Dang Phuong Chi", 2, 8};
	st[1] = st2;
	student st3 = {"Nguyen Van Nam", 3, 6.5};
	st[2] = st3;
	student st4 = {"Hoang Nguyen Yen Vy", 4, 9.3};
	st[3] = st4;
	student st5 = {"Ta Thi Tram", 5, 8.6};
	st[4] = st5;
	student st6 = {"Phung Nam Phong", 6, 8};
	st[5] = st6;
}

// Sắp xếp theo điểm
void scoreSorting(student *st, int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (st[j].score > st[i].score) {
				student temp = st[i];
				st[i] = st[j];
				st[j] = temp;
			}
		}
	}
	printf("Successful Sorting!\n");
}

// Sắp xếp theo tên ABC
void getName(char str[], char *strRes) {
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

void nameSorting(student *st, int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			char strRes1[20];
			char strRes2[20];
			getName(st[j].fullName, strRes1);
			getName(st[i].fullName, strRes2);
			if(strcmp(strRes1, strRes2) < 0) {
				student temp = st[i];
				st[i] = st[j];
				st[j] = temp;
			}
		}
	}
	printf("Successful Sorting!\n");
}
