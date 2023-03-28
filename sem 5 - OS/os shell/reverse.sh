echo "Enter the number"
read n
t=0
while [ $n -ne 0 ]
do
  t=$(($t*10))
  x=$(($n%10))
  t=$(($t+$x))
  n=$(($n/10))
done
echo "The reverse is $t"
