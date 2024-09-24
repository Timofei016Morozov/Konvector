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
        cout << "������� ���������� ������ ��� ������: ";
        cin >> amountRub;

        if (amountRub <= 0) {
            cout << "����� ������ ���� �������������. ���������� �����." << endl;
            continue;
        }

        cout << "\n�������� ������ ��� ������:" << endl;
        cout << "1. ������" << endl;
        cout << "2. ����" << endl;
        cout << "3. ����" << endl;
        cout << "4. �����" << endl;
        cout << "5. ����" << endl;

        int choice;
        cout << "������� ����� ������ (1-5): ";
        cin >> choice;

        if (choice < 1 || choice > 5) {
            cout << "�������� �����. ���������� �����." << endl;
            continue;
        }

        double exchangeRate;
        string currencyName;

        switch (choice) {
        case 1:
            exchangeRate = USD_RATE;
            currencyName = "������";
            break;
        case 2:
            exchangeRate = EUR_RATE;
            currencyName = "����";
            break;
        case 3:
            exchangeRate = CNY_RATE;
            currencyName = "����";
            break;
        case 4:
            exchangeRate = GBP_RATE;
            currencyName = "�����";
            break;
        case 5:
            exchangeRate = JPY_RATE;
            currencyName = "����";
            break;
        }

        double commission;
        double convertedAmount = convertCurrency(amountRub, exchangeRate, commission);

        cout << fixed << setprecision(2);
        cout << "\n�� �������� " << convertedAmount << " " << currencyName << "." << endl;
        cout << "�������� ���������: " << commission << " ������." << endl;

        string repeat;
        cout << "\n������ ��������� �����? (��/���): ";
        cin >> repeat;

    
        if (repeat == "���" || repeat == "���" || repeat == "���") {
            cout << "������� �� ������������� ���������� �����!" << endl;
            break; 
        }
    }

    return 0;
}

