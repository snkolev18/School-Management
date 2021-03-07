#!/bin/bash

WIDTH=40
HEIGHT=15
OPTION=4
BACKTITLE="Back"
TITLE="Title here"
MENU="Choose one of the options below:"

OPTIONS=(1 "Execute application"
         2 "Developers information"
         3 "Exit")

CHOICE=$(dialog --clear \
                --backtitle "$BACKTITLE" \
                --title "$TITLE" \
                --menu "$MENU" \
                $HEIGHT $WIDTH $OPTION \
                "${OPTIONS[@]}" \
                2>&1 >/dev/tty)

clear
case $CHOICE in
        1)
            cd SchoolManagement
            make
            ./SchoolManagement
            ;;
        2)
            printf "Stoyan Kolev - Scrum Master and Quality Assurance Engineer \n";
            printf "Alexander DInev - Backend Developer \n";
            printf "Atanas Burmov - Frontend Developer \n";
            ;;
        3)
            printf "BYE, BYE!!! :)"
            ;;
esac
