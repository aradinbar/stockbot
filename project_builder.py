import os
import shutil
from os import path
from datetime import datetime
import time

def main():

    if path.exists("database/mydatabase.db"):

        src = path.realpath("database/mydatabase.db")
        now = datetime.now()
        current_date = now.strftime("%d-%m-%Y:%H:%M:%S")
        new_file_name = str(current_date)+".db"
        print(new_file_name)
        new_file_path = "database/db_backups/"+new_file_name
        os.rename("database/mydatabase.db", new_file_path) 

    os.chdir('python_scrapper')
    os.system('python main.py')
    time.sleep(0.1)
    
    print("starting with stockbot")
    
    os.chdir('../src')
    os.system('make')
    time.sleep(0.1)
    os.system('./stockbot')

	

if __name__ == "__main__":
    main()