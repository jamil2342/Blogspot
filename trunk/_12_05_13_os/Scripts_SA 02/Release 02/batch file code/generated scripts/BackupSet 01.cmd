@echo off
Rem Automated script for backup created by Backup program interactive mode
set sourcePath="F:\C"
set destPath="E:\C Programming Backup"
Rem Check if directories exist
if not exist %sourcePath% (
	echo Source directory %sourcePath% does not exist. Please check provided directory path.
	goto exit
)
if not exist %destPath% (
	mkdir %destPath%
)
Rem perform backup
echo Performing backup from %sourcePath% to %destPath%, please wait..
xcopy /e /v /y %sourcePath% %destPath%
echo.
if %ERRORLEVEL% neq 0 echo There is a problem with destination directory. Please check destination directory path.
echo Backup operation for %sourcePath% is complete.
echo.
set sourcePath="F:\DNA Shifter"
set destPath="G:\DNA Shifter Backup"
Rem Check if directories exist
if not exist %sourcePath% (
	echo Source directory %sourcePath% does not exist. Please check provided directory path.
	goto exit
)
if not exist %destPath% (
	mkdir %destPath%
)
Rem perform backup
echo Performing backup from %sourcePath% to %destPath%, please wait..
xcopy /e /v /y %sourcePath% %destPath%
echo.
if %ERRORLEVEL% neq 0 echo There is a problem with destination directory. Please check destination directory path.
echo Backup operation for %sourcePath% is complete.
echo.
set sourcePath="F:\ssh keys"
set destPath="G:\ssh keys backup"
Rem Check if directories exist
if not exist %sourcePath% (
	echo Source directory %sourcePath% does not exist. Please check provided directory path.
	goto exit
)
if not exist %destPath% (
	mkdir %destPath%
)
Rem perform backup
echo Performing backup from %sourcePath% to %destPath%, please wait..
xcopy /e /v /y %sourcePath% %destPath%
echo.
if %ERRORLEVEL% neq 0 echo There is a problem with destination directory. Please check destination directory path.
echo Backup operation for %sourcePath% is complete.
echo.
:exit
Rem Unset variables
set sourcePath=
set destPath=
Rem Turn back echo on
@echo on
