/*
 * Copyright (C) 2019 Jaume Mila Bea <jaume@westial.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Author: Jaume Mila Bea <jaume@westial.com>
 */

#include "CommandBus.h"

void CommandBus::setup(Command** items, int maxItems)
{
	this->lastIndex = -1;
	this->maxItems = maxItems;
    this->items = items;
}

CommandBus::CommandBus(Command** items, int maxItems)
{
	this->setup(items, maxItems);
};

CommandBus::CommandBus() {
	this->setup(new Command*[25], 25);
};

CommandBus::~CommandBus()
{
    delete [] items;
};

void CommandBus::moveDown()
{
    for (int index = 0; index < this->lastIndex; index ++)
    {
    	this->items[index] = this->items[index + 1];
    }
    this->lastIndex --;
};

void CommandBus::append(Command* command)
{
    this->lastIndex ++;
    this->items[this->lastIndex] = command;
};

Command* CommandBus::last()
{
    Command* returner = this->items[this->lastIndex];
    this->lastIndex --;
    return returner;
};

Command* CommandBus::first()
{
    Command* returner = this->items[0];
    this->moveDown();
    return returner;
};

bool CommandBus::isEmpty()
{
	return this->lastIndex == -1;
}

void CommandBus::clean() {
	this->lastIndex = -1;
}
