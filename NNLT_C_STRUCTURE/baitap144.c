// Lập chương trình ghép phách bài thi có các yêu cầu như sau:
// • Thông tin về thí sinh gồm có:
//  – Tên học sinh: không vượt quá 20 kí tự
//  – Mã học sinh: không quá 8 ký tự
//  – Số phách: số nguyên.
// • Điểm bài thi gồm có:
//  – Số phách: số nguyên.
//  – Điểm: số thực
// Có n thí sinh tham gia thi, n <=10 và nhập từ bàn phím.
// Lập chương trình thực hiện các công việc sau:
// a/ Nhập danh sách thí sinh. Sắp xếp thí sinh theo thứ tự tăng dần của số phách.
// b/ Nhập danh sách kết quả bài thi. Sắp xếp danh sách đó theo thứ tự tăng dần của số phách.
// c/ Sử dụng kết quả của câu a) và b) ở trên để đưa ra màn hình kết quả thi dưới dạng:
#include <stdio.h>
#include <string.h>

typedef struct Candidate {
	char name[20];
	char id[8];
	int idTest;
} candidate;

typedef struct Test {
	int idTest;
	double score;
} test;

// Phần nhập
void inputACandidate();
void inputManyCandidate();
void inputATest();
void inputManyTest();

// Phần xuất
void outputACandidateAndScore();
void outputManyCandidateAndScore();
void printWithFormat();

// Dummy Data
void dummyDataCandidate();
void dummyDataTest();

// Sắp xếp thí sinh theo tăng dần số phách
void candidateIdTestSorting();

// Sắp xếp bài thi theo tăng dần số phách
void testIdTestSorting();

void getData();

int main() {
    int n;
    candidate cdd[n];
    test t[n];
    printf("Nhập 1. Chạy chương trình theo dữ liệu nhập\n");
    printf("Nhập 2. Chạy chương trình theo dữ liệu dummmy data\n");
    int choose; printf("Lựa chọn >> "); scanf("%d", &choose);
    getchar();
    switch(choose) {
        case 1:
            do{
                printf("Nhập số thí sinh tham gia thi: ");
                scanf("%d", &n);
            }while(n<=0 || n>10);
            getchar();
	    inputManyCandidate(cdd, n);
	    inputManyTest(t, n);
            break;
        case 2:
            n=8;
	    dummyDataCandidate(cdd);
	    dummyDataTest(t);
            break;
        default: 
            printf("Lựa chọn không hợp lệ! Chọn 1 hoặc 2\n");
            break;
    }
    candidateIdTestSorting(cdd, n);
    testIdTestSorting(t, n);
    printWithFormat(cdd, t, n);
    return 0;
}

// Phần nhập
void inputACandidate(candidate *cdd) {
	fflush(stdin);
	printf("Nhập tên thí sinh: ");
	fgets(cdd->name, 20, stdin);
	cdd->name[strlen(cdd->name) - 1] = '\0';
	printf("Nhập mã thí sinh: ");
	fgets(cdd->id, 8, stdin);
	cdd->id[strlen(cdd->id) - 1] = '\0';
	printf("Nhập số phách thí sinh: ");
	scanf("%d", &cdd->idTest);
	getchar();
}

void inputManyCandidate(candidate *cdd, int n) {
	for (int i = 0; i < n; i++) {
		inputACandidate(&cdd[i]);
	}
}

void inputATest(test *t) {
	fflush(stdin);
	printf("Nhập số phách bài thi: ");
	scanf("%d", &t->idTest);
	printf("Nhập điểm bài thi: ");
	scanf("%lf", &t->score);
	getchar();
}

void inputManyTest(test *t, int n) {
	for (int i = 0; i < n; i++) {
		inputATest(&t[i]);
	}
}

// Phần xuất
// void outputACandidate(candidate cdd) {
//     printf("%s\t%s\t%d\n", cdd.name, cdd.id, cdd.idTest);
// }

// void outputManyCandidate(candidate cdd[], int n) {
//     for (int i = 0; i < n; i++) {
//         outputACandidate(cdd[i]);
//     }
// }

// void outputATest(test t) {
//     printf("%d\t%.2f\n", t.idTest, t.score);
// }

// void outputManyTest(test t[], int n) {
//     for (int i = 0; i < n; i++) {
//         outputATest(t[i]);
//     }
// }

void outputACandidateAndScore(candidate cdd, test t, int i) {
	//printf("%d\t%s\t%s\t%.2f\n", i, cdd.id, cdd.name, t.score); 
	char chr = ' ';
	printf("|%2c%02d%3c|", chr, i, chr);
	printf("%4c%-11s|", chr, cdd.id);
	printf("%2c%-20s|", chr, cdd.name);
	printf("%2c%-6.2f|\n", chr, t.score);
}

void outputManyCandidateAndScore(candidate cdd[], test t[], int n) {
	for (int i = 0; i < n; i++) {
		outputACandidateAndScore(cdd[i], t[i], i+1);
	}
}

void printLine() {
	printf("+-------+---------------+----------------------+--------+\n");
}

void printHeader() {
	char chr = ' ';
	printf("|%2c%-5s|", chr, "STT");
	printf("%2c%-13s|", chr, "Ma thi sinh");
	printf("%8c%-14s|", chr, "Ho ten");
	printf("%2c%-6s|\n", chr, "Diem");
}

void printWithFormat(candidate cdd[], test t[], int n) {
	printLine();
	printHeader();
	printLine();
	outputManyCandidateAndScore(cdd, t, n);
	printLine();
}

// Dummy Data
void dummyDataCandidate(candidate *cdd) {
    candidate cdd1 = {"Vu Nam Khanh", "CDD001", 1};
    cdd[0] = cdd1;
    candidate cdd2 = {"Pham Thanh Trung", "CDD002", 6};
    cdd[1] = cdd2;
    candidate cdd3 = {"Nguyen Van Duy", "CDD003", 3};
    cdd[2] = cdd3;
    candidate cdd4 = {"Hoang Trieu Vy", "CDD004", 4};
    cdd[3] = cdd4;
    candidate cdd5 = {"Ta Thi Tram", "CDD005", 8};
    cdd[4] = cdd5;
    candidate cdd6 = {"Phung Than Thien", "CDD006", 2};
    cdd[5] = cdd6;
    candidate cdd7 = {"Cao Thuy Linh", "CDD007", 7};
    cdd[6] = cdd7;
    candidate cdd8 = {"Hoang Thi Minh", "CDD008", 5};
    cdd[7] = cdd8;
}

void dummyDataTest(test *t) {
    test t1 = {4, 8.5};
    t[0] = t1;
    test t2 = {8, 7.5};
    t[1] = t2;
    test t3 = {1, 8.8};
    t[2] = t3;
    test t4 = {6, 9.3};
    t[3] = t4;
    test t5 = {2, 5.4};
    t[4] = t5;
    test t6 = {3, 6.8};
    t[5] = t6;
    test t7 = {7, 8};
    t[6] = t7;
    test t8 = {5, 7.7};
    t[7] = t8;
}

// Sắp xếp thí sinh theo tăng dần số phách
void candidateIdTestSorting(candidate *cdd, int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (cdd[j].idTest < cdd[i].idTest) {
				candidate temp = cdd[i];
				cdd[i] = cdd[j];
				cdd[j] = temp;
			}
		}
	}
}

// Sắp xếp bài thi theo tăng dần số phách
void testIdTestSorting(test *t, int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n; j++) {
			if (t[j].idTest < t[i].idTest) {
				test temp = t[i];
				t[i] = t[j];
				t[j] = temp;
			}
		}
	}
}
