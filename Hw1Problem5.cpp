#include <iostream>
#include <vector>


#include "Hw1Problem3-4.h"

using namespace std;


int main() 
{
	double speed,step,iter,travel;

	speed = 450.0 / 3600.0;					//Between 400 and 500  mph
											
	step = 15;			//Between 10 and 100 seconds

	iter = 1500;		//Between 1000 and 2000 iterations

	Plane obj;			//In your main function, instantiate an object from the “Plane” class written in Question 3 & 4

	obj.setvel(speed);

	for (int i = 0; i < iter*step; i=i+step)
	{

		if (i == 0) 
		{
			travel = obj.operate(0);
		}
		else 
		{
			travel = obj.operate(step);
		}

		std::cout << "Time: " << i << " seconds, Position: " << travel << " miles." << std::endl;		

	}

	return 0;

}