
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
  
  ### Notes
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

  #### Another alternative:
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
  ```
  #include <unistd.h>
  #include <stdio.h>

  void ft_div_mod(int a, int b, int *div, int *mod)
  {
    *div = a / b;
    *mod = a % b;
  }

  int main(void)
  {
    int x = 10;
    int y = 3;
    int div;
    int mod;

    int *ptr_div = &div;
    int *ptr_mod = &mod;

    ft_div_mod(x, y, ptr_div, ptr_mod);

    printf("%d\n", x);
    printf("%d\n", y);
    printf("%d\n", div);
    printf("%d\n", mod);
  }
  ```
  - ``ft_div_mod(x, y, &div, &mod);``: This is another alternative to pass the memory address to the fuction ``ft_div_mod``, without declaring a initilizing a pointer.

<br>
<br>

  ## EXERCISE 12: 
  ### Description
  - Create an iterated function that returns a number. This number is the result of a factorial operation based on the number given as a parameter.
  - If there’s an error, the function should return 0.
  - Here’s how it should be prototyped: ``int ft_iterative_factorial(int nb);``
  - Your function must return its result in less than two seconds.
    ```
    ```
  
  ### Notes
  ```
  #include <unistd.h>
  #include <stdio.h>

  int ft_iterative_factorial(int nb)
  {
    int sum;
    sum = 1;

    while(nb>0)
    {
      sum *= nb;
      nb--;
    }
    return sum;
  }

  int main(void)
  {
    int num = 5;
    int sum;
    sum = ft_iterative_factorial(num);
    printf("%d\n", sum);
  }
  ```
  - Another option is to do the following: ``sum = nb;``. By this way we are initializing the sum variable to the nb variable so in the while loop we can do:
  ```
  while (nb > 1)
	{
		nb--;
		res *= nb;
	}
  ```
  - Using this method we are saving an iteration.

<br>
<br>

  ## EXERCISE 13: 
  ### Description
  - Create a recursive function that returns the factorial of the number given as a parameter.
  - If there’s an error, the function should return 0.
  - Here’s how it should be prototyped: ``int ft_recursive_factorial(int nb);``
  
  ### Notes
  ```
  #include <unistd.h>
  #include <stdio.h>

  int ft_recursive_factorial(int nb)
  {
      if (nb < 0)
          return 0;
      if (nb == 0)
          return 1;
      if (nb > 1)
          nb *= ft_recursive_factorial(nb - 1);
      return nb;
  }

  int	main(void)
  {
    int num = 5;
    int sum;
    sum = ft_recursive_factorial(num);
    printf("%d\n", sum);
    return (0);
  }
  ```

  #### Explanation of the Code
  Base Cases:
  - If ``nb < 0``, it returns 0, indicating that the factorial of a negative number is not defined.
  - If ``nb == 0``, it returns 1, based on the definition of 0! = 1.

  Recursive Case:
  - If ``nb > 1``, the function calls itself with ``nb - 1`` and multiplies the current value of ``nb`` by the result of this recursive call.
  
  #### Iteration by Iteration Breakdown for ``nb = 5``
  Let's follow the execution when nb is 5.
  - Iteration 1
    - Function Call: ``ft_recursive_factorial(5)``
    - Condition: ``nb > 1`` is true.
    - Action: ``5 * ft_recursive_factorial(4)``
  - Iteration 2
    - Function Call: ``ft_recursive_factorial(4)``
    - ondition: ``nb > 1`` is true.
    - Action: ``4 * ft_recursive_factorial(3)``
  - Iteration 3
    - Function Call: ``ft_recursive_factorial(3)``
    - Condition: ``nb > 1`` is true.
    - Action: ``3 * ft_recursive_factorial(2)``
  - Iteration 4
    - Function Call: ``ft_recursive_factorial(2)``
    - Condition: ``nb > 1`` is true.
    - Action: ``2 * ft_recursive_factorial(1)``
  - Iteration 5
    - Function Call: ``ft_recursive_factorial(1)``
    - Condition: ``nb > 1`` is false.
    - Return Value: Since ``nb == 1`` is true, the function returns ``1``.


  #### Unwinding the Recursion
  Now, the recursion starts unwinding, and the values are multiplied:

  - Returning from Iteration 5: ``ft_recursive_factorial(1)`` returns 1.
    - Calculation: ``2 * 1 = 2``
    - Returning from Iteration 4: ``ft_recursive_factorial(2)`` returns 2.

  - Returning from Iteration 4: ``ft_recursive_factorial(2)`` returns 2.
    - Calculation: ``3 * 2 = 6``
    - Returning from Iteration 3: ``ft_recursive_factorial(3)`` returns 6.

  - Returning from Iteration 3: ``ft_recursive_factorial(3)`` returns 6.
    - Calculation: ``4 * 6 = 24``
    - Returning from Iteration 2: ``ft_recursive_factorial(4)`` returns 24.

  - Returning from Iteration 2: ``ft_recursive_factorial(4)`` returns 24.
    - Calculation: ``5 * 24 = 120``
    - Returning from Iteration 1: ``ft_recursive_factorial(5)`` returns 120.

  #### Summary
  The function call ``ft_recursive_factorial(5)`` ultimately returns 120, which is the factorial of 5.

  #### Full Recursion Tree
  ```
  ft_recursive_factorial(5)
    -> 5 * ft_recursive_factorial(4)
        -> 4 * ft_recursive_factorial(3)
            -> 3 * ft_recursive_factorial(2)
                -> 2 * ft_recursive_factorial(1)
                    -> 1 (base case)
  ```
  Multiplying the results as the recursion unwinds:
  5 * (4 * (3 * (2 * 1))) = 120



