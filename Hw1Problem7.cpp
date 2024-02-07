#include <iostream>
#include <vector>

#include "Hw1Problem3-4.h"
#include "Hw1Problem6.h"

using namespace std;

int main()
{
	double step, iter,speed;

	string Alpha, Bravo, name,name1;

	speed = 450.0 / 3600.0;    //Between 400 and 500 mph

	step = 15;			//Between 10 and 100 seconds

	iter = 1500;		//Between 1000 and 2000 iterations

	Pilot pilot1("Alpha");
	Pilot pilot2("Bravo");
	
	Plane obj1;

	pilot1.myPlane = &obj1;

	obj1.setvel(speed);

	int z = 1;
	int* x = nullptr;  

	std::cout << "Pilot " << pilot1.getname() << " with certificate number " << &pilot1 << " is in control of a plane: " << &obj1 << std::endl;
	std::cout << "Pilot " << pilot2.getname() << " with certificate number " << &pilot2 << " is in control of a plane: " << x << std::endl << std::endl;

	for (int i = 0; i < iter * step; i = i + step)
	{
		if (i == 0) 
		{
			obj1.operate(0);
			obj1.getat_SCE();
		}												//Check other problems are correct enough
		else											//Need to get memory address the same as the first one declared in 3-4
		{												//Need to determine how to seperate pilot names, and determine how to transfer their memory
			obj1.operate(step);							//Ask how to do last problem if it the same thing etc.
			obj1.getat_SCE();
		}

		if (obj1.getat_SCE() ==1)
		{


			std::cout << "The Plane " << &obj1 << " is at SCE" << std::endl;

			if(z % 2 == 0)
			{
																											
				std::cout << "Pilot " << pilot1.getname() << " with certificate number " << &pilot1 << " is in control of a plane: " << &obj1 << std::endl;
				std::cout << "Pilot " << pilot2.getname() << " with certificate number " << &pilot2 << " is in control of a plane: " << x << std::endl << std::endl;

			}
			else if (z % 2 == 1)
			{
			                   
				std::cout << "Pilot " << pilot2.getname() << " with certificate number " << &pilot2 << " is in control of a plane: " << &obj1 << std::endl;
				std::cout << "Pilot " << pilot1.getname() << " with certificate number " << &pilot1 << " is in control of a plane: " << x << std::endl << std::endl;

			}

			z = z + 1;

		}

	}

	return 0;

}