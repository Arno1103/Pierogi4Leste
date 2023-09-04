//
// eiki.cpp
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
// along with Pierogi; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//

#include "eiki.h"

#include "protocols/necprotocol.h"

EikiProjector1::EikiProjector1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Projector Keyset 1",
      Eiki_Make,
      MediaControl_Panels,
      index)
{
}


void EikiProjector1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x30, 8);

  addKey("Power", Power_Key, 0x00, 8);
  addKey("Digital Zoom +", Unmapped_Key, 0x01, 8);
  addKey("Digital Zoom -", Unmapped_Key, 0x02, 8);
  addKey("Input", Input_Key, 0x05, 8);
  addKey("Vol +", VolumeUp_Key, 0x09, 8);
  addKey("Vol -", VolumeDown_Key, 0x0A, 8);
  addKey("Mute", Mute_Key, 0x0B, 8);
  addKey("Image", Unmapped_Key, 0x0C, 8);
  addKey("Menu", Menu_Key, 0x1C, 8);
  addKey("Right Arrow", Right_Key, 0x1D, 8);
  addKey("Left Arrow", Left_Key, 0x1E, 8);
  addKey("Select", Select_Key, 0x3F, 8);
  addKey("Freeze", Pause_Key, 0x43, 8);
  addKey("Zoom -", Unmapped_Key, 0x46, 8);
  addKey("Zoom +", Unmapped_Key, 0x47, 8);
  addKey("Focus +", Unmapped_Key, 0x4A, 8);
  addKey("Focus -", Unmapped_Key, 0x4B, 8);
//  addKey("Input", Input_Key, 0x65, 8);
//  addKey("Vol +", VolumeUp_Key, 0x67, 8);
//  addKey("Vol -", VolumeDown_Key, 0x68, 8);
//  addKey("Service Mode", Unmapped_Key, 0x6B, 8);
//  addKey("Zoom", Unmapped_Key, 0x6D, 8);
//  addKey("Focus", Unmapped_Key, 0x6E, 8);
//  addKey("Image", Unmapped_Key, 0x6F, 8);
//  addKey("Power", Unmapped_Key, 0x71, 8);
  addKey("Auto PC Adj", Unmapped_Key, 0x89, 8);
  addKey("P-Timer", Unmapped_Key, 0x8A, 8);
  addKey("No Show", Unmapped_Key, 0x8B, 8);
  addKey("Up Arrow", Up_Key, 0x8C, 8);
  addKey("Down Arrow", Down_Key, 0x8D, 8);
  addKey("Keystone +", Unmapped_Key, 0x8E, 8);
  addKey("Keystone -", Unmapped_Key, 0x8F, 8);
//  addKey("Diagnostic EEProm Ck", Unmapped_Key, 0x92, 8);
//  addKey("Service Mode", Unmapped_Key, 0x93, 8);
//  addKey("Service Mode", Unmapped_Key, 0x94, 8);
//  addKey("Service Mode", Unmapped_Key, 0x95, 8);
//  addKey("Vol 0-43-63", Unmapped_Key, 0x96, 8);
//  addKey("Service Mode", Unmapped_Key, 0x97, 8);
//  addKey("Service Mode", Unmapped_Key, 0x98, 8);
//  addKey("Service Mode", Unmapped_Key, 0x99, 8);
//  addKey("Service Mode", Unmapped_Key, 0x9A, 8);
//  addKey("Service Mode", Unmapped_Key, 0x9B, 8);
//  addKey("Service Mode", Unmapped_Key, 0x9C, 8);
//  addKey("Reset ??", Unmapped_Key, 0x9D, 8);
//  addKey("Service Mode", Unmapped_Key, 0x9E, 8);
  addKey("Discrete On", PowerOn_Key, 0xA0, 8);
  addKey("Discrete Off", PowerOff_Key, 0xA1, 8);
//  addKey("Power Off/Query", Unmapped_Key, 0xA2, 8);
//  addKey("Input 1", Unmapped_Key, 0xA5, 8);
//  addKey("Input 2", Unmapped_Key, 0xA6, 8);
//  addKey("Input 3", Unmapped_Key, 0xA7, 8);
//  addKey("Digital Computer", Unmapped_Key, 0xA8, 8);
//  addKey("Freeze On", Unmapped_Key, 0xA9, 8);
//  addKey("No Show Discrete Off", Unmapped_Key, 0xAA, 8);
//  addKey("Mute On", Unmapped_Key, 0xAB, 8);
//  addKey("Mute Off", Unmapped_Key, 0xAC, 8);
//  addKey("No Show Discrete On", Unmapped_Key, 0xAD, 8);
//  addKey("Freeze Off", Unmapped_Key, 0xAE, 8);
  addKey("Menu Off", Exit_Key, 0xBD, 8);
//  addKey("Contrast 0-32-63", Unmapped_Key, 0xC2, 8);
//  addKey("Brightness 0-32-63", Unmapped_Key, 0xC3, 8);
//  addKey("Service Mode", Unmapped_Key, 0xC6, 8);
//  addKey("Composite", CompositeInput_Key, 0xC7, 8);
//  addKey("Gamma", Unmapped_Key, 0xC8, 8);
//  addKey("Service Mode", Unmapped_Key, 0xC9, 8);
//  addKey("Gamma 0-8-15", Unmapped_Key, 0xCC, 8);
//  addKey("Color 0", Unmapped_Key, 0xCD, 8);
//  addKey("Discrete Standard", Unmapped_Key, 0xCE, 8);
//  addKey("Service Mode", Unmapped_Key, 0xCF, 8);
}
