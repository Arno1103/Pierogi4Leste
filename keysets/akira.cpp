//
// akira.cpp
//
// Copyright 2014 by John Pietrzak (jpietrzak8@gmail.com)
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
// along with Pierogi; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//

#include "akira.h"
#include "protocols/necprotocol.h"

AkiraTV1::AkiraTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Akira_Make,
      TV_Panels,
      index)
{
}


void AkiraTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x000A, 16);

  addKey("0", Zero_Key, 0x00, 8);
  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("3", Three_Key, 0x03, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("6", Six_Key, 0x06, 8);
  addKey("7", Seven_Key, 0x07, 8);
  addKey("8", Eight_Key, 0x08, 8);
  addKey("9", Nine_Key, 0x09, 8);
  addKey("NumberEnter", DoubleDigit_Key, 0x0A, 8);
  addKey("Mute", Mute_Key, 0x0B, 8);
  addKey("VolumeUp", VolumeUp_Key, 0x0D, 8);
  addKey("VolumeDown", VolumeDown_Key, 0x0E, 8);
  addKey("ChannelUp", ChannelUp_Key, 0x0F, 8);
  addKey("ChannelDown", ChannelDown_Key, 0x10, 8);
  addKey("Menu", Menu_Key, 0x11, 8);
  addKey("PowerToggle", Power_Key, 0x12, 8);
  addKey("Timer", Sleep_Key, 0x13, 8);
  addKey("InputNext", Input_Key, 0x14, 8);
  addKey("PreviousChannel", PrevChannel_Key, 0x17, 8);
  addKey("Presets", Favorites_Key, 0x18, 8);
  addKey("System", Unmapped_Key, 0x1D, 8);
  addKey("Lock", Unmapped_Key, 0x1F, 8);
}
