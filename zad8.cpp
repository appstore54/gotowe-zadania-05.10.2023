

#include <iostream>

using namespace std;

int main()
{
int x, y, z;
cout << "Wprowadz pierwsza liczbe: ";
cin >> x;
cout << "Wprowadz druga liczbe: ";
cin >> y;
cout << "Wprowadz trzecia liczbe: ";
cin >> z;
if ( x ==y || x == z || y == z)
cout << "conajmniej dwie liczby sa takie same";
else
cout << "zadna liczba nie jest taka sama";
}