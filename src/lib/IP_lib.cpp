#include "IP_lib.h"

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



auto to_int(std::vector<std::string>&& ip){
    ip result;
    for(const auto& item : ip)
        result.push_back(std::stoi(item));
    return result;
}

std::ostream& operator<<(std::ostream& stream, const IP& ip){
    for(auto i = 0u; i < ip.size(); ++i){
        stream << ip.at(i);
        if(i != ip.size() - 1) stream << '.';
    }
    return stream;
}


std::ostream& operator << (std::ostream& stream, const IP_POOL& ip_pool){
    for(const auto& ip : ip_pool)
        stream << ip << '\n';
    return stream;
}


IP ip_address(){
    return ip(0);
}

template<typename T, typename ... Args>
auto ip_address(T number, Args ... args){
    ip result = ip_address(args...);
    result.push_back(number);
    std::reverse(result.begin(), result.end());
    return result;
}

void ip_filter(const ip_pool& ip_pool, const ip& ip){
    std::for_each(
        ip_pool.begin(),
        ip_pool.end(),
        [=](auto a) {
            int i = 0;
            for(auto item : ip)
                if (item != a.at(i)) return;
                else ++i;
            std::cout << a << '\n';
        }
    );
}

void ip_filter_any(const ip_pool& ip_pool, int number){
    std::for_each(
        ip_pool.begin(),
        ip_pool.end(),
        [=](auto a){
            for(auto item : a)
                if (item == number){
                    std::cout << a << '\n';
                    return;
                }
        }
    );
}