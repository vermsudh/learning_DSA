**Example 1:**

<pre><strong>Input:</strong> words = ["abc","car","ada","racecar","cool"]
<strong>Output:</strong> "ada"
<strong>Explanation:</strong> The first string that is palindromic is "ada".
Note that "racecar" is also palindromic, but it is not the first.
</pre>

**Example 2:**

<pre><strong>Input:</strong> words = ["notapalindrome","racecar"]
<strong>Output:</strong> "racecar"
<strong>Explanation:</strong> The first and only string that is palindromic is "racecar".
</pre>

**Example 3:**

<pre><strong>Input:</strong> words = ["def","ghi"]
<strong>Output:</strong> ""
<strong>Explanation:</strong> There are no palindromic strings, so the empty string is returned.
</pre>


---

1) First of all, we know that we have words of array. we would have to access each word in the vector first. So
   for(string word : words){

   }
   2) Once we have one word, we will check if that word is palindrome or not using 2 pointers approach.
   int left = 0;
   int right = word.length() - 1;
   while(left < right){
   if(word[left] != word[right]]]){

   return " ";
   word ++;

   }
   right --;
   left ++ ;

   }

   ---

   Lets create a function to check if the word is a palindrome or not?
2)
