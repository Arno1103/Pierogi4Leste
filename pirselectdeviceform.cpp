//
// pirselectdeviceform.cpp
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

#include "pirselectdeviceform.h"
#include "ui_pirselectdeviceform.h"
#include "pirkeysetwidgetitem.h"
#include <QKeyEvent>

PIRDeviceTypeMgr deviceTypeManager;

extern PIRMakeMgr makeManager;

PIRSelectDeviceForm::PIRSelectDeviceForm(
  QWidget *parent)
  : QWidget(parent),
    ui(new Ui::PIRSelectDeviceForm),
    currentMake(Any_Make),
    currentDevice(Any_Device)
{
  ui->setupUi(this);

  // Make sure the user can only select one device at a time:
  ui->deviceListWidget->setSelectionMode(
    QAbstractItemView::SingleSelection);

  // Don't want to start with the line editor visible:
  ui->searchStringLineEdit->hide();
  ui->searchStringLineEdit->lower();
  ui->ssClosePushButton->hide();

  // Set some initial flags:
//  setAttribute(Qt::WA_Maemo5StackedWindow);
  setWindowFlags(windowFlags() | Qt::Window);

  // push the list of makers into the make combo box:
  makeManager.populateComboBox(ui->makeComboBox);
  deviceTypeManager.populateComboBox(ui->deviceComboBox);

  // Connection telling main window that keyset has been selected:
  connect(
    ui->deviceListWidget,
    SIGNAL(itemActivated(QListWidgetItem *)),
    parent,
    SLOT(keysetSelectionChanged(QListWidgetItem *)),
    Qt::QueuedConnection);

  // Connection used to filter keyset list:
  connect(
    ui->makeComboBox,
    SIGNAL(currentIndexChanged(int)),
    this,
    SLOT(filterListByMake(int)),
    Qt::QueuedConnection);

  connect(
    ui->deviceComboBox,
    SIGNAL(currentIndexChanged(int)),
    this,
    SLOT(filterListByDeviceType(int)),
    Qt::QueuedConnection);
}

PIRSelectDeviceForm::~PIRSelectDeviceForm()
{
  delete ui;
}

/*
void PIRSelectDeviceForm::addNameToList(
  QString name,
  unsigned int index,
  PIRMakeName make)
{
  ui->deviceListWidget->addItem(new PIRKeysetWidgetItem(name, index, make));
}
*/


void PIRSelectDeviceForm::addWidgetItem(
  PIRKeysetWidgetItem *kwi)
{
  ui->deviceListWidget->addItem(kwi);
}


QListWidget *PIRSelectDeviceForm::getDeviceListWidget()
{
  return ui->deviceListWidget;
}


void PIRSelectDeviceForm::keyPressEvent(
  QKeyEvent *event)
{
  ui->searchStringLineEdit->show();
  ui->searchStringLineEdit->raise();
  ui->ssClosePushButton->show();

  ui->searchStringLineEdit->setText(event->text());
  ui->searchStringLineEdit->setFocus();
}


void PIRSelectDeviceForm::on_searchStringLineEdit_textChanged(
  const QString &arg1)
{
  filterListByString(arg1);
}


void PIRSelectDeviceForm::on_ssClosePushButton_clicked()
{
  ui->searchStringLineEdit->hide();
  ui->searchStringLineEdit->lower();
  ui->ssClosePushButton->hide();
  ui->searchStringLineEdit->clear();
}


void PIRSelectDeviceForm::filterListByMake(
  int make)
{
  currentMake = (PIRMakeName) make;
  refilterList();
}


void PIRSelectDeviceForm::filterListByDeviceType(
  int deviceType)
{
  currentDevice = (PIRDeviceTypeName) deviceType;
  refilterList();
}


void PIRSelectDeviceForm::filterListByString(
  QString string)
{
  searchString = string;
  refilterList();
}


void PIRSelectDeviceForm::refilterList()
{
  int index = 0;
  int count = ui->deviceListWidget->count();
  PIRKeysetWidgetItem *item;
  while (index < count)
  {
    item = dynamic_cast<PIRKeysetWidgetItem *>(
      ui->deviceListWidget->item(index));

    // Does the keylist have the required make?
    if ((currentMake == Any_Make) || (item->getMake() == currentMake))
    {
      // And does it have the required type?
      if ( (currentDevice == Any_Device)
        || (item->getDeviceType() == currentDevice))
     {
        // Does it match the search string?
        if ( searchString.isEmpty()
          || item->text().contains(searchString, Qt::CaseInsensitive))
        {
          // Yes, we can show this keylist:
          item->setHidden(false);
        }
        else
        {
          item->setHidden(true);
        }
      }
      else
      {
        item->setHidden(true);
      }
    }
    else
    {
      item->setHidden(true);
    }

    ++index;
  }
}
