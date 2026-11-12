#include <iostream>
#include <limits>
#include <string>
#include <random>
#include <windows.h>
#include <algorithm>
#include <cstring>
#include <chrono>

using namespace std::chrono;
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int bw = 0;
    while (bw == 0){
        const int N = 100;
        int choice;
        mt19937 gen(random_device{}());
        uniform_int_distribution<int> dist(-99, 99);
        cout << "Выбери пункт (0-9)" << endl;
        cout << "1. Создание целочисленного массива размерности 100 со случайными значениями" << endl;
        cout << "2. Отсортировать массив различными сортировками" << endl;
        cout << "3. Найти максимальный и минимальный элементы массива" << endl;
        cout << "4. Вывести среднее значение максимума и минимума" << endl;
        cout << "5. Вывести количество элементов, которые меньше числа" << endl;
        cout << "6. Вывести количество элементов, которые больше числа" << endl;
        cout << "7. Проверить наличие числа в массиве через бинарный поиск" << endl;
        cout << "8. Поменять местами элементы массива" << endl;
        cout << "9. Определить, отсортирован ли массив" << endl;
        
        cin >> choice;
        
        switch(choice){
            case 0:
            {
                return 0;
            }
            case 1:{ 
                int arr[N];
                for(int i = 0; i < N; i++){
                    arr[i] = dist(gen);
                }
                for(int i = 0; i < N; i++){
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;
            }
            case 2:{
                int orig[N];
                int a[N];
                for(int i = 0; i < N; i++){
                    orig[i] = dist(gen);
                }
                for (int i = 0; i < N; i++) a[i] = orig[i];
                cout << "Пузырьковая сортировка" << endl;
                auto start = steady_clock::now();
                for (int i = 0; i < N - 1; i++) {
                    bool swapped = false;
                    for (int j = 0; j < N - 1 - i; j++) {
                        if (a[j] > a[j + 1]) {
                            swap(a[j], a[j + 1]);
                            swapped = true;
                        }
                    }
                    if (!swapped) break;
                }
                auto end = steady_clock::now();
                double konec = duration<double, std::micro>(end - start).count();
                cout << konec << "мкс" << endl;
                

                cout << "Сортировка вставками" << endl;
                for (int i = 0; i < N; i++) a[i] = orig[i];
                auto start1 = steady_clock::now();
                for (int i = 1; i < N; i++) {
                    int key = a[i];
                    int j = i - 1;
                    while (j >= 0 && a[j] > key) {
                        a[j + 1] = a[j];
                        j--;
                    }
                    a[j + 1] = key;
                }
                auto end1 = steady_clock::now();
                double konec1 = duration<double, std::micro>(end1 - start1).count();
                cout << konec1 << "мкс" << endl;


                cout << "Сортировка выбором" << endl;
                for (int i = 0; i < N; i++) a[i] = orig[i];
                auto start2 = steady_clock::now();
                for (int i = 0; i < N - 1; i++) {
                    int min = i;
                    for (int j = i + 1; j < N; j++) {
                        if (a[j] < a[min]) min = j;
                    }
                    if (min != i) swap(a[i], a[min]);
                }
                auto end2 = steady_clock::now();
                double konec2 = duration<double, std::micro>(end2 - start2).count();
                cout << konec2 << "мкс" << endl;

                
                cout << "Шейкерная сортировка" << endl;
                for (int i = 0; i < N; i++) a[i] = orig[i];
                auto start3 = steady_clock::now();
                int left = 0, right = N - 1;
                bool swapped = true;
                while (swapped && left < right) {
                    swapped = false;
                    for (int i = left; i < right; i++) {
                        if (a[i] > a[i + 1]) {
                            swap(a[i], a[i + 1]);
                            swapped = true;
                        }
                    }
                    right--;
                    for (int i = right; i > left; i--) {
                        if (a[i - 1] > a[i]) {
                            swap(a[i - 1], a[i]);
                            swapped = true;
                        }
                    }
                    left++;
                }
                auto end3 = steady_clock::now();
                double konec3 = duration<double, std::micro>(end3 - start3).count();
                cout << konec3 << "мкс" << endl;


                cout << "Стандартная сортировка" << endl;
                for (int i = 0; i < N; i++) a[i] = orig[i];
                auto start4 = steady_clock::now();
                sort(a, a+N);
                auto end4 = steady_clock::now();
                double konec4 = duration<double, std::micro>(end4 - start4).count();
                cout << konec4 << "мкс" << endl;
                
                cout << " " << endl;
                cout << "Самая долгая : ";
                if ((konec > konec1) && (konec > konec2) && (konec > konec3)){
                    cout << "Пузырьковая" << endl;
                }
                if ((konec1 > konec) && (konec1 > konec2) && (konec1 > konec3)){
                    cout << "Вставками" << endl;
                }
                if ((konec2 > konec1) && (konec2 > konec) && (konec2 > konec3)){
                    cout << "Выбором" << endl;
                }
                if ((konec3 > konec1) && (konec3 > konec2) && (konec3 > konec)){
                    cout << "Шейкерная" << endl;
                }
                
                cout << " " << endl;
                cout << "Самая быстрая : ";
                if ((konec < konec1) && (konec < konec2) && (konec < konec3) && (konec < konec4)){
                    cout << "Пузырьковая" << endl;
                }
                if ((konec1 < konec) && (konec1 < konec2) && (konec1 < konec3) && (konec1 < konec4)){
                    cout << "Вставками" << endl;
                }
                if ((konec2 < konec1) && (konec2 < konec) && (konec2 < konec3) && (konec2 < konec4)){
                    cout << "Выбором" << endl;
                }
                if ((konec3 < konec1) && (konec3 < konec2) && (konec3 < konec) && (konec3 < konec4)){
                    cout << "Шейкерная" << endl;
                }
                if ((konec4 < konec1) && (konec4 < konec2) && (konec4 < konec) && (konec4 < konec3)){
                    cout << "Стандартная" << endl;
                }
                break;
            }
                case 3:{
                    int arr[N];
                    for(int i = 0; i < N; i++){
                        arr[i] = dist(gen);
                    }
                    int mx = -100000000;
                    int mn = 100000000;
                    cout << "НЕОТСОРТИРОВАННЫЙ МАССИВ" << endl;
                    auto start12 = steady_clock::now();
                    for(int i = 0; i < N; i++){
                        if(mx < arr[i]){
                            mx = arr[i];
                        } 
                    }
                    auto end12 = steady_clock::now();
                    double k = duration<double, std::nano>(end12 - start12).count();
                    cout << "Самое большое число : " << mx << endl;
                    cout << "Время за которое найдено число : " << k << " нс" << endl;

                    auto start13 = steady_clock::now();
                    for(int i = 0; i < N; i++){
                        if(mn > arr[i]){
                            mn = arr[i];
                        } 
                    }
                    auto end13 = steady_clock::now();
                    double k1 = duration<double, std::nano>(end13 - start13).count();
                    cout << "Самое маленькое число : " << mn << endl;
                    cout << "Время за которое найдено число : " << k1 << " нс" << endl;
                    
                    cout << endl;
                    cout << "ОТСОРТИРОВАННЫЙ МАССИВ" << endl;
                    sort(arr, arr+N);
                    auto start14 = steady_clock::now();
                    int mx1 = arr[N-1];
                    auto end14 = steady_clock::now();
                    double k2 = duration<double, std::nano>(end14 - start14).count();
                    cout << "Самое большое число : " << mx1 << endl;
                    cout << "Время за которое найдено число : " << k2 << " нс" << endl;

                    auto start15 = steady_clock::now();
                    int mn1 = arr[0];
                    auto end15 = steady_clock::now();
                    double k3 = duration<double, std::nano>(end15 - start15).count();
                    cout << "Самое маленькое число : " << mn1 << endl;
                    cout << "Время за которое найдено число : " << k3 << " нс" << endl;

                    if (k + k1 > k2 + k3){
                        cout << "Время выполнения для отсортированного массива меньше" << endl;
                    }
                    else{
                        cout << "Время выполнения для неотсортированного массива меньше" << endl;
                    }
                    break; 
                }
                case 4:{
                    int original[N];
                    int a[N];
                    for(int i = 0; i < N; i++){
                        original[i] = dist(gen);
                    }
                    for (int i = 0; i < N; i++) a[i] = original[i];

                    sort(a,a+N);
                    int mid = (a[0]+a[N-1])/2;
                    int index[N];
                    int count = 0;

                    auto nach1 = steady_clock::now();
                    for (int i = 0; i < N; i++){
                        if (original[i] == mid){
                            index[count] = i;
                            count++;
                        }
                    }

                    auto kon1 = steady_clock::now();
                    double r = duration<double, std::nano>(kon1 - nach1).count();
                    cout << "В неотсортированном массиве найдено : " << count << " элементов" << endl;
                    cout << "Индексы найденных чисел : ";
                    for(int i = 0; i < count; i++){
                        cout << index[i] << " ";
                    }
                    cout << "Это заняло : " << r << " нс" << endl;


                    int index1[N];
                    int count1=0;
                    auto nach2 = steady_clock::now();
                    for (int i = 0; i < N; i++){
                        if (a[i] == mid){
                            index1[count1] = i;
                            count1++;
                        }
                    }

                    auto kon2 = steady_clock::now();
                    double r1 = duration<double, std::nano>(kon2 - nach2).count();
                    cout << "В отсортированном массиве найдено : " << count1 << " элементов" << endl;
                    cout << "Индексы найденных чисел : ";
                    for(int i = 0; i < count1; i++){
                        cout << index1[i] << " ";
                    }
                    cout << "Это заняло : " << r1 << " нс" << endl;
                    break;
                }
                case 5:{
                    int a[N];
                    for(int i = 0; i < N; i++){
                        a[i] = dist(gen);
                    }
                    sort(a,a+N);
                    int v;
                    cout << "Введите число : ";
                    cin >> v;
                    cout << endl;

                    auto nach1 = steady_clock::now();
                    int count = 0;
                    for (int i = 0; i < N; i++){
                        if (a[i] < v){
                            count++;
                        }
                    }
                    auto kon1 = steady_clock::now();
                    double tLin = duration<double, std::nano>(kon1 - nach1).count();

                    auto nach2 = steady_clock::now();
                    int left = 0, right = N;
                    while (left < right) {
                        int m = left + (right - left) / 2;
                        if (a[m] < v) left = m + 1;
                        else          right = m;
                    }
                    int countBin = left;
                    auto kon2 = steady_clock::now();
                    double tBin = duration<double, std::nano>(kon2 - nach2).count();

                    cout << "Линейно: найдено " << count << " элементов меньше " << v
                        << ", время " << tLin << " нс" << endl;
                    cout << "Бинарно: найдено " << countBin << " элементов меньше " << v
                        << ", время " << tBin << " нс" << endl;
                    break;
                }
                case 6:{
                    int a[N];
                    for(int i = 0; i < N; i++){
                        a[i] = dist(gen);
                    }
                    sort(a,a+N);
                    int v;
                    cout << "Введите число : ";
                    cin >> v;
                    cout << endl;

                    auto nach1 = steady_clock::now();
                    int count = 0;
                    for (int i = 0; i < N; i++){
                        if (a[i] > v){
                            count++;
                        }
                    }
                    auto kon1 = steady_clock::now();
                    double tLin = duration<double, std::nano>(kon1 - nach1).count();

                    auto nach2 = steady_clock::now();
                    int left = 0, right = N;
                    while (left < right) {
                        int m = left + (right - left) / 2;
                        if (a[m] <= v) left = m + 1;
                        else           right = m;
                    }
                    int countBin = N - left;
                    auto kon2 = steady_clock::now();
                    double tBin = duration<double, std::nano>(kon2 - nach2).count();

                    cout << "Линейно: найдено " << count << " элементов больше " << v
                        << ", время " << tLin << " нс" << endl;
                    cout << "Бинарно: найдено " << countBin << " элементов больше " << v
                        << ", время " << tBin << " нс" << endl;
                    break;
                }
                case 7:{
                    int a[N];
                    for(int i = 0; i < N; i++){
                        a[i] = dist(gen);
                    }
                    sort(a,a+N);
                    int v;
                    cout << "Введите число : ";
                    cin >> v;
                    cout << endl;
                    const int K = 1000;

                    bool foundLin = false;
                    auto nach1 = steady_clock::now();
                    for (int k = 0; k < K; k++){
                        foundLin = false;
                        for (int i = 0; i < N; i++){
                            if (a[i] == v){
                                foundLin = true;
                                break;
                            }
                        }
                    }
                    auto kon1 = steady_clock::now();
                    double tLin = duration<double, std::nano>(kon1 - nach1).count() / K;

                    bool foundBin = false;
                    auto nach2 = steady_clock::now();
                    for (int k = 0; k < K; k++){
                        foundBin = false;
                        int left = 0, right = N - 1;
                        while (left <= right){
                            int m = left + (right - left) / 2;
                            if (a[m] == v){
                                foundBin = true;
                                break;
                            }
                            if (a[m] < v) left = m + 1;
                            else right = m - 1;
                        }
                    }
                    auto kon2 = steady_clock::now();
                    double tBin = duration<double, std::nano>(kon2 - nach2).count() / K;

                    if (foundLin) cout << "Линейный поиск: число найдено" << endl;
                    else cout << "Линейный поиск: числа нет" << endl;
                    if (foundBin) cout << "Бинарный поиск: число найдено" << endl;
                    else cout << "Бинарный поиск: числа нет" << endl;
                    cout << "Линейный, среднее время : " << tLin << " нс" << endl;
                    cout << "Бинарный, среднее время : " << tBin << " нс" << endl;
                    break;
                }
                case 8:{
                    int a[N];
                    for(int i = 0; i < N; i++){
                        a[i] = dist(gen);
                    }
                    int i1, i2;
                    cout << "Введите два индекса (0-" << N - 1 << ") : ";
                    cin >> i1 >> i2;
                    cout << endl;
                    if (i1 < 0 || i1 >= N || i2 < 0 || i2 >= N){
                        cout << "Неверный индекс" << endl;
                        break;
                    }
                    const int K = 100000;

                    cout << "До обмена : a[" << i1 << "] = " << a[i1] << ", a[" << i2 << "] = " << a[i2] << endl;
                    swap(a[i1], a[i2]);
                    cout << "После обмена : a[" << i1 << "] = " << a[i1] << ", a[" << i2 << "] = " << a[i2] << endl;

                    auto nach1 = steady_clock::now();
                    for (int i = 0; i < K; i++){
                        swap(a[i1], a[i2]);
                    }
                    auto kon1 = steady_clock::now();
                    double t = duration<double, std::nano>(kon1 - nach1).count() / K;

                    cout << "Среднее время одного обмена : " << t << " нс" << endl;
                    break;
                }
                case 9:{
                    int a[N];
                    for(int i = 0; i < N; i++){
                        a[i] = dist(gen);
                    }

                    int bad = -1;
                    for (int i = 0; i < N - 1; i++){
                        if (a[i] > a[i + 1]){
                            bad = i + 1;
                            break;
                        }
                    }
                    if (bad == -1) cout << "Массив отсортирован" << endl;
                    else cout << "Массив не отсортирован, порядок нарушается с индекса " << bad
                            << " (a[" << bad - 1 << "] = " << a[bad - 1] << " > a[" << bad << "] = " << a[bad] << ")" << endl;

                    sort(a, a + N);

                    bad = -1;
                    for (int i = 0; i < N - 1; i++){
                        if (a[i] > a[i + 1]){
                            bad = i + 1;
                            break;
                        }
                    }
                    if (bad == -1) cout << "После сортировки массив отсортирован" << endl;
                    else cout << "После сортировки порядок нарушается с индекса " << bad << endl;
                    break;
                }
            }
        }
    }