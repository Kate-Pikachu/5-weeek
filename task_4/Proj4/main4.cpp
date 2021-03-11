#include <iostream>
#include <regex>
#include <string>

int main(int argc, char** argv) {


	std::string data = "da%fj2021.03.11gj13:48:33ij";

	std::regex time(R"(([0-2]*\d):(([0-5]*\d):([0-5]*\d)))");

	std::sregex_iterator begin(data.cbegin(), data.cend(), time);
	std::sregex_iterator endTime;

	std::cout << "Time: ";
	std::for_each(begin, endTime, [](const std::smatch& m)
		{
			std::cout << m[0] << std::endl;
		});


	std::regex date(R"((([1-2]\d{3}).(([0]*[1-9])).([0-31]*\d)))");

	std::sregex_iterator beginData(data.cbegin(), data.cend(), date);
	std::sregex_iterator endDate;

	std::cout << "Date: " ;
	std::for_each(beginData, endDate, [](const std::smatch& m)
		{
			std::cout << m[0] << std::endl;
		});



	system("pause");
	return EXIT_SUCCESS;
}
