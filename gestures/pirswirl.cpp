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

#include "pirswirl.h"

#include <QWidget>
//#include <QGraphicsObject>
#include <QGesture>
#include <QTouchEvent>

// PIRSwirlGestureRecognizer methods:

QGesture *PIRSwirlGestureRecognizer::create(
  QObject *target)
{
  if (target)
  {
    if (target->isWidgetType())
    {
      QWidget *widget = static_cast<QWidget *>(target);

      widget->setAttribute(Qt::WA_AcceptTouchEvents);
    }
/*
    else
    {
      QGraphicsObject *go = qobject_cast<QGraphicsObject *>(target);

      if (go)
      {
        go->setAcceptTouchEvents(true);
      }
    }
*/
  }

  return new PIRSwirlGesture();
}

QGestureRecognizer::Result PIRSwirlGestureRecognizer::recognize(
  QGesture *state,
  QObject *,
  QEvent *event)
{
  PIRSwirlGesture *psg = static_cast<PIRSwirlGesture *>(state);

  const QTouchEvent *tev = static_cast<const QTouchEvent *>(event);

  QGestureRecognizer::Result result = QGestureRecognizer::Ignore;

  switch (event->type())
  {
  case QEvent::TouchBegin:
    result = QGestureRecognizer::MayBeGesture;
    if (tev->touchPoints().size() >= 1)
    {
      QTouchEvent::TouchPoint p1 = tev->touchPoints().first();
      psg->startPoint = p1.startPos();
    }
    break;

  case QEvent::TouchEnd:
    if (psg->cancelled)
    {
      result = QGestureRecognizer::Ignore;
    }
    else if (psg->triggered)
    {
      result = QGestureRecognizer::FinishGesture;
    }
    else
    {
      result = QGestureRecognizer::CancelGesture;
    }
    break;

  case QEvent::TouchUpdate:
    if ( (!psg->cancelled)
      && (tev->touchPoints().size() >= 1))
    {
      QTouchEvent::TouchPoint p1 = tev->touchPoints().first();

      psg->currentPoint = p1.pos();

      // Update the hot-spot; need more info on this!
      psg->setHotSpot(
        QPointF(
          p1.screenPos().x()
            - (psg->currentPoint.x() - psg->startPoint.x()) / 2,
          p1.screenPos().y()
            - (psg->currentPoint.y() - psg->startPoint.y()) / 2));

      QPointF delta = p1.pos() - psg->startPoint;

      if ( (qAbs(delta.x()) > 25)
        && (qAbs(delta.y()) < qAbs(delta.x()) * 0.2))
      {
        if (delta.x() > 0)
        {
          psg->direction = Right_Direction;
        }
        else
        {
          psg->direction = Left_Direction;
        }

        if (!psg->triggered)
        {
          psg->triggered = true;
          result = QGestureRecognizer::TriggerGesture;
        }
      }
// Ignore up/down for now:
/*
      else if ( (qAbs(delta.y()) > 25)
        && (qAbs(delta.x()) < qAbs(delta.y()) * 0.2))
      {
        if (delta.y() > 0)
        {
          psg->direction = Down_Direction;
        }
        else
        {
          psg->direction = Up_Direction;
        }

        if (!psg->triggered)
        {
          psg->triggered = true;
          result = QGestureRecognizer::TriggerGesture;
        }
      }
*/
      else
      {
        if (!psg->triggered)
        {
          result = QGestureRecognizer::MayBeGesture;
        }
        else
        {
          psg->cancelled = true;
          result = QGestureRecognizer::CancelGesture;
        }
      }
    }
    break;

  default:
    break;
  }

  return result;
}


void PIRSwirlGestureRecognizer::reset(
  QGesture *state)
{
  PIRSwirlGesture *psg = static_cast<PIRSwirlGesture *>(state);

  psg->reset();

  QGestureRecognizer::reset(state);
}


// PIRSwirlGesture methods:

PIRSwirlGesture::PIRSwirlGesture(
  QObject *parent)
  : QGesture(parent),
    triggered(false),
    cancelled(false),
    direction(No_Direction)
{
}


PIRSwirlGesture::~PIRSwirlGesture()
{
}


void PIRSwirlGesture::reset()
{
  startPoint = QPoint();
  lastPoint = QPoint();
  currentPoint = QPoint();
  triggered = false;
  cancelled = false;
  direction = No_Direction;
}


PIRSwirlDirection PIRSwirlGesture::swipeDirection()
{
  return direction;
}
