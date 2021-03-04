#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T>
class array
{
    private:
        T *p;
        size_t sz;
    public:
        array(size_t sz_)
        {
            sz = sz_;
            p = new T[sz];
        }
        int size()
        {
            return sz;
        }
        T& operator[] (size_t i)
        {
            return p[i];
        }
        void print(string delimeter = " ")
        {
            for (size_t i = 0; i < sz; i++) { std::cout << p[i]; if (i < sz - 1) std::cout << delimeter; }
            std::cout << endl;
        }
        void resize(size_t sz_)
        {
            T *p_new = new T[sz_];
            for (size_t i = 0; i < sz_ && i < sz; i++) p_new[i] = p[i];
            delete []p;
            p = p_new;
            sz = sz_;
        }
        ~array()
        {
            delete []p;
            std::cout << "CLEANING UP" << std::endl;
        }
};

int main()
{
    array<double> arr(10);
    for (size_t i = 0; i < arr.size(); i++) arr[i] = i;
    arr.print();
    arr.resize(14);
    arr.print();
}