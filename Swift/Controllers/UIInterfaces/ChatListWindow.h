/*
 * Copyright (c) 2010-2011 Kevin Smith
 * Licensed under the GNU General Public License v3.
 * See Documentation/Licenses/GPLv3.txt for more information.
 */

#pragma once

#include <list>
#include <boost/shared_ptr.hpp>
#include <Swiften/MUC/MUCBookmark.h>

#include "Swiften/Base/boost_bsignals.h"

namespace Swift {
	class ChatListWindow {
		public:
			class Chat {
				public:
					Chat(const JID& jid, const std::string& chatName, const std::string& activity, int unreadCount, bool isMUC, const std::string& nick = "")
					: jid(jid), chatName(chatName), activity(activity), isMUC(isMUC), nick(nick), unreadCount(unreadCount) {}
					/** Assume that nicks and other transient features aren't important for equality */
					bool operator==(const Chat& other) const {
						return jid.toBare() == other.jid.toBare()
								&& isMUC == other.isMUC;
					};
					void setUnreadCount(int unread) {
						unreadCount = unread;
					}
					JID jid;
					std::string chatName;
					std::string activity;
					bool isMUC;
					std::string nick;
					int unreadCount;
			};
			virtual ~ChatListWindow();

			virtual void setBookmarksEnabled(bool enabled) = 0;
			virtual void addMUCBookmark(const MUCBookmark& bookmark) = 0;
			virtual void removeMUCBookmark(const MUCBookmark& bookmark) = 0;
			virtual void setRecents(const std::list<Chat>& recents) = 0;
			virtual void setUnreadCount(int unread) = 0;
			virtual void clearBookmarks() = 0;

			boost::signal<void (const MUCBookmark&)> onMUCBookmarkActivated;
			boost::signal<void (const Chat&)> onRecentActivated;
	};
}
