#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

Ice::Ice() : _type("ice")
{
	std::cout << this->_type << " constructed\n";
}

Ice::~Ice()
{
	std::cout << this->_type << " destroyed\n";
}

Ice::Ice(Ice const & ref) : _type(ref.getType())
{
	std::cout << this->_type << " constructed from copy\n";
}

Ice & Ice::operator=(Ice const & ref)
{
	std::cout << "Assigned from " << ref.getType() << std::endl;
	return (*this);
}

std::string const & Ice::getType( void ) const
{
	return (this->_type);
}

Ice *Ice::clone() const
{
	Ice	*ret = new Ice;
	return (ret);
}

void Ice::use(ICharacter& target)
{
	std::string target_name = target.getName();

	std::cout << " shoots an ice bolt at " << target_name << std::endl;
}