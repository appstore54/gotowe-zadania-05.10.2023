#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

struct Student {
    std::string nazwisko;
    int ocena;
};

std::vector<Student> wczytajDaneZPliku(const std::string& nazwaPliku) {
    std::vector<Student> studenci;
    std::ifstream plik(nazwaPliku);
    if (plik.is_open()) {
        std::string linia;
        while (std::getline(plik, linia)) {
            std::istringstream iss(linia);
            Student student;
            iss >> student.nazwisko >> student.ocena;
            studenci.push_back(student);
        }
        plik.close();
    } else {
        std::cerr << "Nie mozna otworzyc pliku: " << nazwaPliku << std::endl;
    }
    return studenci;
}

double obliczSrednia(const std::vector<Student>& studenci) {
    double suma = 0;
    for (const auto& student : studenci) {
        suma += student.ocena;
    }
    return studenci.empty() ? 0 : suma / studenci.size();
}

int znajdzNajwyzszaOcene(const std::vector<Student>& studenci) {
    return std::max_element(studenci.begin(), studenci.end(), 
                            [](const Student& a, const Student& b) {
                                return a.ocena < b.ocena;
                            })->ocena;
}

int znajdzNajnizszaOcene(const std::vector<Student>& studenci) {
    return std::min_element(studenci.begin(), studenci.end(), 
                            [](const Student& a, const Student& b) {
                                return a.ocena < b.ocena;
                            })->ocena;
}

int policzZdanych(const std::vector<Student>& studenci) {
    return std::count_if(studenci.begin(), studenci.end(), [](const Student& student) {
        return student.ocena >= 50;
    });
}

std::vector<std::string> znajdzNiezdanych(const std::vector<Student>& studenci) {
    std::vector<std::string> niezdani;
    for (const auto& student : studenci) {
        if (student.ocena < 50) {
            niezdani.push_back(student.nazwisko);
        }
    }
    return niezdani;
}

void zapiszRaportDoPliku(const std::string& nazwaPliku, double srednia, int najwyzsza, int najnizsza, int zdani, const std::vector<std::string>& niezdani) {
    std::ofstream plik(nazwaPliku);
    if (plik.is_open()) {
        plik << "Srednia ocena wszystkich studentow: " << srednia << std::endl;
        plik << "Najwyzsza ocena: " << najwyzsza << std::endl;
        plik << "Najnizsza ocena: " << najnizsza << std::endl;
        plik << "Liczba studentow, ktorzy zdali: " << zdani << std::endl;
        plik << "Lista studentow, ktorzy nie zdali:" << std::endl;
        for (const auto& nazwisko : niezdani) {
            plik << nazwisko << std::endl;
        }
        plik.close();
    } else {
        std::cerr << "Nie mozna otworzyc pliku do zapisu: " << nazwaPliku << std::endl;
    }
}

int main() {
    const std::string nazwaPlikuWejsciowego = "wyniki.txt";
    const std::string nazwaPlikuWyjsciowego = "raport.txt";

    std::vector<Student> studenci = wczytajDaneZPliku(nazwaPlikuWejsciowego);

    double srednia = obliczSrednia(studenci);
    int najwyzsza = znajdzNajwyzszaOcene(studenci);
    int najnizsza = znajdzNajnizszaOcene(studenci);
    int zdani = policzZdanych(studenci);
    std::vector<std::string> niezdani = znajdzNiezdanych(studenci);

    zapiszRaportDoPliku(nazwaPlikuWyjsciowego, srednia, najwyzsza, najnizsza, zdani, niezdani);

    return 0;
}
