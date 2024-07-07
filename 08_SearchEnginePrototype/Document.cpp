#include "Document.h"
#include <fstream>
#include <iostream>

Document::Document(const std::string& title, const std::string& filePath)
    : title(title) {
    std::ifstream file(filePath);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            content += line + "\n";
        }
        file.close();
        std::cout << "File read successfully: " << filePath << std::endl;
    } else {
        std::cerr << "Error opening file: " << filePath << std::endl;
    }
}

std::string Document::getTitle() const {
    return title;
}

std::string Document::getContent() const {
    return content;
}
