#include <gtest/gtest.h>
#include <Sorting/Sorting.h>
#include <vector>



//
//TEST(Sorting, SelectionSort) {
//	vector<int> v = { 9,5,6,8,1,0,4,2,3,7 };
//	vector<int> v_sorted = { 0,1,2,3,4,5,6,7,8,9 };
//	stats statistic = selection_sort(v);
//	cout << "Comparison_count:" << statistic.comparison_count << " copy_count:" << statistic.copy_count << endl;
//	EXPECT_TRUE(v_sorted == v);
//}
//
//TEST(Sorting, ShellSort) {
//	vector<int> v = { 9,5,6,8,1,0,4,2,3,7 };
//	vector<int> v_sorted = { 0,1,2,3,4,5,6,7,8,9 };
//	stats statistic = shell_sort(v);
//	cout << "Comparison_count:" << statistic.comparison_count << " copy_count:" << statistic.copy_count << endl;
//	EXPECT_TRUE(v_sorted == v);
//}
//
//TEST(Sorting, HeapSort) {
//	vector<int> v = { 9,5,6,8,1,0,4,2,3,7 };
//	vector<int> v_sorted = { 0,1,2,3,4,5,6,7,8,9 };
//	stats statistic = heap_sort(v);
//	cout << "Comparison_count:" << statistic.comparison_count << " copy_count:" << statistic.copy_count << endl;
//	EXPECT_TRUE(v_sorted == v);
//}
//
//TEST(Sorting, SelectionSortBad) {
//	vector<int> v;
//	for (int i = 0; i != 10; ++i)
//		v.push_back(i);
//	stats statistic = selection_sort(v);
//	cout << "Comparison_count:" << statistic.comparison_count << " copy_count:" << statistic.copy_count << endl;
//}

#define SIZE 50000


TEST(Example2, AverageShellSort) {
	size_t sum_comparison = 0, sum_copy = 0;
	for (size_t i = 0; i < 100; ++i) {
		srand(i);
		vector<int> Tmp = generateRandomVector(SIZE);
		//vector<int> gmp = Tmp;
		stats tmp = shell_sort(Tmp);
		//sort(gmp.begin(), gmp.end());
		//EXPECT_TRUE(Tmp == gmp);
		sum_comparison += tmp.comparison_count;
		sum_copy += tmp.copy_count;
	}
	cout << "size: " << SIZE << endl;
	cout << "Average comparison quantity: " << sum_comparison / 100 << endl;
	cout << "Average copy quantity: " << sum_copy / 100 << endl;
}

TEST(Example2, AverageHeapSort) {
	size_t sum_comparison = 0, sum_copy = 0;
	for (size_t i = 0; i < 100; ++i) {
		srand(i);
		vector<int> Tmp = generateRandomVector(SIZE);
		stats tmp = heap_sort(Tmp);
		//vector<int> gmp = Tmp;
		/*sort(gmp.begin(), gmp.end());
		EXPECT_TRUE(Tmp == gmp);*/
		sum_comparison += tmp.comparison_count;
		sum_copy += tmp.copy_count;
	}
	cout << "size: " << SIZE << endl;
	cout << "Average comparison quantity: " << sum_comparison / 100 << endl;
	cout << "Average copy quantity: " << sum_copy / 100 << endl;
}

TEST(Example2, AverageSelectionSort) {
	size_t sum_comparison = 0, sum_copy = 0;
	for (size_t i = 0; i < 100; ++i) {
		srand(rand() + i);
		vector<int> Tmp = generateRandomVector(SIZE);
		//vector<int> gmp = Tmp;
		stats tmp = selection_sort(Tmp);
		//sort(gmp.begin(), gmp.end());
		//EXPECT_TRUE(Tmp == gmp);
		sum_comparison += tmp.comparison_count;
		sum_copy += tmp.copy_count;
	}
	cout << "size: " << SIZE << endl;
	cout << "Average comparison quantity: " << sum_comparison / 100 << endl;
	cout << "Average copy quantity: " << sum_copy / 100 << endl;
}