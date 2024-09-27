#include "functions.h"
#include "Interface.h"
#include "ShellaSort.h"

enum { TestWithRandom = 1, Manual = 2, Exit = 3 };

void Result(vector<double>& arr) {
	vector<double> unsortedshella = arr;
	cout << "��������������� ������:" << endl;
	PrintArray(unsortedshella);

	ShellaSort ShellaArray;

	cout << "\n��������������� ������ ������� �����:\n";
	ShellaArray.sort(unsortedshella);
	PrintArray(unsortedshella);
}

void ManualFill() {
	int n;
	cout << "������� ������ �������: ";
	n = CheckInt();
	while (n <= 0) {
		cout << "������ ������� �� ����� ���� ������ ��� ����� 0.\n������� ����� ������ 0: ";
		n = CheckInt();
	}
	vector<double> arr(n);
	cout << "������� �������� ������:\n";
	for (int i = 0; i < n; i++) {
		cout << "[" << i + 1 << "]: ";
		arr[i] = CheckDouble();
	}
	Result(arr);
}

void RandomFill() {
	int n;
	cout << "������� ������ �������: ";
	n = CheckInt();
	while (n <= 0) {
		cout << "������ ������� �� ����� ���� ������ ��� ����� 0.\n������� ����� ������ 0: ";
		n = CheckInt();
	}
	vector<double> arr(n);
	cout << "������� �������� ������:\n";
	for (int i = 0; i < n; i++) {
		arr[i] = -100 + (rand() % 20001) / 100.0;
	}
	Result(arr);
}

int solution() {
	int UserChoice;
	do {
		system("cls");
		ShowGreeting();
		MainMenu();
		UserChoice = CheckInt();
		switch (UserChoice) {
		case TestWithRandom:
			RandomFill();
			break;
		case Manual:
			ManualFill();
			break;
		case Exit:
			cout << "����� �� ���������..." << endl;
			cout << "�� ��������!" << endl;
			break;
		default:
			cout << "������ ������ ���� �� ����������" << endl << endl;
			break;
		} if (UserChoice != Exit) system("pause");
	} while (UserChoice != Exit);
	return 0;
}