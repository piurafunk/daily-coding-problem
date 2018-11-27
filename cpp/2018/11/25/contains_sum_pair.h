#include <iostream>
#include <vector>
#include <algorithm>

namespace algorithm
{

template <class T>
bool contains_sum_pair(const std::vector<T> &vector, T sum)
{
    typename std::vector<T>::const_iterator i = vector.begin();
    while (i != vector.end())
    {
        if (std::find(vector.begin(), vector.end(), sum - *i) != vector.end())
        {
            return true;
        }
        i++;
    }

    return false;
}

} // namespace algorithm