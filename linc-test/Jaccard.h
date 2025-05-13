#pragma once

class ShoppingHistory;

class Jaccard
{
    public:
        static double CalculateIndex(
            const ShoppingHistory& historyA, 
            const ShoppingHistory& historyB
        );
};