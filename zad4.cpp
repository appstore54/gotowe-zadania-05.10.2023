

#include <iostream>

using namespace std;

int main()
{
int x;
cout << "Podaj liczbe ";
cin >> x;
if (x > 0)
cout << x << "jest wieksza od 0";
else if (x<0)
cout << x << "jest mniejszy od 0";
else
cout << x << "jest rowne 0";
}