#pragma once
#include<iostream>

class Crime
{
	std::string plase; // ����� ������������
	std::string crime; // ���������
public:
	const std::string& get_place() const;
	const std::string& get_crime() const;
	Crime(std::string plase, std::string crime);
	~Crime();
};

