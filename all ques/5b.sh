# Write a shell script that accepts a string from the terminal and echo a suitable message if it
# doesn’t have at least 5 characters including the other symbols.

string="$@"
if [ $# -eq 0 ]
then
        echo "Syntax: ${0##*/} string"
        exit 1
elif [ ${#string} -lt 5 ]
then
        echo "String must have at least 5 characters"
        exit 1
fi
length=${#string}
echo "String length = $length"