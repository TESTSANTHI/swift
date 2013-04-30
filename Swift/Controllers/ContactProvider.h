/*
 * Copyright (c) 2013 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */

#pragma once

#include <vector>

#include <Swift/Controllers/Contact.h>

namespace Swift {

class ContactProvider {
	public:
		virtual ~ContactProvider();
		virtual std::vector<Contact> getContacts() = 0;
};

}
