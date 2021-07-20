#include "GoodMemory.h"

GoodMemory::GoodMemory() : someBoxPtr(nullptr)
{

}

GoodMemory::~GoodMemory()
{
	delete someBoxPtr;
	someBoxPtr = nullptr;
}

void GoodMemory::unleakyMethod(const double& someItem)
{
	if (someBoxPtr != nullptr) { delete someBoxPtr; }
	someBoxPtr = new ToyBox<double>();
	someBoxPtr->setItem(someItem);
}