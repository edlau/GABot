/// -= C++ =-
///
/// Read team data from XML file

#ifndef TEAMPARSER_H
#define TEAMPARSER_H

// include files for QT
#include <qxml.h>

// other predirectives
#include <string>
#include "team.h"
#include "bot.h"
#include "garule.h"
#include "thing.h"

// Class prototypes
class QString;

/// Main class for parsing team XML data files, 
/// Derived from QXmlDefaultHandler from QT Library
class TeamParser : public QXmlDefaultHandler
{
   public:
      /// Constructor
      TeamParser();
      /// Member function for the start of document
      bool startDocument();
      /// Member function for the start of a XML element (tag)
      bool startElement(const QString&, const QString&, const QString&,
		        const QXmlAttributes& );
      /// Member function for the end of a XML element (tag)
      bool endElement(const QString&, const QString&, const QString&);
      /// Member function for return the parsed data
      Team* teamData();

   private:
      /// Pointer to the team data
      Team* team;
      /// Pointer to the bot data
      Bot* bot;
      /// Pointer to the rule data
      GARule* rule;
      /// Poniter to the sensor array
      Thing* sens;
      /// Internal counter for bots
      int botcount;
      /// Internal counter for rules
      int rulecount;

};

#endif
