#include "functions.h"
#include "Interface.h"
#include "ShellaSort.h"

enum MainMenu { TestWithRandom = 1, Manual = 2, Exit = 3 };
enum Save {Original = 1, Product, No};

void Save(vector<double>& unsortedarray, vector<double>& sortedarray) {
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
				for (int i = 0; i < unsortedarray.size(); i++) {
					//if (i < unsortedarray.size() - 1) {
						//file << endl;
					//}
					///else {
						file << unsortedarray[i] << "\t";
					//}
				}
				file << endl << "��������������� ������:" << endl;
				for (int i = 0; i < sortedarray.size(); i++) {
					//if (i < sortedarray.size() - 1) {
						//file << endl;
					//}
					//else {
						file << sortedarray[i] << "\t";
					//}
				}
			}
			while (!file.is_open()) {
				cout << "������. ���������� �����: " << endl;
				file = OpenFile();
				if (file.is_open()) {
					file << "����������������� ������:" << endl;
					for (int i = 0; i < unsortedarray.size(); i++) {
						//if (i < unsortedarray.size() - 1) {
							//file << endl;
						//}
						//else {
							file << unsortedarray[i] << "\t";
						//}
					}
					file << endl << "��������������� ������:" << endl;
					for (int i = 0; i < sortedarray.size(); i++) {
						//if (i < sortedarray.size() - 1) {
							file << endl;
						//}
						//else {
							file << sortedarray[i] << "\t";
						//}
					}
				}
			}
		}
		else {
			file << "����������������� ������:" << endl;
			for (int i = 0; i < unsortedarray.size(); i++) {
				//if (i < unsortedarray.size() - 1) {
					file << endl;
				//}
				///else {
					file << unsortedarray[i] << "\t";
				//}
			}
			file << endl << "��������������� ������:" << endl;
			for (int i = 0; i < sortedarray.size(); i++) {
				//if (i < sortedarray.size() - 1) {
					file << endl;
				//}
				//else {
					file << sortedarray[i] << "\t";
				//}
			}
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
				file << "����������������� ������:" << endl;
				for (int i = 0; i < unsortedarray.size(); i++) {
					//if (i < unsortedarray.size() - 1) {
						//file << endl;
					//}
					//else {
						file << unsortedarray[i] << "\t";
					//}
				}
				file << endl << "��������������� ������:" << endl;
				for (int i = 0; i < sortedarray.size(); i++) {
					//if (i < sortedarray.size() - 1) {
						//file << endl;
					//}
					//else {
						file << sortedarray[i] << "\t";
					//}
				}
			}
			while (!file.is_open()) {
				cout << "������. ���������� �����: " << endl;
				file = OpenFile();
				if (file.is_open()) {
					file << "����������������� ������:" << endl;
					for (int i = 0; i < unsortedarray.size(); i++) {
					//	if (i < unsortedarray.size() - 1) {
						//	file << endl;
						//}
						//else {
							file << unsortedarray[i] << "\t";
						//}
					}
					file << endl << "��������������� ������:" << endl;
					for (int i = 0; i < sortedarray.size(); i++) {
						//if (i < sortedarray.size() - 1) {
						//	file << endl;
						//}
						//else {
							file << sortedarray[i] << "\t";
						//}
					}
				}
			}
		}
		else {
			file << "����������������� ������:" << endl;
			for (int i = 0; i < unsortedarray.size(); i++) {
				//if (i < unsortedarray.size() - 1) {
					//file << endl;
				//}
				//else {
					file << unsortedarray[i] << "\t";
				//}
			}
			file << endl << "��������������� ������:" << endl;
			for (int i = 0; i < sortedarray.size(); i++) {
				//if (i < sortedarray.size() - 1) {
					//file << endl;
				//}
				//else {
					file << sortedarray[i] << "\t";
				//}
			}
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
	vector<double> unsortedshella = arr;
	cout << "��������������� ������:" << endl;
	PrintArray(unsortedshella);

	ShellaSort ShellaArray;

	cout << "\n��������������� ������ ������� �����:\n";
	ShellaArray.sort(unsortedshella);
	vector<double> sortedarray = unsortedshella;
	PrintArray(sortedarray);
	Save(unsortedshella, sortedarray);
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