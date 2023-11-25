#pragma once
#include <cmath>
#include <stdexcept>
#include <iostream>
#include <random>
#include <complex>
#include <vector>

using namespace std;

struct stats {
    size_t comparison_count = 0;
    size_t copy_count = 0;
};


stats selection_sort(vector<int>& arr)
{
    stats result;
    size_t size = arr.size();
    if (size < 2)
        return result;

    for (size_t i = 0; i < size - 1; ++i)
    {
        size_t min_index = i;
        for (size_t j = i + 1; j < size; ++j)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
            ++result.comparison_count;
        }
        if (min_index != i)
        {
            swap(arr[i], arr[min_index]);
            ++result.copy_count;
        }
    }
    return result;
}


stats shell_sort(vector<int>& arr)
{
    stats result;
    size_t size = arr.size();
    size_t i, j, step;
    for (step = size / 2; step > 0; step /= 2)
        for (i = step; i < size; ++i)
        {
            size_t tmp = arr[i];
            ++result.copy_count;
            for (j = i; j >= step; j -= step)
            {
                ++result.comparison_count;
                if (tmp < arr[j - step])
                    arr[j] = arr[j - step];
                else
                    break;
            }
            arr[j] = tmp;
        }
    return result;
}

void heapify(vector<int>& arr, size_t size, size_t i, stats& result)
{
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest]) {
        largest = left;
        ++result.comparison_count;
    }

    if (right < size && arr[right] > arr[largest]) {
        largest = right;
        ++result.comparison_count;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        ++result.copy_count;
        heapify(arr, size, largest, result);
    }
}


stats heap_sort(vector<int>& arr)
{
    stats result;
    size_t size = arr.size();
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i, result);

    for (int i = size - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        ++result.copy_count;
        heapify(arr, i, 0, result);
    }
    return result;
}

vector<int> generateRandomVector(size_t n) {
    vector<int> result;
    for (size_t i = 0; i < n; ++i) {
        result.push_back(rand() % 100);
    }
    return result;
}