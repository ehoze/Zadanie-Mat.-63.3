#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class zadanie633
{
				ifstream plik;
                vector <int> numbers;
        public:
//                void wprowadz();
//                void wypisz();
                void obliczanie();
                int zapiszDoPliku(const char *, int wynik, int min, int max);             
};

int convert(long long n)
{
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}

vector <int> factors(int number)
{
 vector <int> czynniki;
 for (int i=2; i<=number; i++)
 {
   while (number %i ==0)
    {
         number /=i;
         czynniki.push_back(i);
    }
 }
 return czynniki;
}

void zadanie633::obliczanie()
{			
			long long wprowadzany = 0;
			int wynik = 0;
			int min = 999;
			int max = 0;
			plik.open("B:\\Programowanie z Panem Fulaa\\Zadanie Mat. 63.3\\ciagi.txt", ios::in); 
			if(plik.good()) 
			while(!plik.eof()) 
			    {
			  		plik >> wprowadzany;
			  		int number = convert(wprowadzany);					
					vector <int> czynniki = factors(number);
				    if(czynniki.size()==2)
				    {
				    	wynik++;
				    	if(number < min)
				    	{
				    		min = number;
						}
						
						if(number > max)
						{
							max = number;
						}
					}
					wprowadzany = 0;
				}
			   	cout << "Czynniki: " << wynik << endl;
			   	cout << "Min: " << min << endl;
			   	cout << "Max: " << max;
			   	zapiszDoPliku("B:\\Programowanie z Panem Fulaa\\Zadanie Mat. 63.3\\632wynik.txt", wynik, min ,max);
			    plik.close(); 
}

zadanie633::zapiszDoPliku(const char *nazwa, int wynik, int min, int max)
{	
        ofstream plik;
        plik.open(nazwa);
        plik << "Czynniki: " << wynik << endl;
		plik << "Min: " << min << endl;
		plik << "Max: " << max;
        plik.close();
        
}

int main()
{
//Eryk Kucharski
	zadanie633 x;
  	x.obliczanie();
    return 0;
}
