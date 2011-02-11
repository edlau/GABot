/****************************************************************************
** Team meta object code from reading C++ file 'team.h'
**
** Created: Mon Apr 8 21:05:52 2002
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.2.4   edited 2001-01-04 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "team.h"
#include <qmetaobject.h>
#include <qapplication.h>



const char *Team::className() const
{
    return "Team";
}

QMetaObject *Team::metaObj = 0;

void Team::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QObject::className(), "QObject") != 0 )
	badSuperclassWarning("Team","QObject");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString Team::tr(const char* s)
{
    return qApp->translate( "Team", s, 0 );
}

QString Team::tr(const char* s, const char * c)
{
    return qApp->translate( "Team", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* Team::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QObject::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (Team::*m1_t0)(Coordinate,Coordinate);
    typedef void (QObject::*om1_t0)(Coordinate,Coordinate);
    typedef void (Team::*m1_t1)(Coordinate,Direction);
    typedef void (QObject::*om1_t1)(Coordinate,Direction);
    m1_t0 v1_0 = &Team::slotBotMove;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    m1_t1 v1_1 = &Team::slotBotDirection;
    om1_t1 ov1_1 = (om1_t1)v1_1;
    QMetaData *slot_tbl = QMetaObject::new_metadata(2);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(2);
    slot_tbl[0].name = "slotBotMove(Coordinate,Coordinate)";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Protected;
    slot_tbl[1].name = "slotBotDirection(Coordinate,Direction)";
    slot_tbl[1].ptr = (QMember)ov1_1;
    slot_tbl_access[1] = QMetaData::Protected;
    typedef void (Team::*m2_t0)(Coordinate,Coordinate);
    typedef void (QObject::*om2_t0)(Coordinate,Coordinate);
    typedef void (Team::*m2_t1)(Coordinate,Direction);
    typedef void (QObject::*om2_t1)(Coordinate,Direction);
    m2_t0 v2_0 = &Team::botMove;
    om2_t0 ov2_0 = (om2_t0)v2_0;
    m2_t1 v2_1 = &Team::botDirection;
    om2_t1 ov2_1 = (om2_t1)v2_1;
    QMetaData *signal_tbl = QMetaObject::new_metadata(2);
    signal_tbl[0].name = "botMove(Coordinate,Coordinate)";
    signal_tbl[0].ptr = (QMember)ov2_0;
    signal_tbl[1].name = "botDirection(Coordinate,Direction)";
    signal_tbl[1].ptr = (QMember)ov2_1;
    metaObj = QMetaObject::new_metaobject(
	"Team", "QObject",
	slot_tbl, 2,
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
void Team::botMove( Coordinate t0, Coordinate t1 )
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
void Team::botDirection( Coordinate t0, Direction t1 )
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
