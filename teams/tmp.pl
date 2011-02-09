#!/usr/bin/perl

while(<STDIN>) {
   s/myBall="F"/myBall="T"/g if rand > 0.5;
   s/myBall="0"//g;
   print $_;
}
