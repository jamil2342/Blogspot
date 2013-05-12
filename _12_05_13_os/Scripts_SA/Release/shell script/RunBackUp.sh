#!/bin/sh
##########################################################
################### Backup Script ########################
############# Author:  Saint Atique ######################
##########################################################

# Get number of command line arguments provided by user using $#
# Backup for command line if number of arguments provided is 2
if [ $# -eq 2 ]; then
	# Get source directory and destionation directory from command line
	sourcePath=$1
	destPath=$2
	# Check for directory exist

	if ! [ -e "$sourcePath" ]; then
		echo "Directory $sourcePath does not exist. Please check path."
		exit
	elif ! [ -d "$sourcePath" ]; then
		echo "$sourcePath is not a directory. Please check path."
		exit
	fi
	
	if [ -d "$destPath" ]; then
		# directory exists, that's fine
		echo
	# directory does not exist but file exists
	# if it exists but as a file; only directories can be source
	elif [ -e "$destPath" ]; then
		echo "A file $destPath already exists. Please check path."
		exit
	# none exists then create the directory
	else
		mkdir $destPath
	fi
	# we have acquired source and destination, now let's perform backup
	echo "Performing backup from $sourcePath to $destPath, please wait.."
	# using cp command with recursive option we can perform the copy
	# v switch with cp provides verbose output on console
	cp -rv $sourcePath/* $destPath
	echo "Backup complete"
	echo " "
	exit
# After if else block is executed it will execute statements which will perform backup afterwards
# if total number of command line arguments is 4 and 3rd argument is "--createscript"
elif [ $# -eq 4 ] && [ $3 == --createscript ]; then
	# Save the script file name/path into variable scriptFile
	scriptFile=$4
	echo "Creating script $scriptFile for backup automation"
	# scriptFile is the variable which contains script path or script name
	# we redirect command statements of standard output using echo to script file
	echo "# Automated script for backup created by Backup program command line"> $scriptFile
	# variables sourcePath and destPath will be used to remember the directories mentioned in command line
	echo "sourcePath=$1">> $scriptFile
	echo "destPath=$2">> $scriptFile
	
	# using if with -e we check whether directories exist
	echo "if ! [ -e \"\$sourcePath\" ]; then">> $scriptFile
	echo "	echo \"Directory \$sourcePath does not exist. Please check path.\"">> $scriptFile
	echo "	exit">> $scriptFile
	# using if with -d we check whether it is directory
	echo "elif ! [ -d \"\$sourcePath\" ]; then">> $scriptFile
	echo "/	echo \"\$sourcePath is not a directory. Please check path.\"">> $scriptFile
	echo "	exit">> $scriptFile
	echo fi>> $scriptFile
	
	echo "if [ -d "\$destPath" ]; then">> $scriptFile
	echo "	# directory exists, that's fine">> $scriptFile
	echo "	# dir does not exist but file exists">> $scriptFile
	echo "	echo">> $scriptFile
	echo "elif [ -e \"\$destPath\" ]; then">> $scriptFile
	echo "	echo \"A file \$destPath already exists. Please check path.\"">> $scriptFile
	echo "	exit">> $scriptFile
	echo "# none exists">> $scriptFile
	echo else>> $scriptFile
	echo "	mkdir \$destPath">> $scriptFile
	echo fi>> $scriptFile
	echo "echo \"Performing backup from \$sourcePath to \$destPath, please wait..\"">> $scriptFile
	echo "cp -rv \$sourcePath/* \$destPath">> $scriptFile
	echo "echo \"Backup complete\"">> $scriptFile
	echo "Automated backup script has been created successfully."

	# Make the script executable
	chmod a+x $scriptFile
	exit
# Back up with interactive menu
else
	echo "Number of command line arguments is not two. Invoking interactive menu."
	echo " "
	# We run the menu loop as long as variable menuStatus is 1
	menuStatus=1
	# Menu implementation using while loop
	while [ $menuStatus -eq 1 ]; do
		echo "Automated Backup Program Task"
		echo "================================"
		echo "1. Backup"
		echo "2. Create script"
		echo "3. Quit"
		echo
		echo "Enter your choice: "
		# Take choice from user and store in variable userChoice
		read userChoice
		echo
		if [ $userChoice -eq 1 ]; then
			isEndOfSet=0
			while [ $isEndOfSet -eq 0 ]; do
				# run loop until correct path is given
				PathValid=0
				while [ $PathValid -eq 0 ]; do
					# take source path from user
					echo "Enter source directory path: "
					read sourcePath

					if ! [ -e "$sourcePath" ]; then
						echo "Directory $sourcePath does not exist. Please provide this information again."
					elif ! [ -d "$sourcePath" ]; then
						echo "$sourcePath is not a directory. Please provide this information again."
					else
						PathValid=1
					fi
				done

				# run loop until correct path is given
				PathValid=0
				while [ $PathValid -eq 0 ]; do
					# take destination path from user
					echo "Enter destination directory path: "
					read destPath

					if [ -d "$destPath" ]; then
						# directory exists, that's fine
						PathValid=1
					# dir does not exist but file exists
					elif [ -e "$destPath" ]; then
						echo "A file $destPath already exists. Please check path."
						exit
					# none exists
					else
						mkdir $destPath
						PathValid=1
					fi
				done
				# we have acquired source and destination, now let's perform backup
				echo "Performing backup from $sourcePath to $destPath, please wait.."
				cp -rv $sourcePath/* $destPath
				echo "Backup complete"
				echo " "

				userChoice=c
				while [ $userChoice != y ] && [ $userChoice != n ]; do
					echo "Do you want to perform another backup operation? (y/n)"
					read userChoice
				done
				if [ $userChoice == n ]; then
					isEndOfSet=1
				fi
			done

		# Create script for set of backup operations
		elif [ $userChoice -eq 2 ]; then
			# Retrieve script file name from user
			echo "Please enter file name/path of the script:"
			read scriptFile
			echo "# Automated script for backup created by Backup program interactive mode"> $scriptFile

			# Run interactive mode as long user wants to add backup operations on the set
			isEndOfSet=0
			while [ $isEndOfSet -eq 0 ]; do
				# take source path from user
				echo "Enter source directory path: "
				read sourcePath
				# take destination path from user
				echo "Enter destination directory path: "
				read destPath

				echo "Adding backup operation to the script $scriptFile for backup automation"
				echo "sourcePath=$sourcePath">> $scriptFile
				echo "destPath=$destPath">> $scriptFile

				echo "if ! [ -e \"\$sourcePath\" ]; then">> $scriptFile
				echo "	echo \"Directory \$sourcePath does not exist. Please check path.\"">> $scriptFile
				echo "	exit">> $scriptFile
				echo "elif ! [ -d \"\$sourcePath\" ]; then">> $scriptFile
				echo "/	echo \"\$sourcePath is not a directory. Please check path.\"">> $scriptFile
				echo "	exit">> $scriptFile
				echo fi>> $scriptFile
	
				echo "if [ -d "\$destPath" ]; then">> $scriptFile
				echo "	# directory exists, that's fine">> $scriptFile
				echo "	# dir does not exist but file exists">> $scriptFile
				echo "	echo">> $scriptFile
				echo "elif [ -e \"\$destPath\" ]; then">> $scriptFile
				echo "	echo \"A file \$destPath already exists. Please check path.\"">> $scriptFile
				echo "	exit">> $scriptFile
				echo "# none exists">> $scriptFile
				echo else>> $scriptFile
				echo "	mkdir \$destPath">> $scriptFile
				echo fi>> $scriptFile
				echo "echo \"Performing backup from \$sourcePath to \$destPath, please wait..\"">> $scriptFile
				echo "cp -rv \$sourcePath/* \$destPath">> $scriptFile
				echo "echo \"Backup complete for \$sourcePath\"">> $scriptFile
				echo "echo \" \"">> $scriptFile
				userChoice=c
				while [ $userChoice != y ] && [ $userChoice != n ]; do
					echo "Do you want to add another backup operation to the set? (y/n)"
					read userChoice
				done
				if [ $userChoice == n ]; then
					isEndOfSet=1
				fi
			done
			echo "echo \"Backup of the set complete\"">> $scriptFile
			echo "Automated script $scriptFile has been created successfully."

			# Make the script executable
			chmod a+x $scriptFile
			exit
		# user selected to quit the program
		elif [ $userChoice -eq 3 ]; then
			#menuStatus=0
			echo "Exiting backup program"
			exit
		else
			echo "You have entered an invalid choice."
		fi
	done
fi

echo "Exiting backup program"
