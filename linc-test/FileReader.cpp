#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "FileReader.h"

#define MAX_BUFFER_SIZE 1024

bool FileReader::Parse(
    const char* file, 
    std::map<std::string, ShoppingHistory>& allHistory /*output*/)
{
    std::string buffer;
    std::ifstream inputStream;
    inputStream.open(file);
    if (!inputStream.good()) {
        std::cout << "open file " << file << " error." << std::endl;
        return false;
    }

    // drop first header line
    std::getline(inputStream, buffer);

    // read each line
    while (std::getline(inputStream, buffer)) {
        std::stringstream dataStream(buffer);
        std::vector<std::string> tokens;
        std::string value;

        // tokenize data and delimiter is TAB
        // columns: "Shopper ID" "Product ID" "Purchase datetime"
        while (std::getline(dataStream, value, '\t')) {
            tokens.push_back(value);
        }

        std::string shopperId = tokens.at(0);
        int productId = ::atoi(tokens.at(1).c_str());
        std::map<std::string, ShoppingHistory>::iterator it = allHistory.find(shopperId);
        if (it != allHistory.end()) {
            it->second.AddShopItem(productId);
        } else {
            ShoppingHistory shoppingHistory(shopperId);
            shoppingHistory.AddShopItem(productId);
            allHistory.insert(
                std::pair<std::string, ShoppingHistory>(shopperId, shoppingHistory)
            );
        }
    }

    inputStream.close();    

    return true;
}