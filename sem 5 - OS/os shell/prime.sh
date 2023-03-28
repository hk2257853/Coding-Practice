echo "Enter the number"
read num
i=2
flag=0
while [ $i -lt $num ]
do
	x=$(($num%$i)) 
	if [ $x -eq 0 ]
	then
		flag=1
	fi
	
	i=$(($i+1))
done
if [ $flag -eq 0 ]
then
	echo "Prime number"
else
	echo "Not a prime number"
fi
