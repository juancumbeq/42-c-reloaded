
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

  #### Regular Expression Breakdown:
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

  #### Combined Regular Expression:
  - ``([0-9A-Fa-f]{2}:){5}([0-9A-Fa-f]{2})``
    - This entire regular expression matches MAC addresses in the standard format ``XX:XX:XX:XX:XX:XX``, where ``X`` is a hexadecimal digit (0-9, A-F, or a-f).

  #### Full Command Execution:
  - ``ifconfig -a`` outputs information about all network interfaces.
  - The output is piped (``|``) to ``grep -oE '([0-9A-Fa-f]{2}:){5}([0-9A-Fa-f]{2})'``.
  - grep searches the ``ifconfig`` output for patterns that match the regular expression.
  - ``grep -o`` ensures only the matched parts (MAC addresses) are printed.

  #### Result:
  - This command will display all MAC addresses from the network interfaces on your system, each on a new line. The MAC addresses will be in the format ``XX:XX:XX:XX:XX:XX``, where ``XX`` is a pair of hexadecimal digits.

  #### Another alternative:
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

  #### Detailed Steps:
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
  #### Result: 
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
  - To create a file named ``"\?$*'MaRViN'*$?\"`` that includes special characters, you need to properly escape those characters when using shell commands. Here’s how you can do it:

  #### Using Quoting and Escaping
  You can create the file using touch and properly quote or escape the filename:
  ```
  touch '"\\?$*'\''MaRViN'\''*$?\\"'
  ```
  Let's break down the quoting and escaping:
  - ``"`` and ``'``: Used to quote parts of the filename that contain special characters.
  - ``\'``: Escapes the single quote ``'`` character within a single-quoted string.
  - ``\\``: Escapes the backslash ``\`` character, which is necessary to include it in the filename.
  
  #### Example Explanation
  ```
  touch '"\\?$*'\''MaRViN'\''*$?\\"'
  ```
  This command uses single quotes (') to group parts of the filename that contain special characters (\, $, *, '). Inside the single quotes:

  - ``\\`` is the escaped backslash ``\``.
  - ``?\$*`` are literal characters.
  - ``'\''`` is the escaped single quote ``'``.

  This constructs the filename "\?$*'MaRViN'*$?\" correctly.

  ### Inserting ``42``
  - As we could see in a previous exercise to insert data into the "\?$*'MaRViN'*$?\" file we can execute the command: ``cat > "\?$*'MaRViN'*$?\" ``.
  - This command opens an input stream. To close that input stream use: ``CTRL + DD``

<br>
<br>

  ## EXERCISE 06: 
  ### Description
  - Create a function that displays the alphabet in lowercase, on a single line, by ascending order, starting from the letter ’a’.
  - Here’s how it should be prototyped: ``void ft_print_alphabet(void);``
  
  ### Notes
  ```
  #include <unistd.h>

  void ft_print_alphabet(void)
  {	
    char letter = 'a';
    while(letter <= 'z')
    {
      write(1, &letter, 1);
      letter++;
    }
  }

  int main(void)
  {
    ft_print_alphabet();	
    return(0);
  }
  ```
  - For C language the characters are also numbers, following the ASCII code. This is the reason we can do ``letter++`` because we are adding ``+1`` to the ASCII number that represents the ``a`` letter for the first loop iteration.

<br>
<br>

  ## EXERCISE 07: 
  ### Description
  - Create a function that displays all digits, on a single line, by ascending order.
  - Here’s how it should be prototyped: ``void ft_print_numbers(void)``;

  ### Notes
  ```
  #include <unistd.h>

  void ft_print_numbers(void)
  {
    int digit;
    digit = 48;

    while(digit <= 57)
    {
      write(1, &digit,1);
      digit++;
    }
  }

  int main(void)
  {
    ft_print_numbers();
    return(0);
  }
  ```
  - As we did in the previous exercise the graphical representation of a letter or a digit is based on the ASCII code. That's the reason the ``digit``variable starts with the 48 number, because this value equals the ``0``.


