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


	//SetConsoleCP(CP_UTF8);
	//SetConsoleOutputCP(CP_UTF8);
	
	const int k = 83;

	//int mon;
	std::cout << "enter money: ";
	std::cin.imbue(std::locale("en_US.UTF-8"));
	std::string mon;
	std::cin >> mon;


	long int val;
	std::istringstream sout(mon);
	sout.imbue(std::locale("de_DE.UTF-8"));
	sout >> std::get_money(val);
	std::cout <<val/100 << std::endl;

	val *= k;
	std::cout << val / 100 << std::endl;

	std::ostringstream ssout;
	ssout.imbue(std::locale("de_DE.utf8"));
	ssout << std::showbase << std::put_money(mon, false) << std::endl;
	std::cout << ssout.str() << std::endl;


	system("pause");
	return EXIT_SUCCESS;
}