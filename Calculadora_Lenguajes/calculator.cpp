/*
 * calculator.cpp
 *
 *  Created on: 12 nov. 2018
 *      Author: Serah
 */

#include "calculator.h"

calculator_t::calculator_t()
{
	language_(request_language());
	language2_(request_language());
}

calculator_t::~calculator_t() {}


void calculator_t::inverse()
{
	std::set<symbols_t>::reverse_iterator reverse = language_.get_rlanguage();
	std::set<symbols_t>::reverse_iterator end_while = language_.get_end_rlanguage();
	std::set<symbols_t>::reverse_iterator aux = language_.get_end_rlanguage();
	aux--;

    std::cout << "\nInversa: {";
    while (reverse != end_while)
    {
    	if(reverse == aux)
    		std::cout << (*reverse);

    	else
    		std::cout << (*reverse) << ", ";

    	reverse++;
    }
    std::cout << "}\n";
}

void calculator_t::concatenation()
{

}

void calculator_t::unionl()
{

}

void calculator_t::intersection()
{

}

void calculator_t::diference()
{

}

void calculator_t::sublanguage()
{

}

void calculator_t::equality()
{

}

void calculator_t::potency()
{

}

void calculator_t::kleene()
{

}

void calculator_t::menu()
{
	int option;

	do{
		//system("clear");
		std::cout << "\n\t\t ----MENU----\n\n";


		std::cout << "1  -\tCambiar los dos lenguajes.\n";
		std::cout << "2  -\tInversa.\n";
		std::cout << "3  -\tConcatenacion.\n";
		std::cout << "4  -\tUnion.\n";
		std::cout << "5  -\tInterseccion.\n";
		std::cout << "6  -\tDiferencia.\n";
		std::cout << "7  -\tSublenguajes.\n";
		std::cout << "8  -\tIgualdad de lenguajes.\n";
		std::cout << "9  -\tPotencia.\n";
		std::cout << "10 -\tCierre de Kleene.\n";
		std::cout << "0  -\tSalir.\n";

		std::cout << "\tElige la opcion: ";
		std::cin >> option;
		std::cout << "\n\n";
		
		switch(option)
		{
			case 0:
				std::cout << "\tSaliendo...\n";
				break;
	
			case 1:
				language_(request_language());
				language2_(request_language());
				break;

			case 2:
				//inversa
				inverse();
				break;

			case 3:
				//concatenacion
				concatenation();
				break;
	
			case 4:
				//union
				unionl();
				break;
	
			case 5:
				//interseccion
				intersection();
				break;
		
			case 6:
				//diferencia
				diference();
				break;

			case 7:
				//sublenguajes
				sublanguage();
				break;
	
			case 8:
				//igualdad de lenguajes
				equality();
				break;
	
			case 9:
				//potencia
				potency();
				break;	

			case 10:
				//kleene
				kleene();
				break;

			default:
				std::cout << "\t  *-¡Esa opcion no esta permitida!-*\n";
				break;
		}
	}while (option != 0);
}

std::string calculator_t::request_language()
{
	std::string input;

	std::cout << "Introduce un lenguaje: ";
	std::getline(std::cin, input);

	while((input[0] != '{') && (input[0] != '('))
	{
	        std::cout << "*Introduzca el lenguaje correctamente *: ";
	        std::getline(std::cin, input);
	}
	return input;
}
