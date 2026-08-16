#include <cctype>
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j] != '\0'; j++)
		{
			// std::cout << (char)std::toupper(argv[i][j]);
			std::cout << static_cast<char>(std::toupper(argv[i][j]));
			// Changing the value itself then printing
			// argv[i][j] = (char)std::toupper(argv[i][j]);
		}
		// printing the word.
		// std::cout << argv[i];
		std::cout << " ";
	}
	std::cout << std::endl;
}
