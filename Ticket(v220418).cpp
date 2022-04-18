#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>

// ���� ���� 
const int ALL_1DAY_ADULT = 62000, ALL_1DAY_TEEN = 54000, ALL_1DAY_KID = 47000;
const int ALL_AFTER4_ADULT = 50000, ALL_AFTER4_TEEN = 43000, ALL_AFTER4_KID = 36000;
const int PARK_1DAY_ADULT = 59000, PARK_1DAY_TEEN = 52000, PARK_1DAY_KID = 46000;
const int PARK_AFTER4_ADULT = 47000, PARK_AFTER4_TEEN = 41000, PARK_AFTER4_KID = 35000;
const int BABY = 15000, FREE = 0;
const int ADULT_MAX_AGE = 65, ADULT_MIN_AGE = 18, TEEN_MIN_AGE = 13, KID_MAX_AGE = 12, KID_MIN_AGE = 3, BABY_AGE_0 = 0, BABY_AGE_1 = 1;
const float DISABLED = 0.5, NATIONAL_MERIT = 0.5, SODIER_ON_VACATION = 0.49, PREGNANT = 0.5, MULTIPLE_KIDS = 0.3;

int price = 0; // Ƽ�ϱݾ� 
int ticketCount = 0; // Ƽ�� ���� ����
int totalprice = 0; // �� �����ݾ� 
int ticketChoice; // �����̿�ǰ� ��ũ�̿�� ���� 
int timeChoice; // �ð� �̿�� ����
int today = 0; // ���ó�¥ ���� 
int age; // �⺻ ���� 
int realAge; // �� ���� 
int residentRegistrationNumber_Front; // �ֹι�ȣ ���ڸ� 6�ڸ� 
int residentRegistrationNumber_Back; // �ֹι�ȣ �� 1�ڸ� 
int personType = 0; // �, û�ҳ�, ���, ���̺� 
int kidsPlayroom; // ���� ���̹� �������� ������ 
int alwaysPrefer; // ��ÿ�� ���� 
int whetherToBuy; // �� �������� ������ 
int orderCount = 0;  // �迭 �� 
int orderList[100][100] = {0}; // ������ �迭 

// �Լ�
// �̿�� ���� 
int checkTicketChoice() {
	printf("***************************** Ƽ �� �� �� *****************************\n\n");
	do {
	printf("1. �����̿�� (�̿���� : �Ե����� + �μӹڹ���)\n2. ��ũ�̿�� (�̿���� : �Ե�����)\n���� : ");
    scanf("%d", & ticketChoice);
	if(!(ticketChoice == 1 || ticketChoice == 2)){
		printf("�߸��� �Է��Դϴ�. 1 �Ǵ� 2�� �Է��ϼ���.\n\n");
	}	
	} while (!(ticketChoice == 1 || ticketChoice == 2)); // 1 �Ǵ� 2�� �������� �ʾ��� ��� �ٽ� �Է��� �޴´�. 
    return ticketChoice;
}
// �̿�ð� ���� 
int checkTimeChoice() {
	do {
	printf("\n1. 1Day �̿��\n2. After4 �̿��(�̿�ð� : ���� 4�ú��� ����)\n���� : ");
    scanf("%d", & timeChoice);
    if(!(timeChoice == 1 || timeChoice == 2)){
		printf("�߸��� �Է��Դϴ�. 1 �Ǵ� 2�� �Է��ϼ���.\n");
	} 
	} while (!(timeChoice == 1 || timeChoice == 2)); // 1 �Ǵ� 2�� �������� �ʾ��� ��� �ٽ� �Է��� �޴´�. 
    return timeChoice;
}

// ������ ��� 
int checkAge() {
    printf("\n�ֹε�Ϲ�ȣ �� 6�ڸ��� �Է��� �ּ���.\n�Է� : ");
    scanf("%d", & residentRegistrationNumber_Front);
    printf("\n�ֹε�Ϲ�ȣ ���ڸ� ù ��° ���ڸ� �Է��� �ּ���.\n�Է� : ");
    scanf("%d", & residentRegistrationNumber_Back);

    time_t rawTime;
    struct tm* pTimeInfo;
 
    rawTime = time(NULL);
    pTimeInfo = localtime(&rawTime); 

    int year = pTimeInfo->tm_year - 100 ; // year = ���� �⵵ - 1900��  
    int month = pTimeInfo->tm_mon +1; // month = ���� �� 
	int day = pTimeInfo->tm_mday; // day = ���� �� 
	
	today = year * 10000 + month * 100 + day;
	
    if (residentRegistrationNumber_Back == 1 || residentRegistrationNumber_Back == 2) { // 1900����  
        age = (int)(today * 0.0001) + 100 - (int)(residentRegistrationNumber_Front * 0.0001) + 1;
        if (today - (int)(today * 0.0001) * 10000 < residentRegistrationNumber_Front - (int)(residentRegistrationNumber_Front * 0.0001) * 10000) {
            realAge = age - 2;
        } else {
            realAge = age - 1;
        }
    } else if (residentRegistrationNumber_Back == 3 || residentRegistrationNumber_Back == 4) { // 2000���� 
        age = (int)(today * 0.0001) + 100 - (int)(residentRegistrationNumber_Front * 0.0001) + 1 - 100;
        if (today - (int)(today * 0.0001) * 10000 < residentRegistrationNumber_Front - (int)(residentRegistrationNumber_Front * 0.0001) * 10000) {
            realAge = age - 2;
        } else {
            realAge = age - 1;
        }
    } else {}	
}

