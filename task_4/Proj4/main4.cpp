#include <iostream>
#include <regex>
#include <string>

int main(int argc, char** argv) {


	std::string data = "dafj 2021.03.11 gj 325:1:21 ij 13:43:00  inhvv 2039.23.1" ;

	std::regex time(R"((\d{2})(:[0-5]\d){2})");

	std::sregex_iterator begin(data.cbegin(), data.cend(), time);
	std::sregex_iterator endTime;

	std::cout << "Time: ";
	std::for_each(begin, endTime, [](const std::smatch& m) {
			std::cout << m[0] << std::endl;
		});


	std::regex date(R"((([1-2]\d{3}).(([1][0-2])|([0][1-9])).(([0-2]\d)|([3][0,1]))))");

	std::sregex_iterator beginData(data.cbegin(), data.cend(), date);
	std::sregex_iterator endDate;

	std::cout << "Date: " ;
	std::for_each(beginData, endDate, [](const std::smatch& m) {
			std::cout << m[0] << std::endl;
		});


	system("pause");
	return EXIT_SUCCESS;
}
