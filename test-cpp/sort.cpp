#include <stdio.h>
#include <array>

void swap(int& lhs, int& rhs)
{
    int temp = lhs;
    lhs = rhs;
    rhs = temp;
}

int main()
{
    std::array<int, 9> array = { 11, 3, 5, 11, 9, 2, 4, 1, 8 };
    int count = array.size();

    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
            }
        }
    }

    for (int i = 0; i < count; ++i) {
        printf("%d ", array[i]);
    }

    return 0;
}