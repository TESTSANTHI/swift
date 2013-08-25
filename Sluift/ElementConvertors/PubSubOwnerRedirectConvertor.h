/*
 * Copyright (c) 2013 Remko Tronçon
 * Licensed under the GNU General Public License.
 * See the COPYING file for more information.
 */

#pragma once

#include <Swiften/Base/Override.h>

#include <Sluift/GenericLuaElementConvertor.h>
#include <Swiften/Elements/PubSubOwnerRedirect.h>

namespace Swift {
	class LuaElementConvertors;

	class PubSubOwnerRedirectConvertor : public GenericLuaElementConvertor<PubSubOwnerRedirect> {
		public:
			PubSubOwnerRedirectConvertor(LuaElementConvertors* convertors);
			virtual ~PubSubOwnerRedirectConvertor();

			virtual boost::shared_ptr<PubSubOwnerRedirect> doConvertFromLua(lua_State*) SWIFTEN_OVERRIDE;
			virtual void doConvertToLua(lua_State*, boost::shared_ptr<PubSubOwnerRedirect>) SWIFTEN_OVERRIDE;

		private:
			LuaElementConvertors* convertors;
	};
}
