#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>
#include <fstream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
public:
    BST();
    ~BST();

    void add(int value);
    bool remove(int value);
    void clear();
    bool findPath(int value, std::vector<int>& path);
    void display(int order);
    void saveToFile(const std::string& filename);

private:
    Node* root;
    Node* addRecursive(Node* node, int value);
    Node* removeRecursive(Node* node, int value);
    Node* findMin(Node* node);
    void clearRecursive(Node* node);
    bool findPathRecursive(Node* node, int value, std::vector<int>& path);
    void displayPreorder(Node* node);
    void displayInorder(Node* node);
    void displayPostorder(Node* node);
    void saveToFileRecursive(Node* node, std::ofstream& file);
};

#endif