/****************************************************************************
** Bot meta object code from reading C++ file 'bot.h'
**
** Created: Mon Apr 8 21:04:51 2002
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.2.4   edited 2001-01-04 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "bot.h"
#include <qmetaobject.h>
#include <qapplication.h>



const char *Bot::className() const
{
    return "Bot";
}

QMetaObject *Bot::metaObj = 0;

void Bot::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QObject::className(), "QObject") != 0 )
	badSuperclassWarning("Bot","QObject");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString Bot::tr(const char* s)
{
    return qApp->translate( "Bot", s, 0 );
}

QString Bot::tr(const char* s, const char * c)
{
    return qApp->translate( "Bot", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* Bot::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QObject::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    typedef void (Bot::*m2_t0)(Coordinate,Coordinate);
    typedef void (QObject::*om2_t0)(Coordinate,Coordinate);
    typedef void (Bot::*m2_t1)(Coordinate,Direction);
    typedef void (QObject::*om2_t1)(Coordinate,Direction);
    m2_t0 v2_0 = &Bot::botMove;
    om2_t0 ov2_0 = (om2_t0)v2_0;
    m2_t1 v2_1 = &Bot::botDirection;
    om2_t1 ov2_1 = (om2_t1)v2_1;
    QMetaData *signal_tbl = QMetaObject::new_metadata(2);
    signal_tbl[0].name = "botMove(Coordinate,Coordinate)";
    signal_tbl[0].ptr = (QMember)ov2_0;
    signal_tbl[1].name = "botDirection(Coordinate,Direction)";
    signal_tbl[1].ptr = (QMember)ov2_1;
    metaObj = QMetaObject::new_metaobject(
	"Bot", "QObject",
	0, 0,
	signal_tbl, 2,
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

// SIGNAL botMove
void Bot::botMove( Coordinate t0, Coordinate t1 )
{
    // No builtin function for signal parameter type Coordinate,Coordinate
    QConnectionList *clist = receivers("botMove(Coordinate,Coordinate)");
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

// SIGNAL botDirection
void Bot::botDirection( Coordinate t0, Direction t1 )
{
    // No builtin function for signal parameter type Coordinate,Direction
    QConnectionList *clist = receivers("botDirection(Coordinate,Direction)");
    if ( !clist || signalsBlocked() )
	return;
    typedef void (QObject::*RT0)();
    typedef void (QObject::*RT1)(Coordinate);
    typedef void (QObject::*RT2)(Coordinate,Direction);
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
