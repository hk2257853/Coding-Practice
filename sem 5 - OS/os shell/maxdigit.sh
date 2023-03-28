echo "Enter the number"
read n
t=0
while [ $n -ne 0 ]
do
	x=$(($n%10))
 	if [ $x -gt $t ]
 	then
	 t=$x
	fi
	n=$(($n/10))
done
echo "The max digit is $t"
