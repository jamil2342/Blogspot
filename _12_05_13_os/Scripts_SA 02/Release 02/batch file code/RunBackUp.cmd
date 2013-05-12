@echo off
Rem Turning echo off so that commands of this script are not echoed on the terminal

Rem ##########################################################
Rem ################### Backup Script ########################
Rem ##########################################################

Rem Get number of command line arguments provided by user
Rem Initialize variable number of arguments: nArgs to zero
set numArgs=0
Rem count for each item and increment the variable by one to get total number of command line arguments
for %%x in (%*) do Set /A numArgs+=1

Rem if number of command line arguments is four and /createscript is mentioned as 3rd argument
if %numArgs% equ 4 if "%3"=="/CreateScript" (
	Rem Set Script File Path from commandline
	goto setScriptFile
)

Rem If no command line argument is provided or too many arguments are provided then it will fall back to menu driven system.
if %numArgs% neq 2 (
	echo Number of command line arguments is not two. Invoking interactive menu.
	echo.
	goto runMenu
)

Rem Number of command line arguments provided is two. Perform backup.
goto performBackUpCmd

Rem Take the file path/name of the script from command line and store it to a variable
:setScriptFile
	set scriptFile=%4
	goto createScriptLabel
Rem Script File Setup ends here

Rem Logical Module Menu starts here
:runMenu
	echo Automated Backup Program Task
	echo ====================================
	echo 1. Backup
	echo 2. Create script
	echo 3. Quit

	echo.
	Rem using set command we take the input from user
	set /p userChoice= Enter your choice: 
	Rem input is stored in userChoice variable; we perform operation depending on the user input
	if %userChoice% equ 1 (
		goto runBackUpMenu
	)
	if %userChoice% equ 2 (
		goto menuCreateScript
	)
	Rem if user presses 3 we exit the program
	if %userChoice% equ 3 (
		echo.
		echo Exiting backup program
		goto exit
	)
	echo You have entered an invalid choice.
	echo.
	goto runMenu
Rem Logical Module Menu ends here

Rem Logical Module BackUPMenu starts here
:runBackUpMenu
	Rem take the source directory from user
	set /p sourcePath= Enter source directory path: 
	set sourcePath="%sourcePath%"
	if not exist %sourcePath% (
		echo.
		echo Directory %sourcePath% not found. You have to provide this information again.
		goto runBackUpMenu
	)
	Rem take the destination directory from user
	set /p destPath= Enter destination directory path: 
	set destPath="%destPath%"
	Rem if the destionation does not exist we create the directory
	if not exist %destPath% mkdir %destPath%
	echo.
	goto menuBackup
	goto exit
Rem Logical Module BackUPMenu ends here

Rem Logical Module BackUp operation for menu starts here
:menuBackup
	Rem perform backup for menu selection
	echo Performing backup from %sourcePath% to %destPath%, please wait..
	Rem xcopy is better for copying large number of files, so we use xcopy
	xcopy /e /v /y %sourcePath% %destPath%
	Rem if xcopy encounters an error it will set a non-zero error level
	if %ERRORLEVEL% neq 0 echo There is a problem with destination directory. Please check destination directory path.
	rem xcopy /f /e /v /y %sourcePath% %destPath%
	echo Backup complete
	echo.
	Rem Ask user whether he/she wants another backup
	set /p userChoice= Do you want to perform another backup operation? (y/n) 
	Rem if user chooses yes then we run another backup operation
	if %userChoice% == y goto runBackUpMenu
	Rem otherwise we go back to previous menu
	echo.
	goto runMenu
Rem BackUp operation for menu ends here

Rem Backup operation starts here
:performBackUpCmd
	Rem Set source and destination variables from command line arguments
	set sourcePath=%1
	set destPath=%2

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
	Rem if xcopy encounters an error it will set a non-zero error level
	if %ERRORLEVEL% neq 0 echo Please check destination directory path.
	echo.
	echo Backup complete.
	goto exit
Rem Backup operation ends here

