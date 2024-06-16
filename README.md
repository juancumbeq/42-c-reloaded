
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

  ## EXERCISE 02: 
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


<br>
<br>

  ## EXERCISE 03: 
  ### Description
  - Write a command line that searches for all file namess end with ``'.sh'`` (without the quotation marks) in the currect directory and all its sub-directories. It should display only the file names without the ``.sh``.
  ```
  ./find_sh.sh | cat -e
  find_sh
  file1
  file2
  file3
  ```
 
  ### Notes
  - ``find .``: Starts the search from the current directory ``.``. Replace the ``.`` with any other directory path if you want to search from a specific directory.

  - ``type f``: Specifies that you are interested only in regular files (not directories or other types of files).

  - ``name '*.sh'``: Searches for files whose names end with ``.sh``.

  - ``exec basename {} .sh \;``: Executes the ``basename`` command on each found file ``{}``. ``basename`` is used to strip directory and suffix from filenames. The ``.`` before ``sh`` specifies the suffix to be removed ``.sh``. The ``\;`` at the end terminates the ``-exec`` command.

    - Make sure to use ``;`` at the end of the ``-exec`` command to properly terminate it. The semicolon ``;`` needs to be escaped with a backslash ``\`` or quoted '``;``' to prevent the shell from interpreting it.

    - If you have a large number of files matching the criteria, you might see each file name printed on a new line.

<br>
<br>

  ## EXERCISE 04: 
  ### Description
  - Write a command line that displays your machine’s MAC addresses. Each address must be followed by a line break.
  
  ### Notes
  - The command is:
  ```
  #!/bin/bash
  ifconfig -a | grep -oE '([0-9A-Fa-f]{2}:){5}([0-9A-Fa-f]{2})'
  ``` 

  - ``#!/bin/bash``: This is the shebang line, which specifies the script should be run using the Bash shell. It must be the first line in the script.

  - ``ifconfig -a``: ``ifconfig`` is a command-line utility used to configure network interfaces in Unix-like operating systems. The ``-a`` option tells ``ifconfig`` to display all interfaces, both active and inactive. This command will output a lot of information about all the network interfaces on your system, including their MAC addresses.

  - ``|``: This is a pipe operator. It takes the output of the command on its left (``ifconfig -a``) and passes it as input to the command on its right (``grep -oE '([0-9A-Fa-f]{2}:){5}([0-9A-Fa-f]{2})'``).

  - ``grep -oE '([0-9A-Fa-f]{2}:){5}([0-9A-Fa-f]{2})'``: ``grep`` is a command-line utility used to search for patterns within text. 
    - The ``-o`` option tells ``grep`` to only print the parts of the input that match the pattern, not the entire line.
    - The ``-E`` option enables extended regular expressions, which allow for more complex patterns.

  - ``'([0-9A-Fa-f]{2}:){5}([0-9A-Fa-f]{2})'``: This is the regular expression used by ``grep`` to find patterns in the output of ``ifconfig -a``.

  - Regular Expression Breakdown:
    - ``([0-9A-Fa-f]{2}:){5}``
      - ``[`` and ``]``: Define a character class, which in this case includes the characters 0-9, A-F, and a-f. This means it will match any single hexadecimal digit.
      - ``{2}``: Indicates that exactly 2 of the preceding characters should be matched. So, ``[0-9A-Fa-f]{2}`` matches exactly two hexadecimal digits.
      - ``:``: Matches a literal colon character.
      - ``(...)``: Groups the preceding pattern.
      - ``{5}``: Indicates that the grouped pattern (two hexadecimal digits followed by a colon) should be matched exactly 5 times.
    - ``([0-9A-Fa-f]{2})``
      - ``[0-9A-Fa-f]{2}``: As before, this matches exactly two hexadecimal digits.
      - ``(...)``: Groups the preceding pattern.
      - This matches the final pair of hexadecimal digits without a following colon.

  - Combined Regular Expression:
    - ``([0-9A-Fa-f]{2}:){5}([0-9A-Fa-f]{2})``
      - This entire regular expression matches MAC addresses in the standard format ``XX:XX:XX:XX:XX:XX``, where ``X`` is a hexadecimal digit (0-9, A-F, or a-f).

  - Full Command Execution:
    - ``ifconfig -a`` outputs information about all network interfaces.
    - The output is piped (``|``) to ``grep -oE '([0-9A-Fa-f]{2}:){5}([0-9A-Fa-f]{2})'``.
    - grep searches the ``ifconfig`` output for patterns that match the regular expression.
    - ``grep -o`` ensures only the matched parts (MAC addresses) are printed.

  - Result:
    - This command will display all MAC addresses from the network interfaces on your system, each on a new line. The MAC addresses will be in the format ``XX:XX:XX:XX:XX:XX``, where ``XX`` is a pair of hexadecimal digits.

  - Another alternative:
  ```
  #!/bin/bash
  ifconfig | grep 'ether' | cut -d ' ' -f 2 
  ```
    - ``grep 'ether'``: ``grep`` is a command-line utility used to search for patterns within text.
      - ``'ether'`` is the pattern to search for. This command searches the output of ``ifconfig`` for lines that contain the string ``'ether'``.
      - On most Unix-like systems, ``ifconfig`` displays MAC addresses on lines that contain the string ``'ether'``.
    - ``|``: Another pipe operator. It takes the output of the ``grep 'ether'`` command and passes it as input to the ``cut`` command.
    - ``cut -d ' ' -f 2``: ``cut`` is a command-line utility used to extract sections from each line of input.
      - ``-d ' '`` specifies the delimiter, which in this case is a space character. This tells ``cut`` to consider spaces as the field delimiter.
      - ``-f 2`` specifies the field to extract. This tells ``cut`` to extract the second field from each line of input.

    - Detailed Steps:
      - ``ifconfig`` Output: The ifconfig command generates output that includes various details about network interfaces, including MAC addresses. For example:
      ```
      en0: flags=8863<UP,BROADCAST,SMART,RUNNING,SIMPLEX,MULTICAST> mtu 1500
              ether aa:bb:cc:dd:ee:ff 
              inet 192.168.1.2 netmask 0xffffff00 broadcast 192.168.1.255
              ...
      en1: flags=8863<UP,BROADCAST,SMART,RUNNING,SIMPLEX,MULTICAST> mtu 1500
              ether 11:22:33:44:55:66
              inet 192.168.1.3 netmask 0xffffff00 broadcast 192.168.1.255
              ...
      ```
      - ``grep 'ether'`` Output:``grep`` searches for lines containing the string 'ether'. From the above example, it extracts:
      ```
      ether aa:bb:cc:dd:ee:ff 
      ether 11:22:33:44:55:66
      ```

      - ``cut -d ' ' -f 2`` Output: ``cut`` uses space as the delimiter and extracts the second field from each line. Given the lines:
      ```
      ether aa:bb:cc:dd:ee:ff 
      ether 11:22:33:44:55:66
      ```
      It extracts:
      ```
      aa:bb:cc:dd:ee:ff
      11:22:33:44:55:66
      ```
    - Result: 
      - The command sequence ifconfig | grep 'ether' | cut -d ' ' -f 2 will output the MAC addresses of the network interfaces, each on a new line, by extracting the second field (the MAC address) from lines containing the word 'ether'.

