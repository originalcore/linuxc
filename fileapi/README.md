# File Handling API Exploration

参考:GNU/Linux Application Programming

## STDIN_FILENO和stdin

	stdin 是FILE * 类型
	STDIN_FILENO 是fd类型
	STDIN_FILENO = fileno(stdin)

## Character Interfaces

[char read](./char_read.c)

[char write](./char_write.c)

## String Interfaces

### ASCII format

[string read](./string_read.c)

[string write](./string_write.c)

Structured Data in ASCII Format

[structured ascii write](./structured_ascii_write.c)

[structured ascii read](./structured_ascii_read.c)

### Binary format

[structured binary read](./structured_bin_read_nonseq.c)

[structured binary write](./structured_bin_write.c)
