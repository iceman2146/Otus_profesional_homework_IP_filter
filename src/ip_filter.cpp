#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>



auto split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

int main()
{
    std::cout<<"IP_filter"<<std::endl;
        std::vector<std::vector<std::string> > ip_pool;
        std::cout<<ip_pool.size();

        for(std::string line; std::getline(std::cin, line);)
        {
            
            std::vector<std::string> v = split(line, '\t');
            std::cout<<line;
            ip_pool.push_back(split(v.at(0), '.'));
        }
        

        for(auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
        {
            
            for(auto ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
            {
                std::cout << __PRETTY_FUNCTION__ << std::endl;
                if (ip_part != ip->cbegin())
                {
                    std::cout << __PRETTY_FUNCTION__ << std::endl;
                    std::cout << ".";

                }
                std::cout << *ip_part;
            }
            std::cout << std::endl;
        }

    return 0;
}