#include <gtest/gtest.h>
#include <Sorting/Sorting.h>
#include <vector>

#define SIZE 10000



TEST(Sorting, SelectionSort) {
	vector<int> v = { 9,5,6,8,1,0,4,2,3,7 };
	vector<int> v_sorted = { 0,1,2,3,4,5,6,7,8,9 };
	stats statistic = selection_sort(v);
	cout << "Comparison_count:" << statistic.comparison_count << " copy_count:" << statistic.copy_count << endl;
	EXPECT_TRUE(v_sorted == v);
}

TEST(Sorting, ShellSort) {
	vector<int> v = { 9,5,6,8,1,0,4,2,3,7 };
	vector<int> v_sorted = { 0,1,2,3,4,5,6,7,8,9 };
	stats statistic = shell_sort(v);
	cout << v.size() << endl;
	cout << "Comparison_count:" << statistic.comparison_count << " copy_count:" << statistic.copy_count << endl;
	EXPECT_TRUE(v_sorted == v);
}

TEST(Sorting, HeapSort) {
	vector<int> v = { 9,5,6,8,1,0,4,2,3,7 };
	vector<int> v_sorted = { 0,1,2,3,4,5,6,7,8,9 };
	stats statistic = heap_sort(v);
	cout << "Comparison_count:" << statistic.comparison_count << " copy_count:" << statistic.copy_count << endl;
	EXPECT_TRUE(v_sorted == v);
}

TEST(Sorting, SelectionSortBad) {
	vector<int> v;
	for (int i = 0; i != 10; ++i)
		v.push_back(i);
	stats statistic = selection_sort(v);
	cout << "Comparison_count:" << statistic.comparison_count << " copy_count:" << statistic.copy_count << endl;
}




TEST(Example2a, AverageShellSort) {
	size_t sum_comparison = 0, sum_copy = 0;
	for (size_t i = 0; i < 100; ++i) {
		srand(i);
		vector<int> Tmp = generate_random_vector(SIZE);
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

TEST(Example2a, AverageHeapSort) {
	size_t sum_comparison = 0, sum_copy = 0;
	for (size_t i = 0; i < 100; ++i) {
		srand(i);
		vector<int> Tmp = generate_random_vector(SIZE);
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

TEST(Example2a, AverageSelectionSort) {
	size_t sum_comparison = 0, sum_copy = 0;
	for (size_t i = 0; i < 100; ++i) {
		srand(rand() + i);
		vector<int> Tmp = generate_random_vector(SIZE);
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


TEST(Example2b, AverageShellSort) {
	size_t sum_comparison = 0, sum_copy = 0;
	for (size_t i = 0; i < 100; ++i) {
		vector<int> Tmp = generate_sorted_vector(SIZE);
		stats tmp = shell_sort(Tmp);
		sum_comparison += tmp.comparison_count;
		sum_copy += tmp.copy_count;
	}
	cout << "size: " << SIZE << endl;
	cout << "Average comparison quantity: " << sum_comparison / 100 << endl;
	cout << "Average copy quantity: " << sum_copy / 100 << endl;
}






TEST(Example2b, SortedSelectionSort) {
	vector<int> Tmp = generate_sorted_vector(SIZE);
	stats tmp = selection_sort(Tmp);
	cout << "size: " << SIZE << endl;
	cout << "comparison quantity: " << tmp.comparison_count << endl;
	cout << "copy quantity: " << tmp.copy_count << endl;
}
TEST(Example2c, InvertedSelectionSort) {
	vector<int> Tmp = generate_inverted_vector(SIZE);
	stats tmp = selection_sort(Tmp);
	cout << "size: " << SIZE << endl;
	cout << "comparison quantity: " << tmp.comparison_count << endl;
	cout << "copy quantity: " << tmp.copy_count << endl;
}

TEST(Example2b, SortedShellSort) {
	vector<int> Tmp = generate_sorted_vector(SIZE);
	stats tmp = shell_sort(Tmp);
	cout << "size: " << SIZE << endl;
	cout << "comparison quantity: " << tmp.comparison_count << endl;
	cout << "copy quantity: " << tmp.copy_count << endl;
}
TEST(Example2c, InvertedShellSort) {
	vector<int> Tmp = generate_inverted_vector(SIZE);
	stats tmp = shell_sort(Tmp);
	cout << "size: " << SIZE << endl;
	cout << "comparison quantity: " << tmp.comparison_count << endl;
	cout << "copy quantity: " << tmp.copy_count << endl;
}

TEST(Example2b, SortedHeapSort) {
	vector<int> Tmp = generate_sorted_vector(SIZE);
	stats tmp = heap_sort(Tmp);
	cout << "size: " << SIZE << endl;
	cout << "comparison quantity: " << tmp.comparison_count << endl;
	cout << "copy quantity: " << tmp.copy_count << endl;
}
TEST(Example2c, InvertedHeapSort) {
	vector<int> Tmp = generate_inverted_vector(SIZE);
	stats tmp = heap_sort(Tmp);
	cout << "size: " << SIZE << endl;
	cout << "comparison quantity: " << tmp.comparison_count << endl;
	cout << "copy quantity: " << tmp.copy_count << endl;
}
TEST(Example2b, AverageSelectionSort) {
	size_t sum_comparison = 0, sum_copy = 0;
	for (size_t i = 0; i < 100; ++i) {
		vector<int> Tmp = generate_sorted_vector(SIZE);
		stats tmp = selection_sort(Tmp);
		sum_comparison += tmp.comparison_count;
		sum_copy += tmp.copy_count;
	}
	cout << "size: " << SIZE << endl;
	cout << "Average comparison quantity: " << sum_comparison / 100 << endl;
	cout << "Average copy quantity: " << sum_copy / 100 << endl;
}
TEST(Example3, SelectionSort) {
	vector<int> v = generate_inverted_vector(SIZE);
	vector<int> v_sorted = generate_sorted_vector(SIZE);
	stats statistic = selection_sort(v.begin(), v.end());
	cout << "Comparison_count:" << statistic.comparison_count << " copy_count:" << statistic.copy_count << endl;
	EXPECT_TRUE(v_sorted == v);
}

TEST(Example3, InvertedShellSort) {
	vector<int> Tmp = generate_inverted_vector(SIZE);
	vector<int> v_sorted = generate_sorted_vector(SIZE);
	stats tmp = shell_sort(Tmp.begin(), Tmp.end());
	cout << "size: " << SIZE << endl;
	cout << "comparison quantity: " << tmp.comparison_count << endl;
	cout << "copy quantity: " << tmp.copy_count << endl;
	EXPECT_TRUE(v_sorted == Tmp);
}
TEST(Example3, InvertedHeapSort) {
	vector<int> Tmp = generate_inverted_vector(SIZE);
	vector<int> v_sorted = generate_sorted_vector(SIZE);
	stats tmp = heap_sort(Tmp.begin(), Tmp.end());
	cout << "size: " << SIZE << endl;
	cout << "comparison quantity: " << tmp.comparison_count << endl;
	cout << "copy quantity: " << tmp.copy_count << endl;
	EXPECT_TRUE(v_sorted == Tmp);
}