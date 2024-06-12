
  ## EXERCISE 00: OH YEAH, MOOORE...
  - Create the following files and directories. Do what's necessary so that when you use the ``ls -l``command in your directory, the output will look like this:
  ```
  %> ls -l
  total XX
  drwx--xr-x 2 XX XX XX Jun 1 20:47 test0
  -rwx--xr-- 1 XX XX 4 Jun 1 21:46 test1
  dr-x---r-- 2 XX XX XX Jun 1 22:45 test2
  -r-----r-- 2 XX XX 1 Jun 1 23:44 test3
  -rw-r----x 1 XX XX 2 Jun 1 23:43 test4
  -r-----r-- 2 XX XX 1 Jun 1 23:44 test5
  lrwxrwxrwx 1 XX XX 5 Jun 1 22:20 test6 -> test0
  %>
  ```
  - About the hours, it will be accepted if the year is displayed in the case of the exercise’s date (1 Jun) is outdated by six month or more.
  - Once you’ve done that, run tar -cf exo.tar * to create the file to be submitted.


  Notes:
  - The first letter of every line indicates if it is a file, a directory or a link. As we can see the in the first line apperas a ``d`` at the very beginning indicating it is a directory.

  - To change the files and directories permissions the command ``chmod u=rw,g=r,o=r <file_name>`` can be used. As we know, the permissions are divided into three groups: user, group and others. 

  - To create a link the command: ``ln -s <origin> <destiny>`` must be used. Where origin is the file that represents the links and destiny is the file or directory where we are heading.

  - To modify the link permissions the command used previusly must be modified to avoid changing the destily file permissions: ``chmod -h u=rwx,g=rwx,o=rwx test6``.

  - The fifth column indicates the file weigth (1 byte for a letter and 1 byte for a break line), this is the reason the file test3 does not have content but its weight is 1. To ensure that a file does not have any new line character, the following command can be used: ``echo -n "a" > test3``

  - To change the hour and date the following command can be used: ``touch -t 202406012344 test3``. In the link case an ``-h`` must be added before the ``-t``.

  - The second column indicates the number of hard links to that file. In this example the hard links can be created using: ``ln test3 test3_hardlink``

  - The previous step adds metadata to the original file, this is indicated by the ``@``character after the permissions. To remove that metadata we must know them so to list them use the command: ``xattr test3``. After that, apply the command: ``xattr -d <attribute-name> test3``. If the erro: ``[Errno 13] Permission denied: 'test3'``is thrown, use the ``sudo`` before the command, it is due to permissions change.