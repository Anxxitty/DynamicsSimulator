#include "Graphics.h"

#include <iostream>

Graphics::Graphics() {
#ifdef CONSTRUCTOR
	std::cout << "Created a Graphics Class" << std::endl;
#endif
}