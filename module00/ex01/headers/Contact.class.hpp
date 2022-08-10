#ifndef PERSON_CLASS_HPP
# define PERSON_CLASS_HPP

#include "INC.hpp"

class Contact {
	private:
		int			_index;
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
	public:
		Contact (void);
		~Contact (void);
		void addPerson(
					int index,
					std::string firstName,
					std::string lastName,
					std::string nickname
		);
		void printAllInfo (void);
		void printSpecInfo (void);
};

#endif
