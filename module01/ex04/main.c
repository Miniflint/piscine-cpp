#include "sedding.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
        return ((std::cout << "Usage:" << argv[0] << " <file> <search> <replace>" << std::endl), 1);
    std::ifstream   inFile(argv[1]);
    if (!inFile.is_open())
        return ((std::cout << "inFile does not open/exist" << std::endl), 1);
    std::ofstream   outFile(std::string(argv[1]) + ".replace");
    if (!outFile.is_open())
        return ((std::cout << "outFile does not open/exist" << std::endl), 1);
    std::string     s1 = argv[2];
    std::string     s2 = argv[3];
    std::string     cText;
    std::string     tmp;
    long            i = 0;
    const size_t    iSize = s1.size();
    while (std::getline(inFile, cText))
    {
        tmp = cText;
        while (1)
        {
            i = cText.find(s1, i + iSize);
            if (i == std::string::npos)
                break ;
            cText = cText.substr(0, i) + s2 + cText.substr(i + iSize, cText.size() - (i + iSize));
        }
        outFile << cText << std::endl;
    }
    inFile.close();
    outFile.close();
}