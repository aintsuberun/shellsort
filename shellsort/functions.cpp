/* 
����������:
    ������ functions.cpp ������������ ��� �������� ����� ������ �������������.
    �� ������������ ���������� ���� ������������� � ������������ �������� � �������� ������������ � ������������ ������.
������:
    �������� ������ �������� � �������� ����.
������������ ���������:
    ������� CheckInt(): ��� ������� ��������� ������������� ��������, ��������� �������������.
    ��� ����������� ������������ ������ (��������, ���� ������ ������ �����), ��� ������� ���� � �������� ������������ 
    � ������������� ������ ������������� ��������. ����� ��������� ����� ������� ���������� ��������� ������������� ��������.
    ������� CheckDouble(): ����������� �������� ������������� ������� CheckInt() ������ ��� ������������ �����.
    ������� PrintArray(): ������ ��� ����������� ����������� ������� ���� double �� �������.
    ��� ������� ������ ������� �������, �������� �� ����������, � � ����� ��������� ������� ������.
    ������� IsReservedName(string path): ������ ��� �������� ����������������� �������� ���, ����������� � ���� ���� � �����.
    ������� EnteringPathToFile(): ������ ������������ ������ ���� � ����� ��� ��� ��������.
    ������� OpenFile(): ���������� ��� �������� �����, ����� �������� ������ � ����. ���� ����� ���� ��� ����������, ��
    ��� ���������� �������������� ���� �������: ������������ ����, �������� ������ ��� ������ ������ ��������.
 */

#include <iostream>
#include <Windows.h>
#include <vector>
#include <time.h>
#include <string>
#include <fstream>
#include <filesystem>
#include <sstream>

using namespace std;

enum file { Replace = 1, Append, OtherName };

int CheckInt() {
    int Check;
    cin >> Check;
    while (getchar() != '\n') { // ������� getchar ���������� ��������� ������ �� ������������ ������ �����
        while (cin.fail()) { //�������� �� ������ ����������� ����� �� ������������ ����� (� �������, �������� ������ ����� ���� ������)
            cin.ignore();// ����� cin.ignore ������������ ��� ���������� �������� �� �������� ������ (cin). ����������� ������� ������������ � �� ������������.
            cin.clear(); // ��� ������� ����������� ��������� ������. ����� ������������� cin.clear ���������� ��������� ����� ��������������� �� goodbit, ��� �������� ���������� "������"
            while (getchar() != '\n');
            cout << "������ �����, �������� �������� ������������ ������. ������� ����� ������:" << endl;
            cin >> Check;
        }
    }
    return Check;
}

double CheckDouble() {
    double Check;
    cin >> Check;
    while (getchar() != '\n') { 
        while (cin.fail()) { 
            cin.ignore();
            cin.clear(); 
            while (getchar() != '\n');
            cout << "������ �����, �������� �������� ������������ ������. ������� ����� ������:" << endl;
            cin >> Check;
        }
    }
    return Check;
}

void PrintArray(vector<double>& arr) {
    for (int i = 0; i < arr.size(); i++) { // ���� �� ������� �������� ������� �� ����������
        cout << arr[i] << "\t"; // ����� �������� ������� � ���������� ���������
    }
    cout << endl;
}

bool IsReservedName(string path) {
    try {
        // ���� ����� ���������� ������ (���� ��� ���������������), ��� ���������� � ���� catch. is_regular_file ��������� ��������������� �� ��� �����
        return filesystem::is_regular_file(path);
    }
    catch (filesystem::filesystem_error) { // filesystem_error - ������ �� ����������������� ���. �.�. �� ������������ ������ �� ����������������� ���
        return true;
    }
}

