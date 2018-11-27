#include <vector>
#include <iterator>

namespace algorithm
{
template <class T>
std::vector<T> multiply_sibling_elements(const std::vector<T> &vector)
{
    std::vector<T> result(vector.size());

    typename std::vector<T>::iterator i = result.begin();

    while (i != result.end())
    {
        typename std::vector<T>::const_iterator j = vector.begin();
        bool initialized = false;

        while (j != vector.end())
        {
            // Skip if we are on the current index
            if (std::distance(i, result.begin()) == std::distance(j, vector.begin()))
            {
                j++;
                continue;
            }

            if (initialized)
            {
                // Multiply through
                *i *= *j;
            }
            else
            {
                // Initial value
                *i = *j;
                initialized = true;
            }

            // Increment loop
            j++;
        }

        // Increment loop
        i++;
    }

    return result;
}
} // namespace algorithm