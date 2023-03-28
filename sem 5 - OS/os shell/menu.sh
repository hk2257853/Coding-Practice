ch=1
while [ $ch -eq 1 ]
do
	echo "1. Display Calender"
	echo "2. Display Users"
	echo "3. Display current directory"
	read choice
	case $choice in
	1) cal
	;;
	2) who
	;;
	3) pwd
	;;
	*) echo "Invalid choice"
	;;
	esac
	echo "Do you want to continue 1/0"
	read ch
done