<br>
<br>

  ## EXERCISE 05: 
  ### Description
  - Create a file containing only "42", and NOTHING else.
  - Its name will be: ``"\?$*'MaRViN'*$?\"``
  - Example:
    ```
    $>ls -lRa *MaRV* | cat -e
    -rw---xr-- 1 75355 32015 2 Oct 2 12:21 "\?$*'MaRViN'*$?\"$
    $>
    ```
  
  ### Notes
  - To create a file named "\?$*'MaRViN'*$?\" that includes special characters, you need to properly escape those characters when using shell commands. Here’s how you can do it:

Using Quoting and Escaping
You can create the file using touch and properly quote or escape the filename:

sh
Copiar código
touch '"\\?$*'\''MaRViN'\''*$?\\"'
Let's break down the quoting and escaping:

" and ': Used to quote parts of the filename that contain special characters.
\': Escapes the single quote ' character within a single-quoted string.
\\: Escapes the backslash \ character, which is necessary to include it in the filename.
Example Explanation
sh
Copiar código
touch '"\\?$*'\''MaRViN'\''*$?\\"'
This command uses single quotes (') to group parts of the filename that contain special characters (\, $, *, '). Inside the single quotes:

\\ is the escaped backslash (\).
?\$* are literal characters.
'\'' is the escaped single quote (').
This constructs the filename "\?$*'MaRViN'*$?\" correctly.

Verification
After running the touch command, you can verify that the file was created using:

sh
Copiar código
ls -l '"\\?$*'\''MaRViN'\''*$?\\"'
This ls command uses similar quoting and escaping to correctly reference the filename.

Conclusion
By properly quoting and escaping special characters, you can create files with names that include characters like quotes, backslashes, and special symbols in the shell. This method ensures that the shell interprets the filename correctly and passes it as a literal string to the command.


<br>
<br>

  ## EXERCISE 0: 
  ### Description
  - 
    ```
    ```
  
  ### Notes
  - 

<br>
<br>

  ## EXERCISE 0: 
  ### Description
  - 
    ```
    ```
  
  ### Notes
  - 


<br>
<br>

  ## EXERCISE 0: 
  ### Description
  - 
    ```
    ```
  
  ### Notes
  - 


<br>
<br>

  ## EXERCISE 0: 
  ### Description
  - 
    ```
    ```
  
  ### Notes
  - 


<br>
<br>

  ## EXERCISE 0: 
  ### Description
  - 
    ```
    ```
  
  ### Notes
  - 
