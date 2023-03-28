echo "Enter a"
read a
echo "Enter b"
read b
echo "Enter c"
read c

if [ $a -gt $b ]
then
	if [ $a -gt $b ]
	then	
		echo "Max=$a"
	else
		echo "Max=$b"
	fi
else
	if [ $b -gt $c ]
	then	
		echo "Max=$b"
	else
		echo "Max=$c"
	fi
fi
