/*ls: Lists files and directories in the current directory.
cd: Changes the current directory.
pwd: Prints the current working directory.
mkdir: Creates a new directory.
rm: Removes files and directories.
cp: Copies files and directories.
mv: Moves or renames files and directories.
cat: Concatenates and displays the contents of a file.
grep: Searches for a specified pattern in files.
find: Searches for files and directories based on various criteria.
chmod: Changes the permissions of files and directories.
chown: Changes the ownership of files and directories.
tar: Archives files and directories into a tarball.
gzip: Compresses files.
gunzip: Decompresses files compressed with gzip.
ssh: Connects to a remote server via Secure Shell (SSH).
scp: Copies files between local and remote systems using SSH.
wget: Downloads files from the web.
top: Displays real-time system information and processes.
man: Displays the manual page of a command*/

/*Write down Linux commands for following statements:
i. Redirect the output of ls command to a file named outfile. Use this as an
input file
for remaining commands. 
ii. To select the lines in a file which has digit as one of the character in that
line and redirect the output to the file named list.
 iii. Assign execute permission to owner and remove read permission from
other for an ordinary file named test by relative way. 
iv. Create an alias named rm that always deletes file interactively. v. Count the currently login users */

1) ans   ls > outfile
2) ans   grep '[0-9]' outfile > list
3) ans   chmod u+x,go-r test
4) ans   alias rm='rm -i' //This alias will make the rm command prompt for confirmation before deleting each file.
5) ans   who | wc -l  //This command uses the who command to list the currently logged-in users, and the wc -l command counts the number of lines, which corresponds to the number of logged-in users.
 



///Write down Linux commands for following statements:
i. Redirect the output of cat command to a file named outfile. Use this as
an input file
for remaining commands. 
ii. List all hidden files under current directory and store in “hidden” file
iii. Assign write permission to owner and remove execute permission from
other for an ordinary file named test by absolute way. iv. To create soft and hard link for given file
v. To convert lowercase to upper case of a given file
vi. To extract 1st and 10th character of a given file
vii. To display how many times lines are repeated in a given


1) ans cat > outfile//After executing this command, you can enter the content you want to store in outfile. Press Ctrl+D to save the input and exit.
2) ans ls -a | grep "^\." > hidden//This command uses ls -a to list all files (including hidden ones) and grep "^\." to filter out only the hidden files starting with a dot (.) and redirects the output to the file hidden
3) ans chmod u+w,o-x test
4) ans ln -s <source_file> <soft_link_name>
ln <source_file> <hard_link_name>
5) ans tr '[:lower:]' '[:upper:]' < input_file > output_file
6) ans cut -c 1,10 input_file
7) ans sort input_file | uniq -c
