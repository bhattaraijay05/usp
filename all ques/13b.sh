# Write a shell script to echo the string length of the given string as argument.
string="$@"
if [ $# -eq 0 ]
then
        echo "Syntax: ${0##*/} string"
        exit 1
fi
length=${#string}
echo "String length = $length"