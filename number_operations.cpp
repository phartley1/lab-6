#include <iostream> 
using namespace std;

int sum(int* nums, int size);
int* odds(int* nums, int size);
double getAverage(int arr[], int size);
void changeValue(int* nums, int new_value, int index);

/*
This main function has an array of integers and performs various operations on them.
There are bugs throughout - use GDB to try and find the errors. Refer to the comments
above each function as to what it is supposed to do
*/
int main() {
	// array of numbers to have operations performed on it
	int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int nums_size = (sizeof(nums))/4; 
	/*error here: nums_size is 40, because each element is 4 bits, need to divide 
	by 4 (used print nums_size & breakpoint)*/

	// getting array of odds and printing them out
	int * o = odds(nums, nums_size);
	cout << "ODD NUMBERS: " << endl;
	for (int i = 0; i < 10; i++) {
		cout << *(o + i) << endl;
	}
	//breaked to find issue is within function

	// getting sum of the array 
	int s = sum(nums, nums_size);
	cout << "SUM: " << endl;
	cout << s << endl;
	//works with nums_size = 10 rather than 40

	// average value of the numbers in nums
	double average = getAverage(nums, nums_size);
	cout << "AVERAGE: " << endl;
	cout << average << endl;
	// issue within function

	changeValue(nums, 2343, 6);
	cout << "NEW VALUE INSERTED: " << endl;
	for (int i = 0; i < 10; i++) {
		cout << *(nums + i) << endl;
	}
}


// takes an array and a size as input and returns the sum of the elements
int sum(int* nums, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += *(nums + i);
	}
	return sum;
}

/*
 takes an array of numbers and it's size and returns an array of the same size
 but with only the odd numbers in the original array. The rest of the values in the
 new array are 0's. The odd values found in the original array should be placed into
 the new array starting at 0

 example:
 
 nums[5] = {1, 2, 7, 8, 8};
 odds[5] = {1, 7, 0, 0, 0}; <- array returned

 */
int* odds(int* nums, int size) {
	static int odds[10]; 
	int j = 0;
	for (int i = 0; i < size; i++){
		if ( *(nums + i) % 2 != 0 ) { 
		/*needs to function only if number in array is odd, stepped through*/
			odds[j] = *(nums + i); 
			j++;
		}
	}
	return odds;

}

/*
  Takes an array of numbers and it's size and returns the average 
  of the numbers inside the array
*/
double getAverage(int* nums, int size) {
  int sum;       
  double avg;          

   for (int i = 0; i < size; i++) { //added 1 too many elements. stepped, printed sum.
      sum += *(nums + i);
   }
   avg = double(sum) / size;

   return avg;
}

/*
This function takes an array, a new value to be assigned, and the position of 
the new value to be overwritten
*/
void changeValue(int* nums, int new_value, int index) {
	*(nums + (index)) = new_value; 
	/* doesn't actually change index value bc of formatting, no returned value, 
	corrected pointers */
}