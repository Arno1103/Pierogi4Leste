//
// pirswirl.h
//
// Copyright 2014 by John Pietrzak
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

#ifndef PIRSWIRL_H
#define PIRSWIRL_H

// Pierogi "swirl" gesture recognizer

// Based on the Qt "finger swipe gesture" example for Maemo devices.

#include <QGesture>
#include <QGestureRecognizer>
#include <QPointF>

class PIRSwirlGestureRecognizer
  : public QGestureRecognizer
{
public:
  PIRSwirlGestureRecognizer() {}

  QGesture *create(QObject *target);

  QGestureRecognizer::Result recognize(
    QGesture *state,
    QObject *watched,
    QEvent *event);

  void reset(
    QGesture *state);
};


typedef enum PIRSwirlDirection
{
  No_Direction,
  Clockwise_Direction,
  CounterClockwise_Direction
};


class PIRSwirlGesture
  : public QGesture
{
public:
  PIRSwirlGesture(
    QObject *parent = 0);

  virtual ~PIRSwirlGesture();

  void reset();

  PIRSwirlDirection swirlDirection();

private:
  QPointF startPoint;
  QPointF lastPoint;
  QPointF currentPoint;
  bool triggered;
  bool cancelled;
  PIRSwirlDirection direction;

  friend class PIRSwirlGestureRecognizer;
};


#endif // PIRSWIRL_H
