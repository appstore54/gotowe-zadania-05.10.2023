

#include <iostream>

using namespace std;

int main()
{
int x;
cout << "Wprowadz rok";
cin >> x;
if ((x%4==0 && x%100!=0) || x%400==0)
cout << "w roku " << x << "luty mial 29 dni";
else
cout << "w roku " << x <<"luty mial 28 dni";
}