<br>
<br>

  ## EXERCISE 14: 
  ### Description
  - Create a function that returns the square root of a number (if it exists), or 0 if the square root is an irrational number.
  - Here’s how it should be prototyped: ``int ft_sqrt(int nb);``
  - Your function must return its result in less than two seconds.

  ### Notes
  ```
  #include <stdio.h>
  #include <unistd.h>

  int	ft_sqrt(int nb)
  {
    int	x;

    x = 0;
    if (nb <= 0)
      return (0);
    if (nb == 1)
      return (1);
    while (x <= nb / 2)
    {
      if ((x * x) == nb)
        return (x);
      x++;
    }
    return (0);
  }

  int	main(void)
  {
    int num = 26;
    int sqrt;
    sqrt = ft_sqrt(num);
    printf("%d\n", sqrt);
    return (0);
  }
  ```
  
  #### Variable Initialization
  ``int x = 0;``: this initializes the variable x to 0. This variable will be used to iterate and find the square root.

  #### Handling Non-positive Numbers
  ```
  if (nb <= 0)
    return (0);
  ```
  If the input number nb is less than or equal to 0, the function returns 0 because the square root of non-positive numbers is not defined in this context.

  #### Special Case for 1
  ```
  if (nb == 1)
      return (1);
  ```
  If the input number is 1, the function returns 1, since the square root of 1 is 1.

  ### Iterative Search for Square Root:
  ```
  while (x <= nb / 2)
  {
      if ((x * x) == nb)
          return (x);
      x++;
  }
  return (0);
  ```
  - The while loop iterates through values of ``x`` from 0 to ``nb / 2``.
  - For each value of ``x``, it checks if ``x * x`` equals nb.
    - If true, it returns ``x`` because it found the integer square root.
  - If no such ``x`` is found, the loop exits, and the function returns 0.
  - If the loop completes without finding an integer whose square is ``nb``, the function returns 0.

  #### Detailed Example: ``nb = 26``
  Let's walk through the code execution for ``nb = 26``.

  - Initialization:
    - ``x`` is initialized to 0.
    - The input ``nb`` is 26.

  - First Condition Check:
    - ``nb <= 0`` is false, so the function proceeds.

  - Second Condition Check:
    - ``nb == 1`` is false, so the function proceeds.
  
  - While Loop:
    - The loop runs`` while x <= 26 / 2`` (i.e., ``x <= 13``).

  - Iterations:
    - For each iteration, the function checks if ``x * x == 26``.
    ```
    x = 0 -> 0 * 0 = 0
    x = 1 -> 1 * 1 = 1
    x = 2 -> 2 * 2 = 4
    x = 3 -> 3 * 3 = 9
    x = 4 -> 4 * 4 = 16
    x = 5 -> 5 * 5 = 25
    x = 6 -> 6 * 6 = 36
    ```
    - None of these values (from ``x = 0`` to ``x = 6``) satisfy the condition ``x * x == 26``.
    - The loop exits after ``x`` exceeds 13.

  - Return Statement:
    - Since no integer ``x`` was found such that`` x * x == 26``, the function returns 0.

