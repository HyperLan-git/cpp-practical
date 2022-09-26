#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

int count_motive(std::istream &stream, std::string pattern)
{
    int result = 0;
    std::string line;
    while (stream >> line)
        if (line.find(pattern) != std::string::npos)
            result++;
    return result;
}

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        std::cout << "Missing arguments !" << std::endl;
        return 0;
    }
    std::string path(argv[1]), pattern(argv[2]);
    std::fstream stream = std::fstream(path);
    if (!stream)
    {
        std::cout << "The file " << path << " could not be opened." << std::endl;
        return 1;
    }
    std::cout << "The file " << path << " contains " << count_motive(stream, pattern) <<
            " words containing the motive " << pattern << std::endl;
    return 0;
}