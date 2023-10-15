#pragma once

#include<string>

class menu
{
public:
	std::string name{ 0 };
	int count{ 0 };

	menu() = default;

	bool operator==(const menu& other) const
	{
		return name == other.name && count == other.count;
	}

	menu(const std::string& name, int count)
		: name(name), count(count)
	{
	}
};