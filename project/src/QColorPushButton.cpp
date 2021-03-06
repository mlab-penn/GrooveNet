/***************************************************************************
 *   Copyright (C) 2005, Carnegie Mellon University.                       *
 *   Maintained by: Daniel Weller                                          *
 *                  Rahul Mangharam                                        *
 *                  and the rest of the GrooveNet Team                     *
 *                                                                         *
 *   Email: dweller@ece.cmu.edu or rahulm@ece.cmu.edu                      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "QColorPushButton.h"

#include <qcolordialog.h>

QColorPushButton::QColorPushButton(QLineEdit * pBuddy, const QString & strText, QWidget * parent, const char * name)
: QPushButton(strText, parent, name), m_pBuddy(pBuddy)
{
	connect(this, SIGNAL(clicked()), SLOT(slotChangeColor()));
}

QColorPushButton::~QColorPushButton()
{
}

void QColorPushButton::slotChangeColor()
{
	QColor clrInitial(m_strColor);
	QColor clrNew = QColorDialog::getColor(clrInitial.isValid() ? clrInitial : QColor(0, 0, 0), this, "colordialog");
	if (clrNew.isValid()) {
		m_strColor = clrNew.name();
		if (m_pBuddy != NULL)
			m_pBuddy->setText(m_strColor);
		emit colorChanged();
	}
}
