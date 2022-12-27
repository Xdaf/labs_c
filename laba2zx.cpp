#include <iostream>
#include <string>
#include <conio.h>
#include <math.h>


class Complex
{
private:
    double x, y;// целая и мнимая части
    int arr[4]{ 10, 5, 4, 1 };

public:

    Complex()
    {
        x = 0;
        y = 0;
    } // конструктор по умолчанию

    Complex(double j, double i)
    {
        x = j;
        y = i;
    }

    ~Complex() {}

    Complex operator = (const Complex& c) // перегрузка оператора присваивания
    {
        x = c.x;
        y = c.y;

        return (*this);
    }

    Complex operator + (const Complex& c) // перегрузка оператора сложения
    {
        return Complex(this->x + c.x, this->y + c.y);
    }

    int & operator [] (int index)  // перегрузка индексации
    {
        return arr[index];
    }

    Complex operator++ (int)  // перегрузка ++
    {
        Complex temp;
        temp.y = y++;
        return temp;
    }
    Complex operator++ () 
    {
        Complex temp;
        temp.x = ++x;
        return temp;
    }
    bool operator ==(Complex& c)
    {
        return x == c.x && y == c.y;
    }


    friend std::ostream& operator<<(std::ostream&, Complex&); // перегрузка  <<
    friend Complex operator-- (Complex&, int);
    friend Complex operator-- (Complex&);

    operator int()
    {
        return x * y;
    }
};
std::ostream& operator<<(std::ostream& out, Complex& c)
{
    out << "(" << c.x << ") + I (" << c.y << ")" << "\n";

    return out;
}
Complex operator-- (Complex& c, int) // перегрузка мнимой части (--)
{
    Complex temp;
    temp.y = c.y--;
    return temp;

}
Complex operator-- (Complex& c) // перегрузка целой части (--)
{
    Complex temp;
    temp.x = --c.x;
    return temp;
}




int main()
{
    setlocale(LC_ALL, "Russian");

    Complex value1(5, 2);
    Complex value2(3, -3);
    Complex value3;
    Complex value4(10, 10);
    Complex value5(10, 10);
    Complex a;


    value3 = value1 + value2;
    std::cout << "перегрузка + : " << value3 << std::endl;
    value1++;
    std::cout << "перегрузка ++ : " << value1 << std::endl;
    value2--;
    std::cout << "перегрузка -- : " << value2 << std::endl;
    ++value1;
    std::cout << "++ перегрузка : " << value1 << std::endl;
    --value2;
    std::cout << "-- перегрузка : " << value2 << std::endl;
    if (value4 == value5)
    {
        std::cout << "перегрузка == : " << "значения равны" << std::endl;
    }
    else
    {
        std::cout << "перегрузка == : " << "значения различны" << std::endl;
    }
    std::cout << "преобразование типа: " << value4 + 10 << std::endl;

    value3 = value1 = value2;
    std::cout << "перегрузка = : " << value3 << std::endl;
    std::cout << "перегрузка [] :" << a[1] << std::endl;

    return 0;
}
