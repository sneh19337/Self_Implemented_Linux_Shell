all: bin test shell externals

only_executables: shell externals bin

bin:
	mkdir -p ../bin

test:
	mkdir -p ../OS/folder_tester
	ln -sf OS/folder_tester/ ../"Linking to tester"
	echo "Hey welcome to the shell stimulator\n\I am happy to have you\n\n\n" > ../OS/file1.txt
	echo "These files are just for testing purpose\n\nthis is another one\n\n" > ../OS/file2.txt
	echo "Another testing file being creted " > ../OS/.testingdoc
	echo "" > ../OS/folder_tester/newfile.txt


shell: shell.c cd.c echo.c history.c
	gcc shell.c -o ../bin/shell

externals: ls date cat mkdir rm

ls: ls.c
	gcc ls.c -o ../bin/ls

date: date.c
	gcc date.c -o ../bin/date

cat: cat.c
	gcc cat.c -o ../bin/cat

mkdir: makeDir.c 
	gcc makeDir.c -o ../bin/mkdir

rm: rm.c
	gcc rm.c -o ../bin/rm


.PHONY: clean	
clean:
	rm -rf ../OS ../bin
	rm -f "../Linking to tester"
