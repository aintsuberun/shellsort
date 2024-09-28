/*
����������:
	������� ���������� sort ��������� �������� ���������� ������� ����� ��� �������������� ��������� �������.
������:
	�������� ������ �������� � �������� ����.
��������:
	1. ������������� ����, ������� � �������� ����� �������.
	2. ��������� ���� ��� ����������� �� ��������� ������� � ������� �����.
	3. ���������� �������� ��������.
	4. ���������� ���� ��� ����������� ���������, ������� ��������, �� ��� ������.
	5. ������� ������������ �������� �� ���������� ������� � ��������������� ����� �������.
*/

#include "ShellaSort.h"
#include "functions.h"

void ShellaSort::sort(vector<double>& arr) {
	for (size_t step = arr.size() / 2; step > 0; step /= 2) { // ���������� size_t
		for (size_t i = step; i < arr.size(); i++) { // ���������� size_t
			double temp = arr[i];
			size_t j; // ���������� size_t
			for (j = i; j >= step && arr[j - step] > temp; j -= step) {
				arr[j] = arr[j - step];
			}
			arr[j] = temp;
		}
	}
}

/*void ShellaSort::sort(vector<double>& arr) {
	for (int step = arr.size() / 2; step > 0; step /= 2) {
		for (int i = step; i < arr.size(); i++) {
			double temp = arr[i];
			int j;
			for (j = i; j >= step && arr[j - step] > temp; j -= step) {
				arr[j] = arr[j - step];
			}
			arr[j] = temp;
		}
	}
}
*/
