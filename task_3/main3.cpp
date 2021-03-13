#include <iostream>
#include <regex>
#include <string>

int main(int argc, char** argv) {

	std::string text = "kotik@mail.ru, octupus-3*3@swim.com, capybara@hate.you, dif44gdf@list.ru";
	std::cout << "Email adress: " << text << std::endl;

	std::regex pattern(R"((([\w][0-9A-z.]+[\w]))@([_[:alpha:]]+\.)+([_[:alpha:]]{2,6}))");

	std::sregex_iterator begin(text.cbegin(), text.cend(), pattern);
	std::sregex_iterator end;

	std::for_each(begin, end, [](const std::smatch& m) {
			std::cout << m[3] << m[4] << std::endl;
		});

	system("pause");
	return EXIT_SUCCESS;
}

