/*
 * language.h
 *
 *  Created on: 10 nov. 2018
 *      Author: Serah
 */

#ifndef LANGUAGE_H_
#define LANGUAGE_H_

#pragma once

#include <set>

#include "symbols.h"

class language_t
{
private:

	std::set<symbols_t> language_;
	std::set<char> alphabet_;

public:

	language_t();
	language_t(const language_t &lang);
	language_t(std::string string);
	virtual ~language_t();

	std::set<symbols_t> get_language() const;
	std::set<symbols_t> get_language();
	
	std::set<symbols_t>::reverse_iterator get_rlanguage();
	std::set<symbols_t>::reverse_iterator get_rlanguage() const;
	
	std::set<symbols_t>::reverse_iterator get_end_rlanguage();
	std::set<symbols_t>::reverse_iterator get_end_rlanguage() const;

	std::set<char> get_alphabet() const;
	std::set<char> get_alphabet();

	void set_symbol_lang(symbols_t symb);
	void set_symbol_alph(char symb);
	void set_language(std::set<symbols_t> symb);
	void set_alphabet(std::set<char> symb);

	void operator()(std::string str);
};

std::ostream &operator<<(std::ostream &os, const language_t& lang);

#endif /* LANGUAGE_H_ */
