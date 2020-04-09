STOCKBOT
analyzing current sp500 stocks by implementing a modified benjamin-graham's algorithm. 

General Arhictecture 
the project consists of three parts:
  1.python scrapper - a multhi-threaded python scrapper.
  2.sql database - sql database to store the stock data.
  3.c++ engine - a c++ engine to anazlyze the stocks.

Description 
- The python scrapper download all the sp500 stock symbols. for each one of the stocks the scrapper download stock data : p/e, current-     ratio, etc.
- The python scrapper save all the data to an sql database file.
- The c++ engine reads the database, calculate every stock by benjamin graham parameters and gives indicator to every stock from 0-7.
- The c++ engine will display the 10 best stocks to buy at this moment, according to benjamin graham algorithm. 






Installation
OS X & Linux & Windows:

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
