#include "Jaccard.h"
#include "ShoppingHistory.h"

double Jaccard::CalculateIndex(
    const ShoppingHistory& historyA, 
    const ShoppingHistory& historyB)
{
    const std::set<int>& setA = historyA.GetHistory();
    const std::set<int>& setB = historyB.GetHistory();

    std::set<int> intersection;
    std::set_intersection(
        setA.begin(), 
        setA.end(), 
        setB.begin(), 
        setB.end(), 
        std::inserter(intersection, intersection.begin())
    );

    std::set<int> unionSet;
    std::set_union(
        setA.begin(), 
        setA.end(), 
        setB.begin(), 
        setB.end(), 
        std::inserter(unionSet, unionSet.begin())
    );

    if (unionSet.empty()) {
        return 0.0;
    } else {
        return double(intersection.size()) / double(unionSet.size());
    }
}
