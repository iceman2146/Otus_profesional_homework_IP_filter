
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
//usings
using ip = std::vector<int>;
using ip_pool = std::vector<ip>;



auto split(const std::string&, char ){};
auto to_int(std::vector<std::string>&&){};
std::ostream& operator<<(std::ostream&, const ip&){};
std::ostream& operator << (std::ostream&, const ip_pool&){};
ip ip_address(){};


void ip_filter(const ip_pool&, const ip&){};


void ip_filter_any(const ip_pool&, int){};