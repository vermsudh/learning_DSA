# from collections import Counter


# def isAnagram():

#     s = input("type your string : ")
#     t = input("Type your second sring: ")

#     s_dict = dict(Counter(s))
#     t_dict = dict(Counter(t))

#     if len(s) == len(t):
#         if s_dict == t_dict:
#             print("This word is Anagram")
#     else:
#         return "Both stings are not equal, hence they are not Anagram word"


# print(isAnagram())


class Solution(object):
    def isAnagram(self, s, t):
        if len(s) != len(t):
            return False

        # Firs we are going to create the hasmaps
        map_s = {}
        map_t = {}

        # Then we are going to iterate over the string
        # and add the keys and values and store it inside
        # hashmps which are map_s and map_t

        for char in s:
            map_s[char] = map_s.get(char, 0) + 1
            # the reason we used map_s.get is because we need to
            # check if that value is present or not initially
            # if we do not check this, and add the value directly
            # it will throw us an error.

        # Now we will iterate over the secong string
        for char in t:
            map_t[char] = map_t.get(char, 0) + 1

        # Now we iterate over both the hashmpas to check
        # if the keys and values are matching or not?

        for key in map_t:
            if map_s[key] != map_t.get(key, 0):
                # The reason we are using .get method
                # is to check if all the keys/values are present in
                #  each hashmaps or not?
                # lets say if we have one character inside
                # one hasmaps and it does not exist on other
                # this will will make sure that it checks every key and value
                return False
        return True
