echo "Enter the number"
read num
sum=0
while [ $num -ne 0 ]
do
	echo "Enter num"
	read x
	sum=$(($sum+$x))
	num=$(($num-1))
done
echo "The sum is $sum"
sum=$(($sum/2))
echo "The average is $sum"
