//Lập chương trình quản lí bán hàng với các yêu cầu như sau: Thông tin về hàng hóa được lưu dưới dạng bản ghi:
//Tên hàng: không vượt quá 20 kí tự
//Mã hàng: 6 ký tự
//Đơn giá: số thực
//Số lượng bán: số nguyên
//Viết chương trình nhập dữ liệu cho 1 ngày bán. Việc nhập sẽ dừng lại khi tên hàng nhập là ***
//Sắp xếp lại danh sách đã nhập theo Mã hàng.
//Đưa ra màn hình danh sách các mặt hàng có tổng giá trị bán > 500000 đồng
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const int MAX = 100;
const int LIMIT_VALUE = 5000;

typedef struct Goods {
	char name[20];
	char id[7];
	double unitPrice;
	int quantitySold;
	double totalMoney;
} goods;

// Phần nhập
void inputAGoodsInformation();
void inputManyGoodsInformation();

// Phần xuất
void outputAGoodsInformation();
void outputManyGoodsInformation();
void outputLine();
void outputHeader();
void outputWithFormat();

// Sắp xếp theo mã hàng
void idSorting();

// Lấy danh sách hàng hoá có tổng giá trị bán được > 5000
void getTMGoodsMT5000List();

// Dummy data
void dummyData();

void processMenu();

int main() {
	goods gs[MAX];
	int numberOfItems;
	processMenu(gs, numberOfItems);
	return 0;
}

void printMenu() {
	printf("========================== Menu Chương Trình ===========================\n");
	printf("|| Nhập 1. Chạy dữ liệu theo dummy data                               ||\n");
	printf("|| Nhập 2. Chạy dữ liệu theo nhập thông thường                        ||\n");
	printf("|| Nhập 3. Hiển thị danh sách                                         ||\n");
	printf("|| Nhập 4. Sắp xếp lại danh sách theo Mã Hàng                         ||\n");
	printf("|| Nhập 5. Hiển thị danh sách các mặt hàng có tổng giá trị bán > %d ||\n", LIMIT_VALUE);
        printf("|| Nhập 0. Thoát chương trình                                         ||\n");
        printf("========================================================================\n");	
}

void processMenu(goods gs[], int numberOfItems) {
	bool flag = true;
	do {
		printMenu();
		int choose; printf("Lựa chọn >> "); scanf("%d", &choose);
		getchar();
		goods gsRes[MAX];
		int numberOfItems5;
		double totalMoneyDay;
		switch(choose) {
			case 1: 
				dummyData(gs);
				numberOfItems = 10;
				break;
			case 2: 
				inputManyGoodsInformation(gs, &numberOfItems);
				break;
			case 3: 
				outputWithFormat(gs, numberOfItems);
				break;
			case 4: 
				idSorting(gs, numberOfItems);
				break;
			case 5:
				getTMGoodsMT5000List(gs, gsRes, numberOfItems, &numberOfItems5, &totalMoneyDay);
				outputWithFormat(gsRes, numberOfItems5);
				printf("%64c%-15s%.1lf $\n", ' ', "TỔNG TIỀN: ", totalMoneyDay);
				break;
			case 0: 
				flag = false;
				break;
			default: 
				printf("Lựa chọn không hợp lệ! Chọn từ 0 -> 5!\n");
				break;
		}
	} while(flag);
}

//Phần nhập
void inputAGoodsInformation(goods *gs) {
	fflush(stdin);
	printf("Nhập tên hàng: ");
	fgets(gs->name, 20, stdin);
	gs->name[strlen(gs->name) - 1] = '\0';
	printf("Nhập mã hàng: ");
	fgets(gs->id, 7, stdin);
	gs->id[strlen(gs->id) - 1] = '\0';
	printf("Nhập đơn giá: ");
	scanf("%lf", &gs->unitPrice);
	printf("Nhập số lượng bán: ");
	scanf("%d", &gs->quantitySold);
	getchar();
}

