#!/usr/bin/bash

# Build all examples and exercises for each directory
# TODO: creation and testing of golden files

directories=("./chapter-1")
declare -i passes failures
passes=0
failures=0

for dir in "${directories[@]}"; do
	echo "Building --> $dir"
	make -BC "$dir" > /dev/null

	if [[ "$?" -eq 0 ]] then
		passes+=1
	else 
		failures+=1
	fi
done

echo 
echo "All done"
echo "Passes: $passes"
echo "Failures: $failures"

#TODO
