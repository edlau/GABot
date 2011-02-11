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

Naming Conventions
------------------

All filenames are lowercase, regardless of their contents. The directives at
the start of each header file check for and define the name of the file, in
uppercase, with the period replaced by an underscore.

Classes have their first letter capitalized, and if there are multiple words
in their name, then they are concatenated (without a separator), and the
first letter of each word is capitalized.

Variables in classes are named in the same way as classes.

Methods have their first letter in lowercase, but if they are made of
multiple words, then the first letter of each successive word is
capitalized. The words are also concatenated without a separator. Methods
that read or alter a particular variable will generally have the same name
as the variable, but the first letter will be in lowercase instead of
capitalized. Overloading should be used to avoid using
getVariable/setVariable pairs of methods.

Makefile
--------

```sh
tmake gabot.pro > Makefile
```

Qt Linking
----------

If you experience linker errors when linking to qt, and you
compiled qt with thread support (or can't remember if you did),
you may have to create a symbolic link from `libqt-mt.so` to `libqt.so`.

```sh
ln -s $QTDIR/lib/libqt-mt.so $QTDIR/lib/libqt.so
```

```sh
ldconfig
```

GARule
------
[See this file](https://github.com/edlau/GABot/blob/master/README.GARule)