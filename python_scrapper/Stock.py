import requests
import re
from bs4 import BeautifulSoup
import array as arr
import xlwt 
from xlwt import Workbook 
import ast
from operator import eq, add, sub
import sqlite3 
from MarketWatch_Scrapper_Financials import MarketWatch_Scrapper_Financials
from MarketWatch_Scrapper_Profile import MarketWatch_Scrapper_Profile

class Stock(MarketWatch_Scrapper_Financials,MarketWatch_Scrapper_Profile):

    def __init__(self, stock_name):
        MarketWatch_Scrapper_Financials.__init__(self, stock_name)
        MarketWatch_Scrapper_Profile.__init__(self, stock_name)
        
        self.others = self.get_others()
        self.gross_profit = self.get_gross_profit()
        self.operation_expenses = self.get_operation_expenses()  
        self.graham_multiplier = self.get_graham_multiplier()

        build_sql_db(self)
    
    def get_gross_profit(self):
       lst1 = []
       for x in range(5):
            num1 = self.total_revenue[x] - self.cost_of_revenue[x] 
            lst1.append(num1)
       return lst1
       
    def get_operation_expenses(self):
       lst1 = []
       for x in range(5):
            num1 = self.selling_general_admin[x] + self.reasearch_and_development[x] + self.others[x] 
            lst1.append(num1)
       return lst1

    def get_others(self):
       lst1 = []
       for x in range(5):
            num1 = self.other_operating_expenses[x] + self.other_unusual_expenses[x] 
            lst1.append(num1)
       return lst1
       
    def get_graham_multiplier(self):
       return (self.p_e) * (self.price_to_book_ratio)





   
def build_excel_shit(Stock1):
  
    #Workbook is created 
    wb = Workbook() 
      
    # add new colour to palette and set RGB colour value
    xlwt.add_palette_colour("custom_colour", 0x21)
    wb.set_colour_RGB(0x21,1, 183, 2)
    # now you can use the colour in styles
    sheet1 = wb.add_sheet('Sheet 1')
    style = xlwt.easyxf('pattern: pattern solid, fore_colour custom_colour')    
    
    sheet1.write(1, 0, 'Sales') 
    sheet1.write(2, 0, 'Current Ratio') 
    sheet1.write(3, 0, 'P/E') 
    sheet1.write(4, 0, 'Graham Multiplier ') 
    sheet1.write(5, 0, 'Eps Growth')
    sheet1.write(7, 0, 'ROE')
    sheet1.write(8, 0, 'ROI')
    

    
    if ( Stock1.total_revenue[4]  > 350000000 ) :
        sheet1.write(1 ,1, Stock1.total_revenue[4],style)
    else :
        sheet1.write(1, 1, Stock1.total_revenue[4])
    
    if ( Stock1.current_ratio ) > 2 :
        sheet1.write(2, 1, Stock1.current_ratio,style)
    else :
        sheet1.write(2, 1, Stock1.current_ratio) 
    
    if ( Stock1.p_e ) > 5  and ( Stock1.p_e ) < 15:
        sheet1.write(3, 1, Stock1.p_e,style)
    else :
        sheet1.write(3, 1, Stock1.p_e)     
      
    if ( Stock1.graham_multiplier ) < 22 :
        sheet1.write(4, 1, Stock1.graham_multiplier,style)
    else :
        sheet1.write(4, 1, Stock1.graham_multiplier)  
        
    if ( Stock1.eps_growth[4] ) > 0.3 :
        sheet1.write(5, 1, Stock1.eps_growth[4],style)
    else :
        sheet1.write(5, 1, Stock1.eps_growth[4]) 
        
    if ( Stock1.return_on_equity ) > 15 :
        sheet1.write(7, 1, Stock1.return_on_equity,style)
    else :
        sheet1.write(7, 1, Stock1.return_on_equity) 

    if ( Stock1.return_on_invested_capital ) > 15 :
        sheet1.write(8, 1, Stock1.return_on_invested_capital,style)
    else :
        sheet1.write(8, 1, Stock1.return_on_invested_capital) 

    wb.save('xlwt example.xls') 


def build_sql_db(Stock1):
  
    # creates a database in RAM 
    con = sqlite3.connect('../database/mydatabase.db') 
    cur = con.cursor() 
    cur.execute("create table if not exists stock (stock_number, name, total_revenue, current_ratio, p_e, graham_multiplier, eps_growth, return_on_equity, return_on_invested_capital   )") 
    
    cur.execute("SELECT COUNT(*) FROM stock");
    count = cur.fetchall() 
    # This is the q-mark style: 
    cur.execute("insert into stock values (?, ?, ?, ?, ? , ? , ? , ? , ?)", (count[0][0]+1, Stock1.stock_name, Stock1.total_revenue[4],Stock1.current_ratio, Stock1.p_e, Stock1.graham_multiplier,Stock1.eps_growth[4],Stock1.return_on_equity,Stock1.return_on_invested_capital ))      
    cur.execute("select * from stock") 
    
    # Fetches all entries from table 
    for row in cur:
        print(row)

    con.commit() 
    con.close() 