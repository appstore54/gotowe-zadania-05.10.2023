

#include <iostream>

using namespace std;

int main()
{
int x;
cout << "Wprowadz wiek: ";
cin >> x;
if (x <= 11)
cout << "dziecko";
else if (x > 11 && x < 18)
cout << "nastolatek";
else
cout << "dorosly";
}