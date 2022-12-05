@ECHO OFF 
title Authserver.exe || by: AzgathCore
color 05
CLS 
ECHO Server Restart Started %time:~0,5% %date:~1% 
:SERVERLOOP 
authserver.exe
ECHO Server Restart %time:~0,5% %date:~1% 
ECHO. 
GOTO SERVERLOOP 
:END