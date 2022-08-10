#ifndef PERSONARRAY_CLASS_HPP
# define PERSONARRAY_CLASS_HPP

#include "INC.hpp"

class PhoneBook {
	private:
		int			_amountContact;
		Contact		_contact[MAX_SIZE];

	public:
		PhoneBook (void);
		~PhoneBook (void);
		int __init__ (void);
		void addContact (int x);
		void printInfos (int x);
		void specSearch (int x);

};

#endif
