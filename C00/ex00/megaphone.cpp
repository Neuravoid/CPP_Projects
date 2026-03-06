#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    // Eğer argüman yoksa
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else
    {
        // Argümanları büyük harfe çevir ve yazdır
        for (int i = 1; i < ac; i++) // Argümanları dolaş
        {
            for (int j = 0; av[i][j]; j++) // Her argümanın karakterlerini dolaş
            {
                std::cout << (char)toupper(av[i][j]);
            }
        }
        std::cout << std::endl; // Yeni satır ekle
    }
    return 0;
}