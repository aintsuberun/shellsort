#include "functions.h"
#include "Interface.h"
#include "ShellaSort.h"

enum MainMenu { TestWithRandom = 1, Manual = 2, Exit = 3 };
enum Save {Original = 1, Product, No};

void Save(vector<double>& unsortedarray, vector<double>& sortedarray) {
	int choice;
	cout << endl << endl << "Хотите сохранить результат в файл?" << endl << "Сохранить исходные данные - 1" << endl << "Сохранить результат - 2" << endl << "Нет - 3" << endl << "> ";
	choice = CheckInt();
	while (choice != Original and choice != Product and choice != No) {
		cout << "Такого пункта меню не существует, выберите другой: ";
		choice = CheckInt();
	}
	if (choice == Original) {
		fstream file = OpenFile();
		if (!file.is_open()) {
			cout << "Ошибка. Попробуйте снова: " << endl;
			file = OpenFile();
			if (file.is_open()) {
				file << "Неотсортированный массив:" << endl;
				for (int i = 0; i < unsortedarray.size(); i++) {
					//if (i < unsortedarray.size() - 1) {
						//file << endl;
					//}
					///else {
						file << unsortedarray[i] << "\t";
					//}
				}
				file << endl << "Отсортированный массив:" << endl;
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
				cout << "Ошибка. Попробуйте снова: " << endl;
				file = OpenFile();
				if (file.is_open()) {
					file << "Неотсортированный массив:" << endl;
					for (int i = 0; i < unsortedarray.size(); i++) {
						//if (i < unsortedarray.size() - 1) {
							//file << endl;
						//}
						//else {
							file << unsortedarray[i] << "\t";
						//}
					}
					file << endl << "Отсортированный массив:" << endl;
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
			file << "Неотсортированный массив:" << endl;
			for (int i = 0; i < unsortedarray.size(); i++) {
				//if (i < unsortedarray.size() - 1) {
					file << endl;
				//}
				///else {
					file << unsortedarray[i] << "\t";
				//}
			}
			file << endl << "Отсортированный массив:" << endl;
			for (int i = 0; i < sortedarray.size(); i++) {
				//if (i < sortedarray.size() - 1) {
					file << endl;
				//}
				//else {
					file << sortedarray[i] << "\t";
				//}
			}
		}
		cout << endl << "Файл открыт.";
		cout << endl << endl << "Хотите сохранить результат в файл?" << endl << "Сохранить исходные данные - 1" << endl << "Сохранить результат - 2" << endl << "Нет - 3" << endl << "> ";
		choice = CheckInt();
		while (choice != Original and choice != Product and choice != No) {
			cout << "Такого пункта меню не существует, выберите другой: ";
			choice = CheckInt();
		}
	}
	if (choice == Product) {
		fstream file = OpenFile();
		if (!file.is_open()) {
			cout << "Ошибка. Попробуйте снова: " << endl;
			file = OpenFile();
			if (file.is_open()) {
				file << "Неотсортированный массив:" << endl;
				for (int i = 0; i < unsortedarray.size(); i++) {
					//if (i < unsortedarray.size() - 1) {
						//file << endl;
					//}
					//else {
						file << unsortedarray[i] << "\t";
					//}
				}
				file << endl << "Отсортированный массив:" << endl;
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
				cout << "Ошибка. Попробуйте снова: " << endl;
				file = OpenFile();
				if (file.is_open()) {
					file << "Неотсортированный массив:" << endl;
					for (int i = 0; i < unsortedarray.size(); i++) {
					//	if (i < unsortedarray.size() - 1) {
						//	file << endl;
						//}
						//else {
							file << unsortedarray[i] << "\t";
						//}
					}
					file << endl << "Отсортированный массив:" << endl;
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
			file << "Неотсортированный массив:" << endl;
			for (int i = 0; i < unsortedarray.size(); i++) {
				//if (i < unsortedarray.size() - 1) {
					//file << endl;
				//}
				//else {
					file << unsortedarray[i] << "\t";
				//}
			}
			file << endl << "Отсортированный массив:" << endl;
			for (int i = 0; i < sortedarray.size(); i++) {
				//if (i < sortedarray.size() - 1) {
					//file << endl;
				//}
				//else {
					file << sortedarray[i] << "\t";
				//}
			}
		}
		cout << endl << "Файл открыт.";
		cout << endl << endl << "Хотите сохранить результат в файл?" << endl << "Сохранить исходные данные - 1" << endl << "Сохранить результат - 2" << endl << "Нет - 3" << endl << "> ";
		choice = CheckInt();
		while (choice != Original and choice != Product and choice != No) {
			cout << "Такого пункта меню не существует, выберите другой: ";
			choice = CheckInt();
		}
	}
	if (choice == No) {
		cout << "Вы выбрали не сохранять данные в файл." << endl << endl;
	}
}

void Result(vector<double>& arr) {
	vector<double> unsortedshella = arr;
	cout << "Неупорядоченный массив:" << endl;
	PrintArray(unsortedshella);

	ShellaSort ShellaArray;

	cout << "\nОтсортированный массив методом Шелла:\n";
	ShellaArray.sort(unsortedshella);
	vector<double> sortedarray = unsortedshella;
	PrintArray(sortedarray);
	Save(unsortedshella, sortedarray);
}

void ManualFill() {
	int n;
	cout << "Введите размер массива: ";
	n = CheckInt();
	while (n <= 0) {
		cout << "Размер массива не может быть меньше или равен 0.\nВведите число больше 0: ";
		n = CheckInt();
	}
	vector<double> arr(n);
	cout << "Введите элементы масива:\n";
	for (int i = 0; i < n; i++) {
		cout << "[" << i + 1 << "]: ";
		arr[i] = CheckDouble();
	}
	Result(arr);
}

void RandomFill() {
	int n;
	cout << "Введите размер массива: ";
	n = CheckInt();
	while (n <= 0) {
		cout << "Размер массива не может быть меньше или равен 0.\nВведите число больше 0: ";
		n = CheckInt();
	}
	vector<double> arr(n);
	cout << "Введите элементы масива:\n";
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
			cout << "Выход из программы..." << endl;
			cout << "До свидания!" << endl;
			break;
		default:
			cout << "Такого пункта меню не существует" << endl << endl;
			break;
		} if (UserChoice != Exit) system("pause");
	} while (UserChoice != Exit);
	return 0;
}