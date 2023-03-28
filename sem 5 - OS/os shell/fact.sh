echo "Enter the number"
read num
p=1
while [ $num -gt 1 ]
do
	p=$(($p*$num))
	num=$(($num-1))
done
echo "The factorial is $p"
