//zadanie 7

#include <iostream>
#include <string>
#include <array>

template <typename T>
const void find(const T& array, size_t size)
{
    typename T::value_type x;
    std::cout << "Введите ключ" << std::endl;
    std::cin >> x;
    
    int c = 0;
    
    for (size_t i = 0; i < size; i++) {
        if (array[i] == x)
        {
            //std::cout << "Найдено совпадение с ключом: " << array[i] << std::endl;
            c++;
        }
        if (c != 0)
        {
            std::cout << "Найдено совпадение с ключом: " << array[i] << " индекс: "<< i <<std::endl;
            break;
        }
    }
    if (c == 0)
    {
        std::cout << " совпадений нет " << std::endl;
    }
    
}

int main()
{
    setlocale(LC_ALL, "ru");
    std::array<int, 8> index_html = { 2,4,7,1,8,3,5,9 };
    find(index_html, size(index_html));
    std::string str("zcdfab");
    find(str, size(str));
}




