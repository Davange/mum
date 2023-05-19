1. who : The ‘$ who’ command displays all the users who have logged into the system currently. As shown above, on my system I am the only user currently logged in.The thing tty2 is terminal line the user is using and the next line gives the current date and time

$ who
Output: harssh tty2 2017-07-18 09:32 (:0)
2. pwd : The ‘$pwd’ command stands for ‘print working directory’ and as the name says,it displays the directory in which we are currently (directory is same as folder for Windows OS users). 
In the output, we are harssh directory(folder for Windows OS that are moving to Linux),which is present inside the home directory.


 $ pwd
Output: /home/harssh
3. mkdir : The ‘$ mkdir’ stands for ‘make directory’ and it creates a new directory.We have used ‘$ cd’ (which is discussed below) to get into the newly created directory and again on giving ‘$ pwd’ command,we are displayed with the new ‘newfolder’ directory.

$ mkdir newfolder
$ cd newfolder
$ pwd
Output: /home/harssh/newfolder
4. rmdir : The ‘$ rmdir’ command deletes any directory we want to delete and you can remember it by its names ‘rmdir’ which stands for ‘remove directory’.

$ rmdir newfolder
5. cd : The ‘$ cd’ command stands for ‘change directory’ and it changes your current directory to the ‘newfolder’ directory.You can understand this a double-clicking a folder and then you do some stuff in that folder.

$ cd newfolder (assuming that there is a directory named 'newfolder' on your system)
6. ls : The ‘ls’ command simply displays the contents of a directory.

$ ls
Output: Desktop Documents Downloads Music Pictures Public Scratch Templates Videos
7. touch : The ‘$ touch’ command creates a file(not directory) and you can simple add an extension such as .txt after it to make it a Text File.

$ touch example
$ ls
Output: Desktop Documents Downloads Music Pictures Public Scratch Templates Videos example
Note: It is important to note that according to the Unix File structure, Unix treats all the stuff it has as a ‘file’, even the directories(folders) are also treated as a file.You will get to know more about this as you will further use Linux/Unix based OS 🙂 

8. cp : This ‘$ cp ‘ command stands for ‘copy’ and it simply copy/paste the file wherever you want to.In the above example, we are copying a file ‘file.txt’ from the directory harssh to a new directory new.

$ cp /home/harssh/file.txt /home/harssh/new/
9. mv : The ‘$ mv’ command stands for ‘move’ and it simply move a file from a directory to another directory.In the above example a file named ‘file.txt’ is being moved into a new directory ‘new’

$ mv /home/harssh/file.txt /home/harssh/new
10. rm : The ‘$ rm ‘ command for remove and the ‘-r’ simply recursively deletes file. Try ‘$ rm filename.txt’ at your terminal 🙂

$ rm file.txt
11. chmod : The ‘$ chmod’ command stands for change mode command.As there are many modes in Unix that can be used to manipulate files in the Unix environment.Basically there are 3 modes that we can use with the ‘chmod’ command 
1. +w (stands for write and it changes file permissions to write) 
2. +r (stands for read and it changes file permissions to read) 
3. +x (generally it is used to make a file executable)

$ chmod +w file.txt
$ chmod +r file.txt
$ chmod +x file.txt
12. cal : The ‘$ cal’ means calendar and it simply display calendar on to your screen.

$ cal
Output : July 2017
Su Mo Tu We Th Fr Sa
1
2 3 4 5 6 7 8
9 10 11 12 13 14 15
16 17 18 19 20 21 22
23 24 25 26 27 28 29
30 31
13. file : The ‘$ file’ command displays the type of file.As I mentioned earlier Linux treats everything as a file so on executing the command file on a directory(Downloads) it displays directory as the output

$ ls
Output: Desktop Documents Downloads Music Pictures Public Scratch Templates Videos
$ file Downloads
Output: Downloads: directory
14. sort : As the name suggests the ‘$ sort’ sorts the contents of the file according to the ASCII rules.

$ sort file
15. grep : grep is an acronym for ‘globally search a regular expression and print it’.The ‘$ grep’ command searches the specified input fully(globally) for a match with the supplied pattern and displays it. 
In the example, this would search for the word ‘picture’ in the file newsfile and if found,the lines containing it would be displayed on the screen.

$ grep picture newsfile
16. man : The ‘$ man’ command stands for ‘manual’ and it can display the in-built manual for most of the commands that we ever need.In the above example, we can read about the ‘$ pwd’ command.

$ man pwd
17. lpr : The ‘$ lpr’ command send a file to the printer for printing.

$ lpr new.txt
18. passwd : The ‘$ passwd’ command simply changes the password of the user.In above case ‘harssh’ is the user.

$ passwd
Output: Changing password for harssh.
(current) UNIX password:
19. clear : The ‘$ clear’ command is used to clean up the terminal so that you can type with more accuracy 🙂

$ clear
20. history : The ‘$ history’ command is used to get list of previous commands may be obtained by executing the following command. you can also use parameters like !n to re-execute the nth command, !! to executes the most recent command, and !cp this will execute the most recent command that starts with cp.

$ history 