Rem Logical Module Create Script starts here; this module creates script when specified from command line with option /CreateScript
:createScriptLabel
	echo Creating script %scriptFile% for backup automation
	Rem %scriptFile% is the variable which contains script path or script name
	Rem we redirect command statements of standard output using echo to script file
	echo @echo off> %scriptFile%
	Rem We also put some comments on the created script
	echo Rem Automated script for backup created by Backup program>> %scriptFile%
	Rem variables sourcePath and destPath will be used to remember the directories mentioned in command line
	echo set sourcePath=%1>> %scriptFile%
	echo set destPath=%2>> %scriptFile%

	Rem using if not exist we check whether directories exist
	echo Rem Check if directories exist>> %scriptFile%
	echo if not exist %%sourcePath%% (>> %scriptFile%
	echo 	echo Source directory %%sourcePath%% does not exist. Please check provided directory path.>> %scriptFile%
	echo 	goto exit>> %scriptFile%
	echo )>> %scriptFile%
	Rem Now check our destination directory exist; if it does not exist we will create
	echo if not exist %%destPath%% (>> %scriptFile%
	echo 	mkdir %%destPath%%>> %scriptFile%
		rem echo error level is %ERRORLEVEL%
		rem echo Destination directory %%destPath%% does not exist. Please check provided directory path.
		rem goto exit
	echo )>> %scriptFile%

	echo Rem perform backup>> %scriptFile%
	echo echo Performing backup from %%sourcePath%% to %%destPath%%, please wait..>> %scriptFile%
	Rem xcopy is better for copying larger number of files, so we use xcopy
	echo xcopy /e /v /y %%sourcePath%% %%destPath%%>> %scriptFile%
	Rem Print a new line
	echo echo.>> %scriptFile%
	Rem if xcopy encounters an error it will set a non-zero error level
	echo if %%ERRORLEVEL%% neq 0 echo There is a problem with destination directory. Please check destination directory path.>> %scriptFile%
	rem xcopy /f /e /v /y %sourcePath% %destPath%
	echo echo Backup complete.>> %scriptFile%

	echo goto exit>> %scriptFile%
	echo :exit>> %scriptFile%
	echo Rem Unset variables>> %scriptFile%
	echo set sourcePath=>> %scriptFile%
	echo set destPath=>> %scriptFile%
	echo Rem Turn back echo on>> %scriptFile%
	echo @echo on>> %scriptFile%
	echo.
	echo Automated script has been created successfully.
	goto exit
Rem Logical Module Create Script Setup ends here

Rem Create Script from Menu starts here
:menuCreateScript
	set /p scriptFile= Please enter file name/path of the script: 
	set scriptFile="%scriptFile%"
	echo @echo off> %scriptFile%
	echo Rem Automated script for backup created by Backup program interactive mode>> %scriptFile%
	echo Creating script %scriptFile% for backup automation

Rem if user wants to add another backup operation to the set we jump here again using goto
:appendBackupToScript
	Rem take source and destionation directories from user
	set /p sourcePath= Enter source directory path: 
	set /p destPath= Enter destination directory path: 

	Rem variables sourcePath and destPath will be used to save the directories provided by user
	echo set sourcePath="%sourcePath%">> %scriptFile%
	echo set destPath="%destPath%">> %scriptFile%

	echo Rem Check if directories exist>> %scriptFile%
	echo if not exist %%sourcePath%% (>> %scriptFile%
	echo 	echo Source directory %%sourcePath%% does not exist. Please check provided directory path.>> %scriptFile%
	echo 	goto exit>> %scriptFile%
	echo )>> %scriptFile%
	echo if not exist %%destPath%% (>> %scriptFile%
	echo 	mkdir %%destPath%%>> %scriptFile%
		rem echo error level is %ERRORLEVEL%
		rem echo Destination directory %%destPath%% does not exist. Please check provided directory path.
		rem goto exit
	echo )>> %scriptFile%

	echo Rem perform backup>> %scriptFile%
	echo echo Performing backup from %%sourcePath%% to %%destPath%%, please wait..>> %scriptFile%
	echo xcopy /e /v /y %%sourcePath%% %%destPath%%>> %scriptFile%
	echo echo.>> %scriptFile%
	echo if %%ERRORLEVEL%% neq 0 echo There is a problem with destination directory. Please check destination directory path.>> %scriptFile%
	rem xcopy /f /e /v /y %sourcePath% %destPath%
	echo echo Backup operation for %%sourcePath%% is complete.>> %scriptFile%
	echo echo.>> %scriptFile%
	set /p userChoice= Do you want to add another backup operation to the set? (y/n) 
	if "%userChoice%"=="y" goto appendBackupToScript
		
	Rem :finishCreateMenuScript
	echo :exit>> %scriptFile%
	echo Rem Unset variables>> %scriptFile%
	echo set sourcePath=>> %scriptFile%
	echo set destPath=>> %scriptFile%
	echo Rem Turn back echo on>> %scriptFile%
	echo @echo on>> %scriptFile%
	echo.
	echo Automated script has been created successfully.
	goto exit
Rem Create Script Setup ends here

:exit
Rem Unset variables
set sourcePath=
set destPath=
set scriptFile=
Rem Turn back echo on
@echo on