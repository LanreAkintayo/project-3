Open the file
Read all the contents of the file inside a string array, let's call it contentArray
Loop through each element in the contentArray. Whenever you come accross a number as an element, 
Whenever you come across a number, use the element index (since we are inside a loop) and the actual element (since the actual element represents the number of files) to create a subset from that contentArray. 

For example; Let's say;
contentArrray = {2, 2, aaa 6, aa 5, 3, file 3, file 2, file 1} 

During the loop if you detect 3 (at index 4), slice that array from index 5 to index 7 and store that slice inside another array.

Then after obtaining that slice, loop through that slice and split each element of that slice into two subelements. The first subelement will represent the file name, the other will represent the ID.

Try to create another string array that will contain only file names that are not duplicate and also an array that contain all the IDs of those files that are not duplicate. 

