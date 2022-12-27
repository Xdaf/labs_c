#include <iostream>
#include <string>

class sotrud
{
	friend class bykh;
private:
	int salary;
	std::string name;
	int id;

public:

	sotrud(int salary, std::string name, int id)
	{
		this->salary = salary;
		this->name = name;
		this->id = id;
	}
	~sotrud()
	{
		std::cout << "dest." << std::endl;
	}
	void show()
	{
		std::cout << "name: " << this->name << " salary: " << this->salary << " id: " << this->id << std::endl;
	}

};

class bykh {
public:
	void salChange(sotrud& arg, int salary)
	{
		if (salary < 0)
		{
			return;
		}
		arg.salary = salary;

	}
};

int main()
{

	sotrud tom(2500, "Tom", 1);
	tom.show();
	sotrud an(5000, "Anna", 2);
	an.show();
	bykh mom;
	mom.salChange(tom, -1);
	mom.salChange(an, 10000);
	tom.show();
	an.show();


}


