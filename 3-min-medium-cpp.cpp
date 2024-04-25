/*
Longest substring

We are going to have to iterate through the whole array

We can use a hash table and a count to possibly track non-repeating characters

we can use a for loop to iterate through the full array

through each iteration,
check if element is inside of the hashmap, if it is not increment count
and store it inside of the hashmap
increment max
and move to next element

we can have max and count

if we find an element within the hashmap
we clear the hashmap,
set the count to 1
and move to the next element

*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>


/*
We want to use the sliding window technique


*/


#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>


class Solution {
public:
	int lengthOfLongestSubstring(std::string s);
};


int Solution::lengthOfLongestSubstring(std::string s) {

	//We are going to use a hash set, which is a SET (dictionary in python)
	//which holds all unique values, .count returns true if it is already in teh set
	std::unordered_set<char> charSet;

	//We also need to hold a longest counter
	int longest = 0;

	//We want to set the left and right pointers for the sliding window
	int left = 0;
	int right = 0;

	//We want to iterate through the string array, we can use a while loop to do that
	//We can use the right pointer to iterate , we know we are finished when
	//right hits the null pointer

	while (s[right] != '\0') {

		//If we do not see a char inside of the array, we want to insert it
		//inside of the hashset and increment right
		if (!charSet.count(s[right])) {

			//Insert it inside of the hashset
			charSet.insert(s[right]);

			if (charSet.size() > longest) {
				longest = charSet.size();
			}

			right++;

		}//if we do  see it inside of the array
		else {

			//The first thing we want to do is remove the left pointer from the set
			while (charSet.count(s[right])) {
				charSet.erase(s[left]);
				left++;
			}

			//Once the duplicate layer has been removed from the set
			//The next thing we can do is reinsert it back into the set
			charSet.insert(s[right]);

			//then we can check the size of the set
			if (charSet.size() > longest) {
				longest = charSet.size();
			}

			right++;
		}



	}
	//now we can just return longest
	return longest;

}





int main() {

	Solution solution;

	/*std::unordered_set<char> charSet = { 'a','b', 'c', 'a', };

	std::cout << charSet.size();*/


	std::string s = "abcabcbb";
	std::string s1 = "bbbbb";
	std::string s2 = "pwwkew";
	std::string s3 = " ";
	std::string s4 = "dvdf";
	std::string s5 = "dabcdf";
	std::string s6 = "mississippi";

	std::cout << solution.lengthOfLongestSubstring(s6);


	// Time O(n), Space O(n)


	return 0;

}



