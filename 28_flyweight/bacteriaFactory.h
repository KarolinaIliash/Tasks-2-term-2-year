#pragma once
#include<map>
#include<vector>
#include <algorithm>

#include"bacteria.h"


class BacteriaFactory {
	//in map we have bacteria and its age
	std::map<Bacteria, std::vector<int>> colony;
public:
	const Bacteria& GetBacteria(std::string name, Type type, int age);
};