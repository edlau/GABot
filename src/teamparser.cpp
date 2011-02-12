/********************************************************************
 * -= C++ =-
 *
 * read team data from xml files
 ********************************************************************/

//predirectives
#include <qstring.h>
#include <string>

#include "teamparser.h"
#include "thing.h"
#include "team.h"

//constructor
TeamParser::TeamParser():QXmlDefaultHandler(){
   team=0;
   botcount=0;
   rulecount=0;
   bot = 0;
}

//start document
bool TeamParser::startDocument()
{
   return true;
}

//this function execute whenver the parser sees a start tag of xml
bool TeamParser::startElement(const QString& namespaceURI, const QString& localName,
			const QString& qName, const QXmlAttributes& attributes){

   // check tags and build the Team 
   if (qName == "team"){
      if (attributes.length() > 0){
         team = new Team;
	 
         for (int i = 0; i < attributes.length();i++){
            if (attributes.qName(i) == "name"){
               team->name(attributes.value(i));
	    }else if(attributes.qName(i) == "wins"){
               team->wins((attributes.value(i)).toUInt());
	    }else if(attributes.qName(i) == "losses"){
               team->losses((attributes.value(i)).toUInt());
	    }else if(attributes.qName(i) == "ties"){
               team->ties((attributes.value(i)).toUInt());
            }else if(attributes.qName(i) == "generations"){
               team->generations((attributes.value(i)).toUInt());
	    }else{
               debug("error in team tag");
	       return (false);  //error in team tag
	    }//end if
	 }//end for
      }else{
         debug("error in team tag, missing all attributes");
	 return(false);  //error in team tag, missing all attributes
      }//end if
   }else if(qName == "bot"){
      
      if (attributes.length() > 0){
         //allocate memory for the local bot
         bot = new Bot(team);
	 
         for (int i = 0; i < attributes.length(); i++){
            if(attributes.qName(i) == "mass"){
               bot->mass((attributes.value(i)).toUInt());
	    }else if(attributes.qName(i) == "goals"){
               bot->goals((attributes.value(i)).toInt());
	    }else if(attributes.qName(i) == "interceptions"){
               bot->interceptions( (attributes.value(i)).toUInt());
	    }else{
               debug("error in bot tag");
	       return (false);  //error in bot tag
	    }
	 }
      }else{
         debug("error in bot tag, missing all attributes");
	 return(false);  //error in bot tag, missing all attributes
      }//end if
      
   }else if(qName == "gaRule"){
      rulecount = 0;
   }else if(qName == "rule"){

      //allocate memory for the rule
      rule = new GARule;
      
      if (attributes.length() > 0){
         for (int i = 0; i < attributes.length(); i++){
            if(attributes.qName(i) == "teamBall"){
               rule->teamBall( (attributes.value(i)).toInt());
	    }else if(attributes.qName(i) == "myBall"){
               if (attributes.value(i) == "T"){
                  rule->myBall(true);
	       }else{
                  rule->myBall(false);
	       }
	       
	    }else if(attributes.qName(i) == "fire"){
               if (attributes.value(i) == "T"){
                  rule->fire(true);
	       }else{
                  rule->fire(false);
	       }

	    }else if(attributes.qName(i) == "move"){
               if(attributes.value(i) == "T"){
                  rule->move(true);
	       }else{
                  rule->move(false);
	       }

	    }else if(attributes.qName(i) == "turn"){
	       if (attributes.value(i) == "left") {
	          rule->turn(Left);
	       } else if (attributes.value(i) == "right") {
	          rule->turn(Right);
	       } else {
	          rule->turn(None);
	       }
	       
	    }else{
               debug("error in rule tag");
	       return(false); //error in rule tag
	    }//end if
	 }
      }else{
         debug("error in rule tag, missing all attributes");
         return(false);
      }//end if
      
   }else if(qName == "sensors"){
      
      //allocate memory for the sens array
      sens = new Thing[8];
      
      if (attributes.length() > 0){
         for (int i = 0; i < attributes.length(); i++){
            Thing t; unsigned int index;

            if (attributes.value(i) == "mybot") t = MyBot;
            else if (attributes.value(i) == "otherbot") t = OtherBot;
            else if (attributes.value(i) == "net") t = Net;
            else if (attributes.value(i) == "ball") t = TheBall;
            else if (attributes.value(i) == "wall") t = Wall;
            else t = Nothing;

            if (attributes.qName(i) == "s0") index = 0;
            else if (attributes.qName(i) == "s1") index = 1;
            else if (attributes.qName(i) == "s2") index = 2;
            else if (attributes.qName(i) == "s3") index = 3;
            else if (attributes.qName(i) == "s4") index = 4;
            else if (attributes.qName(i) == "s5") index = 5;
            else if (attributes.qName(i) == "s6") index = 6;
            else if (attributes.qName(i) == "s7") index = 7;
            else { debug("error in sensor tag"); return false; }

            sens[index] = t;
	 }//end for

      }else{
         debug("error in sensor tag, missing all attributes");
	 return (false);
      }
      //attach straight to the rule
      rule->sensors(sens);

   }//end if

   return true;
}//end startElement

//function execute whenever the parser sees a end xml tag
bool TeamParser::endElement(const QString&, const QString& qName, const QString&){
   if (qName == "bot"){
      botcount++;
      team->insertBot(bot);  // attach this bot to the team
      
   }else if (qName == "rule"){
      //attach this rule to bot
      bot->insertRule(rule);
      rulecount++;
      
   }
   return true;
}//end endElement

//return the team just loaded
Team* TeamParser::teamData(){
   return(team);
}

//end file

