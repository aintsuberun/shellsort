/*
����������:
	������ ������ ������������� ���������� ��� ������ � ���������, ������� �� ����������,
	���������� ������� � ��������� �������, � ����� ���������� � �������������� ������ �����.
������:
	�������� ������ �������� � �������� ����.
������������ ����������� � �������:
	enum MainMenu: ������������ ��� �������� ����.
	enum Save: ������������ ��� ������ ���������� ������.
	������� Save(): ������� ��� ���������� ������� � ����.
	������� Result(): ����� ���������������� � ���������������� �������, ����� ������� ���������� � ����� ���������� �������.
	������� ManualFill(): ������ ���������� ������� �������������.
	������� RandomFill(): ���������� ������� ���������� �������.
	������� solution(): �������� ���� ���������, ��������������� ������������ ����� ����� ���������� ������� ����.
*/

#include "functions.h"
#include "Interface.h"
#include "ShellaSort.h"

enum MainMenu { TestWithRandom = 1, Manual = 2, Exit = 3 };
enum Save {Original = 1, Product, No};

void Save(vector<double>& arr, vector<double>& sortedshella, size_t n) {
	int choice;
	cout << endl << endl << "������ ��������� ��������� � ����?" << endl << "��������� �������� ������ - 1" << endl << "��������� ��������� - 2" << endl << "��� - 3" << endl << "> ";
	choice = CheckInt();
	while (choice != Original and choice != Product and choice != No) {
		cout << "������ ������ ���� �� ����������, �������� ������: ";
		choice = CheckInt();
	}
	if (choice == Original) {
		fstream file = OpenFile();
		if (!file.is_open()) {
			cout << "������. ���������� �����: " << endl;
			file = OpenFile();
			if (file.is_open()) {
				file << "����������������� ������:" << endl;
				for (int i = 0; i < n; i++) {
					file << arr[i] << "\t";
				}
				file << endl;
			}
			while (!file.is_open()) {
				cout << "������. ���������� �����: " << endl;
				file = OpenFile();
				if (file.is_open()) {
					file << "����������������� ������:" << endl;
					for (int i = 0; i < n; i++) {
						file << arr[i] << "\t";
					}
					file << endl;
				}
			}
		}
		if (file.is_open()) {
			file << "����������������� ������:" << endl;
			for (int i = 0; i < n; i++) {
					file << arr[i] << "\t";
			}
			file << endl;
		}
		cout << endl << "���� ������.";
		cout << endl << endl << "������ ��������� ��������� � ����?" << endl << "��������� �������� ������ - 1" << endl << "��������� ��������� - 2" << endl << "��� - 3" << endl << "> ";
		choice = CheckInt();
		while (choice != Original and choice != Product and choice != No) {
			cout << "������ ������ ���� �� ����������, �������� ������: ";
			choice = CheckInt();
		}
	}
	if (choice == Product) {
		fstream file = OpenFile();
		if (!file.is_open()) {
			cout << "������. ���������� �����: " << endl;
			file = OpenFile();
			if (file.is_open()) {
				file << endl << "��������������� ������:" << endl;
				for (int i = 0; i < n; i++) {
						file << sortedshella[i] << "\t";
				}
				file << endl;
			}
			while (!file.is_open()) {
				cout << "������. ���������� �����: " << endl;
				file = OpenFile();
				if (file.is_open()) {
					file << "��������������� ������:" << endl;
					for (int i = 0; i < n; i++) {
							file << sortedshella[i] << "\t";
					}
				}
				file << endl;
			}
		}
		else {
			file << "��������������� ������:" << endl;
			for (int i = 0; i < n; i++) {
					file << sortedshella[i] << "\t";
			}
			file << endl;
		}
		cout << endl << "���� ������.";
		cout << endl << endl << "������ ��������� ��������� � ����?" << endl << "��������� �������� ������ - 1" << endl << "��������� ��������� - 2" << endl << "��� - 3" << endl << "> ";
		choice = CheckInt();
		while (choice != Original and choice != Product and choice != No) {
			cout << "������ ������ ���� �� ����������, �������� ������: ";
			choice = CheckInt();
		}
	}
	if (choice == No) {
		cout << "�� ������� �� ��������� ������ � ����." << endl << endl;
	}
}

void Result(vector<double>& arr) {
	vector<double> sortedshella = arr;
	cout << "��������������� ������:" << endl;
	PrintArray(sortedshella);
	size_t n = sortedshella.size();
	ShellaSort ShellaArray;

	cout << "\n��������������� ������ ������� �����:\n";
	ShellaArray.sort(sortedshella);
	PrintArray(sortedshella);
	Save(arr, sortedshella, n);
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
	cout << "��������� �������� �������:\n";
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