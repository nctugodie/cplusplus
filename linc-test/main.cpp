#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

#include "FileReader.h"
#include "Jaccard.h"

void MaxJaccardIndex(const std::map<std::string, ShoppingHistory>& allHistory) 
{
    double maxIndex(0.0);
    std::string shopperA, shopperB;

    std::map<std::string, ShoppingHistory>::const_iterator itA;
    for (itA = allHistory.begin(); itA != allHistory.end(); ++itA) {

        std::map<std::string, ShoppingHistory>::const_iterator itB;
        for (itB = std::next(itA); itB != allHistory.end(); ++itB) {
            double index = Jaccard::CalculateIndex(itA->second, itB->second);
            if (index > maxIndex) {
                maxIndex = index;
                shopperA = itA->first;
                shopperB = itB->first;
            }
        }
    }

    std::cout << "Max Jaccard Index: " << maxIndex << " from " << shopperA << ", " << shopperB << std::endl;
}

void TopRecommend(
    const std::map<std::string, ShoppingHistory>& allHistory, 
    const std::string& shopperId,
    int topN)
{
    std::map<std::string, ShoppingHistory>::const_iterator itMap = allHistory.find(shopperId);
    if (itMap == allHistory.end()) {
        std::cout << "No this shopper id: " << shopperId << std::endl;
        return;
    }

    std::set<int> productList;
    const ShoppingHistory& targetShopper = itMap->second;
    for (itMap = allHistory.begin(); itMap != allHistory.end(); ++itMap) {
        const std::set<int>& history = itMap->second.GetHistory();
        std::set_union(
            productList.begin(),
            productList.end(),
            history.begin(),
            history.end(),
            std::inserter(productList, productList.begin())
        );
    }

    std::vector<std::pair<double, int> > productRecommendList;
    std::set<int>::const_iterator itProductId = productList.begin();
    for (; itProductId != productList.end(); ++itProductId) {
        if (targetShopper.HaveBought(*itProductId)) {
            continue;
        }

        double sumJaccardIndex = 0.0;
        double count = 0.0;
        for (itMap = allHistory.begin(); itMap != allHistory.end(); ++itMap) {
            if (itMap->first == targetShopper.GetShopperId()) {
                continue;
            }

            const ShoppingHistory& otherShopper = itMap->second;
            if (!otherShopper.HaveBought(*itProductId)) {
                continue;
            }

            double index = Jaccard::CalculateIndex(targetShopper, otherShopper);
            sumJaccardIndex += index;
            ++count;
        }

        double recommendIndex = sumJaccardIndex / count;
        productRecommendList.push_back(std::pair<double, int>(recommendIndex, *itProductId));
    }

    std::sort(productRecommendList.begin(), productRecommendList.end());
    int count = 0;
    std::vector<std::pair<double, int> >::const_reverse_iterator it = productRecommendList.rbegin();
    for (; it != productRecommendList.rend() && count < topN; ++it, ++count) {
        std::cout << "Recommend index: " << it->first << " Product id: " << it->second <<  std::endl;
    }
}

int main()
{
    std::map<std::string, ShoppingHistory> allHistory;
    if (!FileReader::Parse("data.txt", allHistory)) {
        return -1;
    }

    ::MaxJaccardIndex(allHistory);
    ::TopRecommend(allHistory, std::string("andrew"), 3);

    return 0;
}