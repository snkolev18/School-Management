#!/bin/bash
#sudo apt-get install dialog
$(LANG=da_DK.UTF-8)
 
BLUE='\033[0;34m'
 
show_logo(){
    printf "${BLUE}████████╗███████╗ █████╗ ███╗   ███╗███████╗ ██████╗ ███╗   ██╗██████╗ ██╗   ██╗██████╗  ██████╗ ███████╗████████╗\n"
    printf "${BLUE}╚══██╔══╝██╔════╝██╔══██╗████╗ ████║██╔════╝██╔═══██╗████╗  ██║██╔══██╗██║   ██║██╔══██╗██╔════╝ ██╔════╝╚══██╔══╝\n"
    printf "${BLUE}   ██║   █████╗  ███████║██╔████╔██║███████╗██║   ██║██╔██╗ ██║██████╔╝██║   ██║██║  ██║██║  ███╗█████╗     ██║   \n"
    printf "${BLUE}   ██║   ██╔══╝  ██╔══██║██║╚██╔╝██║╚════██║██║   ██║██║╚██╗██║██╔══██╗██║   ██║██║  ██║██║   ██║██╔══╝     ██║   \n"
    printf "${BLUE}   ██║   ███████╗██║  ██║██║ ╚═╝ ██║███████║╚██████╔╝██║ ╚████║██████╔╝╚██████╔╝██████╔╝╚██████╔╝███████╗   ██║   \n"
    printf "${BLUE}   ╚═╝   ╚══════╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝╚═════╝  ╚═════╝ ╚═════╝  ╚═════╝ ╚══════╝   ╚═╝  \n"
}
 
 
show_logo
printf "${BLUE} Choose an option: \n"
printf "${BLUE} 1) Execute the application: \n"
printf "${BLUE} 2) Info about the developers: \n"
printf "${BLUE} 3) Exit: \n"
 
 
read opt
until [ "$opt" == "3" ]; do
      case $opt in
        1) clear;
            printf "Executing application";
            sleep 1
            echo '\n'
            clear
            cd SchoolManagement/
            sudo make
            clear
            show_logo
            ./SchoolManagement
            break
        ;;
        2) clear;
            printf "Developers info here";
            break
        ;;
        3) clear;
            printf "Are chupendra"
            sleep 1
            exit
        ;;
        *) clear;
            option_picked "Pick an option from the menu";
        ;;
      esac
  done
 
exec bash