  [create an anchor](###STOCKBOT)STOCKBOT

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
 

