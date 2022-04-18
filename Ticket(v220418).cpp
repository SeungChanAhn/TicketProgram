#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>

// 변수 선언 
const int ALL_1DAY_ADULT = 62000, ALL_1DAY_TEEN = 54000, ALL_1DAY_KID = 47000;
const int ALL_AFTER4_ADULT = 50000, ALL_AFTER4_TEEN = 43000, ALL_AFTER4_KID = 36000;
const int PARK_1DAY_ADULT = 59000, PARK_1DAY_TEEN = 52000, PARK_1DAY_KID = 46000;
const int PARK_AFTER4_ADULT = 47000, PARK_AFTER4_TEEN = 41000, PARK_AFTER4_KID = 35000;
const int BABY = 15000, FREE = 0;
const int ADULT_MAX_AGE = 65, ADULT_MIN_AGE = 18, TEEN_MIN_AGE = 13, KID_MAX_AGE = 12, KID_MIN_AGE = 3, BABY_AGE_0 = 0, BABY_AGE_1 = 1;
const float DISABLED = 0.5, NATIONAL_MERIT = 0.5, SODIER_ON_VACATION = 0.49, PREGNANT = 0.5, MULTIPLE_KIDS = 0.3;

int price = 0; // 티켓금액 
int ticketCount = 0; // 티켓 구매 수량
int totalprice = 0; // 총 결제금액 
int ticketChoice; // 종합이용권과 파크이용권 선택 
int timeChoice; // 시간 이용권 선택
int today = 0; // 오늘날짜 저장 
int age; // 기본 나이 
int realAge; // 만 나이 
int residentRegistrationNumber_Front; // 주민번호 앞자리 6자리 
int residentRegistrationNumber_Back; // 주민번호 뒷 1자리 
int personType = 0; // 어른, 청소년, 어린이, 베이비 
int kidsPlayroom; // 유아 놀이방 선택할지 안할지 
int alwaysPrefer; // 상시우대 혜택 
int whetherToBuy; // 더 구매할지 안할지 
int orderCount = 0;  // 배열 행 
int orderList[100][100] = {0}; // 영수증 배열 

// 함수
// 이용권 선택 
int checkTicketChoice() {
	printf("***************************** 티 켓 구 매 *****************************\n\n");
	do {
	printf("1. 종합이용권 (이용범위 : 롯데월드 + 민속박물관)\n2. 파크이용권 (이용범위 : 롯데월드)\n선택 : ");
    scanf("%d", & ticketChoice);
	if(!(ticketChoice == 1 || ticketChoice == 2)){
		printf("잘못된 입력입니다. 1 또는 2를 입력하세요.\n\n");
	}	
	} while (!(ticketChoice == 1 || ticketChoice == 2)); // 1 또는 2를 선택하지 않았을 경우 다시 입력을 받는다. 
    return ticketChoice;
}
// 이용시간 선택 
int checkTimeChoice() {
	do {
	printf("\n1. 1Day 이용권\n2. After4 이용권(이용시간 : 오후 4시부터 입장)\n선택 : ");
    scanf("%d", & timeChoice);
    if(!(timeChoice == 1 || timeChoice == 2)){
		printf("잘못된 입력입니다. 1 또는 2를 입력하세요.\n");
	} 
	} while (!(timeChoice == 1 || timeChoice == 2)); // 1 또는 2를 선택하지 않았을 경우 다시 입력을 받는다. 
    return timeChoice;
}

