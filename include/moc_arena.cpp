/****************************************************************************
** Arena meta object code from reading C++ file 'arena.h'
**
** Created: Mon Apr 8 21:06:32 2002
**      by: The Qt MOC ($Id: qt/src/moc/moc.y   2.2.4   edited 2001-01-04 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#if !defined(Q_MOC_OUTPUT_REVISION)
#define Q_MOC_OUTPUT_REVISION 9
#elif Q_MOC_OUTPUT_REVISION != 9
#error "Moc format conflict - please regenerate all moc files"
#endif

#include "arena.h"
#include <qmetaobject.h>
#include <qapplication.h>



const char *Arena::className() const
{
    return "Arena";
}

QMetaObject *Arena::metaObj = 0;

void Arena::initMetaObject()
{
    if ( metaObj )
	return;
    if ( qstrcmp(QWidget::className(), "QWidget") != 0 )
	badSuperclassWarning("Arena","QWidget");
    (void) staticMetaObject();
}

#ifndef QT_NO_TRANSLATION

QString Arena::tr(const char* s)
{
    return qApp->translate( "Arena", s, 0 );
}

QString Arena::tr(const char* s, const char * c)
{
    return qApp->translate( "Arena", s, c );
}

#endif // QT_NO_TRANSLATION

QMetaObject* Arena::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    (void) QWidget::staticMetaObject();
#ifndef QT_NO_PROPERTIES
#endif // QT_NO_PROPERTIES
    QMetaData::Access *slot_tbl_access = 0;
    metaObj = QMetaObject::new_metaobject(
	"Arena", "QWidget",
	0, 0,
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
