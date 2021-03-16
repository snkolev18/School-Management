# School-Management

<p align="center">
  <img src="https://github.com/snkolev18/School-Management/blob/master/docs/logo.png" alt="Logo goes here"></img>
</p> 
<h1 align="center">TeamsOnBudget</h1>
<p align="center">
    <a href="https://en.cppreference.com/w/">
    <img src="https://img.shields.io/badge/C++-Solutions-blue.svg?style=flat&logo=c%2B%2B">
    </a>
</p>

Our project is a multi-platform console application written on C++. It is intended for teachers or school directors and its main purpose is to make their job easier. Like assigning students to different teams, add students/teachers and update their info and so on. 

## Features
- [x] Works on many platforms 
- [x] An incredible table and design that formats the results

## Tested On/Working On
[![Windows)](https://www.google.com/s2/favicons?domain=https://www.microsoft.com/en-in/windows/)](https://www.microsoft.com/en-in/windows/) **Windows 10**

[![GNU/Linux)](https://www.google.com/s2/favicons?domain=https://www.gnu.org/) **Linux Distributions**

[![Debian)](https://www.google.com/s2/favicons?domain=https://www.debian.org/)](https://www.debian.org/) **Debian Distributions**


## 🏁 Getting Started <a name = "getting_started"></a>
Here we will briefly describe you how you can run the application on your machine


### Prerequisites
What things you need to install the software and how to install them. So firstly you have to just copy the following command and paste in your terminal and your set.<br>
For Windows - Windows 7 or LATER versions and up-to date Visual Studio<br>
For Linux – Up-to date g++ compiler, works on most distributions<br>
For <b>GUIsetup.sh</b> you will have to: ``` sudo apt-get install dialog ```

 ``` git clone https://github.com/snkolev18/School-Management.git  ```

### Installing
Here are the installation steps in order to have the application running.

<p>For <b>Windows</b> you will have to open the .sln file like this one below. Simple as that</p>
<img alt="SLN goes here" src="https://github.com/snkolev18/School-Management/blob/master/docs/w_install.png"> </img>

<p>For <b>Linux</b> you will have to follow some more steps. When you have cloned the repository do the following: Find the location where you have cloned the repository and then: </p>

``` chmod +x setup.sh ``` or  ``` chmod +x GUIsetup.sh ``` Both works fine it's just about interface and preferences. setup.sh -> text based setup and GUIsetup.sh -> graphical mode setup:)

<p>Then you run one of the following scripts: </p>

``` ./setup ``` or ``` ./GUIsetup ```

<p> Now you are granted with menu and you can select options </p>
<img alt="Linux install comes here (.sh photos)" src="https://github.com/snkolev18/School-Management/blob/master/docs/l_menu.png"> </img>
<img alt="Linux install comes here (.sh photos)" src="https://github.com/snkolev18/School-Management/blob/master/docs/l_menu2.png"> </img>

<p> If you choose option 1 on both menus, g++ (using the Makefile) will link your executables into an ELF and will execute the programme </p>

