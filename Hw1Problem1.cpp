#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int nofso, norso;
	double ew, ewm, fsma, worso, rsma, nguf, wouf, ftma, bw, bma, wofso;

	std::cout << "What is the Airplane empty weight in pounds?" << std::endl;
	std::cin >> ew;

	std::cout << "What is the Airplane empty-weight moment in pounds-inches?" << std::endl;
	std::cin >> ewm;

	std::cout << "What is the number of front seat occupants?" << std::endl;
	std::cin >> nofso;

	std::vector<double> wofsoa(nofso);

	for (int i=0; i<nofso;++i)
	{

		std::cout << "What is the weight of each front seat occupant in pounds enter each one individually?" << std::endl;
		std::cin >> wofsoa[i];

	}

	double sum = 0.0;

	for (int i = 0; i < nofso; ++i) {
		sum += wofsoa[i];
	}

	wofso = sum;

	std::cout << "What is the front seat moment arm in inches?" << std::endl;
	std::cin >> fsma;

	std::cout << "What is the number of rear seat occupants?" << std::endl;
	std::cin >> norso;

	std::vector<double> worsoa(norso);

	for (int i = 0; i < norso; ++i)
	{

		std::cout << "What is the weight of each rear seat occupant in pounds enter each one individually?" << std::endl;
		std::cin >> worsoa[i];

	}

	double sum1 = 0.0;

	for (int i = 0; i < norso; ++i) {
		sum1 += worsoa[i];
	}

	worso = sum1;

	std::cout << "What is the rear seat moment arm in inches?" << std::endl;
	std::cin >> rsma;

	std::cout << "What is the number of gallons of usable fuel in gallons?" << std::endl;
	std::cin >> nguf;

	std::cout << "What is the usable fuel weight per gallon in pounds?" << std::endl;
	std::cin >> wouf;

	std::cout << "What is the fuel tank moment arm in inches?" << std::endl;
	std::cin >> ftma;

	std::cout << "What is the baggage weight in pounds?" << std::endl;
	std::cin >> bw;

	std::cout << "What is the baggage moment arm in inches?" << std::endl;
	std::cin >> bma;

	double gw, cg, tm;

	gw = ew + (wofso) + (worso) + (nguf * wouf) + bw;

	tm = ewm + (fsma * wofso) + (rsma * worso) + (ftma * wouf * nguf) + (bw * bma);

	cg = tm / gw;

	double fw;

	fw = (nguf * wouf);

	//std::cout << "First value is " << gw << "   " << cg << std::endl;

	if (gw > 2950 || cg > 84.7 || cg < 82.1)
	{

		for (int i=0; gw > 2950; i++)
		{
			
				fw = fw - 0.01;

				gw = ew + (wofso) + (worso) + (fw) + bw;

				tm = ewm + (fsma * wofso) + (rsma * worso) + (ftma * fw) + (bw * bma);

				cg = tm / gw;

				//std::cout << gw << "     " << cg << std::endl;

		}

		for (int i = 0; cg > 84.7 || cg < 82.1; i++)
		{
			if (cg > 84.7)
			{
				fw = fw + 0.01;

				gw = ew + (wofso)+(worso)+(fw)+bw;

				tm = ewm + (fsma * wofso) + (rsma * worso) + (ftma * fw) + (bw * bma);

				cg = tm / gw;

				//std::cout << gw << "     " << cg << std::endl;

			}
			else if (cg<82.1)
			{
				fw = fw - 0.01;

				gw = ew + (wofso)+(worso)+(fw)+bw;

				tm = ewm + (fsma * wofso) + (rsma * worso) + (ftma * fw) + (bw * bma);

				cg = tm / gw;

				//std::cout << gw << "     " << cg << std::endl;
			}

		}

		std::cout << "The new value of gross weight is "<< gw <<" and the C.G. location is " << cg << "." << std::endl;
		std::cout << "The new fuel weight is " << fw << " with the difference being " <<abs((wouf*nguf)-fw)<<"." << std::endl;
	}
	else
	{

		std::cout << "The gross weight and the C.G. location are within the airplane design limits!" << std::endl;

	}

	return 0;

}







