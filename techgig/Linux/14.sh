myfilesize=0
totsize=0
for myfile in *
do
        if [ -f $myfile ]
        then
                myfilesize=`wc -c < $myfile`
                totsize=`expr $totsize + $myfilesize`
        fi
done
echo "Total Size of Regular file is $totsize"
