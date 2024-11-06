#include "PlikiBST.h"
#include <fstream>

void PlikiBST::zapiszDoPliku(const DrzewoBST& drzewo, const std::string& nazwa) {
    std::ofstream plik(nazwa, std::ios::binary);
    // Do implementacji zapisu binarnego drzewa.
}

void PlikiBST::wczytajZPliku(DrzewoBST& drzewo, const std::string& nazwa) {
    std::ifstream plik(nazwa, std::ios::binary);
    // Do implementacji odczytu binarnego drzewa.
}

void PlikiBST::wczytajZTeksu(DrzewoBST& drzewo, const std::string& nazwa) {
    std::ifstream plik(nazwa);
    int liczba;
    while (plik >> liczba) {
        drzewo.dodaj(liczba);
    }
}