// ������� ���� 
int checkAlwaysPrefer() {
	printf("\n***************************** �� �� �� ��  *****************************");
    printf("\n\n�ش������ �����ø� �Է��� �ּ���. ���ٸ� 6���� �Է��� �ּ���. (�ߺ� �Ұ�)\n");
    do {
    printf("1. �����\n2. ����������\n3. �ް��庴\n4. �ӻ��\n5. �ٵ��� �ູī��\n6. �ش���� ����\n���� : ");
    scanf("%d", & alwaysPrefer);
	if(!(alwaysPrefer == 1 || alwaysPrefer == 2 || alwaysPrefer == 3 || alwaysPrefer == 4 || alwaysPrefer == 5 || alwaysPrefer == 6)){
		printf("�߸��� �Է��Դϴ�. 1~6�߿� �ϳ��� �Է��ϼ���.\n\n");
	} 
	} while (!(alwaysPrefer == 1 || alwaysPrefer == 2 || alwaysPrefer == 3 || alwaysPrefer == 4 || alwaysPrefer == 5 || alwaysPrefer == 6)); // 1���� 6��  �������� �ʾ��� ��� �ٽ� �Է��� �޴´�. 
    return alwaysPrefer;
}
// ���ɺ� ���� 
int checkPersonType() {
	if (realAge >= ADULT_MIN_AGE) {
        personType = 1; // � 
    } else if (realAge >= TEEN_MIN_AGE && realAge < ADULT_MIN_AGE) {
        personType = 2; // û�ҳ� 
    } else if (realAge >= KID_MIN_AGE && realAge < KID_MAX_AGE) {
        personType = 3; // ��� 
    } else if (realAge > BABY_AGE_0 && realAge < KID_MAX_AGE) {
        personType = 4; // ���̺� 
    }
}
// ���� ���Ǻ� �������� 
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
// ���Ƴ��̽ü� �̿�
int checkPrice_KidsPlayroom() {
    if (realAge > 0 && realAge < 1) {
        price = FREE;
    } else if (realAge >= 1 && realAge < 3) {
        printf("\n\n�� 1������ 3������ ���� ���̽ü��� ����� �̿� �����մϴ�. �̿��Ͻðڽ��ϱ�?\n");
        printf("1. �̿�O\n2. �̿�X (��ũ���� ����)\n���� : ");
        scanf("%d", & kidsPlayroom);
        if (kidsPlayroom == 1) {
            price = BABY;
        } else if (kidsPlayroom == 2) {
            price = FREE;
        }
    } else {}
}

int checkPrice_alwaysPrefer() {
	if (alwaysPrefer == 1) { // ����� 
        price *= DISABLED;
        printf("\n������� �� �������� ���� �� + ���� 1��\n�����̿��/��ũ�̿�� 50%% ���\n");
    } else if (alwaysPrefer == 2) { // ���������� 
        price *= NATIONAL_MERIT;
        printf("\n������������ �� �������� ���� �� + ����1��\n�����̿��/��ũ�̿�� 50%% ���\n");
    } else if (ticketChoice == 1 && alwaysPrefer == 3) { // �ް��庴�� ���� �̿�Ǹ� ����
        price *= SODIER_ON_VACATION;
        printf("\n�ް��庴(�ǰ�, �ǹ��ҹ��, ������ ����) �������� ���� �� + ������ 1��\n�����̿�� 49%% ���\n");
    } else if (ticketChoice == 1 && alwaysPrefer == 4) { // �ӻ�δ� ���� �̿�Ǹ� ����
        if (residentRegistrationNumber_Back == 2 || residentRegistrationNumber_Back == 4) {
            price *= PREGNANT;
            printf("\n���ڼ�ø �� �������� ���� �ӻ�� ����\n�����̿�� 50%% ���\n");
        } else {
            printf("\n�ӻ�� ������ �̿��Ͻ� �� �����ϴ�.\n");
        }
    } else if (ticketChoice == 1 && alwaysPrefer == 5) { // �ٵ��� �ູī��� ���� �̿�Ǹ� ����
        price *= MULTIPLE_KIDS;
        printf("\n�ٵ��� �ູī�� ȸ�� ���� ����(ī�忡 ���� ������ ����)\n�����̿�� 30%% ���\n");
    } else if (alwaysPrefer == 6) {
        price = price;
    } else {}
}

