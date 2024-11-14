#include "FileManager.h"

void FileManager::saveToBinaryFile(BST& tree, const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    // Kod zapisu binarnego drzewa
    file.close();
}

void FileManager::loadFromBinaryFile(BST& tree, const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    // Kod odczytu binarnego drzewa
    file.close();
}

void FileManager::loadFromTextFile(BST& tree, const std::string& filename) {
    std::ifstream file(filename);
    int value;
    while (file >> value) {
        tree.add(value);
    }
    file.close();
}
