# Write a shell script that receives any number of file names as arguments checks if every
# argument supplied is a file or a directory and reports accordingly. Whenever the argument is a
# file or directory.


for x in $*
do
if [ -f $x ]
then
echo " $x is  a file "
echo " no of lines in the file are "
wc -l $x
elif [ -d $x ]
then
echo " $x is  a directory "
else
echo " enter valid filename or directory name "
fi
done