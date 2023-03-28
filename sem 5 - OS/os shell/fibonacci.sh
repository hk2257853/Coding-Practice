echo "Enter the number"
read num
i=1
a=0
b=1
while [ $i -le $num ]
do 
	if [ $i -eq 1 ]
	then
		echo "$a "
	fi
	if [ $i -eq 2 ]
	then
		echo "$b "
	fi
	if [ $i -gt 2 ]
	then
		c=$(($a+$b))
		echo "$c "
		a=$b
		b=$c
	fi
	i=$(($i+1))
done
