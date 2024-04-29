#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;


vector<string> wczytajSlowaZPliku(const string& nazwaPliku) {
    ifstream plik(nazwaPliku);
    vector<string> slowa;
    string slowo;
    if (plik.is_open()) {
        while (getline(plik, slowo)) {
            slowa.push_back(slowo);
        }
        plik.close();
    }
    else {
        cerr << "Błąd podczas otwierania pliku" << endl;
    }
    return slowa;
}

string losujHaslo(const vector<string>& slowa) {
    srand(time(nullptr));
    int indeks = rand() % slowa.size();
    return slowa[indeks];
}


void rysujSzubienice(int proby) {
    switch (proby) {
    case 0:
        cout << "________" << endl;
        cout << "|     |" << endl;
        cout << "|     O" << endl;
        cout << "|    /|\\ " << endl;
        cout << "|    / \\" << endl;
        cout << "|___" << endl;
        break;
    case 1:
        cout << "________" << endl;
        cout << "|     |" << endl;
        cout << "|     O" << endl;
        cout << "|    /|\\ " << endl;
        cout << "|    /" << endl;
        cout << "|___" << endl;
        break;
    case 2:
        cout << "________" << endl;
        cout << "|     |" << endl;
        cout << "|     O" << endl;
        cout << "|    /|\\ " << endl;
        cout << "|" << endl;
        cout << "|___" << endl;
        break;
    case 3:
        cout << "________" << endl;
        cout << "|     |" << endl;
        cout << "|     O" << endl;
        cout << "|    /|\\" << endl;
        cout << "|" << endl;
        cout << "|___" << endl;
        break;
    case 4:
        cout << "________" << endl;
        cout << "|     |" << endl;
        cout << "|     O" << endl;
        cout << "|     |" << endl;
        cout << "|" << endl;
        cout << "|___" << endl;
        break;
    case 5:
        cout << "________" << endl;
        cout << "|     |" << endl;
        cout << "|     O" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|___" << endl;
        break;
    default:
        cout << "________" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|" << endl;
        cout << "|___" << endl;
        break;
    }
}


bool sprawdzLitera(const string& haslo, char litera, string& ukryte) {
    bool znaleziona = false;
    for (int i = 0; i < haslo.length(); ++i) {
        if (haslo[i] == litera) {
            ukryte[i] = litera;
            znaleziona = true;
        }
    }
    return znaleziona;
}

int main() {
    vector<string> slowa = wczytajSlowaZPliku("C:/Users/jakub/Desktop/słowa/slowa.txt");
    if (slowa.empty()) {
        cerr << "Brak slow w pliku. Gra nie moze zostac uruchomiona." << endl;
        return 1;
    }

    string imie;
    cout << "Podaj swoje imie: ";
    cin >> imie;

    int maxProby = 5;
    int wybor;
    bool zakoncz = false;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Nowa gra" << endl;
        cout << "2. Sprawdz swoje wyniki" << endl;
        cout << "3. Zmiana ustawien" << endl;
        cout << "4. Wyjscie" << endl;
        cout << "Wybierz opcje: ";
        cin >> wybor;

        switch (wybor) {
        case 1: {
            string haslo = losujHaslo(slowa);
            string ukryte(haslo.length(), '_');
            int proby = 0;

            cout << "Zaczynamy gre, " << imie << "!" << endl;

            while (proby < maxProby) {
                cout << "Haslo do odgadniecia: " << ukryte << endl;
                cout << "Podaj litere: ";
                char litera;
                cin >> litera;

                if (sprawdzLitera(haslo, litera, ukryte)) {
                    cout << "Poprawna litera!" << endl;
                    if (ukryte == haslo) {
                        cout << "Gratulacje! Odgadles haslo: " << haslo << endl;
                        break;
                    }
                }
                else {
                    cout << "Niepoprawna litera!" << endl;
                    proby++;
                    rysujSzubienice(proby);
                    cout << "Liczba pozostalych prob: " << maxProby - proby << endl;
                }
            }

            if (proby == maxProby) {
                cout << "Niestety, nie udalo sie odgadnac hasla. Poprawne haslo to: " << haslo << endl;

            }
            break;
        }
        case 2: {
       
            cout << "Funkcja sprawdzajaca wyniki jeszcze nie zostala zaimplementowana." << endl;
            break;
        }
        case 3: {
            
            cout << "Podaj nowa maksymalna liczbe blednych prob (1-10): ";
            cin >> maxProby;
            while (maxProby < 1 || maxProby > 10 || cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Niepoprawna wartosc. Podaj liczbę od 1 do 10: ";
                cin >> maxProby;
            }
            break;
        }
        case 4: {
           
            zakoncz = true;
            break;
        }
        default:
            cout << "Niepoprawny wybor. Wybierz opcję z menu." << endl;
            break;
        }
    } while (!zakoncz);

    return 0;
}