<br>
<br>

  ## EXERCISE 15: 
  ### Description
  - Create a function that displays a string of characters on the standard output.
  - Here’s how it should be prototyped: ``void ft_putstr(char *str);``
  
  ### Notes
  - Let's break down the given code step by step, explaining each function and how they work together.

  #### Code Breakdown
  - Function: ``ft_putstr``
    ```
    void ft_putstr(char *str)
    {
        while (*str != '\0')
        {
            ft_putchar(*str);
            str++;
        }
    }
    ```
    - Purpose: This function writes a string ``str`` to the standard output, character by character.
    - Parameters: ``char *str`` - a pointer to the string to be written.
    - Loop: ``while (*str != '\0')``
      - The loop continues until the null terminator ('\0') is encountered, which marks the end of the string.
    - Inside the Loop:
      - ``ft_putchar(*str);`` - Calls ``ft_putchar`` to write the current character pointed to by ``str``.
      - ``str++;`` - Moves the pointer to the next character in the string.
  
  - Main Function
    ```
    int main(void)
    {
        char *str;

        str = "Hola";
        ft_putstr(str);
        return (0);
    }
    ```
    - Purpose: The main function is the entry point of the program.
    - Variable Declaration: ``char *str;`` - Declares a pointer to a character.
    - String Assignment: ``str = "Hola";`` - Assigns the string "Hola" to the pointer str.
    - Function Call: ``ft_putstr(str);`` - Calls ``ft_putstr`` to write the string "Hola" to the standard output.
    - Return Statement: ``return (0);`` - Indicates that the program terminated successfully.

  #### Keys
  - ``char *str;``:  pointer declaration, this pointer will store a memory address.
  - ``str = "Hola";``: the string "Hola" is stored on the read-only section of memory. At the same time the pointer is initialized with the memory address of the first letter of the string "Hola".
  - ``ft_putstr(str);``: the memory address is passed to the function ``ft_putstr()``
  - ``void	ft_putstr(char *str)``: the memory address is stores inside the pointer called ``str``.
  - ``while (*str != '\0')``: every iteration we are checking that the value of the memory address pointed by the pointer in not null terminator.
  - ``ft_putchar(*str);``: the value stored in the memory address pointed by the pointer is sent to the ``ft_putchar``fuction.
  - ``str++;``: we are incrementing (+1) the memory address stored in the pointer. This allow us to access the next character.

<br>
<br>

  ## EXERCISE 16: 
  ### Description
  - Reproduce the behavior of the function strlen (man strlen)
  - Here’s how it should be prototyped: ``int ft_strlen(char *str);``
  
  ### Notes
  ```
  #include <stdio.h>
  #include <unistd.h>

  int	ft_strlen(char *str)
  {
    int	i;

    i = 0;
    while (*str != '\0')
    {
      i++;
      str++;
    }
    return (i);
  }

  int	main(void)
  {
    int len = 0;
    char *str = "Hola";

    len = ft_strlen(str);

    printf("%d\n", len);
    return (0);
  }
  ```

<br>
<br>

  ## EXERCISE 17: 
  ### Description
  - Reproduce the behavior of the function strcmp (man strcmp).
  - Here’s how it should be prototyped: ``int ft_strcmp(char *s1, char *s2);``
  
  ### Notes
  ```
  #include <stdio.h>
  #include <unistd.h>

  int	ft_strcmp(char *s1, char *s2)
  {
    int	cmp;

    while (*s1 != '\0' && *s2 != '\0')
    {
      cmp = *s1 - *s2;
      if (cmp == 0)
      {
        s1++;
        s2++;
      }
      else
      {
        return (*s1 - *s2);
      }
    }
    return (*s1 - *s2);
  }

  int	main(void)
  {
    char *str1 = "Holaa";
    char *str2 = "Hola";
    int cmp;

    cmp = ft_strcmp(str1, str2);

    printf("%d\n", cmp);
    return (0);
  }
  ```
  - The ``strcmp`` function in the C language is used to compare two strings. Here is a detailed explanation of how it works:

  #### Parameters:

  - str1: A constant pointer to the first string to be compared.
  - str2: A constant pointer to the second string to be compared.

  #### Behavior:
  - The function compares the characters of both strings (str1 and str2) one by one.
  - It starts with the first characters of both strings and advances until it finds a differing character or reaches the end of one of the strings.

  #### Return value:
  - The function returns an integer value based on the comparison:
    - Less than zero (< 0): If str1 is less than str2. This means that the first differing character has a lower ASCII value in str1 than in str2.
    - Equal to zero (== 0): If str1 is equal to str2. This means that both strings are identical in content and length.
    - Greater than zero (> 0): If str1 is greater than str2. This means that the first differing character has a higher ASCII value in str1 than in str2.

  #### Termination:
  - The comparison continues until a difference is found in the corresponding characters of the two strings, or until the null terminators ('\0') of both strings are reached simultaneously, indicating that both strings have the same length and content.

  #### Additional Details
    - Case Sensitivity: The strcmp function distinguishes between uppercase and lowercase letters. For example, 'A' and 'a' are considered different due to their different ASCII values.
    - Safety: strcmp does not perform any boundary checks on the strings. It assumes that both strings are properly null-terminated ('\0').

  #### One string reaches null terminator first
  - Scenario
    - str1 is shorter and reaches its null terminator before str2.
    - str2 is longer and still has characters after the position where str1 ends.

  - Explanation
    - Reaching the null terminator: When strcmp encounters the null terminator in one string but not in the other, the null terminator ('\0', which is essentially a character with ASCII value 0) is compared with the corresponding character in the longer string.

  - Return Value
    - If str1 reaches the null terminator first, strcmp will return a negative value. This is because the null terminator ('\0', ASCII value 0) is less than any other character in str2 that it is compared with.
    - Conversely, if str2 reaches the null terminator first, strcmp will return a positive value. This is because the null terminator in str2 will be less than the corresponding character in str1.


