

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
if(x > y && y > z)
cout << x << "jest najwieksze";
else if ( y > x && y > z)
cout << y << "jest najwieksze";
else if (z > y && z > x)
cout << z << "jest najwieksze";
else
cout << "liczby sa te same";
}