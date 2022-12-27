// zadanie 10

#include <iostream>
#include <string>
#include <exception>
template<typename T>
class List
{
public:
   
    List()
    {
        size = 0;
        head = nullptr;
    }
    ~List()
    {
        clear();
    }

    void add(T data);
    int get_size()
    {
        return size;
    }
    T& show(const int index);
    int search(T data);
    void del();
    void clear()
    {
        while(size)
        del();
        
    }
    
    
private:
    template<typename T>
    class Node
    {
    public:
        Node* next;
        T data;

        Node(T data=T(), Node* next = nullptr)
        {
            this->data = data;
            this->next = next;
        }
    };
    Node<T> *head;
    int size;

};



template<typename T>
void List<T>::add(T data)
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {   
        Node<T>* cur = this->head;
        
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = new Node<T>(data);
    }
    size++;

}

template<typename T>
T& List<T>::show(const int index)
{
    int count = 0;
    Node<T>* cur = this->head;
    while (cur != nullptr)
    {
        if (count == index)
        {
            return cur->data;

        }
        cur = cur->next;
        count++;
    }
}

template<typename T>
int List<T>::search(T val)
{
    int count = 0;
    Node<T>* cur = this->head;
    while (cur != nullptr)
    {
        if (val == cur->data)
        {
            return count;
        }
        cur = cur->next;
        count++;
        
    }
    return -1;
    
}

template<typename T>
void List<T>::del()
{
    Node<T> *temp = head;
    head = head->next;
    delete temp;
    size--;
}

int main()
{
    setlocale(LC_ALL, "ru");
    int q = 1;
    List<int> list;
    std::string r;
    const char* c_r;
    int m;
    int f;
    int l;
    bool count = false;
    while (q == 1)
    {
        std::cout << "1 - Ввод числа в список" << std::endl;
        std::cout << "2 - Вывод списка" << std::endl;
        std::cout << "3 - Поиск числа и вывод его индекса" << std::endl;
        std::cout << "4 - Удаление из списка" << std::endl;
        std::cout << "5 - очистить список" << std::endl;
        std::cout << "число > 5 - Выход" << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Количество элементов в списке: " << list.get_size() << std::endl;
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
        default:
            q = 0;
            break;
        case 1:
            system("cls");
            std::cout << "Введите число в список: " << std::endl;
            fflush(stdin);
            std::cin >> r;
            c_r = r.c_str();
            while (!(m = atoi(c_r)))
            {

                std::cout << "Ошибка ввода! Введите число: ";
                std::cin >> r;


            }
            try 
            {
                if (m < 0)
                {
                    throw ("Число меньше 0");
                }
            }
            catch (const char*)
            {

                std::cout << "Число меньше 0" << std::endl;

                system("pause");
                system("cls");
                break;
            }
           
            list.add(m);
            system("cls");
            break;

           
        case 2:
            system("cls");
            for (int i = 0; i < list.get_size(); i++)
            {
                std::cout << list.show(i) << std::endl;
            }
            system("pause");
            system("cls");
            break;

           
        case 4:
            system("cls");
            list.del();
            break;
        case 3:
            system("cls");
            std::cout << "Введите число для поиска: " << std::endl;
            fflush(stdin);
            std::cin >> r;
            c_r = r.c_str();
            while (!(f = atoi(c_r)))
            {

                std::cout << "Ошибка ввода! Введите число: ";
                std::cin >> r;


            }
           
            std::cout << "индекс введенного числа : " << list.search(f) << std::endl;
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            list.clear();
            break;
            
        }
        
    }
}

