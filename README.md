# Flight-Strip-Manager-cpp
Flight Strip Manager for online ATC controllers built with Qt and C++


## Introduction

Since VATSIM's new technology called AFV went into service, complaints about the unstable voice server connection emerged in mainlan China.
If the client informs "lost connection with voice server", users have to completely reconnect to VATSIM so as to get themselves back onto to channel.
Consequently, the controller will lose all the changes made to the tag.
Especially for the controller in charge of clearance delivery, the queue may be disrupted since the marks on scratch pad disapper.
So this program was developed mainly to aid DELs, GNDs, TWRs to better manage the sequence of each stage on the ground.


## Features

1. Filtered key entries: only legal characters in a callsign can be typed into the box.
2. Drag & Drop supported: Drag on "strip" from on3e list to another and drop.
3. Auto-calculated sequence: Hover your mouse on a strip an the sequence of that flight will pop up.
4. Distinguished color: Double click a strip in the list, its turn green (cleared), double click again, back to normal (standby).
    Note that in departure list, the second double click will delete the strip, meaning that the flight has departed.
5. Window opacity and Stay-on-Top: These two functions enable users to monitor ES and this application at the same time.
6. Convenient key shortcuts: Improves efficiency via a set of key shortcuts each matching a major funcion.
7. Statistics: Record every flight that has been added into list and those already departed.


## Download and installation

Directly download the FSM.exe and it should work. Otherwise download the whole dist folder then execute FSM.exe inside.
No need of installations, just double-click it.


## Other information

The author of this software is a member of VATSIM VATPRC division with an S2 rating. If there's any suggestions to imporve the software please advise.
This is the first project after I learn the basics of C++, and I don't major in computer science or software engineering, so my code may looks fussy.
Beside this project there is an obsolete version built with PyQt5 on [https://github.com/KingfuChan/Flight-Strip-Manager](https://github.com/KingfuChan/Flight-Strip-Manager). That version will no longer be developed since PyQt is actually quite cumbersome. 
The icon of the application was downloaded from the open-source icon database [iconfont](https://www.iconfont.cn/).