STOCKBOT
analyzing current sp500 stocks by implementing a modified benjamin-graham's algorithm. 

General Arhictecture 
the project consists of three parts:
 - python scrapper - a multhi-threaded python scrapper.
 - sql database - sql database to store the stock data.
 - c++ engine - a c++ engine to anazlyze the stocks.

Description 
- The python scrapper download all the sp500 stock symbols. for each one of the stocks the scrapper download stock data : p/e, current-     ratio, etc.
- The python scrapper save all the data to an sql database file.
- The c++ engine reads the database, calculate every stock by benjamin graham parameters and gives indicator to every stock from 0-7.
- The c++ engine will display the 10 best stocks to buy at this moment, according to benjamin graham algorithm. 

C++ Gui

![GitHub Logo](/images/gui.png)

Requiered Liabries:

Python:
    - requests
    - re
    - BeautifulSoup 
    - ast
    - sqlite3 

c++:
   - c++ 11 and above.
   - sqlite3.h
   - curses.h
   
Installation
OS X & Linux & Windows: there is 3 ways to install the project:
  
  - building the whole project from scratch.
     from the home directory type : "python build_project.py". the script will start the scrapping, move the older database to                  database/backup folder, create new database, run the c++ engine on the database and display the results.
  
   - running only the python scrapper.
     from the directory python_scrapper type : "python main.py". the scrapper will build the stocks database and save it at database            folder. the name of the database will be "mydatabase.db". if the database is already there, delete it manually before running the          script.
   
   - running only the c++ engine.
     from the directory src type : "make". to run the project type: "./stockbot"
     please note that you must proivde a databse. the starter repository already includes a database.
 
 
npm install my-crazy-module --save
Windows:

edit autoexec.bat
Usage example
A few motivating and useful examples of how your product can be used. Spice this up with code blocks and potentially more screenshots.

For more examples and usage, please refer to the Wiki.

Development setup
Describe how to install all development dependencies and how to run an automated test-suite of some kind. Potentially do this for multiple platforms.

make install
npm test
Release History
0.2.1
CHANGE: Update docs (module code remains unchanged)
0.2.0
CHANGE: Remove setDefaultXYZ()
ADD: Add init()
0.1.1
FIX: Crash when calling baz() (Thanks @GenerousContributorName!)
0.1.0
The first proper release
CHANGE: Rename foo() to bar()
0.0.1
Work in progress
Meta
Your Name – @YourTwitter – YourEmail@example.com

Distributed under the XYZ license. See LICENSE for more information.

https://github.com/yourname/github-link

Contributing
Fork it (https://github.com/yourname/yourproject/fork)
Create your feature branch (git checkout -b feature/fooBar)
Commit your changes (git commit -am 'Add some fooBar')
Push to the branch (git push origin feature/fooBar)
Create a new Pull Request
