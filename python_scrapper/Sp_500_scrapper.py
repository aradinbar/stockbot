# https://www.slickcharts.com/sp500 build sp500 scrapper from this site
import requests
from bs4 import BeautifulSoup

class Sp_500_scrapper:
        
    def __init__(self):
        #Private methods and members
        self.__soup = self.__get_html_sp500_data()
        #Public methods and members
        self.sp500_list = self.__fill_sp500_dict(self.__soup)
        
            
    def __fill_sp500_dict(self,soup):

    	sp500_list = []
    	count = 1
        results = soup.findAll("table",{"class":"table table-hover table-borderless table-sm"})
        for row in results:
        	for td in row.findAll("td"):
        		for a in td.findAll("a"):
        			if (count % 2 == 0):
        				sp500_list.append(a.contents[0])
        			count = count + 1

        return sp500_list

    def __get_html_sp500_data(self):
        URL = 'https://www.slickcharts.com/sp500'
        page = requests.get(URL)
        soup = BeautifulSoup(page.content, 'html.parser')
        return soup