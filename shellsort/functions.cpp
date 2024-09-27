/* 
Назначение:
    Модуль functions.cpp предназначен для проверки ввода данных пользователем.
    Он обеспечивает корректный ввод целочисленных и вещественных значений и сообщает пользователю о некорректных данных.
Авторы:
    Студенты Агеева Вероника и Карташов Артём.
Используемые алгоритмы:
    Функция CheckInt(): Эта функция считывает целочисленное значение, введенное пользователем.
    При обнаружении некорректных данных (например, ввод строки вместо числа), она очищает ввод и сообщает пользователю 
    о необходимости ввести целочисленное значение. После успешного ввода функция возвращает считанное целочисленное значение.
    Функция CheckDouble(): Аналогичный алгоритм использования функции CheckInt() только для вещественных чисел.
    Функция PrintArray(): служит для отображения содержимого вектора типа double на консоль.
    Она выводит каждый элемент вектора, разделяя их табуляцией, и в конце добавляет перенос строки.
    Функция IsReservedName(string path): служит для проверки зарезервированных системой имён, принимающая в себя путь к файлу.
    Функция EnteringPathToFile(): просит пользователя ввести путь к файлу или его название.
    Функция OpenFile(): необходима для открытия файла, чтобы записать данные в него. Если такой файл уже существует, то
    она предлагает альтернативыне пути решения: перезаписать файл, добавить данные или ввести другое название.
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
    while (getchar() != '\n') { // Функция getchar возвращает следующий символ из стандартного потока ввода
        while (cin.fail()) { //проверка на ошибку предыдущего ввода со стандартного ввода (с консоли, например вместо числа ввел строку)
            cin.ignore();// Метод cin.ignore предназначен для извлечения символов из входного потока (cin). Извлеченные символы игнорируются и не используются.
            cin.clear(); // Для очистки внутреннего состояния потока. После использования cin.clear внутреннее состояние снова устанавливается на goodbit, что означает отсутствие "ошибок"
            while (getchar() != '\n');
            cout << "Ошибка ввода, значение содержит неподходящий символ. Введите число заново:" << endl;
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
            cout << "Ошибка ввода, значение содержит неподходящий символ. Введите число заново:" << endl;
            cin >> Check;
        }
    }
    return Check;
}

void PrintArray(vector<double>& arr) {
    for (int i = 0; i < arr.size(); i++) { // Цикл от первого элемента массива до последнего
        cout << arr[i] << "\t"; // Вывод элемента массива и добавление табуляции
    }
    cout << endl;
}

bool IsReservedName(string path) {
    try {
        // если здесь выбивается ошибка (если имя зарезервировано), она передается в блок catch. is_regular_file проверяет зарезервировано ли имя файла
        return filesystem::is_regular_file(path);
    }
    catch (filesystem::filesystem_error) { // filesystem_error - ошибка на зарезервированное имя. Т.е. мы обрабатываем ошибку на зарезервированное имя
        return true;
    }
}

string EnteringPathToFile() {
    cout << "Укажите имя файла или путь к нему:" << endl;
    string NameOfFile; // C:\Users\User\Desktop\abcd.txt
    cin >> NameOfFile;
    if (NameOfFile.find(".txt") != NameOfFile.npos) { // find ищет .txt, возвращает индекс точки (какое-то число), если точки нету, то возвращает npos.  npos - статическая константа класса string (максимально возможное число для string)
        NameOfFile.erase(NameOfFile.find(".txt"), 4); // 4 = .txt (erase удаляет .txt)
    } // C:\Users\User\Desktop\abcd
    string ForCheck = NameOfFile;
    reverse(ForCheck.begin(), ForCheck.end()); // reverse переворачивает строку abcd -> dcba ( dcba\potkseD\resU\sresU\:C )
    istringstream iss(ForCheck); // мы создаем собственный поток ввода, чтобы потом использовать getline, в поток ввода помещаем forCheck
    if (ForCheck.find('\\') != ForCheck.npos) {
        getline(iss, ForCheck, '\\'); // читает до '\'. от пути остается dcba
    }
    reverse(ForCheck.begin(), ForCheck.end()); // abcd
    while (ForCheck.find_first_of("\\ / : ? \" < > | +") != ForCheck.npos or IsReservedName(ForCheck)) { // если существует хоть 1 из запрещенных символов, то он возвращает его индекс, если нет то возвращает npos
        cout << "Имя файла не должно содержать символы \\ / : ? \" < > | + и зарезервированные системой имена" << endl;
        cout << "Укажите имя файла или путь к нему:" << endl;
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
    while (filesystem::exists(path)) { // это функция, которая проверяет, существует ли указанный файл или каталог в файловой системе. Она возвращает true , если файл или каталог существует, и false в противном случае.
        int choice;
        cout << "1 - Заменить файл \n2 - Дозаписать в уже существующий \n3 - Использовать другое название" << endl;
        choice = CheckInt();
        while (choice != Replace and choice != Append and choice != OtherName) {
            while (getchar() != '\n');
            cout << "1 - Заменить файл \n2 - Дозаписать в уже существующий \n3 - Использовать другое название" << endl;
            choice = CheckInt();
        }
        if (choice == Replace) {
            file.open(path, fstream::out); // файл открывается для вывода(записи)
            if (file.is_open()) {
                cout << "Вы успешно сохранили данные в файл!" << endl << endl;
                return file;
            }
            else {
                while (!file.is_open()) {
                    cout << "Ошибка открытия файла! Попробуйте снова." << endl;
                    path = EnteringPathToFile();
                    break;
                }
            }
        }

        if (choice == Append) {
            file.open(path, fstream::out | fstream::app); // побитовый оператор И, он значит что происходит открытие файла с двумя модификаторами, первый - для записи(out), второй для того чтобы при открытия файла данные которые были в файле не удалялись(app)
            //тк по умолчанию стоит стереть данные при открытии(trunc). Оператор нужен для того чтобы показать что мы его открываем и для записи(out) и без удаления(app)
            if (file.is_open()) {
                cout << "Вы успешно сохранили данные в файл!" << endl << endl;
                return file;
            }
            else {
                while (!file.is_open()) {
                    cout << "Ошибка открытия файла! Попробуйте снова." << endl;
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