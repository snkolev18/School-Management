#!/bin/bash
sudo apt-get update
cd SchoolManagement/
chmod +x SchoolManagement.cpp
# Makefile is currently not working
sudo make
chmod +x SchoolManagement
./SchoolManagement
exec bash
