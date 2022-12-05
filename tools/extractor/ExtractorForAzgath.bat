@ECHO OFF
title ExtractorForAzgath
COLOR 05

CLS
ECHO.
ECHO        ______          __                  __    __         
ECHO       /\  _  \        /\ \                /\ \__/\ \        
ECHO       \ \ \L\ \  ____ \ \/    __      __  \ \ ,_\ \ \___    
ECHO        \ \  __ \/\_ ,`\\/   /'_ `\  /'__`\ \ \ \/\ \  _ `\  
ECHO         \ \ \/\ \/_/  /_   /\ \L\ \/\ \L\.\_\ \ \_\ \ \ \ \ 
ECHO          \ \_\ \_\/\____\  \ \____ \ \__/.\_\\ \__\\ \_\ \_\
ECHO           \/_/\/_/\/____/   \/___L\ \/__/\/_/ \/__/ \/_/\/_/
ECHO                               /\____/                       
ECHO                               \_/__/                        
ECHO.
ECHO.
ECHO   	    Project AzgathEmu 2023(c)
ECHO             Github.com/AzgathCore/AzgathCoreMoP
ECHO.
ECHO.
ECHO       Compilateur DBCs/MAPS/VMAPS/MMAPS pour Azgath
ECHO.
ECHO.
PAUSE

:Extract
CLS
COLOR 05
ECHO.
ECHO.
RMDIR /s /q .\buildings
RMDIR /s /q .\vmaps
RMDIR /s /q .\maps
RMDIR /s /q .\mmaps
RMDIR /s /q .\dbc
mapextractor.exe
ECHO.
ECHO.
vmap4extractor.exe
ECHO.
ECHO.
MKDIR vmaps
vmap4assembler.exe Buildings vmaps
ECHO.
ECHO.
ECHO.
ECHO.
MKDIR mmaps
MOVE .\buildings\* .\vmaps
mmaps_generator.exe
PAUSE