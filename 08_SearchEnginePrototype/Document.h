#define DOCUMENT_H

#include <string>

class Document {
private:
    std::string title;
    std::string content;

public:
    Document(const std::string& title, const std::string& filePath);
    std::string getTitle() const;
    std::string getContent() const;
};

