import requests
import re
from bs4 import BeautifulSoup
import array as arr
import xlwt 
from xlwt import Workbook 
import ast
from operator import eq, add, sub
import sqlite3 
from threading import Thread
from multiprocessing import Process
import os
import time
from MarketWatch_Scrapper_Financials import MarketWatch_Scrapper_Financials
from MarketWatch_Scrapper_Profile import MarketWatch_Scrapper_Profile
from Stock import Stock
from Sp_500_scrapper import Sp_500_scrapper



    

def main():


    temp = Sp_500_scrapper()
    print(temp.sp500_list)
    i = 1
    for temp_stock in temp.sp500_list:
        try:
            print(temp_stock)       
            Thread(target=Stock(temp_stock))
            time.sleep(0.2)
            if (i % 5 == 0):
                time.sleep(10)
            i = i + 1
        except:
            pass

    print('Done building sp500 db')

if __name__== "__main__":
    main()