/****************************************************************************
** Game meta object code from reading C++ file 'game.h'
**
** Created: Mon Apr 8 21:06:56 2002
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.2.4   edited 2001-01-04 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "game.h"
#include <qmetaobject.h>
#include <qapplication.h>



const char *Game::className() const
{
    return "Game";
}

QMetaObject *Game::metaObj = 0;

void Game::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QObject::className(), "QObject") != 0 )
	badSuperclassWarning("Game","QObject");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString Game::tr(const char* s)
{
    return qApp->translate( "Game", s, 0 );
}

QString Game::tr(const char* s, const char * c)
{
    return qApp->translate( "Game", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* Game::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QObject::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (Game::*m1_t0)(Coordinate,Coordinate);
    typedef void (QObject::*om1_t0)(Coordinate,Coordinate);
    m1_t0 v1_0 = &Game::slotBallMoved;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    QMetaData *slot_tbl = QMetaObject::new_metadata(1);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(1);
    slot_tbl[0].name = "slotBallMoved(Coordinate,Coordinate)";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Protected;
    typedef void (Game::*m2_t0)(Coordinate,Coordinate);
    typedef void (QObject::*om2_t0)(Coordinate,Coordinate);
    typedef void (Game::*m2_t1)();
    typedef void (QObject::*om2_t1)();
    typedef void (Game::*m2_t2)();
    typedef void (QObject::*om2_t2)();
    typedef void (Game::*m2_t3)();
    typedef void (QObject::*om2_t3)();
    typedef void (Game::*m2_t4)();
    typedef void (QObject::*om2_t4)();
    m2_t0 v2_0 = &Game::ballMoved;
    om2_t0 ov2_0 = (om2_t0)v2_0;
    m2_t1 v2_1 = &Game::teamAScores;
    om2_t1 ov2_1 = (om2_t1)v2_1;
    m2_t2 v2_2 = &Game::teamBScores;
    om2_t2 ov2_2 = (om2_t2)v2_2;
    m2_t3 v2_3 = &Game::clearField;
    om2_t3 ov2_3 = (om2_t3)v2_3;
    m2_t4 v2_4 = &Game::gameOver;
    om2_t4 ov2_4 = (om2_t4)v2_4;
    QMetaData *signal_tbl = QMetaObject::new_metadata(5);
    signal_tbl[0].name = "ballMoved(Coordinate,Coordinate)";
    signal_tbl[0].ptr = (QMember)ov2_0;
    signal_tbl[1].name = "teamAScores()";
    signal_tbl[1].ptr = (QMember)ov2_1;
    signal_tbl[2].name = "teamBScores()";
    signal_tbl[2].ptr = (QMember)ov2_2;
    signal_tbl[3].name = "clearField()";
    signal_tbl[3].ptr = (QMember)ov2_3;
    signal_tbl[4].name = "gameOver()";
    signal_tbl[4].ptr = (QMember)ov2_4;
    metaObj = QMetaObject::new_metaobject(
	"Game", "QObject",
	slot_tbl, 1,
	signal_tbl, 5,
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

// SIGNAL ballMoved
void Game::ballMoved( Coordinate t0, Coordinate t1 )
{
    // No builtin function for signal parameter type Coordinate,Coordinate
    QConnectionList *clist = receivers("ballMoved(Coordinate,Coordinate)");
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

// SIGNAL teamAScores
void Game::teamAScores()
{
    activate_signal( "teamAScores()" );
}

// SIGNAL teamBScores
void Game::teamBScores()
{
    activate_signal( "teamBScores()" );
}

// SIGNAL clearField
void Game::clearField()
{
    activate_signal( "clearField()" );
}

// SIGNAL gameOver
void Game::gameOver()
{
    activate_signal( "gameOver()" );
}
