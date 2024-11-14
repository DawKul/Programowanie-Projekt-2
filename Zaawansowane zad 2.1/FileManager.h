#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <fstream>
#include <string>
#include "BST.h"

class FileManager {
public:
    void saveToBinaryFile(BST& tree, const std::string& filename);
    void loadFromBinaryFile(BST& tree, const std::string& filename);
    void loadFromTextFile(BST& tree, const std::string& filename);
};

#endif
