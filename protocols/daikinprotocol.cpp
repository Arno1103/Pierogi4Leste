//
// daikinprotocol.cpp
//
// Copyright 2012, 2013 by John Pietrzak (jpietrzak8@gmail.com)
//
// This file is part of Pierogi.
//
// Pierogi is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// Pierogi is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//

#include "daikinprotocol.h"

#include "pirinfraredled.h"

#include "pirexception.h"

// Some global communication stuff:
#include <QMutex>
extern bool commandInFlight;
extern QMutex commandIFMutex;

// A "stateful" air conditioner protocol.
//
// At the moment, I've only got partial information on Daikin.  Plus, I've got
// two different protocol descriptions.  Both might be different views of
// the same protocol, though.
//
// Protocol one:
// A "zero" is encoded with a 525 usec pulse, 525 usec space.
// A "one" is encoded with a 525 usec pulse, 1600 usec space.
// Commands end with a trailing 525 usec pulse.
// The carrier frequency is 33 kHz.
//
// Protocol two:
// A "zero" is encoded with a 425 usec pulse, 440 usec space.
// A "one" is encoded with a 425 usec pulse, 1300 usec space.
// The header is a 3440 usec pulse, 1745 usec space.
// Commands end with a trailing 425 usec pulse.
// There is a 30000 usec space mid-command, and a 100000 usec space at the
// end of a command.
// The carrier frequency is 38 kHz.
