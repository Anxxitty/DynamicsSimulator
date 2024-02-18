#include "Hitbox.h"

#include <iostream>

Hitbox::Hitbox() {
#ifdef CONSTRUCTOR
	std::cout << "Created a Hitbox" << std::endl;
#endif
}
