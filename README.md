
  ## EXERCISE 00: OH YEAH, MOOORE...
  ### Description
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


  ### Notes
  - The first letter of every line indicates if it is a file, a directory or a link. As we can see the in the first line apperas a ``d`` at the very beginning indicating it is a directory.

  - To change the files and directories permissions the command ``chmod u=rw,g=r,o=r <file_name>`` can be used. As we know, the permissions are divided into three groups: user, group and others. 

  - To create a link the command: ``ln -s <origin> <destiny>`` must be used. Where origin is the file that represents the links and destiny is the file or directory where we are heading.

  - To modify the link permissions the command used previusly must be modified to avoid changing the destily file permissions: ``chmod -h u=rwx,g=rwx,o=rwx test6``.

  - The fifth column indicates the file weigth (1 byte for a letter and 1 byte for a break line), this is the reason the file test3 does not have content but its weight is 1. To ensure that a file does not have any new line character, the following command can be used: ``echo -n "a" > test3``

  - To change the hour and date the following command can be used: ``touch -t 202406012344 test3``. In the link case an ``-h`` must be added before the ``-t``.

  - The second column indicates the number of hard links to that file. In this example the hard links can be created using: ``ln test3 test3_hardlink``

  - The previous step adds metadata to the original file, this is indicated by the ``@``character after the permissions. To remove that metadata we must know them so to list them use the command: ``xattr test3``. After that, apply the command: ``xattr -d <attribute-name> test3``. If the erro: ``[Errno 13] Permission denied: 'test3'``is thrown, use the ``sudo`` before the command, it is due to permissions change.

<br>
<br>

  ## EXERCISE 01: Z
  ### Description
  - Create a file called z that returns "Z", followed by a new line, whenever the command ``cat`` is used on it:
    ```
    ?>cat z
    Z
    ?>
    ```
  
uii  ### Notes
  - There are various ways to create this file, the first one is using ``cat > z``. This creates write stream, to finish pres ``CTRL + D``
  - The second way is using ``echo "a" > z``. This command does not open a write stream, just saves the ``echo``content into the z file.

<br>
<br>

  ## EXERCISE 03: 
  ### Description
  - In a file called ``clean`` place the command line that will search for all files - in the current directory as well as in its sub-directories - with a name ending by ``~``, or with a name that start and end by ``#`.
  - The command line will show and erase all files found.
  - Only one command is allowed: no ``;`` or ``&&`` or other shenanigans.
  
  ### Notes
  - The resulting code is: ``find . -type f -name '*~' -print -delete -o -name '#*#' -print -delete``
  - Let's dive deep into the code:
    - ``find``: is the search command.
    - ``.`: indicates that the searching must be done in the current directory and subdirectories.
    - ``-type f``: this option is to search files only, not directories.
    - ``-name '*~'``: ``-name``allow us to specify a name pattern. '*~' represets the name pattern, indicating files with name ending with a ``'~'``.
    - ``-print -delete``: ``-print`` shows the found file name. ``-delete``deletes the found file. Both command are applied to the files with the indicated name pattern.
    - ``-o``: is the logical operator OR, used to add another searching condition.
    - ``-name '#*#'``: simila to the previour pattern, this command sets a name pattern to files with name starting and ending with a ``'*#'``. 

  - In other words, the command ``find . -type f -name '*~' -print -delete -o -name '*#' -print -delete`` is searching in the current directory and subdirectories all the files whose name is ending with ``~`` or stating and ending with ``#``. For every found file, executes a ``-print``and a ``-delete``.
sdfasdf
dfasd


<br>
<br>

  ## EXERCISE 04: 
  ### Description
  - Write a command line that searches for all file namess end with '.sh' (without the quotation marks) in the currect directory and all its sub-directories. It should display only the file names without the .sh.

```
./find_sh.sh | cat -e
find_sh
file1
file2
file3
```
 
  ### Notes
  - ``find .``: Starts the search from the current directory ``(.)``. Replace ``.`` with any other directory path if you want to search from a specific directory.
  - ``type f``: Specifies that you are interested only in regular files (not directories or other types of files).
  - ``name '*.sh'``: Searches for files whose names end with ``.sh``.
  - ``exec basename {} .sh \;``: Executes the ``basenam``e command on each found file ``({})``. ``basename`` is used to strip directory and suffix from filenames. The ``.`` before ``sh`` specifies the suffix to be removed ``(.sh)``. The ``\;`` at the end terminates the ``-exec`` command.

  - basename {} .sh removes the directory path and .sh extension from each file name.
';' terminates the -exec command properly.

   - Make sure to use ';' at the end of the -exec command to properly terminate it. The semicolon (;) needs to be escaped with a backslash (\) or quoted (';') to prevent the shell from interpreting it.

  - If you have a large number of files matching the criteria, you might see each file name printed on a new line.1






<br>
<br>

  ## EXERCISE 0: 
  ### Description
  - 
    ```
    ```
  
  ### Notes
  - 
