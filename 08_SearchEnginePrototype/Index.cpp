// Index.cpp

#include "Index.h"
#include <sstream>
#include <algorithm>
#include <cctype>
#include <iostream> // for debugging

// Helper function to convert string to lowercase
std::string toLower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Tokenize the content into words
std::vector<std::string> Index::tokenize(const std::string& content) const {
    std::vector<std::string> tokens;
    std::stringstream ss(content);
    std::string word;
    while (ss >> word) {
        // Remove punctuation from the word
        word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());
        // Convert to lowercase for case-insensitive search
        tokens.push_back(toLower(word));
    }
    return tokens;
}

// Add document to the index
void Index::addDocument(const std::shared_ptr<Document>& document) {
    // Check if document with the same title already exists
    if (documents.find(document->getTitle()) == documents.end()) {
        documents[document->getTitle()] = document;
        std::vector<std::string> tokens = tokenize(document->getContent());
        for (const std::string& token : tokens) {
            index[token].push_back(document);
        }
    } else {
        std::cerr << "Document with title '" << document->getTitle() << "' already exists." << std::endl;
    }
}

// Search for documents containing the query
std::vector<std::shared_ptr<Document>> Index::search(const std::string& query) const {
    std::vector<std::shared_ptr<Document>> results;
    std::string lowerQuery = toLower(query);
    if (index.find(lowerQuery) != index.end()) {
        // Retrieve documents for the query term
        results = index.at(lowerQuery);

        // Ensure uniqueness of results (optional step)
        std::sort(results.begin(), results.end());
        results.erase(std::unique(results.begin(), results.end()), results.end());
    }
    return results;
}
