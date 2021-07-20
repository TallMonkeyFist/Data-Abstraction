#pragma once

#include "ToyBox.h"

class GoodMemory
{
private:
	ToyBox<double>* someBoxPtr;
public:
	GoodMemory();
	virtual ~GoodMemory();
	void unleakyMethod(const double& someItem);
};