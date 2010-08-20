/*
 * Copyright (c) 2010 Kevin Smith
 * Licensed under the GNU General Public License v3.
 * See Documentation/Licenses/GPLv3.txt for more information.
 */


#pragma once

#include <QWebView>

namespace Swift {
	class QtWebView : public QWebView {
		Q_OBJECT
		public:
			QtWebView(QWidget* parent);
			void keyPressEvent(QKeyEvent* event);
		signals:
			void gotFocus();

		protected:
			void focusInEvent(QFocusEvent* event);
	};
}