// 만나이 계산 
int checkAge() {
    printf("\n주민등록번호 앞 6자리를 입력해 주세요.\n입력 : ");
    scanf("%d", & residentRegistrationNumber_Front);
    printf("\n주민등록번호 뒷자리 첫 번째 숫자를 입력해 주세요.\n입력 : ");
    scanf("%d", & residentRegistrationNumber_Back);

    time_t rawTime;
    struct tm* pTimeInfo;
 
    rawTime = time(NULL);
    pTimeInfo = localtime(&rawTime); 

    int year = pTimeInfo->tm_year - 100 ; // year = 현재 년도 - 1900년  
    int month = pTimeInfo->tm_mon +1; // month = 현재 월 
	int day = pTimeInfo->tm_mday; // day = 현재 일 
	
	today = year * 10000 + month * 100 + day;
	
    if (residentRegistrationNumber_Back == 1 || residentRegistrationNumber_Back == 2) { // 1900년대생  
        age = (int)(today * 0.0001) + 100 - (int)(residentRegistrationNumber_Front * 0.0001) + 1;
        if (today - (int)(today * 0.0001) * 10000 < residentRegistrationNumber_Front - (int)(residentRegistrationNumber_Front * 0.0001) * 10000) {
            realAge = age - 2;
        } else {
            realAge = age - 1;
        }
    } else if (residentRegistrationNumber_Back == 3 || residentRegistrationNumber_Back == 4) { // 2000년대생 
        age = (int)(today * 0.0001) + 100 - (int)(residentRegistrationNumber_Front * 0.0001) + 1 - 100;
        if (today - (int)(today * 0.0001) * 10000 < residentRegistrationNumber_Front - (int)(residentRegistrationNumber_Front * 0.0001) * 10000) {
            realAge = age - 2;
        } else {
            realAge = age - 1;
        }
    } else {}	
}

// 우대할인 선택 
int checkAlwaysPrefer() {
	printf("\n***************************** 우 대 할 인  *****************************");
    printf("\n\n해당사항이 있으시면 입력해 주세요. 없다면 6번을 입력해 주세요. (중복 불가)\n");
    do {
    printf("1. 장애인\n2. 국가유공자\n3. 휴가장병\n4. 임산부\n5. 다둥이 행복카드\n6. 해당사항 없음\n선택 : ");
    scanf("%d", & alwaysPrefer);
	if(!(alwaysPrefer == 1 || alwaysPrefer == 2 || alwaysPrefer == 3 || alwaysPrefer == 4 || alwaysPrefer == 5 || alwaysPrefer == 6)){
		printf("잘못된 입력입니다. 1~6중에 하나를 입력하세요.\n\n");
	} 
	} while (!(alwaysPrefer == 1 || alwaysPrefer == 2 || alwaysPrefer == 3 || alwaysPrefer == 4 || alwaysPrefer == 5 || alwaysPrefer == 6)); // 1에서 6을  선택하지 않았을 경우 다시 입력을 받는다. 
    return alwaysPrefer;
}
// 연령별 구분 
int checkPersonType() {
	if (realAge >= ADULT_MIN_AGE) {
        personType = 1; // 어른 
    } else if (realAge >= TEEN_MIN_AGE && realAge < ADULT_MIN_AGE) {
        personType = 2; // 청소년 
    } else if (realAge >= KID_MIN_AGE && realAge < KID_MAX_AGE) {
        personType = 3; // 어린이 
    } else if (realAge > BABY_AGE_0 && realAge < KID_MAX_AGE) {
        personType = 4; // 베이비 
    }
}
// 선택 조건별 가격저장 
int checkPrice_ChoiceAndAge() {
    if (ticketChoice == 1 && timeChoice == 1 && personType == 1) {
        price += ALL_1DAY_ADULT;
    } else if (ticketChoice == 1 && timeChoice == 1 && personType == 2) {
        price += ALL_1DAY_TEEN;
    } else if (ticketChoice == 1 && timeChoice == 1 && personType == 3) {
        price += ALL_1DAY_KID;
    } else if (ticketChoice == 1 && timeChoice == 1 && personType == 4) {
        price += BABY;
    } else if (ticketChoice == 1 && timeChoice == 2 && personType == 1) {
        price += ALL_AFTER4_ADULT;
    } else if (ticketChoice == 1 && timeChoice == 2 && personType == 2) {
        price += ALL_AFTER4_TEEN;
    } else if (ticketChoice == 1 && timeChoice == 2 && personType == 3) {
        price += ALL_AFTER4_KID;
    } else if (ticketChoice == 1 && timeChoice == 2 && personType == 4) {
        price += BABY;
    } else if (ticketChoice == 2 && timeChoice == 1 && personType == 1) {
        price += PARK_1DAY_ADULT;
    } else if (ticketChoice == 2 && timeChoice == 1 && personType == 2) {
        price += PARK_1DAY_TEEN;
    } else if (ticketChoice == 2 && timeChoice == 1 && personType == 3) {
        price += PARK_1DAY_KID;
    } else if (ticketChoice == 2 && timeChoice == 1 && personType == 4) {
        price += BABY;
    } else if (ticketChoice == 2 && timeChoice == 2 && personType == 1) {
        price += PARK_AFTER4_ADULT;
    } else if (ticketChoice == 2 && timeChoice == 2 && personType == 2) {
        price += PARK_AFTER4_TEEN;
    } else if (ticketChoice == 2 && timeChoice == 2 && personType == 3) {
        price += PARK_AFTER4_KID;
    } else if (ticketChoice == 2 && timeChoice == 2 && personType == 4) {
        price += BABY;
    } else {}	
}
// 유아놀이시설 이용
int checkPrice_KidsPlayroom() {
    if (realAge > 0 && realAge < 1) {
        price = FREE;
    } else if (realAge >= 1 && realAge < 3) {
        printf("\n\n만 1세에서 3세까지 유아 놀이시설은 유료로 이용 가능합니다. 이용하시겠습니까?\n");
        printf("1. 이용O\n2. 이용X (파크입장 무료)\n선택 : ");
        scanf("%d", & kidsPlayroom);
        if (kidsPlayroom == 1) {
            price = BABY;
        } else if (kidsPlayroom == 2) {
            price = FREE;
        }
    } else {}
}

