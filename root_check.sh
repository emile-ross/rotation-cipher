if [ "$EUID" -ne 0 ]; then
	echo "You must use sudo privileges in order to install a package"
	echo "Vous devez utiliser les privileges de sudo afin d'installer un package"
	exit 1
fi
