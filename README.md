GABot a.k.a. Generic Algorithm Bot
==================================

GABot was originally a school project from 2002 by Edmond Lau, Chris 
Odorjan and Richard Voino.  The goal was to create a game playing prototype 
based on Genetic Algorithms for our Artificial Intelligence class at 
Wilfrid Laurier University.

Since the completion of the school project, the gang had many discussions
(over beer and wine) on how to revive the project, enhance the code and 
publish the project somewhere on SourceForge.  But after 8 years and much
alcohol consumed, we have decided to push the original code.  Hopefully,
someone out there will find this code useful.

Disclaimer
----------

If you find any comment funny, drop us a line!  If you find anything
offensive, probably because we spent so much time working on this at night.

Code Base
---------

The code is **based on C/C++ and older Qt (probably 2.x or 3.x**, whichever one
from 2002).

Qt Linking
----------

If you experience linker errors when linking to qt, and you
compiled qt with thread support (or can't remember if you did),
you may have to create a symbolic link from `libqt-mt.so` to `libqt.so`.

ex: 
	ln -s $QTDIR/lib/libqt-mt.so $QTDIR/lib/libqt.so
	ldconfig