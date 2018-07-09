#!/usr/bin/env python
# coding=utf-8

# 模块最前面用3个单引号或双引号的多行注释即__doc__变量内容
'''
====================================
Python getopt exaple usage

print "python_getopt -h"
print "python_getopt --help"
print "python_getopt -o <arg>"
print "python_getopt --output <arg>"
print "python_getopt -v"
====================================
'''

import getopt, sys

def main():
    def show_usage(docstring):
        print docstring.rstrip("\n")

    # 看字符右边是否有":"
    # 单字符加冒号表示选项有且必须加参数
    # p, s, x右边都有':'所以必须跟选项参数(optarg)

    # 单个字符表示选项没有参数
    # h, v, p右边没有':'所以可以不需要跟选项参数(optarg)

    # 在long_opts里有=号的就必须有args
    # opts 和long_opts并没有顺序上的对应关系,
    # 他们之间是否关联看下面循环里如何处理而已
    try:
        opts, args = getopt.getopt(sys.argv[1:], "hvp:s:", ["help", "verbose",
            "path=", "longopt_no_args"])
    except getopt.GetoptError as err:
        print str(err)  # will print something like "option -a not recognized"
        show_usage(__doc__)
        sys.exit(2)

    for o, a in opts:
        if o in ("-h", "--help"):
          show_usage(__doc__)
          sys.exit()
        elif o in ("-v", "--verbose"):
            print 'verbose enable'
        elif o in ("-p", "--path"):
            print 'path=' + a
        elif o in ("--longopt_no_args"):
            print 'this longopt no args'
        elif o in ("-s"):
            print 's option is ==> %s' % a
        else:
            print 'default'

if __name__ == "__main__":
    main()
