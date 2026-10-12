#include <fstream>
#include <iostream>
#include <string>

static std::string replaceAll(const std::string &content,
                              const std::string &search,
                              const std::string &replacement)
{
    std::string result;
    std::string::size_type start = 0;
    std::string::size_type position;

    position = content.find(search, start);
    while (position != std::string::npos)
    {
        result += content.substr(start, position - start);
        result += replacement;
        start = position + search.length();
        position = content.find(search, start);
    }
    result += content.substr(start);
    return result;
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>"
                  << std::endl;
        return 1;
    }

    const std::string filename = argv[1];
    const std::string search = argv[2];
    const std::string replacement = argv[3];

    if (search.empty())
    {
        std::cerr << "Error: s1 must not be empty" << std::endl;
        return 1;
    }

    std::ifstream input(filename.c_str(), std::ios::in | std::ios::binary);
    if (!input.is_open())
    {
        std::cerr << "Error: could not open " << filename << std::endl;
        return 1;
    }

    std::string content;
    char character;
    while (input.get(character))
        content += character;
    if (!input.eof())
    {
        std::cerr << "Error: could not read " << filename << std::endl;
        return 1;
    }

    const std::string outputName = filename + ".replace";
    std::ofstream output(outputName.c_str(), std::ios::out | std::ios::binary);
    if (!output.is_open())
    {
        std::cerr << "Error: could not create " << outputName << std::endl;
        return 1;
    }

    output << replaceAll(content, search, replacement);
    output.close();
    if (!output)
    {
        std::cerr << "Error: could not write " << outputName << std::endl;
        return 1;
    }
    return 0;
}
