# Flight-Strip-Manager-cpp
Flight Strip Manager for online ATC controllers built with Qt and C++


## Introduction

Since VATSIM's new technology called AFV went into service, complaints about the unstable voice server connection emerged in mainlan China.
If the client informs "lost connection with voice server", users have to completely reconnect to VATSIM so as to get themselves back onto to channel. Consequently, the controller will lose all the changes made to the tag. Especially for the controller in charge of clearance delivery, the queue may be disrupted since the marks on scratch pad disapper. So this program was developed mainly to aid DELs, GNDs, TWRs to better manage the sequence of each stage on the ground.


## Features

1. Filtered key entries: only legal characters in a callsign can be typed into the box.
2. Drag & Drop supported: Drag a strip from one list to another and drop.
    Note: Don't drag & drop among different program instances, which may have some bugs.
3. Auto-calculated sequence: Hover your mouse on a strip or right click the strip, to check the current sequence for the flight.
4. Distinguished color: Double click a strip in the list, its turn green (cleared), double click again, back to normal (standby).
    Note that in departure list, the second double click will delete the strip, meaning that the flight has departed.
5. Timer: Help control the seperation between flights. Detailed functions:
    + Left click: start/stop timer.
    + Right click: cycle preset time. Preset time (seconds): 30, 60, 120, 180
    + Scroll: precise control. Add or minus 1 second per scroll.
    + Beeping alerts on time-out.
    + Two different time format: sss or m:ss. Changable through menu bar.
6. Window opacity and Stay-on-Top: Enable users to monitor ES and this application at the same time.
7. Convenient key shortcuts: Improves efficiency via a set of key shortcuts each matching a major funcion.
8. Statistics: Record every flight that has been added into list and those already departed.


## Download and installation

Directly download the FSM.exe and it should work. Otherwise download the whole dist folder then execute FSM.exe inside.
No need to install, just double-click and run it.


## Credits

+ Inspired by a member of VATPRC controllers. Howevery I forgot his name :(
+ Application doesn't require any Internet connection and will not change any files in your computer.
+ The author of this software is a member of VATSIM VATPRC division with an S2 rating. If there's any suggestions to imporve the software please advise.
+ This is the first project after I learn the basics of C++, and I don't major in computer science or software engineering, so my code may looks fussy.
+ In addition to this project, there is an obsolete version built with PyQt5 on [https://github.com/KingfuChan/Flight-Strip-Manager](https://github.com/KingfuChan/Flight-Strip-Manager). That version will no longer be developed since PyQt is actually quite cumbersome. 
+ The icon of the application was downloaded from the open-source icon database [iconfont](https://www.iconfont.cn/).