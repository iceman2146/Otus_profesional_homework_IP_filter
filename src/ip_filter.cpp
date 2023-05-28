#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//#include <fstream>
#include "ip_lib.h"
template <typename T, typename... Args>
auto ip_address(T number, Args... args)
{
    ipv4 result = ip_address(args...);
    result.push_back(number);
    std::reverse(result.begin(), result.end());
    return result;
}
int main(/*int argc, char const *argv[]*/)
{
    //std::ifstream file_input;
    //std::ofstream file_otput;
    //file_input.open("C:\\Users\\Comp\\Documents\\Repos\\Otus\\OTUS_Proffesional\\2\\hw\\Otus_profesional_homework_IP_filter\\src\\ip_filter.tsv");
    //file_otput.open("C:\\Users\\Comp\\Documents\\Repos\\Otus\\OTUS_Proffesional\\2\\hw\\Otus_profesional_homework_IP_filter\\src\\ip_filter_test.tsv");
    //file_otput.clear();
    try
    {
        std::vector<ipv4> ip_pool;

        //for (std::string line; std::getline(file_input, line);)
        for (std::string line; std::getline(std::cin, line);)
        {
            auto v = split(line, '\t');
            ip_pool.push_back(to_int(split(v.at(0), '.')));
        }
        std::cout << "Start" << std::endl;
        //file_otput<<ip_pool;
        std::cout << ip_pool;

        std::sort(ip_pool.begin(), ip_pool.end(), [](auto a, auto b)
                  { return (a > b); });
        //std::cout << "sorted" << std::endl;
        //file_otput<<ip_pool;
        
        std::cout << ip_pool;
        

        ip_filter(ip_pool, ip_address(1));
        //std::cout << "Filtered 1" << std::endl;
        std::cout << ip_pool;
        //file_otput<<ip_pool;
        ip_filter(ip_pool, ip_address(46, 70));
        //std::cout << "Filtered 46.70" << std::endl;
        std::cout << ip_pool;
        //file_otput<<ip_pool;
 
        ip_filter_any(ip_pool, 46);
        //std::cout << "Filtered 46" << std::endl;
        std::cout << ip_pool;
        //file_otput<<ip_pool;
        //file_otput.close();
       //file_input.close();

     }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}