int checkPrice_Old() {
	if (realAge >= ADULT_MAX_AGE && ticketChoice == 1 && timeChoice == 1 && alwaysPrefer == 6) {
        price = ALL_1DAY_KID;
        personType = 0; // ����  
		alwaysPrefer = 0; // ��ο�� ��� ��� ���� 
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
	printf("\n\n������ �����Ͻðڽ��ϱ�?\n");
    scanf("%d", & ticketCount);
}

void showPrice() {
	int newPrice = ticketCount * price; // ���� ���� Ƽ�ϱݾ� 
	printf("\nƼ�� �����ݾ��� %d�� �Դϴ�.", newPrice);
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
    printf("\n\n��� �����Ͻðڽ��ϱ�?\n");
    printf("1. ��� ����\n2. ���� �� ���\n���� : ");
    scanf("%d", & whetherToBuy);
}

// �ð� ��� 
void time() {
	time_t t1;
    time(&t1);
    
    char* str1 = ctime(&t1);
    printf("%s\n", str1);
} 

int printReceipt() {
	printf("=============================================================================\n");
	printf("\n\n                                  �� �� �� ��\n");
	printf("\n                                                     ");
	time();
    printf("=============================================================================\n");
    
    printf("Ƽ������\t�̿�ð�\t����\t����\t    ����\t     ���γ���\n");
    printf("-----------------------------------------------------------------------------");
    for (int i = 0; i < orderCount; i++) {
        switch (orderList[i][0]) {
            case 1:
                printf("%12s","\n�����̿��");
                break;
            case 2:
                printf("%12s","\n��ũ�̿��");
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
			    printf("%14s", "����");
                break;
            case 1:
                printf("%14s", "�");
                break;
            case 2:
                printf("%14s", "û�ҳ�");
                break;
            case 3:
                printf("%14s", "���");
                break;
            case 4:
                printf("%14s", "���̺�");
                break;
        }
        printf("%5d ��", orderList[i][3]);
        printf("%9d ��", orderList[i][4]);
        switch (orderList[i][5]) {
        	case 0:
                printf("%21s", "��� ���");
                break;
            case 1:
                printf("%21s", "����� ���");
                break;
            case 2:
                printf("%21s", "���������� ���");
                break;
            case 3:
                printf("%21s", "�ް����� ���");
                break;
            case 4:
                printf("%21s", "�ӻ�� ���");
                break;
            case 5:
                printf("%21s", "�ٵ��̰��� ���");
                break;
            case 6:
                printf("%21s", "�ش���� ����");
                break;
        }
    }
    printf("\n-----------------------------------------------------------------------------\n");
    printf("�����ݾ�\t\t\t\t\t\t\t%11d��", totalprice);
    printf("\n=============================================================================\n");
}

// main
int main() {
    do {
        do {
            price = 0; // Ƽ�ϰ��� �ʱ�ȭ 
            
            checkTicketChoice(); // �̿�� ���� 
            checkTimeChoice(); // �̿�ð� ���� 
			checkAge(); // �� ���� ��� 
			checkAlwaysPrefer(); // ������� ���� 
			checkPersonType(); // ���ɺ� ���� 
			
            checkPrice_ChoiceAndAge(); // ������ �̿�� �̿�ð� �������ǿ� �°� �ʱⰡ�� ���� 
			checkPrice_KidsPlayroom(); // ���� ���̽ü� �̿�� ���ݰ� ���̺� ī�װ� ���� �з� 
			checkPrice_alwaysPrefer(); // ������μ��ý� ���� ���� 
			checkPrice_Old(); // ������� �ش���� ���ε��� ��� �������� å�� 
			
            checkTicketCount(); // �����ϴ� Ƽ�� �� 
            
            showPrice(); // ���� ��� 
            totalprice += ticketCount * price; // �� �ݾ� ���� 
            
            makeArray(); // �迭 ���� 
            
			checkWhetherToBuy(); // �� ������ ������ �ƴ��� 
			
        } while (whetherToBuy == 1); 
        printReceipt(); // ������ ��� 
		checkWhetherToBuy(); // �� ������ ������ �ƴ��� 
    } while (whetherToBuy == 1);
    printf("\n�����ϰڽ��ϴ�."); 
}
