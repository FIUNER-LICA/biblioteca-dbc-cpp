#!/bin/bash

OPTSTRING=":r:o:"

while getopts ${OPTSTRING} opt; do
	case ${opt} in
		r)
			REPETITIONS=${OPTARG}
			;;
		o)
			OPTIMIZATION=${OPTARG}
			;;
		:)
			echo "Option -${OPTARG} requires an argument"
			exit 1
			;;
		?)
			echo "Invalid option: -${OPTARG}"
			exit 1
			;;
	esac
done

if [ -z "${REPETITIONS}" ]; then REPETITIONS=1; else echo "REPETITIONS is ${REPETITIONS}"; fi

flags="-std=c++17"

if [ -z "${OPTIMIZATION}" ]; then echo "Compiling without optimization."; else flags+=" -${OPTIMIZATION}"; fi

export flags=${flags}

# Modos posibles de asserts
assert_modes=("ASSERT_FUNCTION" "ASSERT_MACRO" "ASSERT_CLASS" "ASSERT_NONE")

# Modos posibles de invariantes
invariant_modes=("INVARIANT_LAMBDA" "INVARIANT_MACRO" "INVARIANT_NONE")

output_file="./data/benchmark_output.csv"

echo "assert_mode,invariant_mode,ciclos" > $output_file

for assert_mode in "${assert_modes[@]}"; do
	for invariant_mode in "${invariant_modes[@]}"; do
		current_iterations=0
		make ASSERT_MODE=$assert_mode INVARIANT_MODE=$invariant_mode 
		for ((i=0 ; i<REPETITIONS ; i++)); do
#			temp_file="./data/time_o_tmp.txt"

#			touch $temp_file
#	                /usr/bin/time --output="$temp_file" -f "%e,%U,%S,%K" ./benchmark
#			tiempo=$(<"$temp_file")
#			echo "$assert_mode,$invariant_mode,$tiempo" >> $output_file
#			rm "$temp_file"
      output=$(./benchmark)
      echo "$assert_mode,$invariant_mode,$output" >> $output_file
      ((current_iterations++))
      echo "$current_iterations/$REPETITIONS"
    done
		make ASSERT_MODE=$assert_mode INVARIANT_MODE=$invariant_mode clean
	done
done
