#include "ShoppingHistory.h"

ShoppingHistory::ShoppingHistory(const std::string& shopperId) 
{
    this->shopperId = shopperId;
}

void ShoppingHistory::AddShopItem(int productId)
{
    history.insert(productId);
}

const std::set<int>& ShoppingHistory::GetHistory() const
{
    return history;
}

const std::string& ShoppingHistory::GetShopperId() const
{
    return shopperId;
}

bool ShoppingHistory::HaveBought(int productId) const
{
    return history.find(productId) != history.end();
}