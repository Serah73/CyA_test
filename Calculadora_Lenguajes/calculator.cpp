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
	    std::cout << "\n\tInversa\n\t\tlenguaje (1): {";
	    inverse_aux(language_);
	    
	    std::cout << "\n\tInversa\n\t\tlenguaje (2): {";
		inverse_aux(language2_);
}

void calculator_t::inverse_aux(language_t language)
{
	std::set<symbols_t>::reverse_iterator reverse = language.get_begin_rlanguage();
	std::set<symbols_t>::reverse_iterator end_while = language.get_end_rlanguage();
	std::set<symbols_t>::reverse_iterator aux = language.get_end_rlanguage();
	aux--;

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

void calculator_t::concatenation()		////modificar
{
	std::set<symbols_t> final;
	std::set<symbols_t> laux = language_.get_language();
	std::set<symbols_t> l2aux = language2_.get_language();
	
    symbols_t aux;
    
    for (std::set<symbols_t>::iterator i = laux.begin(); i != laux.end(); i++) 
    {
        for (std::set<symbols_t>::iterator j = l2aux.begin(); j != l2aux.end(); j++) 
        {
            //aux.set_symbol(aux.add_symbol(*i, *j) );
            //aux = *i + *j;
            aux = prueba_concatenacion(*i, *j);
            final.insert(aux);
        }
    }
    std::cout << "\n\tConcatenacion\n\t\tlenguaje final: {";
    std::set<symbols_t>::iterator auxS = final.end();
    auxS--;
    
    for (std::set<symbols_t>::iterator k = final.begin(); k != final.end(); k++)
    {
        if (auxS == k) 
        	std::cout << *k;
        else 
        	std::cout << *k << ", ";
    }
    std::cout << "}\n";
}

symbols_t calculator_t::prueba_concatenacion(symbols_t a, symbols_t b)
{
	symbols_t aux;
	
	//aux.set_symbol( a.get_symbol() + b.get_symbol() );
	aux = a+b;
	
	
	return aux;
}


void calculator_t::unionl()
{
	std::set<symbols_t> aux = language_.get_language();
	
	std::ostream_iterator<symbols_t> iter(std::cout, ", ");
	
    std::cout << "\n\tUnion de los lenguajes: {";
    
    std::set_union(language_.get_begin_language(), language_.get_end_language(),
    			language2_.get_begin_language(), language2_.get_end_language(), iter);
    
    std::cout <<"}";
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

		std::cout << "\n\tElige la opcion: ";
		std::cin >> option;
		std::cout << "\n\n";
		
		switch(option)
		{
			case 0:
				std::cout << "\tSaliendo...\n";
				break;
	
			case 1:
				language_.clear();
				language2_.clear();
				language_(request_language());
				language2_(request_language());
				break;

			case 2:
				//inversa
				std::cout << "antes\n";
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

	while((input[0] != '{') && (input[0] != '('))	//se imprime 2 veces porque si
	{
		
	////////////////////////////////////////////////////////////////////
	////////              D U D A                             //////////
	        std::cout << "*Introduzca el lenguaje correctamente *: ";
	        std::getline(std::cin, input);
	}
	return input;
}
