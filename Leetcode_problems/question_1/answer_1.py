class Solution(object):
    def containDuplicate(seld, nums):

        hashset = set()

        for i in nums:
            if i in hashset:
                return True
            hashset.add(i)
        return False


# We should be able to use hasmaps algorithm in order to resolve this question
# The time and space complexity would become O(n) as we are not creating a new array

# Yes, a HashSet does take up space. Its space complexity is linear,
# or O(n), where n is the number of items stored inside it.
