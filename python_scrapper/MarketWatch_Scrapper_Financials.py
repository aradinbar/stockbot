import requests
import re
from bs4 import BeautifulSoup
import array as arr
import xlwt 
from xlwt import Workbook 
import ast
from operator import eq, add, sub
import sqlite3 

class MarketWatch_Scrapper_Financials:

    def __init__(self,stock_name):
        #Private methods and members
        self.__soup = self.__get_html_financial_data(stock_name)
        #Public methods and members
        self.stock_name = stock_name
        self.total_revenue = self.get_total_revenue(self.__soup)
        self.cost_of_revenue = self.get_cost_of_revenue(self.__soup)
        self.reasearch_and_development = self.get_reasearch_and_development(self.__soup)
        self.selling_general_admin = self.get_selling_general_admin(self.__soup)
        self.other_operating_expenses = self.get_other_operating_expenses(self.__soup)
        self.other_unusual_expenses = self.get_other_unusual_expenses(self.__soup)
        self.operation_profit = self.get_operation_profit(self.__soup)
        self.eps_growth = self.get_eps_growth(self.__soup)

    def __get_html_financial_data(self,stock_name):
        URL = 'https://www.marketwatch.com/investing/stock/'+stock_name+'/financials'
        page = requests.get(URL)
        soup = BeautifulSoup(page.content, 'html.parser')
        return soup

    def generic_get_value(self,soup,str_val,str_class,num):
        results = soup.findAll(str_val,{"class":str_class})[num]
        count = 0
        for row in results.findAll("td"):
            if (count >=6):
                a= str(row).split(':')[1]
                b = a.split('}')[0]
                if (b.find('null') != -1): 
                    b = b.replace("null", "0")
                res = ast.literal_eval(b) 
            count = count + 1
        return res    
      
    def get_total_revenue(self,soup):
        return self.generic_get_value(soup,"table","crDataTable",0)
        
    def get_cost_of_revenue(self,soup):
        return self.generic_get_value(soup,"tr","mainRow",0)
        
    def get_reasearch_and_development(self,soup):
        return self.generic_get_value(soup,"tr","rowLevel-2",2)
    
    def get_selling_general_admin(self,soup):
        return self.generic_get_value(soup,"tr","rowLevel-2",3) 
    
    def get_other_operating_expenses(self,soup):
        return self.generic_get_value(soup,"tr","mainRow",2)
    
    def get_other_unusual_expenses(self,soup):
        return self.generic_get_value(soup,"tr","mainRow",3)
    
    def get_operation_profit(self,soup):
        return self.generic_get_value(soup,"tr","mainRow",4)

    def get_eps_growth(self,soup):
        return self.generic_get_value(soup,"tr","childRow hidden",10)