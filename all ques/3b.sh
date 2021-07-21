# Write a shell script that displays a list of all the files in the current directory
# Define the list of files
files="$(ls -1)"


# Print the list of files
echo "$files"



# Or DO This

echo "enter directory name"
read dir
if[ -d $dir]
then
echo "list of files in the directory"
ls –l $dir|egrep ‘^d’
else
echo "enter proper directory name"
fi