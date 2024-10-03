This is a way to convert a 8x8 (or any scale but only tested on 8x8) png such as one made in piskel to for display on an 8x8 (same as before, any should work but untested.) ws2812 led matrix.

You will need another piece of software called: A-VEKT Image CSV Converter (https://www.avekt.com/en-us/Software/ImageCSV) but it is free.

First. take your png and open it in this software.
then hit edit and decompose.
i close the a channel but if You are using rgbw led's this could be used to drive the W channel.

For each subsequent channel hit save as, change the extension to ".csv". 
save the channels as Red.csv, Blue.csv, Green.csv (you can save them by another name but you will need to adjust the file locators in combiner.py)
Save these in the same directory as combiner.py

once saved you can run combiner .py and should see a similar output to this:

  Your matrix is: 
  {{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}}, {{0,0,0},{0,0,0},{213,223,26},{0,0,0},{0,0,0},{213,223,26},{0,0,0},{0,0,0}}, {{0,0,0},{0,0,0},{213,223,26},{0,0,0},{0,0,0},{213,223,26},{0,0,0},{0,0,0}}, {{0,0,0},{0,0,0},    {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}}, {{223,78,26},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{223,78,26}}, {{223,78,26},{223,78,26},{223,78,26},{0,0,0},{0,0,0},{26,53,223},{223,78,26},{223,78,26}}, {{0,0,0},{26,53,223},      {223,78,26},{223,78,26},{223,78,26},{223,78,26},{0,0,0},{0,0,0}}, {{0,0,0},{26,53,223},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}}};

This output can then be copied into arduino.ino and pasted after the equals of the matrix variable (read the comments).

You must also include the neopixel library on arduino.
