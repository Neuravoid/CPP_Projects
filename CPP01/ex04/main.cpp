#include <fstream>
#include <iostream>
#include <string>


std::string returnAll(std::ifstream &stream)
{
    std::string line;
    std::string content;
    int         is_first = 1;
    
    while (std::getline(stream,line))
    {
        if (is_first == 0) 
            content += '\n';
        content += line;
        is_first = 0;
    }
    return(content);
}
void find_and_replace(std::string *input, const std::string &s1, const std::string &s2)
{
    size_t pos = 0;
    while ((pos = input->find(s1, pos)) != std::string::npos) {
        input->erase(pos, s1.length());
        input->insert(pos, s2);
        pos += s2.length();
    }

}

int main(int ac, char **av)
{
    if (ac != 4 || !av[1] || !av[2] || !av[3]
            || av[1][0] == '\0'  || av[2][0] == '\0' || av[3][0] == '\0')
        return 1;
    
    std::ifstream input(av[1]);
    if(!input)
    {
        std::cerr << "Dosya Açılmadı" << std::endl;
        return 1;
    }

    std::string content = returnAll(input);
    input.close();

    find_and_replace(&content,av[2],av[3]);
    
    std::string new_name = std::string(av[1]) + ".replace";
    std::ofstream output(new_name.c_str());
    if (!output) {
        std::cerr << "Çıktı dosyası oluşturulamadı!" << std::endl;
        return 1;
    }

    output << content;
    output.close();
    return 0;
}
