#include "bacteriaFactory.h"



const Bacteria& BacteriaFactory::GetBacteria(std::string name, Type type, int age) {
	std::map<Bacteria, std::vector<int>>::iterator bactIt = std::find_if(std::begin(colony), std::end(colony), 
												   [&](auto x) { return x.first.GetName() == name && x.first.GetType() == type; });
	if (bactIt != std::end(colony)) {
		std::vector<int>::iterator ageIt = std::find(bactIt->second.begin(), bactIt->second.end(), age);
		if (ageIt == bactIt->second.end()) {
			bactIt->second.push_back(age);
		}
		return bactIt->first;
	}
	else {
		colony.insert(std::pair<Bacteria, std::vector<int>>(Bacteria(name, type), age));
		return std::find_if(std::begin(colony), std::end(colony),
			[&](auto x) { return x.first.GetName() == name && x.first.GetType() == type; })->first;
	}
}