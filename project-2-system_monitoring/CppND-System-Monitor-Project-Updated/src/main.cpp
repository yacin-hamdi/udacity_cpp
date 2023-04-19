#include "ncurses_display.h"
#include "system.h"

#include"linux_parser.h"
#include"process.h"
#include<iostream>
#include<string>

int main() {
  System system;
  NCursesDisplay::Display(system, 10);
  // System system;


  // std::vector<Process>process = system.Processes();
  // for(auto i:process){
  //   std::cout << i.Ram() << " ";
  // }

  return 0;
}