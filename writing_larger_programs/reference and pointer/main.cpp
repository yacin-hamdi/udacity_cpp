#include <iostream>
using std::cout;

int main()
{

    int i = 1;
    int& j = i;

    cout << "i = " << i << std::endl;
    cout << "j = " << j << std::endl;

    i = 2;
    cout << "change i \n";
    cout << "i = " << i << std::endl;
    cout << "j = " << j << std::endl;

    j = 5;
    cout << "change j\n";
    cout << "i = " << i << std::endl;
    cout << "j = " << j << std::endl;
}