#include <iostream>
#include <string>
#include <vector>
 
//http://en.cppreference.com/w/cpp/language/union
union S
{
    std::string str;
    std::vector<int> vec;
    ~S() {} // needs to know which member is active, only possible in union-like class 
};          // the whole union occupies max(sizeof(string), sizeof(vector<int>))
 
int main()
{
    S s = {"Hello, world"};
    // at this point, reading from s.vec is undefined behavior
    std::cout << "s.str = " << s.str << '\n';
    s.str.~basic_string<char>();
    new (&s.vec) std::vector<int>;
    // now, s.vec is the active member of the union
    s.vec.push_back(10);
    std::cout << s.vec.size() << '\n';
    s.vec.~vector<int>();
}