string EnteringPathToFile() {
    cout << "������� ��� ����� ��� ���� � ����:" << endl;
    string NameOfFile; // C:\Users\User\Desktop\abcd.txt
    cin >> NameOfFile;
    if (NameOfFile.find(".txt") != NameOfFile.npos) { // find ���� .txt, ���������� ������ ����� (�����-�� �����), ���� ����� ����, �� ���������� npos.  npos - ����������� ��������� ������ string (����������� ��������� ����� ��� string)
        NameOfFile.erase(NameOfFile.find(".txt"), 4); // 4 = .txt (erase ������� .txt)
    } // C:\Users\User\Desktop\abcd
    string ForCheck = NameOfFile;
    reverse(ForCheck.begin(), ForCheck.end()); // reverse �������������� ������ abcd -> dcba ( dcba\potkseD\resU\sresU\:C )
    istringstream iss(ForCheck); // �� ������� ����������� ����� �����, ����� ����� ������������ getline, � ����� ����� �������� forCheck
    if (ForCheck.find('\\') != ForCheck.npos) {
        getline(iss, ForCheck, '\\'); // ������ �� '\'. �� ���� �������� dcba
    }
    reverse(ForCheck.begin(), ForCheck.end()); // abcd
    while (ForCheck.find_first_of("\\ / : ? \" < > | +") != ForCheck.npos or IsReservedName(ForCheck)) { // ���� ���������� ���� 1 �� ����������� ��������, �� �� ���������� ��� ������, ���� ��� �� ���������� npos
        cout << "��� ����� �� ������ ��������� ������� \\ / : ? \" < > | + � ����������������� �������� �����" << endl;
        cout << "������� ��� ����� ��� ���� � ����:" << endl;
        cin >> NameOfFile;
        if (NameOfFile.find(".txt") != NameOfFile.npos) {
            NameOfFile.erase(NameOfFile.find(".txt"), 4);
        }
        ForCheck = NameOfFile;
        reverse(ForCheck.begin(), ForCheck.end());
        iss.str(ForCheck);
        if (ForCheck.find('\\') != ForCheck.npos) {
            getline(iss, ForCheck, '\\');
        }
        reverse(ForCheck.begin(), ForCheck.end());
    }
    NameOfFile += ".txt";
    return NameOfFile;
}

fstream OpenFile() {
    fstream file;
    string path;
    path = EnteringPathToFile();
    while (filesystem::exists(path)) { // ��� �������, ������� ���������, ���������� �� ��������� ���� ��� ������� � �������� �������. ��� ���������� true , ���� ���� ��� ������� ����������, � false � ��������� ������.
        int choice;
        cout << "1 - �������� ���� \n2 - ���������� � ��� ������������ \n3 - ������������ ������ ��������" << endl;
        choice = CheckInt();
        while (choice != Replace and choice != Append and choice != OtherName) {
            while (getchar() != '\n');
            cout << "1 - �������� ���� \n2 - ���������� � ��� ������������ \n3 - ������������ ������ ��������" << endl;
            choice = CheckInt();
        }
        if (choice == Replace) {
            file.open(path, fstream::out); // ���� ����������� ��� ������(������)
            if (file.is_open()) {
                cout << "�� ������� ��������� ������ � ����!" << endl << endl;
                return file;
            }
            else {
                while (!file.is_open()) {
                    cout << "������ �������� �����! ���������� �����." << endl;
                    path = EnteringPathToFile();
                    break;
                }
            }
        }

        if (choice == Append) {
            file.open(path, fstream::out | fstream::app); // ��������� �������� �, �� ������ ��� ���������� �������� ����� � ����� ��������������, ������ - ��� ������(out), ������ ��� ���� ����� ��� �������� ����� ������ ������� ���� � ����� �� ���������(app)
            //�� �� ��������� ����� ������� ������ ��� ��������(trunc). �������� ����� ��� ���� ����� �������� ��� �� ��� ��������� � ��� ������(out) � ��� ��������(app)
            if (file.is_open()) {
                cout << "�� ������� ��������� ������ � ����!" << endl << endl;
                return file;
            }
            else {
                while (!file.is_open()) {
                    cout << "������ �������� �����! ���������� �����." << endl;
                    path = EnteringPathToFile();
                    break;
                }
            }
        }
        if (choice == OtherName) {
            path = EnteringPathToFile();
        }
    }
    file.open(path, fstream::out);
    return file;
}