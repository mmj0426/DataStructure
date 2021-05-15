#include <iostream>
#include <string>
#include "URLService.h"

std::pair<bool, std::string> URLService::lookup(const TinyURL& url) const
{
    auto it = data.find(url);

    // 단축 URL이 등록되어 있지 않은 경우
    if (it == data.end())
    {
        return std::make_pair(false, std::string());
    }
    else
    {
        return std::make_pair(true, it->second);
    }
}

bool URLService::registerURL(const ActualURL& actualURL, const TinyURL& tinyURL)
{
    auto found = lookup(tinyURL).first;
    if (found)
    {
        return false;
    }

    data[tinyURL] = actualURL;
    return true;
}

bool URLService::deregisterURL(const TinyURL& tinyURL)
{
    auto found = lookup(tinyURL).first;
    if (found)
    {
        data.erase(tinyURL);
        return true;
    }
    return false;
}

void URLService::printURLs() const
{  
    for (const auto& entry : data)
    {
        std::cout << entry.first << " -> " << entry.second << std::endl << std::endl;
    }
    std::cout << std::endl;
}
