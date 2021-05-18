#pragma once
#include <unordered_map>

using ActualURL = std::string;
using TinyURL = std::string;

class URLService
{
public : 
	
	URLService(){}
	~URLService(){}

	std::pair<bool, std::string> lookup(const TinyURL& url) const;

	bool registerURL(const ActualURL& actualURL, const TinyURL& tinyURL);

	bool deregisterURL(const TinyURL& tinyURL);

	void printURLs() const;
	 

private : 

	std::unordered_map<TinyURL, ActualURL> data;

};