int checkPrice_alwaysPrefer() {
	if (alwaysPrefer == 1) { // 장애인 
        price *= DISABLED;
        printf("\n장애인증 등 공식증빙 지참 고객 + 동반 1인\n종합이용권/파크이용권 50%% 우대\n");
    } else if (alwaysPrefer == 2) { // 국가유공자 
        price *= NATIONAL_MERIT;
        printf("\n국가유공자증 등 공식증빙 지참 고객 + 동반1인\n종합이용권/파크이용권 50%% 우대\n");
    } else if (ticketChoice == 1 && alwaysPrefer == 3) { // 휴가장병은 종합 이용권만 할인
        price *= SODIER_ON_VACATION;
        printf("\n휴가장병(의경, 의무소방관, 군무원 포함) 공식증빙 지참 고객 + 동반인 1인\n종합이용권 49%% 우대\n");
    } else if (ticketChoice == 1 && alwaysPrefer == 4) { // 임산부는 종합 이용권만 할인
        if (residentRegistrationNumber_Back == 2 || residentRegistrationNumber_Back == 4) {
            price *= PREGNANT;
            printf("\n모자수첩 등 공식증빙 지참 임산부 본인\n종합이용권 50%% 우대\n");
        } else {
            printf("\n임산부 혜택을 이용하실 수 없습니다.\n");
        }
    } else if (ticketChoice == 1 && alwaysPrefer == 5) { // 다둥이 행복카드는 종합 이용권만 할인
        price *= MULTIPLE_KIDS;
        printf("\n다둥이 행복카드 회원 가족 본인(카드에 명기된 가족에 한함)\n종합이용권 30%% 우대\n");
    } else if (alwaysPrefer == 6) {
        price = price;
    } else {}
}

int checkPrice_Old() {
	if (realAge >= ADULT_MAX_AGE && ticketChoice == 1 && timeChoice == 1 && alwaysPrefer == 6) {
        price = ALL_1DAY_KID;
        personType = 0; // 노인  
		alwaysPrefer = 0; // 경로우대 어린이 요금 적용 
    } else if (realAge >= ADULT_MAX_AGE && ticketChoice == 1 && timeChoice == 2 && alwaysPrefer == 6) {
        price = ALL_AFTER4_KID;
        personType = 0;
        alwaysPrefer = 0;
    } else if (realAge >= ADULT_MAX_AGE && ticketChoice == 2 && timeChoice == 1 && alwaysPrefer == 6) {
        price = PARK_1DAY_KID;
        personType = 0;
        alwaysPrefer = 0;
    } else if (realAge >= ADULT_MAX_AGE && ticketChoice == 2 && timeChoice == 2 && alwaysPrefer == 6) {
        price = PARK_AFTER4_KID;
        personType = 0;
        alwaysPrefer = 0;
    } else {}
}


int checkTicketCount() {
	printf("\n\n몇장을 구매하시겠습니까?\n");
    scanf("%d", & ticketCount);
}

