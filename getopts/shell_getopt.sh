#!/bin/bash

print_usage()
{
	echo "Usage : $0 [-c <chip>] [-t <target>] [-r <rootfs>] [-h]"
}

if [ $# -lt 1 ]
then
	print_usage $0
fi

# 看字符右边是否有":"
# 单字符加冒号表示选项有且必须加参数
# c,t,r右边都有':'所以必须跟选项参数(optarg)

# 单个字符表示选项没有参数
# h右边没有':'所以可以不需要跟选项参数(optarg)
while getopts "c:t:r:h" flag; do
	case $flag in
		c)
			CHIP="$OPTARG"
			echo "option c's optargs is $CHIP"
			;;
		t)
			TARGET="$OPTARG"
			echo "option t's optargs is $TARGET"
			;;
		r)
			ROOTFS_PATH="$OPTARG"
			echo "option r's optargs is $ROOTFS_PATH"
			;;
		h)
			print_usage $0
			;;
		*)
			print_usage $0
			;;
	esac
done
