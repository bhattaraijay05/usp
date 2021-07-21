# Write a shell script that deletes all lines containing a specified word

if [ $# -lt 1]
then
echo “ Check the arguments once”
exit
fi
echo “Enter a word”
read word
for file in $*
do
grep –iv “$word” $file | tee 1> /dev/null
done
echo “ lines containing given word are deleted”