/*
����������:
    ������ interface.cpp ������������ ��� ������ �������� ������ ������������.
    �� ������������ ����� �������� ���� � ���������� � ���������� ����������.
������:
    �������� ������ �������� � �������� ����.
������������ ���������:
    ������� MainMenu(): ��� ������� ������������ ��� ������ ������� �������� ����.
    ������� ShowGreeting(): ��� ������� ����������� ���������� ���������� �������, ������������� ������������, � �����
    ���������� ���������� � ���, ��� �������� ������ ������, ����� �������� � ���� ������.
*/

#pragma once
#include "functions.h"

void MainMenu() {
    cout << "�������� ����� ����:" << endl;
    cout << "�������� �������� ������ ��� ������ ��������� ����� - 1" << endl;
    cout << "���� ������ ������� - 2" << endl << endl;
}

void ShowGreeting() {
    cout << "������������!\n"
        "�������� ������ �433: �������� ���� ������������� � ������ �������� ��������.\n"
        "������� � 7.\n"
        "���� ������: ���������� ��������� ���������� ������� �����." << endl << endl;
}