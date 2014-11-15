set -e
if [ -z $1 ]
then
	var="0"
else
	var=$1
fi

make
echo
./main $1
