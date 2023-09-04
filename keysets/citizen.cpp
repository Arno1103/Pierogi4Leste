//
// citizen.cpp
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

#include "citizen.h"
#include "protocols/necprotocol.h"

CitizenDVD1::CitizenDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Citizen_Make,
      MediaControl_Panels,
      index)
{
}


void CitizenDVD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x00, 8);

  addKey("VOL+", VolumeUp_Key, 0x00, 8);
  addKey("PROGRAM", Program_Key, 0x01, 8);
  addKey("NEXT", Next_Key, 0x02, 8);
  addKey("STOP", Stop_Key, 0x03, 8);
  addKey("ZOOM", Zoom_Key, 0x05, 8);
  addKey("UP", Up_Key, 0x06, 8);
  addKey("ENTER", Select_Key, 0x07, 8);
  addKey("OPEN/CLOSE", Eject_Key, 0x08, 8);
  addKey("1", One_Key, 0x09, 8);
  addKey("PAUSE", Pause_Key, 0x0A, 8);
  addKey("4", Four_Key, 0x0D, 8);
  addKey("FF", FastForward_Key, 0x0E, 8);
  addKey("MUTE", Mute_Key, 0x0F, 8);

  addKey("STANDBY", Power_Key, 0x10, 8);
  addKey("7", Seven_Key, 0x11, 8);
  addKey("10+", DoubleDigit_Key, 0x12, 8);
  addKey("8", Eight_Key, 0x15, 8);
  addKey("9", Nine_Key, 0x17, 8);
  addKey("A-B", RepeatAB_Key, 0x18, 8);
  addKey("5", Five_Key, 0x19, 8);
  addKey("PREV", Previous_Key, 0x1A, 8);
  addKey("6", Six_Key, 0x1B, 8);
  addKey("2", Two_Key, 0x1D, 8);
  addKey("PLAY", Play_Key, 0x1E, 8);
  addKey("3", Three_Key, 0x1F, 8);

  addKey("RIGHT", Right_Key, 0x40, 8);
  addKey("RETURN", Unmapped_Key, 0x41, 8);
  addKey("FR", Rewind_Key, 0x42, 8);
  addKey("SLOW", Slow_Key, 0x43, 8);
  addKey("DOWN", Down_Key, 0x44, 8);
  addKey("TITLE", DiscTitle_Key, 0x45, 8);
  addKey("L/R", Unmapped_Key, 0x46, 8);
  addKey("LEFT", Left_Key, 0x47, 8);
  addKey("SUBTITLE", Captions_Key, 0x48, 8);
  addKey("ANGLE", Angle_Key, 0x49, 8);
  addKey("LANGUAGE", Audio_Key, 0x4A, 8);
  addKey("GOTO", Unmapped_Key, 0x4B, 8);

  addKey("SETUP", Menu_Key, 0x50, 8);
  addKey("OSD", Info_Key, 0x52, 8);
  addKey("STEP", StepForward_Key, 0x53, 8);
  addKey("PBC", Unmapped_Key, 0x55, 8);
  addKey("REPEAT", Repeat_Key, 0x56, 8);
  addKey("VIDEO/PSCAN", Unmapped_Key, 0x57, 8);
  addKey("0", Zero_Key, 0x59, 8);
  addKey("MENU", Menu_Key, 0x5E, 8);
  addKey("VOL-", VolumeDown_Key, 0x5F, 8);
}