void inputManyGoodsInformation(goods *gs, int *numberOfItems) {
	int i = 0;
	*numberOfItems = 0;
	bool flag = true;
	do {
		inputAGoodsInformation(&gs[i]);
		if (strcmp(gs[i].name, "***") == 0) {
			break;
		}
		i++;
		(*numberOfItems)++;
		if (*numberOfItems == MAX) {
			flag = false;
		}
	} while(flag);
}

//Phần xuất
void outputAGoodsInformation(goods gs, int i) {
	//printf("%s\t%s\t%.2f\t%d\n", gs.name, gs.id, gs.unitPrice, gs.quantitySold);
	char chr = ' ';
	printf("|%2c%02d%3c|", chr, i, chr);
	printf("%3c%-8s|", chr, gs.id);
	printf("%1c%-21s|", chr, gs.name);
	printf("%2c%-9.1lf|", chr, gs.unitPrice);
	printf("%5c%-7d|", chr, gs.quantitySold);
	printf("%3c%-12.1lf|\n", chr, gs.totalMoney);
}

void outputManyGoodsInformation(goods gs[], int n) {
	for (int i = 0; i < n; i++) {
		gs[i].totalMoney = gs[i].unitPrice * gs[i].quantitySold;
		outputAGoodsInformation(gs[i], i+1);
	}
}

void outputLine() {
	printf("+-------+-----------+----------------------+-----------+------------+---------------+\n");
}

void outputHeader() {
	char chr = ' ';
	printf("|%2c%-5s|", chr, "STT");
	printf("%2c%-9s|", chr, "Ma hang");
	printf("%5c%-17s|", chr, "Ten hang hoa");
	printf("%2c%-9s|", chr, "Don gia");
	printf("%2c%-10s|", chr, "So luong");
	printf("%3c%-12s|\n", chr, "Tong tien");
}

void outputWithFormat(goods gs[], int n) {
	outputLine();
	outputHeader();
	outputLine();
	outputManyGoodsInformation(gs, n);
	outputLine();
}

//Dummy data
void dummyData(goods *gs) {
	goods gs1 = {"Tu lanh Panasonic", "TL001", 2000, 3};
	gs[0] = gs1;
	goods gs2 = {"Tu lanh SamSung", "TL002", 2300, 5};
	gs[1] = gs2;
	goods gs3 = {"TiVi Sony", "TV001", 1800, 10};
	gs[2] = gs3;
	goods gs4 = {"Tivi SamSung", "TV002", 1500, 8};
	gs[3] = gs4;
	goods gs5 = {"Bep dien Bluestone", "BD001", 500, 9};
	gs[4] = gs5;
	goods gs6 = {"Bep dien Sunhouse", "BD002", 450, 5};
	gs[5] = gs6;
	goods gs7 = {"May lanh Panasonic", "ML001", 800, 6};
	gs[6] = gs7;
	goods gs8 = {"May lanh Daikin", "ML002", 850, 2};
	gs[7] = gs8;
	goods gs9 = {"May lanh SamSung", "ML003", 700, 10};
	gs[8] = gs9;
	goods gs10 = {"Tivi LG", "TV003", 750, 5};
	gs[9] = gs10;
	goods gs11 = {"May xay Panasonic", "MX001", 80, 12};
	gs[10] = gs11;
}

// Sắp xếp lại danh sách theo mã hàng
void idSorting(goods *gs, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (strcmp(gs[j].id, gs[i].id) < 0) {
				goods temp = gs[i];
				gs[i] = gs[j];
				gs[j] = temp;
			}
		}
	}
	printf("Successful Sorting!\n");
}

// Lấy danh sách các mặt hàng có tổng giá trị > 5000
void getTMGoodsMT5000List(goods gs[], goods *gsRes, int n, int *numberOfItems5, double *totalMoneyDay) {
	int j = 0;
	(*numberOfItems5) = 0;
	(*totalMoneyDay) = 0;
	for (int i = 0; i < n; i++) {
		if (gs[i].totalMoney > 5000) {
			gsRes[j] = gs[i];
			j++;
			(*numberOfItems5)++;
			(*totalMoneyDay) += gs[i].totalMoney;
		}
	} 
}
