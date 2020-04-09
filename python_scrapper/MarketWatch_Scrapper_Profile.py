import requests
import re
from bs4 import BeautifulSoup
import array as arr
import xlwt 
from xlwt import Workbook 
import ast
from operator import eq, add, sub
import sqlite3 


class MarketWatch_Scrapper_Profile:

    def __init__(self,stock_name):
        #Private methods and members
        self.__profile_dict = {'P/E Current': 0, 'Price to Sales Ratio': 0, 'Price to Book Ratio': 0,'Return on Assets' :0
        ,'Return on Equity' :0,'Return on Invested Capital' :0 , 'Current Ratio' : 0 , 'Net Margin' : 0, "Pretax Margin" : 0}
        self.__soup = self.__get_html_profile_data(stock_name)
        self.__fill_profile_dict(self.__soup)
        #Public methods and members
        self.p_e = self.get_p_e(self.__soup)
        self.price_to_sale_ratio = self.get_price_to_sale_ratio(self.__soup)
        self.price_to_book_ratio = self.get_price_to_book_ratio(self.__soup)
        self.return_on_assets = self.get_return_on_assets(self.__soup) 
        self.return_on_equity = self.get_return_on_equity(self.__soup)
        self.return_on_invested_capital = self.get_return_on_invested_capital(self.__soup)         
        self.current_ratio =  self.get_current_ratio(self.__soup)
        self.net_margin = self.get_net_margin(self.__soup)         
        self.pretax_margin =  self.get_pretax_margin(self.__soup)



    def __get_html_profile_data(self,stock_name):
        URL = 'https://www.marketwatch.com/investing/stock/'+stock_name+'/profile'
        page = requests.get(URL)
        soup = BeautifulSoup(page.content, 'html.parser')
        return soup
    
            
    def __fill_profile_dict(self,soup):
        results = soup.findAll("p",{"class":"column"})
        for row in results:
            if not row.contents :
                possible_key = 'NULL'
            else:
                possible_key = row.contents[0]
            if (possible_key in self.__profile_dict) :
                value = row.find_next("p")
                self.__profile_dict[possible_key] = float(value.contents[0])
                print(value.contents[0])
        return 1

    def get_p_e(self,soup):
        return self.__profile_dict['P/E Current']

    def get_price_to_sale_ratio(self,soup):
        return self.__profile_dict['Price to Sales Ratio']       
 
    def get_price_to_book_ratio(self,soup):
        return self.__profile_dict['Price to Book Ratio']  

    def get_current_ratio(self,soup):
        return self.__profile_dict['Current Ratio']  

    def get_return_on_assets(self,soup):
        return self.__profile_dict['Return on Assets']  

    def get_return_on_equity(self,soup):
        return self.__profile_dict['Return on Equity']  

    def get_return_on_invested_capital(self,soup):
        return self.__profile_dict['Return on Invested Capital']         

    def get_net_margin(self,soup):
        return self.__profile_dict['Net Margin']  

    def get_pretax_margin(self,soup):
        return self.__profile_dict['Pretax Margin']