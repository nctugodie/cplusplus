#pragma once

#include <map>
#include "ShoppingHistory.h"

class FileReader {
    public:
        static bool Parse(
            const char* file,
            std::map<std::string, ShoppingHistory>& allHistory /*output*/
        );
};