<br>
<br>

  ## EXERCISE 08: 
  ### Description
  - Create a function that displays ’N’ or ’P’ depending on the integer’s sign entered as a parameter. If n is negative, display ’N’. If n is positive or null, display ’P’.
  - Here’s how it should be prototyped: ``void ft_is_negative(int n)``
  
  ### Notes
  ```
  #include <unistd.h>

  void ft_is_negative(int n)
  {
    if(n<0)
    {
      write(1,"N", 1);
    }
    else
    {
      write(1, "P", 1);
    }
  }

  int main (void)
  {
    ft_is_negative(9);
  }
  ```


<br>
<br>

  ## EXERCISE 09: 
  ### Description
  - Create a function that takes a pointer to int as a parameter, and sets the value "42" to that int.
  - Here’s how it should be prototyped:``void ft_ft(int *nbr);``

  ### Notes
  ```
  #include <stdio.h>
  #include <unistd.h>

  void ft_ft(int *nbr)
  {
    *nbr = 42;
    printf("%d\n", *nbr);
  }

  int main(void)
  {
    int value;
    int *pointer = &value;

    ft_ft(pointer);
    return(0);
  }
  ```
  - ``int value`` : it is necessary to have a variable to store the number 42.
  - ``int *pointer = &value``: by this line we are accesing the memory address of the value variable, after that the pointer is created and initialized with the memory address obtained from value variable. Now the pointer variable stores a memory address.
  - ``ft_ft(pointer)``: the memory address is passed as an argument to the ``ft_ft`` function.
  - Inside the ``ft_ft`` function the memory address passed previously is assigned to the pointer ``nbr``. So, ``nbr ``points to ``value``.
  - ``*nbr``: means = the value in the memory addres pointed by nbr.
  - ``*nbr = 42``: means = assign 42 to the value in the memory address pointed by ``nbr``.
  
  #### Key Concept
  Dereference (``*nbr``): this concepts defines accesing and modifying the value stored in the memory address contained by the pointer ``nbr``.

  It is important to difference two scenarios:
  - ``int *nbr``: declares a pointer to a integer.
  - ``*nbr``: access the integer in the memory address pointed by ``nbr``.

  In short, when you do ``*nbr = 42``, you are not changing the memory address that ``nbr`` contains, but the value stored at that memory address. So, even though ``nbr`` is already initialized with the address of ``value``, you can use ``*nbr`` to assign a new value to value.

<br>
<br>

  ## EXERCISE 10: 
  ### Description
  - Create a function that swaps the value of two integers whose addresses are entered as parameters.
  - Here’s how it should be prototyped: ``void ft_swap(int *a, int *b);``
  
  ### Notes
  ```
  #include <unistd.h>
  #include <stdio.h>

  void ft_swap(int *a, int *b)
  {
    int num;
    num = *b;

    *b = *a;
    *a = num;
  }

  int main(void)
  {
    int x;
    int y;

    int *ptr_x = &x;
    int *ptr_y = &y;

    x = 10;
    y = 5;
    
    printf("Before SWAP\n");
    printf("%d\n", x);
    printf("%d\n", y);

    ft_swap(ptr_x, ptr_y);
    
    printf("After SWAP\n");
    printf("%d\n", x);
    printf("%d\n", y);
  }
  ```
  - It is important to initilize the pointer after using them as arguments.



<br>
<br>

  ## EXERCISE 11: 
  ### Description
  - Create a function ``ft_div_mod`` prototyped like this: ``void ft_div_mod(int a, int b, int *div, int *mod);``
  - This function divides parameters ``a`` by ``b`` and stores the result in the int pointed by div. It also stores the remainder of the division of ``a`` by ``b`` in the int pointed by ``mod``.
  
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
