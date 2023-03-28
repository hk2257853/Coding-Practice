echo "Enter the number"
read n
t=9
while [ $n -ne 0 ]
do
	x=$(($n%10))
 	if [ $x -lt $t ]
 	then
	 t=$x
	fi
	n=$(($n/10))
done
echo "The min digit is $t"
