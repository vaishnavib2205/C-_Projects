#ifndef INDEX_H
#define INDEX_H

#include "Document.h"
#include <unordered_map>
#include <vector>
#include <memory>
#include <string>
#include <algorithm> // for std::sort

class Index {
private:
    std::unordered_map<std::string, std::shared_ptr<Document>> documents;
    std::unordered_map<std::string, std::vector<std::shared_ptr<Document>>> index;

    std::vector<std::string> tokenize(const std::string& content) const;

public:
    void addDocument(const std::shared_ptr<Document>& document);
    std::vector<std::shared_ptr<Document>> search(const std::string& query) const;
};

#endif
