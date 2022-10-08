# CS 420 by [Dr. Daniel Ray](https://una.edu/faculty/dray4.html)

I have provided a file (threadhello.cLinks to an external site.) that generates 10 threads, each of which simply prints out a "hello world" message before terminating.  Examine this code carefully.

Upload this file (you may use an ftp client or, better yet, look up how to use the scp command (prefered)) to your CS server account.

Compile this code using the following command: clang threadhello.c -lpthread

Run this command several times.  Submit at least 3 screenshots of different outputs that were all a result of running this code (same rules apply for screenshots as before).

DELIVERABLE #1:  >=3 screenshots of this code correctly running

I have also provided a file (threadarray.cLinks to an external site.).  Upload and run this program.  Run the program several times where you have increased the size of the array.

DELIVERABLE #2: a screenshot of this code correctly running

Change this program so that it fills the array values with (truly) random numbers between 1 and 100.  Then, change the program so that it makes use of five (5) threads to sum the values in the array.   

Hint: you may want to check that your five thread version is correctly working on known totals before updating your code to run on random values.

DELIVERABLE #3: your new program file
DELIVERABLE #4: a screenshot of your program running
