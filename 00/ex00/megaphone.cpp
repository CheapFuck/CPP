#include <iostream>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    for (int i = 1; i < argc; ++i)
    {
        std::string arg(argv[i]);
        for (size_t j = 0; j < arg.length(); j++)
        {
            arg[j] = std::toupper(static_cast<unsigned char>(arg[j]));
        }
        std::cout << arg;
        if (i < argc - 1)
            std::cout << " ";
    }
    std::cout << std::endl;

    return 0;
}