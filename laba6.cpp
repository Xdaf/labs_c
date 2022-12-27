//zadanie 8
#include <iostream>
#include <string>
#include <eh.h>

#define n 6

class QueueException
{
private:
    std::string ms = "Queue exception";
public:
    QueueException(std::string ms) : ms(ms) 
    {
    }
    const char* what() const noexcept
    {
        return ms.c_str();
    }

};

class queue
{
private:
    int size = 0; 
    int arr[n];
public:
    queue()
    {
        for(int i = 0; i < n;i++)
        arr[i] = 0;
    }
    void add(int &x)
    {
        arr[size] = x;
        size++;
        if (size > n)
            throw QueueException("Переполнение очереди");
    }
    void del()
    {
        for (int i = 0; i < size -1 ; i++)
        {
            
            arr[i] = arr[i + 1];
            
        }
        size--;
        
        if (size < 0)
        {

            throw QueueException("Очередь пустая");
        }
    }
    size_t search(const int val)
    {
        for (const auto &q : arr)
            if (q == val)
                return &q - &arr[0];
        throw QueueException("Невозможно найти значение");
    }
    void Show()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << "Число: " << arr[i] << std::endl;
        }
    }

    bool operator==(const queue& A)
    {
        return size == A.size;
    }

    bool operator<(const queue& A)
    {
        return size < A.size;
    }
    bool operator>(const queue& A)
    {
        return size > A.size;
    }
    
    
};



void term_func()
{
    std::cout << "term_func была вызвана\n";
    exit(-1);
}
void unexpected()
{
    std::cout << "unexpected была вызвана" << std::endl;
}


