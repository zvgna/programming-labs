#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

string text;
//удаление лишних пробелов
void DeleteSpace() {
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == ' ' && text[i + 1] == ' ')
            while (text[i + 1] == ' ')
                text.erase((i + 1), 1);
    }
}
//удаление лишних знаков
void Unsign() {
    for (int i = 0; i <= text.size(); i++) {
        if ((text[i] == '.' || text[i] == ',' || text[i] == ';' || text[i] == ':' || text[i] == '!' || text[i] == '?') && (text[i + 1] == '.' || text[i + 1] == ',' || text[i + 1] == ';' || text[i + 1] == ':' || text[i + 1] == '!' || text[i + 1] == '?'))
            if (text[i] == '.' && text[i + 1] == '.' && text[i + 2] == '.' && text[i + 3] == ' ')
                i += 3;
            else {
                while (text[i + 1] == '.' || text[i + 1] == ',' || text[i + 1] == ';' || text[i + 1] == ':' || text[i + 1] == '!' || text[i + 1] == '?')
                    text.erase((i + 1), 1);
            }
    }
}
//изменение регистра
void Registr() {
    for (int i = 1; i < text.size(); i++) {
        if (text[i] == ' ')
            i += 2;
        text[i] = tolower(text[i]);
    }
}
//идз.Вывести на экран ту же последовательность, удалив из всех слов заданный набор букв и (или) цифр.
void Posled (string txt) {
    string destr;
    cout << "\n4. Введите последовательность, которую хотите удалить из каждого слова: ";
    cin >> destr;
    for (int i = 0, k = 0; i < txt.size(); i++)
    {
        if (text[i] == destr[0]) {
            k = 1;
            for (int j = 1; j < destr.size(); j++) 
                if (destr[j] != txt[i + j]) {
                    k = 0;
                    break;
                }
            if (k == 1) {
                while (txt[i] != destr[destr.size() - 1])
                    txt.erase((i), 1);
                txt.erase((i), 1);
                i--;
            }
        }
    }
    cout << "\nРезультат изменения: " << txt <<"\n\n";
}
//линейный поиск
void Search() {
    string key;
    int k;
    int count = 0;

    cin >> key;

    for (int i = 0; i < text.size(); i++) {
        if (text[i] == key[0]) {
            k=1;
            for (int j = 1; j < key.size(); j++) {
                if (text[i + j] != key[j]) {
                    k = 0;
                    break;
                }
            }
            if (k == 1)
                count++;
        }
    }
    if (count == 0) {
        cout << "По запросу ничего не найдено";
    }
    else {
        cout << "Найдено " << count << " соответствий";
    }
}

int main()
{
    setlocale(0, "");

     {
        int input;
    Menu: {
        cout << "Создать новую последовательность или взять готовую\n" <<
            "1. Написать новую последовательность\n" <<
            "2. Взять готовую последовательность\n";
        cin >> input;
        }
    if (input == 1) {
        cin.ignore();
        getline(cin, text);
    }
    else if (input == 2) { 
        ifstream in("C:\\Users\\user\\Documents\\!prog\\lab - 4\\text.txt");

        if (in.is_open())
            getline(in, text);
        in.close();
    }
    else
        goto Menu;
    cout << "1. Исходная строка: " << text << "\n";
    }

     {
        DeleteSpace();
        Unsign();
        Registr();

        cout << "2. Отредактированная строка: " << text << "\n";
    }

    {
        cout << "3. Cтрока в обратном порядке: ";
        int a = 0;
        text += " ";

        for (int i = text.length(); i >= 0; i--) {
            if (text[i] == ' ') {
                for (int k = i + 1; k <= (i + a); k++) {
                    cout << text[k];
                }
                a = 0;
            }
            a++;
        }
        for (int i = 0; i < text.length(); i++) {
            if (text[i] == ' ') break;
            cout << text[i];
        }
    }

    {
        Posled(text);
    }

    {
        cout << "5. Введите подстроку, которую вы хотите найти в отредактированной строке: ";
        Search();
    }
}