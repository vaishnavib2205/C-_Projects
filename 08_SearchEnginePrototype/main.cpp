#include "Document.h"
#include "Index.h"
#include <iostream>
#include <memory>
#include <algorithm> // for std::sort

int main() {
    Index index;

    // Create documents
    std::shared_ptr<Document> doc1 = std::make_shared<Document>("Doc1", "doc1.txt");
    std::shared_ptr<Document> doc2 = std::make_shared<Document>("Doc2", "doc2.txt");

    // Add documents to the index
    index.addDocument(doc1);
    index.addDocument(doc2);

    // Search for a term
    std::string query;
    std::cout << "Enter search query: ";
    std::getline(std::cin, query);
    std::vector<std::shared_ptr<Document>> results = index.search(query);

    // Display search results
    std::cout << "Search results for \"" << query << "\":" << std::endl;
    if (results.empty()) {
        std::cout << "No documents found." << std::endl;
    } else {
        // Track displayed titles to avoid duplication
        std::vector<std::string> displayedTitles;
        for (const auto& result : results) {
            std::string title = result->getTitle();
            // Check if title has already been displayed
            if (std::find(displayedTitles.begin(), displayedTitles.end(), title) == displayedTitles.end()) {
                displayedTitles.push_back(title);
                std::cout << "Document Title: " << title << std::endl;
                std::cout << "Content: " << result->getContent() << std::endl;
                std::cout << "--------------------------" << std::endl;
            }
        }
    }

    return 0;
}