int main()
{
    setlocale(LC_ALL, "ru");
    set_terminate(term_func);
    set_unexpected(unexpected);

    try
    {
        queue t;
        queue b;
        queue z;
        int c;
        std::string r;
        const char* c_r;
        
        int q = 1;
       
        while (q == 1) {
            int que = 1;
            std::cout<<"\33[H\33[J";
            std::cout << " 1 - добавление\n 2 - удаление\n 3 - вывод\n 4 - поиск " << std::endl;
            fflush(stdin);
            std::cin >> r;
            c_r = r.c_str();
            while (!(c = atoi(c_r)))
            {

                std::cout << "Ошибка ввода! Введите число: ";
                std::cin >> r;
                

            }
            system("cls");
           
            while (c < 5)
            {
                switch (c)
                {
                case 1:
                    int i;
                    int o;
                    std::cout << "Выберите очередь в которую хотите добавить введенное число: 1 - t, 2 - b, 3 - z, 4 - выход\n";
                    fflush(stdin);
                    std::cin >> r;
                    c_r = r.c_str();
                    while (!(o = atoi(c_r)))
                    {

                        std::cout << "Ошибка ввода! Введите число: ";
                        std::cin >> r;


                    }
                    system("cls");
                   

                    switch (o)
                    {
                    case 1:
                        std::cout << "Введите число которое хотите добаить: " << std::endl;
                        fflush(stdin);
                        std::cin >> r;
                        c_r = r.c_str();
                        while (!(i = atoi(c_r)))
                        {

                            std::cout << "Ошибка ввода! Введите число: ";
                            std::cin >> r;


                        }
                        
                        t.add(i);
                        break;
                    case 2:
                        std::cout << "Введите число которое хотите добаить: " << std::endl;
                        fflush(stdin);
                        std::cin >> r;
                        c_r = r.c_str();
                        while (!(i = atoi(c_r)))
                        {

                            std::cout << "Ошибка ввода! Введите число: ";
                            std::cin >> r;


                        }
                        std::cin >> i;
                        b.add(i);
                        break;
                    case 3:
                        std::cout << "Введите число которое хотите добаить: " << std::endl;
                        fflush(stdin);
                        std::cin >> r;
                        c_r = r.c_str();
                        while (!(i = atoi(c_r)))
                        {

                            std::cout << "Ошибка ввода! Введите число: ";
                            std::cin >> r;


                        }
                        std::cin >> i;
                        z.add(i);
                        break;
                    case 4:
                        c = 5;
                        break;
                    }
                    break;

                case 2:
                    std::cout << "Выберите очередь которую хотите очистить: 1 - t, 2 - b, 3 - z, 4 - выход\n";
                    int g;
                    fflush(stdin);
                    std::cin >> r;
                    c_r = r.c_str();
                    while (!(g = atoi(c_r)))
                    {

                        std::cout << "Ошибка ввода! Введите число: ";
                        std::cin >> r;


                    }
                   

                    switch (g)
                    {
                    case 1:
                        t.del();
                        std::cout << "очередь очищена" << std::endl;
                        break;
                    case 2:
                        b.del();
                        std::cout << "очередь очищена" << std::endl;
                        break;
                    case 3:
                        z.del();
                        std::cout << "очередь очищена" << std::endl;
                        break;
                    case 4:
                        c = 5;
                        break;

                    }
                    break;
                case 3:
                    std::cout << "Выберите очередь которую нужно вывести: 1 - t, 2 - b, 3 - z, 4 - выход\n";
                    int p;
                    fflush(stdin);
                    std::cin >> r;
                    c_r = r.c_str();
                    while (!(p = atoi(c_r)))
                    {

                        std::cout << "Ошибка ввода! Введите число: ";
                        std::cin >> r;


                    }
                    
                    switch (p)
                    {
                    case 1:
                        
                            t.Show();
                            std::cout << std::endl;
                        
                        break;
                    case 2:
                        
                            b.Show();
                            std::cout << std::endl;
                        
                        break;
                    case 3:
                        
                            z.Show();
                            std::cout << std::endl;
                        
                        break;
                    case 4:
                        c = 5;
                        break;
                    }
                    break;

                case 4:
                    std::cout << "Выберите очередь для поиска: 1 - t, 2 - b, 3 - z, 4 - выход\n";
                    int l , h;
                    fflush(stdin);
                    std::cin >> r;
                    c_r = r.c_str();
                    while (!(l = atoi(c_r)))
                    {

                        std::cout << "Ошибка ввода! Введите число: ";
                        std::cin >> r;


                    }
                   
                    switch (l)
                    {
                    case 1:
                        std::cout << " введите число для поиска: " << std::endl;
                        fflush(stdin);
                        std::cin >> r;
                        c_r = r.c_str();
                        while (!(h = atoi(c_r)))
                        {

                            std::cout << "Ошибка ввода! Введите число: ";
                            std::cin >> r;


                        }
                       

                        std::cout<< "Индекс: " << t.search(h) << std::endl;
                        break;
                    case 2:
                        std::cout << " введите число для поиска: " << std::endl;
                        fflush(stdin);
                        std::cin >> r;
                        c_r = r.c_str();
                        while (!(h = atoi(c_r)))
                        {

                            std::cout << "Ошибка ввода! Введите число: ";
                            std::cin >> r;


                        }
                        
                        std::cout << b.search(h) << std::endl;
                        break;
                    case 3:
                        std::cout << " введите число для поиска: " << std::endl;
                        fflush(stdin);
                        std::cin >> r;
                        c_r = r.c_str();
                        while (!(h = atoi(c_r)))
                        {

                            std::cout << "Ошибка ввода! Введите число: ";
                            std::cin >> r;


                        }
                        std::cout << z.search(h) << std::endl;
                        break;
                    case 4:
                        c = 5;
                        break;
                    }
                    break;
                    
                }


            }
            std::cout << "1 - continue, ... - exit" << std::endl;
            std::cin >> q;
        }
        if (t == b)
        {
            std::cout << "t == b" << std::endl;
        }
        else
        {
            std::cout << "t !=b " << std::endl;
        }
       
    }
    catch (const QueueException &ex)
    {
        std::cout << ex.what() << std::endl;
        terminate();
        
    }
   
}


