#include "Loader.h"

void Loader::saveToFile(string test[3])
{
	fstream plik;
	plik.open("plik.txt", ios::out | ios::trunc);
	if (plik.good())
	{
		
		for (int i = 0; i < 3; i++) {
			if (i != 2)
				plik << test[i] << "\n";
			else
				plik << test[i];
		}


		plik.flush();
		plik.close();
	}
}

void Loader::readFromFile(string test[3])
{
	fstream plik("plik.txt", ios::in); 
	if (plik.good()) {
		int i = 0;

		while (getline(plik, test[i])) {
			i++;
		}
		plik.close();
	}

}
