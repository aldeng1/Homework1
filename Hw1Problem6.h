#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Hw1Problem3-4.h"

using namespace std;

class Pilot 
{
	private:

		string name,name1;

	public:

		Pilot(const std::string& _name) : name(_name)
		{

			cout << "Pilot " << name << " with certificate number " << this << " is at the gate, ready to board the plane." << endl;
		

		}

		~Pilot()
		{
			
			cout << "Pilot " << name << " is out of the plane"<< endl;
			
		}

		string getname()
		{
			return name;
		}

		Plane* myPlane;			//Ask

};