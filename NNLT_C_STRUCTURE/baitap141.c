//Cấu trúc ngày tháng năm
#include <stdio.h>

typedef struct Date {
	int day;
	int month;
	int year;
} date;

void inputDate(date *day) {
	//Nhập năm
	do {
		printf("Nhập năm: ");
		scanf("%d", &(day->year));
	} while(day->year < 1950 || day->year > 2050);
	//Nhập tháng
	do {
		printf("Nhập tháng: ");
		scanf("%d", &(day->month));
	} while(day->month <= 0 || day->month > 12);
	//Nhập ngày
	int ngayCuoi;
	switch(day->month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			ngayCuoi = 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			ngayCuoi = 30;
			break;
		case 2:
			if ((day->year % 4 == 0 && day->year % 100 != 0) || (day->year % 400 == 0)) {
				ngayCuoi = 29;
			} else {
				ngayCuoi = 28;
			}
			break;
	}
	do {
		printf("Nhập ngày: ");
		scanf("%d", &(day->day));
	} while(day->day <= 0 || day->day > ngayCuoi);
}

int compareDate(date day1, date day2) {
	if (day1.year < day2.year) {
		return -1;
	} else if (day1.year > day2.year) {
		return 1;
	} else {
		if (day1.month < day2.month) {
			return -1;
		} else if (day1.month > day2.month) {
			return 1;
		} else {
			if (day1.day < day2.day) {
				return -1;
			} else if (day1.day > day2.day) {
				return 1;
			} else {
				return 0;
			}
		}
	}
}

int main() {
	date day1, day2;
	inputDate(&day1);
	inputDate(&day2);
	printf("%d/%d/%d\n", day1.day, day1.month, day1.year);
	printf("%d/%d/%d\n", day2.day, day2.month, day2.year);
	int compare = compareDate(day1, day2);
	if (compare == -1) {
		printf("Ngày 1 trước ngày 2\n");
	} else if (compare == 1) {
		printf("Ngày 1 sau ngày 2\n");
	} else {
		printf("Ngày 1 trùng ngày 2\n");
	}
	return 0;
}
