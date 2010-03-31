/* ner: src/view.cc
 *
 * Copyright (c) 2010 Michael Forney
 *
 * This file is a part of ner.
 *
 * ner is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License version 3, as published by the Free
 * Software Foundation.
 *
 * ner is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * ner.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "view.hh"
#include "status_bar.hh"
#include "view_manager.hh"

View::~View()
{
}

void View::focus()
{
    updateStatus();
}

std::vector<std::string> View::status() const
{
    return std::vector<std::string>();
}

void View::updateStatus()
{
    if (ViewManager::instance().activeView() == this)
        StatusBar::instance().setStatus(status());
    else
        ViewManager::instance().activeView()->updateStatus();
}

// vim: fdm=syntax fo=croql et sw=4 sts=4 ts=8

