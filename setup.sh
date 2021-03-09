#!/bin/bash
#sudo apt-get install dialog

#Title........: School Management
#Description..: This is a console app, created to make easier the school management work related to teams, teachers, students etc
#Authors.......: SNKOlev18, AGDinev18, AABurmov18
#Version......: 1.0
#Usage........: For Windows: execute .sln file | For Linux: ./setup.sh
#C++ & Bash Version.: 11 & 4.2
 
BLUE='\033[0;34m'
ESCAPE= '\033[0m'
show_logo(){
    printf "████████╗███████╗ █████╗ ███╗   ███╗███████╗ ██████╗ ███╗   ██╗██████╗ ██╗   ██╗██████╗  ██████╗ ███████╗████████╗\n "
    printf "╚══██╔══╝██╔════╝██╔══██╗████╗ ████║██╔════╝██╔═══██╗████╗  ██║██╔══██╗██║   ██║██╔══██╗██╔════╝ ██╔════╝╚══██╔══╝\n " 
    printf "   ██║   █████╗  ███████║██╔████╔██║███████╗██║   ██║██╔██╗ ██║██████╔╝██║   ██║██║  ██║██║  ███╗█████╗     ██║   \n "
    printf "   ██║   ██╔══╝  ██╔══██║██║╚██╔╝██║╚════██║██║   ██║██║╚██╗██║██╔══██╗██║   ██║██║  ██║██║   ██║██╔══╝     ██║   \n "
    printf "   ██║   ███████╗██║  ██║██║ ╚═╝ ██║███████║╚██████╔╝██║ ╚████║██████╔╝╚██████╔╝██████╔╝╚██████╔╝███████╗   ██║   \n "
    printf "   ╚═╝   ╚══════╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝╚═════╝  ╚═════╝ ╚═════╝  ╚═════╝ ╚══════╝   ╚═╝  \n "
}
 
 
show_logo
printf " Choose an option: \n"
printf " 1) Execute the application: \n"
printf " 2) Info about the developers: \n"
printf " 3) Exit: \n"
 
 
read opt
until [ "$opt" == "3" ]; do
      case $opt in
        1) clear;
            printf "Executing application";
            sleep 1
            echo '\n'
            clear
            cd SchoolManagement/
            make
            clear
            ./SchoolManagement
            break
        ;;
        2) clear;
            

            printf "Stoyan Kolev - Scrum Master and Quality Assurance Engineer \n";
            printf "Alexander DInev - Backend Developer \n";
            printf "Atanas Burmov - Frontend Developer \n";

            break
        ;;
        3) clear;
            printf "BYE, BYE!!! :)"
            sleep 1
            exit
        ;;
        *) clear;
            printf "Pick an option from the menu";
            ./setup.sh
        ;;
      esac
  done