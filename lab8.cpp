#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> 
#include <iterator> 

using namespace std;

int main() {
    setlocale(LC_ALL, "Ukrainian");

    int n;
    cout << "Введіть розмір масиву: ";
    if (!(cin >> n) || n < 0) {
        cerr << "Невірний розмір." << endl;
        return 1;
    }

    if (n == 0) {
        cout << "Масив порожній." << endl;
        return 0;
    }

    vector<int> arr(n);
    cout << "Введіть елементи масиву: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    auto max_it = max_element(arr.begin(), arr.end());
    cout << "Максимальний елемент: " << *max_it
        << ", його індекс: " << distance(arr.begin(), max_it) << endl;

    auto first_zero = find(arr.begin(), arr.end(), 0);
    long long product = 1;
    auto second_zero = arr.end();

    if (first_zero != arr.end()) {
        if (std::next(first_zero) != arr.end()) {
            second_zero = find(std::next(first_zero), arr.end(), 0);
        }
    }

    if (first_zero != arr.end() && second_zero != arr.end()) {
        for (auto it = std::next(first_zero); it != second_zero; ++it) {
            product *= *it;
        }
        cout << "Добуток між першим і другим нулем: " << product << endl;
    }
    else {
        cout << "Маємо менше ніж два нулі -> добуток недоступний (встановлюю 0)." << endl;
        cout << "Добуток між першим і другим нулем: " << 0 << endl;
    }


    vector<int> odd_pos, even_pos;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0)
            even_pos.push_back(arr[i]);
        else
            odd_pos.push_back(arr[i]);
    }
    arr.clear();
    arr.insert(arr.end(), odd_pos.begin(), odd_pos.end());
    arr.insert(arr.end(), even_pos.begin(), even_pos.end());

    cout << "Масив після перетворення: ";
    for (auto x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
