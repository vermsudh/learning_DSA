int arr = { 2, 1, 3 , 4};

Nummber of student M  : 2

Number of books N = 4;


---

We know that we wont be able to do binary search on this orginal array, so we would have to do binary search on the possible values. We know the values in the array are the pages of each books. We so we can take our left as 0

and end = sum of all pages. The ans will lie somewhere in between. 

int start = 0

int sum = 0;

for(int i = 0; i < arr.size(); i++)){

	sum += arr[i];

}

int end = sum; (//10)

We will do binary search from 1 to 10 now.

while(start <= end){

	int mid = start + (end - start)/2;

	

}
