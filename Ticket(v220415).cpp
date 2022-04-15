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
    int totalprice = 0; // �� �����ݾ� 
    int ticketChoice; // �����̿�ǰ� ��ũ�̿�� ���� 
    int timeChoice; // �ð� �̿�� ����
    int today = 220415; // ���ó�¥ 
    int age; // �⺻ ���� 
    int realAge; // �� ���� 
    int personNumberFront; // �ֹι�ȣ ���ڸ� 6�ڸ� 
    int personNumberBack; // �ֹι�ȣ �� 1�ڸ� 
    int kidsPlayroom; // ���� ���̹� �������� ������ 
    int alwaysPrefer; // ��ÿ�� ���� 
    int whetherToBuy; // �� �������� ������ 
    
    while (true) {
        int price = 0;
        printf("******************** Ƽ �� �� �� ********************\n\n");
        // ���� ���� �⺻ �ݾ�. 
        printf("1. �����̿�� (�̿���� : �Ե����� + �μӹڹ���)\n2. ��ũ�̿�� (�̿���� : �Ե�����)\n���� : ");
        scanf("%d", & ticketChoice);
        printf("\n1. 1Day �̿��\n2. After4 �̿��(�̿�ð� : ���� 4�ú��� ����)\n���� : ");
        scanf("%d", & timeChoice);
        printf("\n�ֹε�Ϲ�ȣ �� 6�ڸ��� �Է��� �ּ���.\n�Է� : ");
        scanf("%d", & personNumberFront);
        printf("\n�ֹε�Ϲ�ȣ ���ڸ� ù ��° ���ڸ� �Է��� �ּ���.\n�Է� : ");
        scanf("%d", & personNumberBack);
        if (personNumberBack == 1 || personNumberBack == 2) { // 1900����  
            age = (int)(today * 0.0001) + 100 - (int)(personNumberFront * 0.0001) + 1;
            if (today - (int)(today * 0.0001) * 10000 < personNumberFront - (int)(personNumberFront * 0.0001) * 10000) {
                realAge = age - 2;
            } else {
                realAge = age - 1;
            }
        } else if (personNumberBack == 3 || personNumberBack == 4) { // 2000���� 
            age = (int)(today * 0.0001) + 100 - (int)(personNumberFront * 0.0001) + 1 - 100;
            if (today - (int)(today * 0.0001) * 10000 < personNumberFront - (int)(personNumberFront * 0.0001) * 10000) {
                realAge = age - 2;
            } else {
                realAge = age - 1;
            }
        } else {
		}
        printf("\n������ �� ���̴� %d ���Դϴ�. ", realAge);
        
		// ������ Ƽ���� ���� ���� 
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
         
        // ���̺� �� �ݾ�. ���Ƴ��̽ü� �̿� ���� Ȯ��. 
        if (realAge > 0 && realAge < 1) {
            price = FREE;
        } else if (realAge >= 1 && realAge < 3) {
        	printf("\n\n�� 1������ 3������ ���� ���̽ü��� ����� �̿� �����մϴ�. �̿��Ͻðڽ��ϱ�?\n");
        	printf("1. �̿�O (���̺��� 15000�� ����)\n2. �̿�X (��ũ���� ����)\n���� : ");
        	scanf("%d", & kidsPlayroom);
			if (kidsPlayroom == 1){
				price = BABY;
			} else if (kidsPlayroom == 2) {
				price = FREE;
			}
		} else {
		}
        printf("\n\n���� ������ �ݾ��� %d�� �Դϴ�.\n\n", price);

        printf("***************************** �� �� �� ��  *****************************");
        printf("\n\n�ش������ �����ø� �Է��� �ּ���. ���ٸ� 6���� �Է��� �ּ���. (�ߺ� �Ұ�)\n");
        printf("1. �����\n2. ����������\n3. �ް��庴\n4. �ӻ��\n5. �ٵ��� �ູī��\n6. �ش���� ����\n���� : ");
        scanf("%d", & alwaysPrefer);

		// ��� ��� ���� 
        if (alwaysPrefer == 1) { // ����� 
            price *= DISABLED;
            printf("\n������� �� �������� ���� �� + ���� 1��\n�����̿��/��ũ�̿�� 50%% ���\n");
        } else if (alwaysPrefer == 2) { // ���������� 
            price *= NATIONAL_MERIT;
            printf("\n������������ �� �������� ���� �� + ����1��\n�����̿��/��ũ�̿�� 50%% ���\n");
        } else if (ticketChoice == 1 && alwaysPrefer == 3) { // �ް��庴�� ���� �̿�Ǹ� ����
            price *= SODIER_ON_VACATION;
            printf("\n�ް��庴(�ǰ�, �ǹ��ҹ��, ������ ����) �������� ���� �� + ������ 1��\n�����̿�� 49%% ���\n");
        } else if (ticketChoice == 1 && alwaysPrefer == 4 ) { // �ӻ�δ� ���� �̿�Ǹ� ����
            if (personNumberBack == 2 ||personNumberBack == 4){
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
        } else {
		}
        
        // �� 65�� �̻� ��� ��, ��� ��� ���ÿ��� �ش������ ���� ���. ��� ��� ���� 
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
        printf("\nƼ�� �����ݾ��� %d�� �Դϴ�.", price);

        // ��ӱ��� Ȥ�� ���� 
        printf("\n\n��� �����Ͻðڽ��ϱ�?\n");
        printf("1. ��� ����\n2. ���� �� ���\n���� : ");
        scanf("%d", & whetherToBuy);
        if (whetherToBuy == 1) {
            totalprice += price;
        } else if (whetherToBuy == 2) {
            totalprice += price;
            printf("\n�� �����Ͻ� �ݾ��� %d�� �Դϴ�.", totalprice);
            break;
        } else {
		}
    }
    return 0;
}
