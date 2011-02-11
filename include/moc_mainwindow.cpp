/****************************************************************************
** MainWindow meta object code from reading C++ file 'mainwindow.h'
**
** Created: Mon Apr 8 21:05:17 2002
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.2.4   edited 2001-01-04 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "mainwindow.h"
#include <qmetaobject.h>
#include <qapplication.h>



const char *MainWindow::className() const
{
    return "MainWindow";
}

QMetaObject *MainWindow::metaObj = 0;

void MainWindow::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QMainWindow::className(), "QMainWindow") != 0 )
	badSuperclassWarning("MainWindow","QMainWindow");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString MainWindow::tr(const char* s)
{
    return qApp->translate( "MainWindow", s, 0 );
}

QString MainWindow::tr(const char* s, const char * c)
{
    return qApp->translate( "MainWindow", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* MainWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QMainWindow::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    typedef void (MainWindow::*m1_t0)();
    typedef void (QObject::*om1_t0)();
    typedef void (MainWindow::*m1_t1)();
    typedef void (QObject::*om1_t1)();
    typedef void (MainWindow::*m1_t2)(bool);
    typedef void (QObject::*om1_t2)(bool);
    typedef void (MainWindow::*m1_t3)(bool);
    typedef void (QObject::*om1_t3)(bool);
    typedef void (MainWindow::*m1_t4)(bool);
    typedef void (QObject::*om1_t4)(bool);
    typedef void (MainWindow::*m1_t5)();
    typedef void (QObject::*om1_t5)();
    typedef void (MainWindow::*m1_t6)(QString);
    typedef void (QObject::*om1_t6)(QString);
    typedef void (MainWindow::*m1_t7)();
    typedef void (QObject::*om1_t7)();
    typedef void (MainWindow::*m1_t8)();
    typedef void (QObject::*om1_t8)();
    typedef void (MainWindow::*m1_t9)();
    typedef void (QObject::*om1_t9)();
    typedef void (MainWindow::*m1_t10)();
    typedef void (QObject::*om1_t10)();
    typedef void (MainWindow::*m1_t11)();
    typedef void (QObject::*om1_t11)();
    typedef void (MainWindow::*m1_t12)();
    typedef void (QObject::*om1_t12)();
    typedef void (MainWindow::*m1_t13)();
    typedef void (QObject::*om1_t13)();
    typedef void (MainWindow::*m1_t14)();
    typedef void (QObject::*om1_t14)();
    typedef void (MainWindow::*m1_t15)(bool);
    typedef void (QObject::*om1_t15)(bool);
    typedef void (MainWindow::*m1_t16)(int);
    typedef void (QObject::*om1_t16)(int);
    typedef void (MainWindow::*m1_t17)();
    typedef void (QObject::*om1_t17)();
    m1_t0 v1_0 = &MainWindow::slotFileClose;
    om1_t0 ov1_0 = (om1_t0)v1_0;
    m1_t1 v1_1 = &MainWindow::slotFileQuit;
    om1_t1 ov1_1 = (om1_t1)v1_1;
    m1_t2 v1_2 = &MainWindow::slotViewToolBar;
    om1_t2 ov1_2 = (om1_t2)v1_2;
    m1_t3 v1_3 = &MainWindow::slotViewStatusBar;
    om1_t3 ov1_3 = (om1_t3)v1_3;
    m1_t4 v1_4 = &MainWindow::slotViewGame;
    om1_t4 ov1_4 = (om1_t4)v1_4;
    m1_t5 v1_5 = &MainWindow::slotHelpAbout;
    om1_t5 ov1_5 = (om1_t5)v1_5;
    m1_t6 v1_6 = &MainWindow::loading;
    om1_t6 ov1_6 = (om1_t6)v1_6;
    m1_t7 v1_7 = &MainWindow::slotLoadTeamA;
    om1_t7 ov1_7 = (om1_t7)v1_7;
    m1_t8 v1_8 = &MainWindow::slotLoadTeamB;
    om1_t8 ov1_8 = (om1_t8)v1_8;
    m1_t9 v1_9 = &MainWindow::slotSaveTeamA;
    om1_t9 ov1_9 = (om1_t9)v1_9;
    m1_t10 v1_10 = &MainWindow::slotSaveTeamB;
    om1_t10 ov1_10 = (om1_t10)v1_10;
    m1_t11 v1_11 = &MainWindow::slotGenerateTeamA;
    om1_t11 ov1_11 = (om1_t11)v1_11;
    m1_t12 v1_12 = &MainWindow::slotGenerateTeamB;
    om1_t12 ov1_12 = (om1_t12)v1_12;
    m1_t13 v1_13 = &MainWindow::slotGoGame;
    om1_t13 ov1_13 = (om1_t13)v1_13;
    m1_t14 v1_14 = &MainWindow::slotStopGame;
    om1_t14 ov1_14 = (om1_t14)v1_14;
    m1_t15 v1_15 = &MainWindow::slotGameReady;
    om1_t15 ov1_15 = (om1_t15)v1_15;
    m1_t16 v1_16 = &MainWindow::slotTickInterval;
    om1_t16 ov1_16 = (om1_t16)v1_16;
    m1_t17 v1_17 = &MainWindow::slotGameOver;
    om1_t17 ov1_17 = (om1_t17)v1_17;
    QMetaData *slot_tbl = QMetaObject::new_metadata(18);
    QMetaData::Access *slot_tbl_access = QMetaObject::new_metaaccess(18);
    slot_tbl[0].name = "slotFileClose()";
    slot_tbl[0].ptr = (QMember)ov1_0;
    slot_tbl_access[0] = QMetaData::Protected;
    slot_tbl[1].name = "slotFileQuit()";
    slot_tbl[1].ptr = (QMember)ov1_1;
    slot_tbl_access[1] = QMetaData::Protected;
    slot_tbl[2].name = "slotViewToolBar(bool)";
    slot_tbl[2].ptr = (QMember)ov1_2;
    slot_tbl_access[2] = QMetaData::Protected;
    slot_tbl[3].name = "slotViewStatusBar(bool)";
    slot_tbl[3].ptr = (QMember)ov1_3;
    slot_tbl_access[3] = QMetaData::Protected;
    slot_tbl[4].name = "slotViewGame(bool)";
    slot_tbl[4].ptr = (QMember)ov1_4;
    slot_tbl_access[4] = QMetaData::Protected;
    slot_tbl[5].name = "slotHelpAbout()";
    slot_tbl[5].ptr = (QMember)ov1_5;
    slot_tbl_access[5] = QMetaData::Protected;
    slot_tbl[6].name = "loading(QString)";
    slot_tbl[6].ptr = (QMember)ov1_6;
    slot_tbl_access[6] = QMetaData::Protected;
    slot_tbl[7].name = "slotLoadTeamA()";
    slot_tbl[7].ptr = (QMember)ov1_7;
    slot_tbl_access[7] = QMetaData::Protected;
    slot_tbl[8].name = "slotLoadTeamB()";
    slot_tbl[8].ptr = (QMember)ov1_8;
    slot_tbl_access[8] = QMetaData::Protected;
    slot_tbl[9].name = "slotSaveTeamA()";
    slot_tbl[9].ptr = (QMember)ov1_9;
    slot_tbl_access[9] = QMetaData::Protected;
    slot_tbl[10].name = "slotSaveTeamB()";
    slot_tbl[10].ptr = (QMember)ov1_10;
    slot_tbl_access[10] = QMetaData::Protected;
    slot_tbl[11].name = "slotGenerateTeamA()";
    slot_tbl[11].ptr = (QMember)ov1_11;
    slot_tbl_access[11] = QMetaData::Protected;
    slot_tbl[12].name = "slotGenerateTeamB()";
    slot_tbl[12].ptr = (QMember)ov1_12;
    slot_tbl_access[12] = QMetaData::Protected;
    slot_tbl[13].name = "slotGoGame()";
    slot_tbl[13].ptr = (QMember)ov1_13;
    slot_tbl_access[13] = QMetaData::Protected;
    slot_tbl[14].name = "slotStopGame()";
    slot_tbl[14].ptr = (QMember)ov1_14;
    slot_tbl_access[14] = QMetaData::Protected;
    slot_tbl[15].name = "slotGameReady(bool)";
    slot_tbl[15].ptr = (QMember)ov1_15;
    slot_tbl_access[15] = QMetaData::Protected;
    slot_tbl[16].name = "slotTickInterval(int)";
    slot_tbl[16].ptr = (QMember)ov1_16;
    slot_tbl_access[16] = QMetaData::Protected;
    slot_tbl[17].name = "slotGameOver()";
    slot_tbl[17].ptr = (QMember)ov1_17;
    slot_tbl_access[17] = QMetaData::Protected;
    metaObj = QMetaObject::new_metaobject(
	"MainWindow", "QMainWindow",
	slot_tbl, 18,
	0, 0,
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
