#include <iostream>
#include <regex>
#include <string>

int main(int argc, char** argv) {

	std::string text = "kotik@mail.ru, octupus-3*3@swim.com, ca&py;bara@hate.you, dif#44^5gdf@list.ru";
	std::cout << "Email adress: " << text << std::endl;

	std::regex pattern(R"((([0-9|A-Z|a-z]{1,}))@([A-Z|a-z]{1,}\.){1,2}[A-Z|a-z]{2,})");

	std::sregex_iterator begin(text.cbegin(), text.cend(), pattern);
	std::sregex_iterator end;

	std::for_each(begin, end, [](const std::smatch& m) {
			std::cout << m[3] << std::endl;
		});

	system("pause");
	return EXIT_SUCCESS;
}