void showPrice() {
	int newPrice = ticketCount * price; // 수량 곱한 티켓금액 
	printf("\n티켓 결제금액은 %d원 입니다.", newPrice);
}

int makeArray() {
    orderList[orderCount][0] = ticketChoice;
    orderList[orderCount][1] = timeChoice;
    orderList[orderCount][2] = personType;
    orderList[orderCount][3] = ticketCount;
    orderList[orderCount][4] = ticketCount * price;
    orderList[orderCount][5] = alwaysPrefer;
    orderCount++;	
}

int checkWhetherToBuy() {
    printf("\n\n계속 구매하시겠습니까?\n");
    printf("1. 계속 구매\n2. 종료 후 계산\n선택 : ");
    scanf("%d", & whetherToBuy);
}

// 시간 출력 
void time() {
	time_t t1;
    time(&t1);
    
    char* str1 = ctime(&t1);
    printf("%s\n", str1);
} 

int printReceipt() {
	printf("=============================================================================\n");
	printf("\n\n                                  롯 데 월 드\n");
	printf("\n                                                     ");
	time();
    printf("=============================================================================\n");
    
    printf("티켓종류\t이용시간\t구분\t수량\t    가격\t     할인내역\n");
    printf("-----------------------------------------------------------------------------");
    for (int i = 0; i < orderCount; i++) {
        switch (orderList[i][0]) {
            case 1:
                printf("%12s","\n종합이용권");
                break;
            case 2:
                printf("%12s","\n파크이용권");
                break;
        }
        switch (orderList[i][1]) {
            case 1:
                printf("%12s", "Allday");
                break;
            case 2:
                printf("%12s", "After4");
                break;
        }
        switch (orderList[i][2]) {
        	case 0:
			    printf("%14s", "노인");
                break;
            case 1:
                printf("%14s", "어른");
                break;
            case 2:
                printf("%14s", "청소년");
                break;
            case 3:
                printf("%14s", "어린이");
                break;
            case 4:
                printf("%14s", "베이비");
                break;
        }
        printf("%5d 장", orderList[i][3]);
        printf("%9d 원", orderList[i][4]);
        switch (orderList[i][5]) {
        	case 0:
                printf("%21s", "경로 우대");
                break;
            case 1:
                printf("%21s", "장애인 우대");
                break;
            case 2:
                printf("%21s", "국가유공자 우대");
                break;
            case 3:
                printf("%21s", "휴가군인 우대");
                break;
            case 4:
                printf("%21s", "임산부 우대");
                break;
            case 5:
                printf("%21s", "다둥이가족 우대");
                break;
            case 6:
                printf("%21s", "해당사항 없음");
                break;
        }
    }
    printf("\n-----------------------------------------------------------------------------\n");
    printf("결제금액\t\t\t\t\t\t\t%11d원", totalprice);
    printf("\n=============================================================================\n");
}

// main
int main() {
    do {
        do {
            price = 0; // 티켓가격 초기화 
            
            checkTicketChoice(); // 이용권 선택 
            checkTimeChoice(); // 이용시간 선택 
			checkAge(); // 만 나이 계산 
			checkAlwaysPrefer(); // 우대할인 선택 
			checkPersonType(); // 연령별 구분 
			
            checkPrice_ChoiceAndAge(); // 선택한 이용권 이용시간 연령조건에 맞게 초기가격 저장 
			checkPrice_KidsPlayroom(); // 유아 놀이시설 이용시 가격과 베이비 카테고리 가격 분류 
			checkPrice_alwaysPrefer(); // 우대할인선택시 가격 할인 
			checkPrice_Old(); // 우대할인 해당없는 노인들은 어린이 가격으로 책정 
			
            checkTicketCount(); // 구매하는 티켓 수 
            
            showPrice(); // 가격 출력 
            totalprice += ticketCount * price; // 총 금액 누적 
            
            makeArray(); // 배열 생성 
            
			checkWhetherToBuy(); // 더 구매할 것인지 아닌지 
			
        } while (whetherToBuy == 1); 
        printReceipt(); // 영수증 출력 
		checkWhetherToBuy(); // 더 구매할 것인지 아닌지 
    } while (whetherToBuy == 1);
    printf("\n종료하겠습니다."); 
}
