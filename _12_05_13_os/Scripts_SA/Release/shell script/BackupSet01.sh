# Automated script for backup created by Backup program interactive mode
sourcePath=/home/Atique/Public
destPath=/home/Atique/Backup/Public_data
if ! [ -e "$sourcePath" ]; then
	echo "Directory $sourcePath does not exist. Please check path."
	exit
elif ! [ -d "$sourcePath" ]; then
/	echo "$sourcePath is not a directory. Please check path."
	exit
fi
if [ -d $destPath ]; then
	# directory exists, that's fine
	# dir does not exist but file exists
	echo
elif [ -e "$destPath" ]; then
	echo "A file $destPath already exists. Please check path."
	exit
# none exists
else
	mkdir $destPath
fi
echo "Performing backup from $sourcePath to $destPath, please wait.."
cp -rv $sourcePath/* $destPath
echo "Backup complete for $sourcePath"
echo " "
sourcePath=/home/Atique/Documents/Data
destPath=/home/Atique/Backup/Data_backup
if ! [ -e "$sourcePath" ]; then
	echo "Directory $sourcePath does not exist. Please check path."
	exit
elif ! [ -d "$sourcePath" ]; then
/	echo "$sourcePath is not a directory. Please check path."
	exit
fi
if [ -d $destPath ]; then
	# directory exists, that's fine
	# dir does not exist but file exists
	echo
elif [ -e "$destPath" ]; then
	echo "A file $destPath already exists. Please check path."
	exit
# none exists
else
	mkdir $destPath
fi
echo "Performing backup from $sourcePath to $destPath, please wait.."
cp -rv $sourcePath/* $destPath
echo "Backup complete for $sourcePath"
echo " "
echo "Backup of the set complete"
