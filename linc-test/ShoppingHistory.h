#pragma once

#include <set>
#include <string>

class ShoppingHistory
{
    public:
        ShoppingHistory(const std::string& shopperId);

    public:
        void AddShopItem(int productId);
        const std::set<int>& GetHistory() const;
        const std::string& GetShopperId() const;
        bool HaveBought(int productId) const;

    private:
        std::string shopperId;
        std::set<int> history;
};