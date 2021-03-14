#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <locale>
#include <sstream>

#include <Windows.h> 


void show_currency_symbol(const std::string& locale_name) {
	std::cout << locale_name << " : " <<
		std::use_facet < std::moneypunct < char, false > >(
			std::locale(locale_name)).curr_symbol() << std::endl;
}

int main(int argc, char* argv) {

	SetConsoleCP(CP_UTF8); 
	SetConsoleOutputCP(CP_UTF8); 

	const double k = 87.7;
	std::cout << "enter amount: ";

	long double val;
	std::cin.imbue(std::locale("de_DE.utf8"));
	std::cin >> val;
	std::cout << val << " ";
	show_currency_symbol("de_DE.utf8");
	std::cout << std::endl;

	val *= k;

	std::cout.imbue(std::locale("ru_RU.utf8"));
	std::cout << val << " ";
	show_currency_symbol("ru_RU.utf8");
	std::cout << std::endl;


	system("pause");
	return EXIT_SUCCESS;
}