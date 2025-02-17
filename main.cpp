#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::ifstream textFile;
    std::string  text, word, str;
    int count = 0;

    textFile.open("..\\text.txt");

    if (!textFile.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
    }
    else
    {
        std::cout << "File opened." << std::endl;
        std::cout << "Please enter the word you want to find: ";
        std::cin >> word;

        while (!textFile.eof())
        {
            textFile >> str;
            if (str == word) ++count;
            text += (str + " ");
            str = "";
        }

        std::cout << "Coincidences: " << count << std::endl;
        std::cout << std::endl;
        std::cout << "Text in your file: " << std::endl;
        std::cout << text << std::endl;
    }

    textFile.close();
    return 0;
}