<br>
<br>

  ## EXERCISE 18: 
  ### Description
  - We’re dealing with a program here, you should therefore have a function main in
  your .c file.
  - Create a program that displays its given arguments.
  - Example:
  ```
  $>./a.out test1 test2 test3
  test1
  test2
  test3
  $>
  ```
  
  ### Notes
  ```
  #include <stdio.h>
  #include <unistd.h>

  void	ft_putchar(char c)
  {
    write(1, &c, 1);
  }

  int	main(int argc, char *argv[])
  {
    int		i;
    char	*str;

    i = 1;
    while (i < argc)
    {
      str = argv[i];
      while (*str != '\0')
      {
        ft_putchar(*str);
        str++;
      }
      i++;
      ft_putchar('\n');
    }
    if (argc > 0)
    {
      printf("%d\n", argc);
    }
    return (0);
  }
  ```
  - ``argc``: this integer makes reference to the argumentos counter, and tell us how many arguments are being given by the command line. The command ``./a.out`` counts as one argument.
  
  - ``argv[]``: is an array of pointers, where each pointer indicates the memory address of the first letter of every argument given.

  - ``str = argv[i];``: by this line we are assigning a memory address taken from the pointers array to an empty pointer variable.

  #### ``*argv[] vs **argv```
  - Pointer to Pointer:
    - A pointer to a pointer (e.g., ``char **p``) is a variable that holds the address of another pointer.

    - If ``char *p`` is a pointer to a ``char``, then ``char **p`` is a pointer to ``char *``, meaning ``**p`` would ultimately give you a ``char``.

  - Arrays and Pointers:
    - An array name in C (e.g., ``char arr[]``) acts like a pointer to the first element of the array.

    - For example, ``char arr[10]`` and ``char *arr`` can be used similarly in many contexts because the array name decays to a pointer to its first element.

