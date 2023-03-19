cp $1 "$1.copy"
mkdir -p $2
zip -r "$2/$1.zip" "$1.copy"