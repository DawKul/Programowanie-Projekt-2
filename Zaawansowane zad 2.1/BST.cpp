#include "BST.h"

BST::BST() : root(nullptr) {}

BST::~BST() {
    clear();
}

void BST::add(int value) {
    root = addRecursive(root, value);
}

Node* BST::addRecursive(Node* node, int value) {
    if (!node) return new Node(value);
    if (value < node->data)
        node->left = addRecursive(node->left, value);
    else if (value > node->data)
        node->right = addRecursive(node->right, value);
    return node;
}

bool BST::remove(int value) {
    if (!root) return false;
    root = removeRecursive(root, value);
    return true;
}

Node* BST::removeRecursive(Node* node, int value) {
    if (!node) return nullptr;
    if (value < node->data) {
        node->left = removeRecursive(node->left, value);
    }
    else if (value > node->data) {
        node->right = removeRecursive(node->right, value);
    }
    else {
        if (!node->left) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = findMin(node->right);
        node->data = temp->data;
        node->right = removeRecursive(node->right, temp->data);
    }
    return node;
}

Node* BST::findMin(Node* node) {
    while (node && node->left) node = node->left;
    return node;
}

void BST::clear() {
    clearRecursive(root);
    root = nullptr;
}

void BST::clearRecursive(Node* node) {
    if (!node) return;
    clearRecursive(node->left);
    clearRecursive(node->right);
    delete node;
}

bool BST::findPath(int value, std::vector<int>& path) {
    return findPathRecursive(root, value, path);
}

bool BST::findPathRecursive(Node* node, int value, std::vector<int>& path) {
    if (!node) return false;
    path.push_back(node->data);
    if (node->data == value) return true;
    if ((node->left && findPathRecursive(node->left, value, path)) ||
        (node->right && findPathRecursive(node->right, value, path)))
        return true;
    path.pop_back();
    return false;
}

void BST::display(int order) {
    switch (order) {
    case 1: displayPreorder(root); break;
    case 2: displayInorder(root); break;
    case 3: displayPostorder(root); break;
    default: std::cout << "Nieprawid³owy wybór.\n"; break;
    }
}

void BST::displayPreorder(Node* node) {
    if (!node) return;
    std::cout << node->data << " ";
    displayPreorder(node->left);
    displayPreorder(node->right);
}

void BST::displayInorder(Node* node) {
    if (!node) return;
    displayInorder(node->left);
    std::cout << node->data << " ";
    displayInorder(node->right);
}

void BST::displayPostorder(Node* node) {
    if (!node) return;
    displayPostorder(node->left);
    displayPostorder(node->right);
    std::cout << node->data << " ";
}

void BST::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        saveToFileRecursive(root, file);
        file.close();
    }
}

void BST::saveToFileRecursive(Node* node, std::ofstream& file) {
    if (!node) return;
    file << node->data << " ";
    saveToFileRecursive(node->left, file);
    saveToFileRecursive(node->right, file);
}
