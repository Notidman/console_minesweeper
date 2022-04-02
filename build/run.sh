#!/bin/bash

# | COLOR VARIABLE |======================================================|
# |=======================================================================|
#Black        0;30     Dark Gray     1;30
#Red          0;31     Light Red     1;31
#Green        0;32     Light Green   1;32
#Brown/Orange 0;33     Yellow        1;33
#Blue         0;34     Light Blue    1;34
#Purple       0;35     Light Purple  1;35
#Cyan         0;36     Light Cyan    1;36
#Light Gray   0;37     White         1;37

CR_BLACK="\033[0;30m"; 
CR_RED="\033[0;31m"; 
CR_GREEN="\033[0;32m"; 
CR_ORANGE="\033[0;33m"; 
CR_BLUE="\033[0;34m"; 
CR_PURPLE="\033[0;35m"; 
CR_CYAN="\033[0;36m"; 
CR_LIGHT_GRAY="\033[0;37m";

CR_DARK_GRAY="\033[1;30m";
CR_LIGHT_RED="\033[1;31m";
CR_LIGHT_GREEN="\033[1;32m";
CR_YELLOW="\033[1;33m";
CR_LIGHT_BLUE="\033[1;34m";
CR_LIGHT_PURPLE="\033[1;35m";
CR_LIGHT_CYAN="\033[1;36m";
CR_WHITE="\033[1;37m";

CR_END="\033[0m";

# |=======================================================================|

# | Check success |=======================================================|
# |=======================================================================|
check_success() # 1 = "name part"
{
if [[ $? -eq 0 ]]
then
  printf " -- ${CR_LIGHT_PURPLE}$1${CR_END} ${CR_ORANGE}was created${CR_END} ${CR_GREEN}successfully${CR_END}!\n"
else
  printf " -- ${CR_RED}ERROR:${CR_END} ${CR_ORANGE}Script failed${CR_END}!\n" >&2
  exit 1
fi
}
# |=======================================================================|

# | __MAIN__ |============================================================|
# |=======================================================================|
printf " --- [[ ${CR_ORANGE}Start run.sh${CR_END}! ]] ---\n\n"
cmake ..;
check_success "CMake";

while true; do

  printf " -- ${CR_ORANGE}Do you want continue?${CR_END} (${CR_GREEN}y${CR_END},${CR_RED}N${CR_END})\n";
  read answer;

  if [[ $answer == "y"* ]]; then
    make;
    check_success "Make";
    break;
  elif [[ $answer == "N"* ]]; then
    exit 0;
  else
    printf " --- [${CR_RED}Incomprehensible characters${CR_END}] '${CR_ORANGE}$answer${CR_END}' ";
  fi
done

while true; do

  printf " -- ${CR_ORANGE}Do you want continue?${CR_END} (${CR_GREEN}y${CR_END},${CR_RED}N${CR_END})\n";
  read answer;

  if [[ $answer == "y"* ]]; then
    check_success "console_minesweeper"
    printf " --- [[[ ${CR_LIGHT_CYAN}console_minesweeper${CR_END} ${CR_ORANGE}was started${CR_END}! ]]] ---\n\n"
    ./console_minesweeper;
    printf "\n";
    break;
  elif [[ $answer == "N"* ]]; then
    exit 0;
  else
    printf " --- [${CR_RED}Incomprehensible characters${CR_END}] '${CR_ORANGE}$answer${CR_END}' ";
  fi
done

printf "\n --- [[ ${CR_ORANGE}run.sh completed${CR_END} ${CR_LIGHT_GREEN}successfully${CR_END}! ]] ---\n"
exit 0;
# |=======================================================================|
