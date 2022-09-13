#!/bin/bash

target=$1
if [ -z $target ]; then
    echo "[USAGE] bash check_testcase.sh [target]"
    echo "ex) bash check_testcase.sh rotate"
    echo "ex) bash check_testcase.sh avl"
    echo "ex) bash check_testcase.sh rb"
    echo "ex) bash check_testcase.sh all"
    exit 1
fi

if [ "$target" == "rotate" ]; then
    answer_files=("Tree_rotate_test.txt")
    targets=("rotate")
elif [ "$target" == "avl" ]; then
    answer_files=("AVLtest.txt")
    targets=("avl")
elif [ "$target" == "rb" ]; then
    answer_files=("RBtest.txt")
    targets=("rb")
elif [ "$target" == "all" ]; then
    answer_files=("Tree_rotate_test.txt" "AVLtest.txt" "RBtest.txt")
    targets=("rotate" "avl" "rb")
else
    echo "[ERROR] No such target: "$target
    exit 1
fi

for i in "${!targets[@]}" ; do
    target="${targets[$i]}"
    answer_file="${answer_files[$i]}"

    my_file=my_${target}_test.txt
    if [ -f $my_file ]; then
        rm -rf $my_file
    fi

    # Compile your target
    make $target
    ./$target &>> $my_file

    if diff -Z $answer_file $my_file ; then
        echo "[INFO] Correct $target!"
    else
        echo "[INFO] Incorrect $target!"
    fi

done

