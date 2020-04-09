#include <curses.h>
#include <chrono>
#include <string>
#include <thread>
#include <vector>
#include "ncruses_display.h"


using std::string;
using std::to_string;
using namespace ncruses_display; 
using namespace std;



void ncruses_display::DisplayStocks(std::vector<stock> stocks,
                                      WINDOW* window, int n) {
  int row{0};
  int const name_column{2};
  int const current_ratio_column{9};
  int const p_e_column{23};
  int const graham_multiplier_column{36};
  int const return_on_equity_column{55};
  int const return_on_invested_capital_column{76};
  int const benjamin_graham_result_column{107};
  wattron(window, COLOR_PAIR(2));
  mvwprintw(window, ++row, name_column, "name");
  mvwprintw(window, row, current_ratio_column, "current_ratio");
  mvwprintw(window, row, p_e_column, "p/e");
  mvwprintw(window, row, graham_multiplier_column, "graham_multiplier");
  mvwprintw(window, row, return_on_equity_column, "return_on_equity");
  mvwprintw(window, row, return_on_invested_capital_column, "return_on_invested_capital");
  mvwprintw(window, row, benjamin_graham_result_column, "benjamin_graham_result");

  wattroff(window, COLOR_PAIR(2));
  for (int i = 0; i < n; ++i) {
    
    mvwprintw(window, ++row, name_column, (stocks[i].get_name()).c_str());
    mvwprintw(window, row, (current_ratio_column), to_string(stocks[i].get_current_ratio()).c_str());
    mvwprintw(window, row, (p_e_column), to_string(stocks[i].get_p_e()).c_str());
    mvwprintw(window, row, (graham_multiplier_column), to_string(stocks[i].get_graham_multiplier()).c_str());
    mvwprintw(window, row, (return_on_equity_column), to_string(stocks[i].get_return_on_equity()).c_str());
    mvwprintw(window, row, (return_on_invested_capital_column), to_string(stocks[i].get_return_on_invested_capital()).c_str());
    mvwprintw(window, row, (benjamin_graham_result_column), to_string(stocks[i].get_benjamin_graham_result()).c_str());
  }


}

void ncruses_display::Display(my_system & system, int n) {
  initscr();      // start ncurses
  noecho();       // do not print input values
  cbreak();       // terminate ncurses on ctrl + c
  start_color();  // enable color

  int x_max{getmaxx(stdscr)};

  WINDOW* process_window = newwin(3 + n, x_max + 200, 1, 0);

  while (1) {
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    box(process_window, 0, 0);
    vector<stock> temp_vector = system.get_vector_of_stocks();
    DisplayStocks(temp_vector, process_window, n);
    wrefresh(process_window);
    refresh();
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  endwin();
}