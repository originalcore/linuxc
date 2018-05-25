#!/usr/bin/env python

import getopt, sys

def main():
    def show_usage():
        print "=================="
        print "python_getopt -h"
        print "python_getopt --help"
        print "python_getopt -o <arg>"
        print "python_getopt --output <arg>"
        print "python_getopt -v"
        print "=================="

    try:
        opts, args = getopt.getopt(sys.argv[1:], "ho:v", ["help", "output="])
    except getopt.GetoptError as err:
        # print help information and exit:
        print str(err)  # will print something like "option -a not recognized"
        show_usage()
        sys.exit(2)

    output = None
    verbose = False
    for o, a in opts:
        # print out the option and option argument
        print "option = %s" % o
        if not a.strip() == '':
            print "optarg = %s" % a

        if o == "-v":
            verbose = True
        elif o in ("-h", "--help"):
            show_usage()
            sys.exit()
        elif o in ("-o", "--output"):
            output = a
        else:
            assert False, "unhandled option"

if __name__ == "__main__":
    main()
