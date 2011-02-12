/********************************************************************
 * -= C++ =-
 *
 * read and write team data to xml file
 ********************************************************************/

#include "teamdata.h"

//read data from xml file
Team* TeamData::readTeamData(QString filename){

   QFile xmlFile(filename);
   QXmlInputSource source(xmlFile);
   QXmlSimpleReader reader;
   TeamParser *handler = new TeamParser();
   reader.setContentHandler(handler);
   reader.parse(source);

   return(handler->teamData());
}

//write team data to file
bool TeamData::writeTeamData(QString filename, Team* team){

   // check if team success
   if (!team){
      return false;
   }
   
   //open the text file, if already exists overwrite
   QFile xmlFile(filename);
   if (xmlFile.open(IO_WriteOnly)){ //file opened as overwrite
      QTextStream ts(&xmlFile);
      QString str;

      //write team tag
      ts << "<team ";
      ts << "name=\"" << team->name() << "\" ";
      ts << "wins=\"" << QString::number(team->wins()) << "\" ";
      ts << "losses=\"" << QString::number(team->losses()) << "\" ";
      ts << "generations=\"" << QString::number(team->generations()) << "\" ";
      ts << "ties=\"" << QString::number(team->ties()) << "\">\n";
      
      //write bot tag
      Bot *b;
      for (unsigned int i = 0; i < team->size(); i++){
         b = team->bot(i); //get bot in sequence
	 ts << "<bot ";
	 ts << "mass=\"" << QString::number(b->mass()) << "\" ";
         ts << "goals=\"" << QString::number(b->goals()) << "\" ";
	 ts << "interceptions=\"" << QString::number(b->interceptions()) << "\">\n";
	 ts << "<gaRule>\n";

	 //write rule tag
	 GARule *r;
	 for (unsigned int j = 0; j < b->ruleSetSize(); j++){
            r = b->rule(j);
	    ts << "<rule ";
	    ts << "teamBall=\"" << QString::number(r->teamBall()) << "\" ";
	    ts << "myBall=\""; (r->myBall()) ? ts << "T" : ts << "F"; ts << "\" ";
	    ts << "fire=\""; (r->fire()) ? ts << "T" : ts << "F";
	    ts << "\" ";
	    ts << "move=\""; (r->move()) ? ts << "T" : ts << "F";
	    ts << "\" ";
	    ts << "turn=\""; (r->turn() == Left) ? ts << "left" :
	                     (r->turn() == Right) ? ts << "right" : ts << "none";
	    ts << "\">\n";
	    
	    //write sensors tag
	    Thing* sen = r->sensors();
	    ts << "<sensors "; 
	    for (unsigned int k = 0; k < 8; k++){
	       QString t;
	       switch(sen[k]) {
	          case Nothing:  t = "nothing"; break;
	          case MyBot:    t = "mybot"; break;
	          case OtherBot: t = "otherbot"; break;
	          case TheBall:  t = "ball"; break;
	          case Wall:     t = "wall"; break;
	          case Net:      t = "net"; break;
	       }//end switch
	       
	       //put the appropriate end tag
               ts << "s" << QString::number(k) << "=\"" << t;
	       if (k < 7){
                  ts << "\" ";
	       }else{
                  ts << "\"/>\n";
	       }//end if
	       
	    }//end putting sensor tag
	    ts << "</rule>\n";
	 }//end for
	 
	 ts << "</gaRule>\n";
	 ts << "</bot>\n";
      }//end for

      ts << "</team>\n"; 
      
      xmlFile.close(); //close file
   }//end if
   return(true);
   
}//end writeTeamData

