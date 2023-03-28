echo "Enter the year"
read year

if [ $(($year%4)) -eq 0 ]
then
	echo "Enter year is a leap year"
else
	echo "Enter year is not a leap year"
fi
