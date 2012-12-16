[Yggdrasil](http://stevenkaras.github.com/yggdrasil)
===========
A project I know there stands,
Yggdrasil is its name.


Introduction
============
Yggdrasil is a foundation library to ease development of cross platform applications written in C++.

The goal of this project is to provide platform agnostic syntax for applications to build upon. The scope is strictly defined to only include code that requires specific platform implementations.


Services Provided
=================

  * *Logging macros* - platform independent logging sinks that can be directed to wherever you need (a full logging library is out of the scope of this project)
  * *Threading* - platform independent threads, locks, and more!


Future Goals
============

  * *Windows support* - currently, none of our services support Windows
  * *Android support* - currently, our services do not support Android
  * *iOS/MacOS support* - currently, our services do not support Apple
  * *File Access* - platform agnostic helpers for user storage, application storage and more


Building
========
Until I can set aside the time to explore some decent options for the build system, you'll need to maintain your own build scripts. I know this is a pain.