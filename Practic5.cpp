#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    //Число максимальных значений
    int const M = 5;

    //Размерность массива
    int const N = 10;

    //Инициализация массива случайных чисел
    int arr[N] { 33, 45, 37, 50, 40, 46, 49, 38, 31, 42 };

    int maxArr[M];

    //Заполнение массива случайными числами
    srand(time(0));
    
    int a = 30, b = 50;
    
    int value = 0;

    if (M > N) {
        cout << "Кол-во максимльных чисел не должно превышать размерности массива" << endl;
        return 0;
    }
    //Заполнение массива случайными числами
    for (int i = 0; i < N; ++i)
    {
        value = a + rand() & (b - a + 1);
        arr[i] = value;
        cout << value << " ";
    }
    
    cout << endl;

    //Временная переменная
    int t = 0;

    for (int i = 1; i < N; i++)
    {
        for (int j = N - 1; j >= i ; j--)
        {
            //Делаем сортировку по убыванию
            if (arr[j - 1] < arr[j]) {
                t = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = t;
            }
        }
    }

    //Заполнение массива максимальными значениями и вывод их на консоль
    for (int i = 0; i < M; i++)
    {
        maxArr[i] = arr[i];
        cout << maxArr[i] << " ";
    }

    cout << endl;

    ////Задание 2 - Вариант 10

    string text = "<html body > "
        "< a href=\"https://www.susu952uuuuuuu.ru\">< / a> < / body> < / html>"
        " lang=\"en\"> < head > href=\"https://www.susu123.ru\" "
        "<meta charset = \"UTF-8\"> href=\"https://ya.ru/?npr=1&utm_referrer=https%3A%2F%2Fyandex.ru%2F\" "
        "<body><a href=\"https://www.susu952.ru\">< / a> < / body> < / html>";

    for (int i = 0; i < text.size(); i++) {
        if (i + 4 < text.size() && text.substr(i, 4) == "href") {
            i += 4;
            while (i < text.size() && (text[i] == ' ' || text[i] == '=')) i++;
            if (i < text.size() && (text[i] == '"' || text[i] == '\'')) {
                char quote = text[i];
                i++;
                string link = "";
                while (i < text.size() && text[i] != quote) {
                    link += text[i];
                    i++;
                }
                cout << link << endl;
            }
        }
    }

}
