/****************************************************************************
** BotView meta object code from reading C++ file 'botview.h'
**
** Created: Mon Apr 8 21:05:29 2002
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.2.4   edited 2001-01-04 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "botview.h"
#include <qmetaobject.h>
#include <qapplication.h>



const char *BotView::className() const
{
    return "BotView";
}

QMetaObject *BotView::metaObj = 0;

void BotView::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QWidget::className(), "QWidget") != 0 )
	badSuperclassWarning("BotView","QWidget");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString BotView::tr(const char* s)
{
    return qApp->translate( "BotView", s, 0 );
}

QString BotView::tr(const char* s, const char * c)
{
    return qApp->translate( "BotView", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* BotView::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (BotView::*m1_t0)();
    typedef void (QObject::*om1_t0)();
    typedef void (BotView::*m1_t1)();
    typedef void (QObject::*om1_t1)();
    typedef void (BotView::*m1_t2)();
    typedef void (QObject::*om1_t2)();
    typedef void (BotView::*m1_t3)();
    typedef void (QObject::*om1_t3)();
    typedef void (BotView::*m1_t4)(Coordinate,Coordinate);
    typedef void (QObject::*om1_t4)(Coordinate,Coordinate);
    typedef void (BotView::*m1_t5)(Coordinate,Coordinate);
    typedef void (QObject::*om1_t5)(Coordinate,Coordinate);
    typedef void (BotView::*m1_t6)(Coordinate,Direction);
    typedef void (QObject::*om1_t6)(Coordinate,Direction);
    typedef void (BotView::*m1_t7)(Coordinate,Direction);
    typedef void (QObject::*om1_t7)(Coordinate,Direction);
    typedef void (BotView::*m1_t8)(Coordinate,Coordinate);
    typedef void (QObject::*om1_t8)(Coordinate,Coordinate);
    typedef void (BotView::*m1_t9)(int);
    typedef void (QObject::*om1_t9)(int);
    m1_t0 v1_0 = &BotView::slotScoreA;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    m1_t1 v1_1 = &BotView::slotScoreB;
    om1_t1 ov1_1 = (om1_t1)v1_1;
    m1_t2 v1_2 = &BotView::slotClearScores;
    om1_t2 ov1_2 = (om1_t2)v1_2;
    m1_t3 v1_3 = &BotView::slotClearField;
    om1_t3 ov1_3 = (om1_t3)v1_3;
    m1_t4 v1_4 = &BotView::slotMoveTeamA;
    om1_t4 ov1_4 = (om1_t4)v1_4;
    m1_t5 v1_5 = &BotView::slotMoveTeamB;
    om1_t5 ov1_5 = (om1_t5)v1_5;
    m1_t6 v1_6 = &BotView::slotTurnTeamA;
    om1_t6 ov1_6 = (om1_t6)v1_6;
    m1_t7 v1_7 = &BotView::slotTurnTeamB;
    om1_t7 ov1_7 = (om1_t7)v1_7;
    m1_t8 v1_8 = &BotView::slotMoveBall;
    om1_t8 ov1_8 = (om1_t8)v1_8;
    m1_t9 v1_9 = &BotView::slotValueChanged;
    om1_t9 ov1_9 = (om1_t9)v1_9;
    QMetaData *slot_tbl = QMetaObject::new_metadata(10);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(10);
    slot_tbl[0].name = "slotScoreA()";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Public;
    slot_tbl[1].name = "slotScoreB()";
    slot_tbl[1].ptr = (QMember)ov1_1;
    slot_tbl_access[1] = QMetaData::Public;
    slot_tbl[2].name = "slotClearScores()";
    slot_tbl[2].ptr = (QMember)ov1_2;
    slot_tbl_access[2] = QMetaData::Public;
    slot_tbl[3].name = "slotClearField()";
    slot_tbl[3].ptr = (QMember)ov1_3;
    slot_tbl_access[3] = QMetaData::Public;
    slot_tbl[4].name = "slotMoveTeamA(Coordinate,Coordinate)";
    slot_tbl[4].ptr = (QMember)ov1_4;
    slot_tbl_access[4] = QMetaData::Public;
    slot_tbl[5].name = "slotMoveTeamB(Coordinate,Coordinate)";
    slot_tbl[5].ptr = (QMember)ov1_5;
    slot_tbl_access[5] = QMetaData::Public;
    slot_tbl[6].name = "slotTurnTeamA(Coordinate,Direction)";
    slot_tbl[6].ptr = (QMember)ov1_6;
    slot_tbl_access[6] = QMetaData::Public;
    slot_tbl[7].name = "slotTurnTeamB(Coordinate,Direction)";
    slot_tbl[7].ptr = (QMember)ov1_7;
    slot_tbl_access[7] = QMetaData::Public;
    slot_tbl[8].name = "slotMoveBall(Coordinate,Coordinate)";
    slot_tbl[8].ptr = (QMember)ov1_8;
    slot_tbl_access[8] = QMetaData::Public;
    slot_tbl[9].name = "slotValueChanged(int)";
    slot_tbl[9].ptr = (QMember)ov1_9;
    slot_tbl_access[9] = QMetaData::Protected;
    typedef void (BotView::*m2_t0)(int);
    typedef void (QObject::*om2_t0)(int);
    m2_t0 v2_0 = &BotView::valueChanged;
    om2_t0 ov2_0 = (om2_t0)v2_0;
    QMetaData *signal_tbl = QMetaObject::new_metadata(1);
    signal_tbl[0].name = "valueChanged(int)";
    signal_tbl[0].ptr = (QMember)ov2_0;
    metaObj = QMetaObject::new_metaobject(
	"BotView", "QWidget",
	slot_tbl, 10,
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

// SIGNAL valueChanged
void BotView::valueChanged( int t0 )
{
    activate_signal( "valueChanged(int)", t0 );
}
