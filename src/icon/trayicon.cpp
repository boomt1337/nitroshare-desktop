/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Nathan Osman
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 **/

#include <QIcon>
#include <QRect>

#include "../util/image.h"
#include "trayicon.h"

TrayIcon::TrayIcon()
{
    mTrayIcon.setContextMenu(&mMenu);

    // KDE 5 requires that we load the SVG and render it to a pixmap - this is
    // also required to get retina-style icons in OS X
    QRect rect = mTrayIcon.geometry();
    QPixmap *pixmap = Image::renderSvg(":/img/tray.svg", QSize(rect.width(), rect.height()));

    // *Now* we can set the icon
    mTrayIcon.setIcon(QIcon(*pixmap));
    delete pixmap;

    mTrayIcon.setToolTip(tr("NitroShare"));
    mTrayIcon.show();
}

void TrayIcon::addAction(const QString &text, QObject *receiver, const char *member)
{
    mMenu.addAction(text, receiver, member);
}

void TrayIcon::addSeparator()
{
    mMenu.addSeparator();
}

void TrayIcon::showMessage(const QString &message)
{
    mTrayIcon.showMessage(tr("NitroShare Notification"), message);
}
