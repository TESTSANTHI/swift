/*
 * Copyright (c) 2013 Remko Tronçon
 * Licensed under the GNU General Public License.
 * See the COPYING file for more information.
 */

#include <Swiften/PubSub/PubSubManagerImpl.h>

#include <boost/bind.hpp>

#include <Swiften/Client/StanzaChannel.h>
#include <Swiften/Elements/Message.h>
#include <Swiften/Elements/PubSubEvent.h>

using namespace Swift;

PubSubManagerImpl::PubSubManagerImpl(StanzaChannel* stanzaChannel, IQRouter* router) : 
		stanzaChannel(stanzaChannel),
		router(router) {
	stanzaChannel->onMessageReceived.connect(boost::bind(&PubSubManagerImpl::handleMessageRecevied, this, _1));
}

PubSubManagerImpl::~PubSubManagerImpl() {
	stanzaChannel->onMessageReceived.disconnect(boost::bind(&PubSubManagerImpl::handleMessageRecevied, this, _1));
}

void PubSubManagerImpl::handleMessageRecevied(boost::shared_ptr<Message> message) {
	if (boost::shared_ptr<PubSubEvent> event = message->getPayload<PubSubEvent>()) {
		onEvent(message->getFrom(), event->getPayload());
	}
}
