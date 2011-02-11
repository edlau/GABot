/// -= C++ =-
///
/// read and write team xml files

#ifndef TEAMDATA_H
#define TEAMDATA_H

// include files for QT
#include <qstring.h>
#include <qfile.h>
#include <qxml.h>
#include <qtextstream.h>

// other predirectives
#include "team.h"
#include "teamparser.h"

/// Read and Write team xml files
class TeamData{

   public:
      /// read team data from xml file
      Team* readTeamData(QString filename);
      /// write team data into xml file
      bool writeTeamData(QString filename, Team*);

};

#endif
