/****************************************************************************
** Ball meta object code from reading C++ file 'ball.h'
**
** Created: Mon Apr 8 21:06:45 2002
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.2.4   edited 2001-01-04 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "ball.h"
#include <qmetaobject.h>
#include <qapplication.h>



const char *Ball::className() const
{
    return "Ball";
}

QMetaObject *Ball::metaObj = 0;

void Ball::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QObject::className(), "QObject") != 0 )
	badSuperclassWarning("Ball","QObject");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString Ball::tr(const char* s)
{
    return qApp->translate( "Ball", s, 0 );
}

QString Ball::tr(const char* s, const char * c)
{
    return qApp->translate( "Ball", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* Ball::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QObject::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    typedef void (Ball::*m2_t0)(Coordinate,Coordinate);
    typedef void (QObject::*om2_t0)(Coordinate,Coordinate);
    m2_t0 v2_0 = &Ball::ballMove;
    om2_t0 ov2_0 = (om2_t0)v2_0;
    QMetaData *signal_tbl = QMetaObject::new_metadata(1);
    signal_tbl[0].name = "ballMove(Coordinate,Coordinate)";
    signal_tbl[0].ptr = (QMember)ov2_0;
    metaObj = QMetaObject::new_metaobject(
	"Ball", "QObject",
	0, 0,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    metaObj->set_slot_access( slot_tbl_access );
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    return metaObj;
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL ballMove
void Ball::ballMove( Coordinate t0, Coordinate t1 )
{
    // No builtin function for signal parameter type Coordinate,Coordinate
    QConnectionList *clist = receivers("ballMove(Coordinate,Coordinate)");
    if ( !clist || signalsBlocked() )
	return;
    typedef void (QObject::*RT0)();
    typedef void (QObject::*RT1)(Coordinate);
    typedef void (QObject::*RT2)(Coordinate,Coordinate);
    RT0 r0;
    RT1 r1;
    RT2 r2;
    QConnectionListIt it(*clist);
    QConnection   *c;
    QSenderObject *object;
    while ( (c=it.current()) ) {
	++it;
	object = (QSenderObject*)c->object();
	object->setSender( this );
	switch ( c->numArgs() ) {
	    case 0:
		r0 = (RT0)*(c->member());
		(object->*r0)();
		break;
	    case 1:
		r1 = (RT1)*(c->member());
		(object->*r1)(t0);
		break;
	    case 2:
		r2 = (RT2)*(c->member());
		(object->*r2)(t0, t1);
		break;
	}
    }
}
