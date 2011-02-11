/****************************************************************************
** GABot meta object code from reading C++ file 'gabot.h'
**
** Created: Mon Apr 8 21:06:14 2002
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.2.4   edited 2001-01-04 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "gabot.h"
#include <qmetaobject.h>
#include <qapplication.h>



const char *GABot::className() const
{
    return "GABot";
}

QMetaObject *GABot::metaObj = 0;

void GABot::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QObject::className(), "QObject") != 0 )
	badSuperclassWarning("GABot","QObject");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString GABot::tr(const char* s)
{
    return qApp->translate( "GABot", s, 0 );
}

QString GABot::tr(const char* s, const char * c)
{
    return qApp->translate( "GABot", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* GABot::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QObject::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (GABot::*m1_t0)();
    typedef void (QObject::*om1_t0)();
    typedef void (GABot::*m1_t1)(Coordinate,Coordinate);
    typedef void (QObject::*om1_t1)(Coordinate,Coordinate);
    typedef void (GABot::*m1_t2)(Coordinate,Coordinate);
    typedef void (QObject::*om1_t2)(Coordinate,Coordinate);
    typedef void (GABot::*m1_t3)(Coordinate,Coordinate);
    typedef void (QObject::*om1_t3)(Coordinate,Coordinate);
    typedef void (GABot::*m1_t4)(Coordinate,Direction);
    typedef void (QObject::*om1_t4)(Coordinate,Direction);
    typedef void (GABot::*m1_t5)(Coordinate,Direction);
    typedef void (QObject::*om1_t5)(Coordinate,Direction);
    typedef void (GABot::*m1_t6)();
    typedef void (QObject::*om1_t6)();
    typedef void (GABot::*m1_t7)();
    typedef void (QObject::*om1_t7)();
    typedef void (GABot::*m1_t8)();
    typedef void (QObject::*om1_t8)();
    typedef void (GABot::*m1_t9)(int);
    typedef void (QObject::*om1_t9)(int);
    typedef void (GABot::*m1_t10)();
    typedef void (QObject::*om1_t10)();
    typedef void (GABot::*m1_t11)();
    typedef void (QObject::*om1_t11)();
    typedef void (GABot::*m1_t12)();
    typedef void (QObject::*om1_t12)();
    m1_t0 v1_0 = &GABot::slotTurn;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    m1_t1 v1_1 = &GABot::slotBallMoved;
    om1_t1 ov1_1 = (om1_t1)v1_1;
    m1_t2 v1_2 = &GABot::slotBotMoveA;
    om1_t2 ov1_2 = (om1_t2)v1_2;
    m1_t3 v1_3 = &GABot::slotBotMoveB;
    om1_t3 ov1_3 = (om1_t3)v1_3;
    m1_t4 v1_4 = &GABot::slotBotDirectionA;
    om1_t4 ov1_4 = (om1_t4)v1_4;
    m1_t5 v1_5 = &GABot::slotBotDirectionB;
    om1_t5 ov1_5 = (om1_t5)v1_5;
    m1_t6 v1_6 = &GABot::slotTeamAScores;
    om1_t6 ov1_6 = (om1_t6)v1_6;
    m1_t7 v1_7 = &GABot::slotTeamBScores;
    om1_t7 ov1_7 = (om1_t7)v1_7;
    m1_t8 v1_8 = &GABot::slotClearField;
    om1_t8 ov1_8 = (om1_t8)v1_8;
    m1_t9 v1_9 = &GABot::slotTickInterval;
    om1_t9 ov1_9 = (om1_t9)v1_9;
    m1_t10 v1_10 = &GABot::slotStartTimer;
    om1_t10 ov1_10 = (om1_t10)v1_10;
    m1_t11 v1_11 = &GABot::slotStopTimer;
    om1_t11 ov1_11 = (om1_t11)v1_11;
    m1_t12 v1_12 = &GABot::slotGameOver;
    om1_t12 ov1_12 = (om1_t12)v1_12;
    QMetaData *slot_tbl = QMetaObject::new_metadata(13);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(13);
    slot_tbl[0].name = "slotTurn()";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Protected;
    slot_tbl[1].name = "slotBallMoved(Coordinate,Coordinate)";
    slot_tbl[1].ptr = (QMember)ov1_1;
    slot_tbl_access[1] = QMetaData::Protected;
    slot_tbl[2].name = "slotBotMoveA(Coordinate,Coordinate)";
    slot_tbl[2].ptr = (QMember)ov1_2;
    slot_tbl_access[2] = QMetaData::Protected;
    slot_tbl[3].name = "slotBotMoveB(Coordinate,Coordinate)";
    slot_tbl[3].ptr = (QMember)ov1_3;
    slot_tbl_access[3] = QMetaData::Protected;
    slot_tbl[4].name = "slotBotDirectionA(Coordinate,Direction)";
    slot_tbl[4].ptr = (QMember)ov1_4;
    slot_tbl_access[4] = QMetaData::Protected;
    slot_tbl[5].name = "slotBotDirectionB(Coordinate,Direction)";
    slot_tbl[5].ptr = (QMember)ov1_5;
    slot_tbl_access[5] = QMetaData::Protected;
    slot_tbl[6].name = "slotTeamAScores()";
    slot_tbl[6].ptr = (QMember)ov1_6;
    slot_tbl_access[6] = QMetaData::Protected;
    slot_tbl[7].name = "slotTeamBScores()";
    slot_tbl[7].ptr = (QMember)ov1_7;
    slot_tbl_access[7] = QMetaData::Protected;
    slot_tbl[8].name = "slotClearField()";
    slot_tbl[8].ptr = (QMember)ov1_8;
    slot_tbl_access[8] = QMetaData::Protected;
    slot_tbl[9].name = "slotTickInterval(int)";
    slot_tbl[9].ptr = (QMember)ov1_9;
    slot_tbl_access[9] = QMetaData::Public;
    slot_tbl[10].name = "slotStartTimer()";
    slot_tbl[10].ptr = (QMember)ov1_10;
    slot_tbl_access[10] = QMetaData::Public;
    slot_tbl[11].name = "slotStopTimer()";
    slot_tbl[11].ptr = (QMember)ov1_11;
    slot_tbl_access[11] = QMetaData::Public;
    slot_tbl[12].name = "slotGameOver()";
    slot_tbl[12].ptr = (QMember)ov1_12;
    slot_tbl_access[12] = QMetaData::Public;
    typedef void (GABot::*m2_t0)();
    typedef void (QObject::*om2_t0)();
    typedef void (GABot::*m2_t1)();
    typedef void (QObject::*om2_t1)();
    typedef void (GABot::*m2_t2)();
    typedef void (QObject::*om2_t2)();
    typedef void (GABot::*m2_t3)(Coordinate);
    typedef void (QObject::*om2_t3)(Coordinate);
    typedef void (GABot::*m2_t4)(Coordinate,Coordinate);
    typedef void (QObject::*om2_t4)(Coordinate,Coordinate);
    typedef void (GABot::*m2_t5)(Coordinate,Coordinate);
    typedef void (QObject::*om2_t5)(Coordinate,Coordinate);
    typedef void (GABot::*m2_t6)(Coordinate,Coordinate);
    typedef void (QObject::*om2_t6)(Coordinate,Coordinate);
    typedef void (GABot::*m2_t7)(Coordinate,Direction);
    typedef void (QObject::*om2_t7)(Coordinate,Direction);
    typedef void (GABot::*m2_t8)(Coordinate,Direction);
    typedef void (QObject::*om2_t8)(Coordinate,Direction);
    typedef void (GABot::*m2_t9)();
    typedef void (QObject::*om2_t9)();
    typedef void (GABot::*m2_t10)(bool);
    typedef void (QObject::*om2_t10)(bool);
    typedef void (GABot::*m2_t11)();
    typedef void (QObject::*om2_t11)();
    m2_t0 v2_0 = &GABot::teamAScores;
    om2_t0 ov2_0 = (om2_t0)v2_0;
    m2_t1 v2_1 = &GABot::teamBScores;
    om2_t1 ov2_1 = (om2_t1)v2_1;
    m2_t2 v2_2 = &GABot::clearScores;
    om2_t2 ov2_2 = (om2_t2)v2_2;
    m2_t3 v2_3 = &GABot::putBall;
    om2_t3 ov2_3 = (om2_t3)v2_3;
    m2_t4 v2_4 = &GABot::moveBall;
    om2_t4 ov2_4 = (om2_t4)v2_4;
    m2_t5 v2_5 = &GABot::moveTeamA;
    om2_t5 ov2_5 = (om2_t5)v2_5;
    m2_t6 v2_6 = &GABot::moveTeamB;
    om2_t6 ov2_6 = (om2_t6)v2_6;
    m2_t7 v2_7 = &GABot::turnTeamA;
    om2_t7 ov2_7 = (om2_t7)v2_7;
    m2_t8 v2_8 = &GABot::turnTeamB;
    om2_t8 ov2_8 = (om2_t8)v2_8;
    m2_t9 v2_9 = &GABot::clearField;
    om2_t9 ov2_9 = (om2_t9)v2_9;
    m2_t10 v2_10 = &GABot::gameReady;
    om2_t10 ov2_10 = (om2_t10)v2_10;
    m2_t11 v2_11 = &GABot::gameOver;
    om2_t11 ov2_11 = (om2_t11)v2_11;
    QMetaData *signal_tbl = QMetaObject::new_metadata(12);
    signal_tbl[0].name = "teamAScores()";
    signal_tbl[0].ptr = (QMember)ov2_0;
    signal_tbl[1].name = "teamBScores()";
    signal_tbl[1].ptr = (QMember)ov2_1;
    signal_tbl[2].name = "clearScores()";
    signal_tbl[2].ptr = (QMember)ov2_2;
    signal_tbl[3].name = "putBall(Coordinate)";
    signal_tbl[3].ptr = (QMember)ov2_3;
    signal_tbl[4].name = "moveBall(Coordinate,Coordinate)";
    signal_tbl[4].ptr = (QMember)ov2_4;
    signal_tbl[5].name = "moveTeamA(Coordinate,Coordinate)";
    signal_tbl[5].ptr = (QMember)ov2_5;
    signal_tbl[6].name = "moveTeamB(Coordinate,Coordinate)";
    signal_tbl[6].ptr = (QMember)ov2_6;
    signal_tbl[7].name = "turnTeamA(Coordinate,Direction)";
    signal_tbl[7].ptr = (QMember)ov2_7;
    signal_tbl[8].name = "turnTeamB(Coordinate,Direction)";
    signal_tbl[8].ptr = (QMember)ov2_8;
    signal_tbl[9].name = "clearField()";
    signal_tbl[9].ptr = (QMember)ov2_9;
    signal_tbl[10].name = "gameReady(bool)";
    signal_tbl[10].ptr = (QMember)ov2_10;
    signal_tbl[11].name = "gameOver()";
    signal_tbl[11].ptr = (QMember)ov2_11;
    metaObj = QMetaObject::new_metaobject(
	"GABot", "QObject",
	slot_tbl, 13,
	signal_tbl, 12,
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

// SIGNAL teamAScores
void GABot::teamAScores()
{
    activate_signal( "teamAScores()" );
}

// SIGNAL teamBScores
void GABot::teamBScores()
{
    activate_signal( "teamBScores()" );
}

// SIGNAL clearScores
void GABot::clearScores()
{
    activate_signal( "clearScores()" );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL putBall
void GABot::putBall( Coordinate t0 )
{
    // No builtin function for signal parameter type Coordinate
    QConnectionList *clist = receivers("putBall(Coordinate)");
    if ( !clist || signalsBlocked() )
	return;
    typedef void (QObject::*RT0)();
    typedef void (QObject::*RT1)(Coordinate);
    RT0 r0;
    RT1 r1;
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
	}
    }
}

// SIGNAL moveBall
void GABot::moveBall( Coordinate t0, Coordinate t1 )
{
    // No builtin function for signal parameter type Coordinate,Coordinate
    QConnectionList *clist = receivers("moveBall(Coordinate,Coordinate)");
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

// SIGNAL moveTeamA
void GABot::moveTeamA( Coordinate t0, Coordinate t1 )
{
    // No builtin function for signal parameter type Coordinate,Coordinate
    QConnectionList *clist = receivers("moveTeamA(Coordinate,Coordinate)");
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

// SIGNAL moveTeamB
void GABot::moveTeamB( Coordinate t0, Coordinate t1 )
{
    // No builtin function for signal parameter type Coordinate,Coordinate
    QConnectionList *clist = receivers("moveTeamB(Coordinate,Coordinate)");
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

// SIGNAL turnTeamA
void GABot::turnTeamA( Coordinate t0, Direction t1 )
{
    // No builtin function for signal parameter type Coordinate,Direction
    QConnectionList *clist = receivers("turnTeamA(Coordinate,Direction)");
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

// SIGNAL turnTeamB
void GABot::turnTeamB( Coordinate t0, Direction t1 )
{
    // No builtin function for signal parameter type Coordinate,Direction
    QConnectionList *clist = receivers("turnTeamB(Coordinate,Direction)");
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

// SIGNAL clearField
void GABot::clearField()
{
    activate_signal( "clearField()" );
}

// SIGNAL gameReady
void GABot::gameReady( bool t0 )
{
    activate_signal_bool( "gameReady(bool)", t0 );
}

// SIGNAL gameOver
void GABot::gameOver()
{
    activate_signal( "gameOver()" );
}
