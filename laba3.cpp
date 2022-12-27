#include <iostream>
#include <string>

class Auto
{
protected:
	std::string car_name;
public:
	Auto(){}
	Auto(std::string name)
	{
		//std::cout << "constr 1" << std::endl;
		car_name = name;
	}
	~Auto()
	{
		//std::cout << "destr 1" << std::endl;
	}
	void Print()
	{
		std::cout << car_name << std::endl;
	}
	
};

class Engine : virtual public Auto
{
protected:
	std::string type_of_engine;
public:
	Engine(){}
	Engine(std::string name, std::string eng)
	{
		//std::cout << "constr 2" << std::endl;
		type_of_engine = eng;
		car_name = name;
	}
	~Engine()
	{
		//std::cout << "destr 2" << std::endl;
	}
	void Print()
	{
		std::cout << car_name << std::endl;
		std::cout << type_of_engine << std::endl;

	}

};

class Color : virtual public Auto 
{
protected:
	std::string color;
public:
	Color() {}
	Color(std::string name, std::string col)
	{
		//std::cout << "constr 3" << std::endl;
		color = col;
		car_name = name;
	}
	~Color()
	{
		//std::cout << "destr 3" << std::endl;
	}

	void Print()
	{
		std::cout << car_name << std::endl;
		std::cout << color << std::endl;

	}
};

class Transmission : public Engine
{
protected:
	std::string number_of_gears;
public:

	Transmission() {}
	Transmission(std::string name, std::string eng, std::string gears)
	{
		car_name = name;
		type_of_engine = eng;
		number_of_gears = gears;
		
		//std::cout << "constr 4" << std::endl;
	}
	~Transmission()
	{
		//std::cout << "destr 4" << std::endl;
	}
	void Print()
	{
		std::cout << car_name << std::endl;
		std::cout << type_of_engine << std::endl;
		std::cout << number_of_gears << std::endl;

	}
};

class Number : public Color
{
protected:
	std::string tag_number;
public:
	Number() {}
	Number(std::string name, std::string col, std::string tag_n)
	{

		//std::cout << "constr 5" << std::endl;
		car_name = name;
		color = col;
		tag_number = tag_n;
	}
	~Number()
	{
		//std::cout << "destr 5" << std::endl;
	}
	void Print()
	{
		std::cout << car_name << std::endl;
		std::cout << color << std::endl;
		std::cout << tag_number << std::endl;

	}
};

class Price : public Transmission, Number
{
private:

public:
	Price() {}

	Price(std::string name, std::string col, std::string tag_n, std::string eng, std::string gears)
	{
		
		//std::cout << "constr 6" << std::endl;
		car_name = name;
		color = col;
		tag_number = tag_n;
		type_of_engine = eng;
		number_of_gears = gears;
	}
	~Price()
	{
		//std::cout << "destr 6" << std::endl;
	}
	void Print()
	{
		std::cout << car_name << std::endl;
		std::cout << color << std::endl;
		std::cout << tag_number << std::endl;
		std::cout << type_of_engine << std::endl;
		std::cout << number_of_gears << std::endl;
	}
};


int main()
{
	setlocale(LC_ALL, "ru");
	Transmission B("BMW", "v12", "4");
	B.Print();
	Engine A("MER", "v12");
	A.Print();
	Auto C("bent");
	C.Print();
	Price D("BWM", "green", "12352A31", "v8", "6");
	D.Print();
	
	Auto* r = &C;
	r->Print();
	
	
	


}