<br>
<br>

  ## EXERCISE 19: 
  ### Description
  - We’re dealing with a program here, you should therefore have a function main in your .c file.
  - Create a program that displays its given arguments sorted by ascii order.
  - It should display all arguments, except for ``argv[0]``.
  - All arguments have to have their own line.
  
  ### Notes
  ```
  #include <unistd.h>

  void ft_putchar(char c)
  {
    write(1, &c, 1);
  }

  void	print_str(char *str)
  {
    while (*str)
    {
      ft_putchar(*str);
      str++;
    }
  }

  int	ft_strcmp(char *str1, char *str2)
  {
    while (*str1 && *str2 && *str1 == *str2)
    {
      str1++;
      str2++;
    }
    return (*str1 - *str2);
  }

  void	print_args(int argc, char **argv)
  {
    int	i;

    i = 1;
    while (i < argc)
    {
      print_str(argv[i]);
      ft_putchar('\n');
      i++;
    }
  }

  int	main(int argc, char **argv)
  {
    int		i;
    int		j;
    char	*aux;

    i = 1;
    while (i < argc)
    {
      j = i + 1;
      while (j < argc)
      {
        if (ft_strcmp(argv[i], argv[j]) > 0)
        {
          aux = argv[i];
          argv[i] = argv[j];
          argv[j] = aux;
        }
        j++;
      }
      i++;
    }
    print_args(argc, argv);
    return (0);
  }
  ```

  #### Step-by-Step Explanation
  - Variable Declarations and Initializations
    - Variable Declarations:
      ```
      int i;
      int j;
      char *aux;
      ```
      - ``i`` and ``j`` are loop indices.
      - ``aux`` is a pointer to char used as a temporary variable for swapping pointers to strings.

  - First Loop (``i``)
    - Initialize ``i``:
      ```
      i = 1;
      ```
      - ``i`` is initialized to 1 to skip the first argument (``argv[0]``), which is the program name.

    - Outer Loop:
      ```
      while (i < argc)
      {
          // Inner loop code
          i++;
      }
      ```
      - This loop iterates from ``i = 1`` to ``i < argc``, ensuring that it processes all command-line arguments.

    - Second Loop (``j``)
      - Initialize ``j``:
        ```
        j = i + 1;
        ```
        - For each ``i``, ``j`` is initialized to ``i + 1``, so ``j ``points to the next argument in the list. This allows comparing ``argv[i]`` with all subsequent elements in the list.

      - Inner Loop: 
        ```
        while (j < argc)
        {
            // Comparison and swap code
            j++;
        }
        ```
        - This loop iterates from ``j = i + 1`` to ``j < argc``, comparing the current argument ``argv[i]`` with each subsequent argument ``argv[j]``.

    - Comparison and Swapping
      - String Comparison:
        ```
        if (ft_strcmp(argv[i], argv[j]) > 0)
        {
            aux = argv[i];
            argv[i] = argv[j];
            argv[j] = aux;
        }
        ```
        - ``ft_strcmp(argv[i], argv[j])`` compares the strings pointed to by ``argv[i]`` and ``argv[j]``.
        - If ``argv[i]`` is lexicographically greater than ``argv[j]`` (i.e., ``ft_strcmp`` returns a positive value), the pointers are swapped to ensure ``argv[i]`` is less than or equal to ``argv[j]``.

      - Swapping Pointers:
        ```
        aux = argv[i];
        argv[i] = argv[j];
        argv[j] = aux;
        ```
          - ``aux`` temporarily stores the pointer ``argv[i]``.
          - ``argv[i]`` is then assigned the value of ``argv[j]``.
          - Finally, ``argv[j]`` is assigned the value of ``aux`` (the original ``argv[i]``).

    - Printing Sorted Arguments
      - Print Sorted Arguments:
        ```
        print_args(argc, argv);
        ```
        - After sorting the arguments, ``print_args`` is called to print each argument. This function iterates through ``argv`` from ``argv[1]`` to ``argv[argc-1]`` and prints each argument on a new line.

    - Return Statement
      - Return from main:
        ```
        return (0);
        ```
        - The main function ``returns 0``, indicating that the program terminated successfully.

  #### Summary of the main Function
  - he main function receives the command-line arguments (argc and argv).
  - It uses a bubble sort algorithm to lexicographically sort the command-line arguments.
  - It iterates over the arguments with two nested loops, comparing and swapping the arguments using a string comparison function (ft_strcmp).
  - After sorting, it prints the sorted arguments using the print_args function.
  - Finally, it returns 0 to indicate successful program execution.

<br>
<br>

  ## EXERCISE 20: 
  ### Description
  - 
  
  ### Notes
  - 
    ```
    ```



<br>
<br>

  ## EXERCISE 21: 
  ### Description
  - 
  
  ### Notes
  - 
    ```
    ```



<br>
<br>

  ## EXERCISE 22: 
  ### Description
  - 
  
  ### Notes
  - 
    ```
    ```

<br>
<br>

  ## EXERCISE 23: 
  ### Description
  - 
  
  ### Notes
  - 
    ```
    ```

<br>
<br>

  ## EXERCISE 24: 
  ### Description
  - 
  
  ### Notes
  - 
    ```
    ```
<br>
<br>

  ## EXERCISE 25: 
  ### Description
  - 
  
  ### Notes
  - 
    ```
    ```


<br>
<br>

  ## EXERCISE 26: 
  ### Description
  - 
  
  ### Notes
  - 
    ```
    ```


<br>
<br>

  ## EXERCISE 27: 
  ### Description
  - 
  
  ### Notes
  - 
    ```
    ```


