#include "list.hpp"
#include <iterator>
#include <list>
#include <algorithm>

// using namespace std;

int main()
{
    // Create a list containing integers
    my_list<int> l = {7, 5, 16, 8};
    // my_list<int> l;
 
    // Add an integer to the front of the list
    l.push_front(2);
    l.push_front(13);
    // Add an integer to the back of the list
    l.push_back(33);
 
    // Insert an integer before 16 by searching
    auto it = std::find(l.begin(), l.end(), 13);
    std::cout << *it << std::endl;

    if (it != l.end())
        l.insert(it, 42);

    std::cout << "size = " << l.get_size() << std::endl;

    std::cout << "l = { ";
    for (auto it = l.begin(); it != l.end(); ++it)
    {
        const auto i = *it;
        std::cout << i << ", ";
    }
    std::cout << "};\n";

    std::cout << "reverse" << std::endl;
    auto n = l.end();
    --n;
    std::cout << "l = { ";
    while (n != l.end())
    {
        std::cout << *n << ", ";
        --n;
    }
    std::cout << "};\n";
}