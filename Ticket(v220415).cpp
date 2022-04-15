#include<stdio.h>

int main() {
    const int ALL_1DAY_ADULT = 62000, ALL_1DAY_TEEN = 54000, ALL_1DAY_KID = 47000;
    const int ALL_AFTER4_ADULT = 50000, ALL_AFTER4_TEEN = 43000, ALL_AFTER4_KID = 36000;
    const int PARK_1DAY_ADULT = 59000, PARK_1DAY_TEEN = 52000, PARK_1DAY_KID = 46000;
    const int PARK_AFTER4_ADULT = 47000, PARK_AFTER4_TEEN = 41000, PARK_AFTER4_KID = 35000;
    const int BABY = 15000;
    const int FREE = 0;
    const int ADULT_MAX_AGE = 65, ADULT_MIN_AGE = 18, TEEN_MIN_AGE = 13, KID_MAX_AGE = 12, KID_MIN_AGE = 3;
    const int BABY_AGE_0 = 0, BABY_AGE_1 = 1;
    const float DISABLED = 0.5, NATIONAL_MERIT = 0.5, SODIER_ON_VACATION = 0.49, PREGNANT = 0.5, MULTIPLE_KIDS = 0.3;
    int totalprice = 0; // 총 결제금액 
    int ticketChoice; // 종합이용권과 파크이용권 선택 
    int timeChoice; // 시간 이용권 선택
    int today = 220415; // 오늘날짜 
    int age; // 기본 나이 
    int realAge; // 만 나이 
    int personNumberFront; // 주민번호 앞자리 6자리 
    int personNumberBack; // 주민번호 뒷 1자리 
    int kidsPlayroom; // 유아 놀이방 선택할지 안할지 
    int alwaysPrefer; // 상시우대 혜택 
    int whetherToBuy; // 더 구매할지 안할지 
    
    while (true) {
        int price = 0;
        printf("******************** 티 켓 구 매 ********************\n\n");
        // 혜택 없는 기본 금액. 
        printf("1. 종합이용권 (이용범위 : 롯데월드 + 민속박물관)\n2. 파크이용권 (이용범위 : 롯데월드)\n선택 : ");
        scanf("%d", & ticketChoice);
        printf("\n1. 1Day 이용권\n2. After4 이용권(이용시간 : 오후 4시부터 입장)\n선택 : ");
        scanf("%d", & timeChoice);
        printf("\n주민등록번호 앞 6자리를 입력해 주세요.\n입력 : ");
        scanf("%d", & personNumberFront);
        printf("\n주민등록번호 뒷자리 첫 번째 숫자를 입력해 주세요.\n입력 : ");
        scanf("%d", & personNumberBack);
        if (personNumberBack == 1 || personNumberBack == 2) { // 1900년대생  
            age = (int)(today * 0.0001) + 100 - (int)(personNumberFront * 0.0001) + 1;
            if (today - (int)(today * 0.0001) * 10000 < personNumberFront - (int)(personNumberFront * 0.0001) * 10000) {
                realAge = age - 2;
            } else {
                realAge = age - 1;
            }
        } else if (personNumberBack == 3 || personNumberBack == 4) { // 2000년대생 
            age = (int)(today * 0.0001) + 100 - (int)(personNumberFront * 0.0001) + 1 - 100;
            if (today - (int)(today * 0.0001) * 10000 < personNumberFront - (int)(personNumberFront * 0.0001) * 10000) {
                realAge = age - 2;
            } else {
                realAge = age - 1;
            }
        } else {
		}
        printf("\n고객님의 만 나이는 %d 세입니다. ", realAge);
        
		// 선택한 티켓의 가격 저장 
        if (ticketChoice == 1 && timeChoice == 1 && realAge >= ADULT_MIN_AGE) {
            price += ALL_1DAY_ADULT;
        } else if (ticketChoice == 1 && timeChoice == 1 && realAge >= TEEN_MIN_AGE && realAge < ADULT_MIN_AGE) {
            price += ALL_1DAY_TEEN;
        } else if (ticketChoice == 1 && timeChoice == 1 && realAge >= KID_MIN_AGE && realAge < KID_MAX_AGE) {
            price += ALL_1DAY_KID;
        } else if (ticketChoice == 1 && timeChoice == 1 && realAge > BABY_AGE_0 && realAge < KID_MAX_AGE) {
            price += BABY;
        } else if (ticketChoice == 1 && timeChoice == 2 && realAge >= ADULT_MIN_AGE) {
            price += ALL_AFTER4_ADULT;
        } else if (ticketChoice == 1 && timeChoice == 2 && realAge >= TEEN_MIN_AGE && realAge < ADULT_MIN_AGE) {
            price += ALL_AFTER4_TEEN;
        } else if (ticketChoice == 1 && timeChoice == 2 && realAge >= KID_MIN_AGE && realAge < KID_MAX_AGE) {
            price += ALL_AFTER4_KID;
        } else if (ticketChoice == 1 && timeChoice == 2 && realAge > BABY_AGE_0 && realAge < KID_MAX_AGE) {
            price += BABY;
        } else if (ticketChoice == 2 && timeChoice == 1 && realAge >= ADULT_MIN_AGE) {
            price += PARK_1DAY_ADULT;
        } else if (ticketChoice == 2 && timeChoice == 1 && realAge >= TEEN_MIN_AGE && realAge < ADULT_MIN_AGE) {
            price += PARK_1DAY_TEEN;
        } else if (ticketChoice == 2 && timeChoice == 1 && realAge >= KID_MIN_AGE && realAge < KID_MAX_AGE) {
            price += PARK_1DAY_KID;
        } else if (ticketChoice == 2 && timeChoice == 1 && realAge > BABY_AGE_0 && realAge < KID_MAX_AGE) {
            price += BABY;
        } else if (ticketChoice == 2 && timeChoice == 2 && realAge >= ADULT_MIN_AGE) {
            price += PARK_AFTER4_ADULT;
        } else if (ticketChoice == 2 && timeChoice == 2 && realAge >= TEEN_MIN_AGE && realAge < ADULT_MIN_AGE) {
            price += PARK_AFTER4_TEEN;
        } else if (ticketChoice == 2 && timeChoice == 2 && realAge >= KID_MIN_AGE && realAge < KID_MAX_AGE) {
            price += PARK_AFTER4_KID;
        } else if (ticketChoice == 2 && timeChoice == 2 && realAge > BABY_AGE_0 && realAge < KID_MAX_AGE) {
            price += BABY;
        } else {
		} 
         
        // 베이비 상세 금액. 유아놀이시설 이용 유무 확인. 
        if (realAge > 0 && realAge < 1) {
            price = FREE;
        } else if (realAge >= 1 && realAge < 3) {
        	printf("\n\n만 1세에서 3세까지 유아 놀이시설은 유료로 이용 가능합니다. 이용하시겠습니까?\n");
        	printf("1. 이용O (베이비요금 15000원 결제)\n2. 이용X (파크입장 무료)\n선택 : ");
        	scanf("%d", & kidsPlayroom);
			if (kidsPlayroom == 1){
				price = BABY;
			} else if (kidsPlayroom == 2) {
				price = FREE;
			}
		} else {
		}
        printf("\n\n할인 미적용 금액은 %d원 입니다.\n\n", price);

        printf("***************************** 우 대 할 인  *****************************");
        printf("\n\n해당사항이 있으시면 입력해 주세요. 없다면 6번을 입력해 주세요. (중복 불가)\n");
        printf("1. 장애인\n2. 국가유공자\n3. 휴가장병\n4. 임산부\n5. 다둥이 행복카드\n6. 해당사항 없음\n선택 : ");
        scanf("%d", & alwaysPrefer);

		// 상시 우대 혜택 
        if (alwaysPrefer == 1) { // 장애인 
            price *= DISABLED;
            printf("\n장애인증 등 공식증빙 지참 고객 + 동반 1인\n종합이용권/파크이용권 50%% 우대\n");
        } else if (alwaysPrefer == 2) { // 국가유공자 
            price *= NATIONAL_MERIT;
            printf("\n국가유공자증 등 공식증빙 지참 고객 + 동반1인\n종합이용권/파크이용권 50%% 우대\n");
        } else if (ticketChoice == 1 && alwaysPrefer == 3) { // 휴가장병은 종합 이용권만 할인
            price *= SODIER_ON_VACATION;
            printf("\n휴가장병(의경, 의무소방관, 군무원 포함) 공식증빙 지참 고객 + 동반인 1인\n종합이용권 49%% 우대\n");
        } else if (ticketChoice == 1 && alwaysPrefer == 4 ) { // 임산부는 종합 이용권만 할인
            if (personNumberBack == 2 ||personNumberBack == 4){
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
        } else {
		}
        
        // 만 65세 이상 어른일 때, 상시 우대 혜택에서 해당사항이 없는 경우. 어린이 요금 적용 
        if (realAge >= ADULT_MAX_AGE && ticketChoice == 1 && timeChoice == 1 && alwaysPrefer == 6) {
            price = ALL_1DAY_KID;
        } else if (realAge >= ADULT_MAX_AGE && ticketChoice == 1 && timeChoice == 2 && alwaysPrefer == 6) {
            price = ALL_AFTER4_KID;
        } else if (realAge >= ADULT_MAX_AGE && ticketChoice == 2 && timeChoice == 1 && alwaysPrefer == 6) {
            price = PARK_1DAY_KID;
        } else if (realAge >= ADULT_MAX_AGE && ticketChoice == 2 && timeChoice == 2 && alwaysPrefer == 6) {
            price = PARK_AFTER4_KID;
        } else {
		}
        printf("\n티켓 결제금액은 %d원 입니다.", price);

        // 계속구매 혹은 종료 
        printf("\n\n계속 구매하시겠습니까?\n");
        printf("1. 계속 구매\n2. 종료 후 계산\n선택 : ");
        scanf("%d", & whetherToBuy);
        if (whetherToBuy == 1) {
            totalprice += price;
        } else if (whetherToBuy == 2) {
            totalprice += price;
            printf("\n총 결제하실 금액은 %d원 입니다.", totalprice);
            break;
        } else {
		}
    }
    return 0;
}
