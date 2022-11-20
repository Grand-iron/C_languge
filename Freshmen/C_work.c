#define _CRT_SECURE_NO_WARNINGS //���� ������ ���� ������ �����ϱ� ����
#include <stdio.h>
#include <stdlib.h> // rand �Լ� �������� ����
#include <time.h>  // srand���� �������� �ٲٱ� ���� ����
#include <windows.h>

typedef struct _Student
{
	char name[20];  //�̸�
	char class[100]; //�а�
	int number;     //�й�
	int age;        //����
	double grade;   //����

}Student; //����ü�� ��Ī�� ����, ��������

void loading(void);  //�ε�â�� �����ش�.
int menu(void);      //�޴�â ��� �� ���ϴ� �л��� ������ �Է��� �޴´�.
void s_print(Student* student, char name[20], int q);  //���ϴ� �޴��� �´� ���� �� s_�� �����ϴ� 4���� �Լ��� �̿��Ͽ� ������ش�.
void s_class(Student* student, int a);    //�а� ��� 
void s_num(Student* student, int a);       //�й� ��� 
void s_age(Student* student, int a);       //���� ��ȯ 
void s_grade(Student* student, int a);     //���� ��ȯ
int main() {
boot:                                      //������ �ʱ�ȭ �� �ε�â�� ����Ѵ�.
	srand((unsigned int)time(NULL));          //������ �������� �ʰ� ����
	char oryu[] = { "(�����߻�)" };          //���� �߻��ߴٴ°� �˷��ֱ� ���� ����
	int i = 0;                               //����� �ݺ������� ������	
	Student student[] = {           //����ü �迭�� �ʱ�ȭ
		{"Kim","Computer science",2022001,20,4.1},
		{"Lee","art",2022002,21,3.8},
		{"Park","media",2022003,22,3.2},
		{"Choi","Physical Education",2022004,24,4.0},
		{"Jeong","Computer science", 2022005,60,4.5},
	};
	loading();                             //�ε��Ѵ�.
	printf("���� ������ �Էµ� �л��� �̸�\n");   //�Էµ� �л����� �˷���
	for (i = 0; i < 5; i++)
		printf("%s\n", student[i].name);
	while (1) {                                    //r_int2�� ���� 25%Ȯ���� ���̰��� ���� r_int�� ���� �߻��� ����ü ���� �������� �ٲ����
		int changer, r_int = rand() % 99999, r_int2 = r_int % 4;
		char name[20];
		changer = menu();             //�޴�â ��� �� �޴����� �Է¹ޱ�
		if (r_int2 == 1) {
			for (i = 0; i < 5; i++) {
				student[i].number = -r_int;
				student[i].age = -r_int;
				student[i].grade = -r_int;
				strcat(student[i].class, oryu);
			}
		}
		if (changer == 4)                     //�������α׷� �ߵ��� 67�� �ٷ� �̵�
			break;
		else if (changer < 4 && changer >= 0) {
			printf("������ ã�� �л��� �̸��� �Է��ϼ��� :");//�л� ������ ����ϱ� �� �̸��� �Է¹ޱ� ����
			scanf("%s", name);
			s_print(student, name, changer);   //���ϴ� ������ �������.
		}
		else if (changer == 5)
			goto finish;  //���α׷� ������
		else {  //�̻��� �� ������ ���α׷��� ��������
			printf("�߸��� ������ ���� �Է��ϼ̽��ϴ�. ���α׷��� �����մϴ�.\n");
			goto finish;
		}
	}
	goto boot;
finish:
	printf("������ּż� �����մϴ�.");
	Sleep(1000);  //1�ʰ� ���α׷� �۵�����
	system("cls");  //ȭ�� �����
	return 0;
}
void loading(void) {  //�ε�â
	const char bar = '='; // ���α׷����� ����  
	const char blank = ' '; // ����ִ� ���α׷����� ����  
	const int LEN = 20; // ���α׷����� ����  
	const int MAX = 300; // �����۾� �ִ밪  
	int count = 0; // ���� ����� �۾�  
	int i; // �ݺ��� ���� ����  
	float tick = (float)100 / LEN; // �� %���� ���α׷����� �߰����� ��� 
	int bar_count; // ���α׷����� ���� ���� ����  
	float percent; // �ۼ�Ʈ ���� ����  
	while (count <= MAX) {
		printf("\r�ε�["); // ���� ���� ���  
		percent = (float)count / MAX * 100; // �ۼ�Ʈ ���  
		bar_count = percent / tick; // ���α׷����� ���� ���  
		for (i = 0; i < LEN; i++) { // LEN������ ���α׷����� ���  
			if (bar_count > i) { // ���α׷����� ���̺��� i�� ������ 
				printf("%c", bar);
			}
			else { // i�� �� Ŀ����  
				printf("%c", blank);
			}
		}
		printf("] %0.2f%%�����", percent); // �ۼ�Ʈ ���  
		count++; // ī��Ʈ 1����  
		Sleep(10); // �ۼ�Ʈ ���� �ð� ����  
	}
	Sleep(200);
	system("cls");
	printf("���� �Ϸ�!\n\n");
	Sleep(1000);
	system("cls");
	return 0;
}
int menu(void) {
	int changer;
	printf("**************************************\n");
	printf("ã�� ������ �����͸� ���ڷ� �Է����ּ���. (������ Ȯ�� 25%%)\n");
	printf("0. �а�\n");
	printf("1. �й�\n");
	printf("2. ����\n");
	printf("3. ����\n");
	printf("4. �����߻��� ���� ���α׷�\n");
	printf("5. ����\n");
	printf("**************************************\n");
	scanf("%d", &changer);
	return changer;
}
void s_print(Student* student, char name[20], int s_want) {
	void (*s_infomation[4])(Student * student, int) = { s_class, s_num, s_age, s_grade };
	for (int i = 0; i < 5; i++)
	{
		if (strcmp(name, student[i].name) == 0) {
			s_infomation[s_want](student, i);
		}

	}
};
void s_class(Student* student, int i) {
	printf("\n%s�л��� �а��� %s�Դϴ�.\n", student[i].name, student[i].class);
}
void s_num(Student* student, int i) {
	printf("\n%s�л��� �й��� %d�Դϴ�.\n", student[i].name, student[i].number);
}
void s_age(Student* student, int i) {
	printf("\n%s�л��� ���̴� %d�Դϴ�.\n", student[i].name, student[i].age);
}
void s_grade(Student* student, int i) {
	printf("\n%s�л��� ������ %.1lf�Դϴ�.\n", student[i].name, student[i].grade);
}