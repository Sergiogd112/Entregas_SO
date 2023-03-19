case $2 in
+)
    res=`expr $1 + $3`
    ;;
-)
    res=`expr $1 - $3`
    ;;
M)
    res=`expr $1 \* $3`
    ;;
D)
    res=`expr $1 \/ $3`
    ;;
esac

echo "Result $res";
