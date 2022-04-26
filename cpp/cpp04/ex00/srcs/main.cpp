#include "Base.hpp"
#include "Derived.hpp"


int main(void)
{
	Derived d;
	Base& b_ref = d;

	b_ref.makeSound();
}
