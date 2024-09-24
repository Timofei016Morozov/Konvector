#include <iostream>
#include <iomanip>

using namespace std;
const double USD_RATE = 82.0;  
const double EUR_RATE = 90.0; 
const double CNY_RATE = 12.0;
const double GBP_RATE = 37.0;
const double JPY_RATE = 0.6;   
const double COMMISSION_RATE = 0.05;  

double convertCurrency(double amountRub, double exchangeRate, double& commission) {
    commission = amountRub * COMMISSION_RATE;
    double amountAfterCommission = amountRub - commission;
    return amountAfterCommission / exchangeRate;
}

int main() {

    setlocale(LC_ALL, "Russian");


    while (true) {
        double amountRub;
        cout << "Введите количество рублей для обмена: ";
        cin >> amountRub;

        if (amountRub <= 0) {
            cout << "Сумма должна быть положительной. Попробуйте снова." << endl;
            continue;
        }

        cout << "\nВыберите валюту для обмена:" << endl;
        cout << "1. Доллар" << endl;
        cout << "2. Евро" << endl;
        cout << "3. Юань" << endl;
        cout << "4. Фарит" << endl;
        cout << "5. Йена" << endl;

        int choice;
        cout << "Введите номер валюты (1-5): ";
        cin >> choice;

        if (choice < 1 || choice > 5) {
            cout << "Неверный выбор. Попробуйте снова." << endl;
            continue;
        }

        double exchangeRate;
        string currencyName;

        switch (choice) {
        case 1:
            exchangeRate = USD_RATE;
            currencyName = "Доллар";
            break;
        case 2:
            exchangeRate = EUR_RATE;
            currencyName = "Евро";
            break;
        case 3:
            exchangeRate = CNY_RATE;
            currencyName = "Юань";
            break;
        case 4:
            exchangeRate = GBP_RATE;
            currencyName = "Фарит";
            break;
        case 5:
            exchangeRate = JPY_RATE;
            currencyName = "Йена";
            break;
        }

        double commission;
        double convertedAmount = convertCurrency(amountRub, exchangeRate, commission);

        cout << fixed << setprecision(2);
        cout << "\nВы получили " << convertedAmount << " " << currencyName << "." << endl;
        cout << "Комиссия составила: " << commission << " рублей." << endl;

        string repeat;
        cout << "\nХотите повторить обмен? (да/нет): ";
        cin >> repeat;

    
        if (repeat == "нет" || repeat == "Нет" || repeat == "НЕТ") {
            cout << "Спасибо за использование конвертера валют!" << endl;
            break; 
        }
    }

    return 0;
}

