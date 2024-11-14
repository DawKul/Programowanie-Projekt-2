#include <iostream>
#include <string>
#include <limits>
#include "BST.h"
#include "FileManager.h"

int main() {
    BST tree;                 // Obiekt drzewa BST
    FileManager fileManager;  // Obiekt do zarz¹dzania zapisem i odczytem plików
    int choice = -1;

    do {
        // Wyœwietlanie menu
        std::cout << "\nMenu:\n";
        std::cout << "1. Dodaj element\n";
        std::cout << "2. Usun element\n";
        std::cout << "3. Usun cale drzewo\n";
        std::cout << "4. Szukaj drogi do elementu\n";
        std::cout << "5. Wyswietl drzewo (1: preorder, 2: inorder, 3: postorder)\n";
        std::cout << "6. Zapisz drzewo do pliku tekstowego\n";
        std::cout << "7. Zapisz drzewo do pliku binarnego\n";
        std::cout << "8. Wczytaj drzewo z pliku tekstowego\n";
        std::cout << "9. Wczytaj drzewo z pliku binarnego\n";
        std::cout << "0. Wyjscie\n";
        std::cout << "Twoj wybor: ";
        std::cin >> choice;

        // Sprawdzenie b³êdów wejœcia
        if (std::cin.fail()) {
            std::cin.clear(); // Czyœci b³¹d wejœcia
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignoruje resztê linii
            choice = -1; // Ustawia `choice` na wartoœæ domyœln¹
            std::cout << "Nieprawidlowy wybor, sprobuj ponownie.\n";
            continue; // Przejœcie do nastêpnej iteracji pêtli
        }

        switch (choice) {
        case 1: {
            int value;
            std::cout << "Podaj wartosc do dodania: ";
            std::cin >> value;
            tree.add(value);
            std::cout << "Dodano element " << value << " do drzewa.\n";
            break;
        }
        case 2: {
            int value;
            std::cout << "Podaj wartosc do usuniecia: ";
            std::cin >> value;
            if (tree.remove(value)) {
                std::cout << "Usunieto element " << value << ".\n";
            }
            else {
                std::cout << "Element " << value << " nie zostal znaleziony.\n";
            }
            break;
        }
        case 3:
            tree.clear();
            std::cout << "Cale drzewo zostalo usuniete.\n";
            break;
        case 4: {
            int value;
            std::cout << "Podaj wartoœæ do znalezienia drogi: ";
            std::cin >> value;
            std::vector<int> path;
            if (tree.findPath(value, path)) {
                std::cout << "Droga do " << value << ": ";
                for (int node : path) {
                    std::cout << node << " ";
                }
                std::cout << "\n";
            }
            else {
                std::cout << "Element " << value << " nie zostal znaleziony.\n";
            }
            break;
        }
        case 5: {
            int displayChoice;
            std::cout << "Wybierz sposob wyswietlania (1: preorder, 2: inorder, 3: postorder): ";
            std::cin >> displayChoice;
            tree.display(displayChoice);
            std::cout << "\n";
            break;
        }
        case 6: {
            std::string filename;
            std::cout << "Podaj nazwe pliku tekstowego: ";
            std::cin >> filename;
            tree.saveToFile(filename);
            std::cout << "Drzewo zapisane do pliku tekstowego.\n";
            break;
        }
        case 7: {
            std::string filename;
            std::cout << "Podaj nazwe pliku binarnego: ";
            std::cin >> filename;
            fileManager.saveToBinaryFile(tree, filename);
            std::cout << "Drzewo zapisane do pliku binarnego.\n";
            break;
        }
        case 8: {
            std::string filename;
            std::cout << "Podaj nazwe pliku tekstowego: ";
            std::cin >> filename;
            fileManager.loadFromTextFile(tree, filename);
            std::cout << "Drzewo wczytane z pliku tekstowego.\n";
            break;
        }
        case 9: {
            std::string filename;
            std::cout << "Podaj nazwê pliku binarnego: ";
            std::cin >> filename;
            fileManager.loadFromBinaryFile(tree, filename);
            std::cout << "Drzewo wczytane z pliku binarnego.\n";
            break;
        }
        case 0:
            std::cout << "Wyjscie z programu.\n";
            break;
        default:
            std::cout << "Nieprawidlowy wybor, sprobuj ponownie.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}
