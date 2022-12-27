//ZADANIE 6 
#include <iostream>
#include <string>

class Auto
{
protected:
    std::string car_name; 
public: 
    Auto() {}
    Auto(std::string name)
    {
        std::cout << "constr 1" << std::endl;
        car_name = name;
    }
	virtual ~Auto()
	{

		std::cout << "destr 1" << std::endl;
	}
	virtual void Print() = 0;
        
};

class Engine : public Auto
{
protected:
	std::string type_of_engine;
public:
	Engine() {}
	Engine(std::string name, std::string eng) : Auto(name)
	{
		std::cout << "constr 2" << std::endl;
		type_of_engine = eng;
		
	}
    ~Engine() override
	{
		std::cout << "destr 2" << std::endl;
	}
	
	virtual void Print() override
	{
		std::cout << car_name << std::endl;
		std::cout << type_of_engine << std::endl;
	}

};

class Transmission : public Engine
{
protected:
	std::string number_of_gears;
public:

	Transmission() {}
	Transmission(std::string name, std::string eng, std::string gears) : Engine(name, eng)
	{
		std::cout << "constr 4" << std::endl;
		number_of_gears = gears;

		
	}
    ~Transmission() override 
	{
		std::cout << "destr 4" << std::endl;
	}
	void Print() override 
	{
		Engine::Print();
		std::cout << number_of_gears << std::endl;

	}
};

class Color : public Auto
{
protected:
	std::string color;
public:
	Color() {}
	Color(std::string name, std::string col) : Auto(name)
	{
		std::cout << "constr 3" << std::endl;
		color = col;
		
	}
	~Color() override
	{
		std::cout << "destr 3" << std::endl;
	}

	void Print() override 
	{
		std::cout << car_name << std::endl;
		std::cout << color << std::endl;

	}
};

int main()
{
	setlocale(LC_ALL, "ru");

	int length = 3;

	Auto** arr = new Auto*[length];

	arr[0] = new Engine("mercedes", "v8");
	arr[1] = new Transmission("nissan", "v6", "7");
	arr[2] = new Color("mazda", "red");

	arr[0]->Print();
	std::cout << std::endl;
	arr[1]->Print();
	std::cout << std::endl;
	arr[2]->Print();
	for(int i = 0;i < 3;i++)
	delete arr[i];
	delete []arr;
	
}


