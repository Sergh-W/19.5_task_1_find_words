#include <iostream>
#include <string>
#include <fstream>

// Vers #1
/*
int counterWords (std::string text, std::string word)
{
    int count = 0;
    for (int i = 0; i < text.length(); ++i) {
        if (word[0] == text[i]) {
            bool found_word = true;
            for (int j = 0; j < text.length()
                && j < word.length(); ++j) {
                if (word[j] == text[i + j]) {
                    continue;
                }
                else
                    found_word = false;
            }

            if (found_word) count++;
        }
    }
    return count;
}

int main()
{
    std::ifstream textFile;
    std::string text;
    std::string word;

    textFile.open("C:\\Text_files\\text.txt");

    if (!textFile.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
    }
    else
    {
        std::cout << "File opened." << std::endl;
        std::string str;
        while (!textFile.eof())
        {
            std::getline(textFile, str);
            text += (str + " ");
        }

        std::cout << "Please enter the word you want to find: ";
        std::cin >> word;
        std::cout << std::endl;
        std::cout << "Text in your file: " << std::endl;
        std::cout << text << std::endl;
        std::cout << std::endl;
        std::cout << "Coincidences: " << counterWords (text, word) << std::endl;
    }

    textFile.close();
    return 0;
}
*/

// Vers #2
int main()
{
    std::ifstream textFile;
    std::string filePath, text, word, str;
    int count = 0;

    std::cout << "Enter the path to the text file\n"
                 "you want to open (Example: C:\\...\\text.txt):\n";
    std::cin >> filePath;
    std::cout << std::endl;

    textFile.open(filePath);

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
        }

        std::cout << "Coincidences: " << count << std::endl;
        std::cout << std::endl;
        std::cout << "Text in your file: " << std::endl;
        std::cout << text << std::endl;
    }

    textFile.close();
    return 0;
}
