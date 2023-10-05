

#include <iostream>

using namespace std;

int main()
{
    int liczba1, liczba2;
    cout << "Wpisz pierwsza liczbe: ";
    cin >> liczba1;
    cout << "Wpisz druga liczbe: ";
    cin >> liczba2;
    if (liczba1%liczba2 == 0)
    cout << liczba1 << "jest podzielna bez reszty przez " << liczba2;
    else
     cout << liczba1 << "nie jest podzielna bez reszty przez " <<liczba2;
}
