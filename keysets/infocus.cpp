//
// infocus.cpp
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

#include "infocus.h"

#include "protocols/necprotocol.h"
#include "protocols/aiwaprotocol.h"


InfocusProjector1::InfocusProjector1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Projector Keyset 1",
      Infocus_Make,
      MediaControl_Panels,
      index)
{
}


void InfocusProjector1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x0134, 16);

  addKey("Right", Right_Key, 0x0A, 8);
  addKey("Down", Down_Key, 0x0B, 8);
  addKey("Contrast-", ContrastDown_Key, 0x0C, 8);
  addKey("Rgb1", Unmapped_Key, 0x0D, 8);
  addKey("Rig Select", Unmapped_Key, 0x0E, 8);
  addKey("Keystone+", Unmapped_Key, 0x0F, 8);
  addKey("Contrast+", ContrastUp_Key, 0x10, 8);
  addKey("LE Select", Unmapped_Key, 0x12, 8);
  addKey("Power", Power_Key, 0x15, 8);
  addKey("Block", Unmapped_Key, 0x16, 8);
  addKey("Keystone-", Unmapped_Key, 0x40, 8);
  addKey("Effect", Unmapped_Key, 0x41, 8);
  addKey("Up", Up_Key, 0x42, 8);
  addKey("Brightness+", BrightnessUp_Key, 0x46, 8);
  addKey("Left", Left_Key, 0x47, 8);
  addKey("Menu", Menu_Key, 0x48, 8);
  addKey("Brightness-", BrightnessDown_Key, 0x4E, 8);
  addKey("Video1", Unmapped_Key, 0x4F, 8);
  addKey("Vol-", VolumeDown_Key, 0x55, 8);
  addKey("Vol+", VolumeUp_Key, 0x56, 8);
}


InfocusProjector2::InfocusProjector2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Projector Keyset 2",
      Infocus_Make,
      MediaControl_Panels,
      index)
{
}


void InfocusProjector2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new AiwaProtocol(guiObject, index);

  setPreData(0x0102, 13);

  addKey("vol up", VolumeUp_Key, 0x0E, 8);
  addKey("vol down", VolumeDown_Key, 0x0F, 8);
  addKey("power", Power_Key, 0x10, 8);
  addKey("lite show", Unmapped_Key, 0x11, 8);
//  addKey("down arrow", Down_Key, 0x12, 8);
  addKey("next ^", Next_Key, 0x12, 8);
  addKey("next ^", Up_Key, 0x12, 8); //?
  addKey("prog", Program_Key, 0x17, 8);
  addKey("freeze/escape", Pause_Key, 0x18, 8);
  addKey("freeze/escape", Exit_Key, 0x18, 8);
  addKey("menu", Menu_Key, 0x19, 8); // "menu edit"
  addKey("mic >", Unmapped_Key, 0x1B, 8);
  addKey("mic >", Right_Key, 0x1B, 8);
  addKey("mute <", Mute_Key, 0x1D, 8);
  addKey("mute <", Left_Key, 0x1D, 8);
  addKey("enter", Select_Key, 0x1E, 8); // "select enter"
//  addKey("up arrow", Up_Key, 0x1F, 8);
  addKey("prev v", Previous_Key, 0x1F, 8);
  addKey("prev v", Down_Key, 0x1F, 8);
}


InfocusProjector3::InfocusProjector3(
  unsigned int index)
  : PIRKeysetMetaData(
      "Projector Keyset 3",
      Infocus_Make,
      MediaControl_Panels,
      index)
{
}


void InfocusProjector3::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x4E87, 16);

  addKey("menu", Menu_Key, 0x02, 8);
  addKey("Bright +", BrightnessUp_Key, 0x03, 8);
  addKey("vol down", VolumeDown_Key, 0x04, 8);
  addKey("Bright -", BrightnessDown_Key, 0x07, 8);
  addKey("vol up", VolumeUp_Key, 0x08, 8);
  addKey("Right mouse", Unmapped_Key, 0x0B, 8);
  addKey("Left mouse", Unmapped_Key, 0x0C, 8);
  addKey("Standby", Unmapped_Key, 0x0D, 8); // ?
  addKey("Freeze", Pause_Key, 0x0E, 8);
  addKey("light", Unmapped_Key, 0x0F, 8);
  addKey("Source Select", Input_Key, 0x10, 8);
  addKey("left arrow", Left_Key, 0x11, 8);
  addKey("right arrow", Right_Key, 0x12, 8);
  addKey("up arrow", Up_Key, 0x13, 8);
  addKey("down arrow", Down_Key, 0x14, 8);
  addKey("Power Toggle", Power_Key, 0x17, 8);
  addKey("Bulb reset", Unmapped_Key, 0x18, 8);
  addKey("Direct source 1", PCInput_Key, 0x19, 8); // "Computer Toggle"
  addKey("Direct source 2", AuxInput_Key, 0x1A, 8); // "Video Toggle"
  addKey("Keystone +", Unmapped_Key, 0x20, 8);
  addKey("Keystone -", Unmapped_Key, 0x21, 8);
  addKey("Slide next", Next_Key, 0x24, 8);
  addKey("Slide previous", Previous_Key, 0x25, 8);
  addKey("Zoom +", Unmapped_Key, 0x26, 8);
  addKey("Zoom -", Unmapped_Key, 0x27, 8);
  addKey("Zoom toggle", Zoom_Key, 0x28, 8);
  addKey("Mute", Mute_Key, 0x29, 8);
  addKey("Program flash", Unmapped_Key, 0x2A, 8);
  addKey("Effect", Unmapped_Key, 0x2B, 8);
  addKey("Presets", PictureMode_Key, 0x2C, 8);
  addKey("Source 1", Unmapped_Key, 0x2D, 8);
  addKey("Source 2", Unmapped_Key, 0x2E, 8);
  addKey("Source 3", Unmapped_Key, 0x2F, 8);
  addKey("Source 4", Unmapped_Key, 0x30, 8);
  addKey("Blank", Unmapped_Key, 0x31, 8);
  addKey("Select", Select_Key, 0x32, 8);
  addKey("Auto Image", Unmapped_Key, 0x33, 8);
  addKey("Resize", Unmapped_Key, 0x34, 8);
  addKey("Overscan", Unmapped_Key, 0x35, 8);
  addKey("Contrast +", ContrastUp_Key, 0x36, 8);
  addKey("Contrast -", ContrastDown_Key, 0x37, 8);
  addKey("Power Off", PowerOff_Key, 0x39, 8);
  addKey("Power On", PowerOn_Key, 0x3A, 8);
  addKey("Native", Unmapped_Key, 0x3B, 8);
  addKey("16:9", Unmapped_Key, 0x3C, 8);
  addKey("4:3", Unmapped_Key, 0x3D, 8);
  addKey("Letterbox", Unmapped_Key, 0x3E, 8);
  addKey("Natrl Wide", Unmapped_Key, 0x3F, 8);
  addKey("Preset 1", Unmapped_Key, 0x40, 8);
  addKey("Preset 2", Unmapped_Key, 0x41, 8);
  addKey("Preset 3", Unmapped_Key, 0x42, 8);
}
