// #include <zephyr/kernel.h>
// #include <zephyr/ztest.h>

// ZTEST(hello_world, test_assert) {
// 	TC_PRINT("Hello world\n");
// 	zassert_true(1, "1 was false");
// 	zassert_false(0, "0 was true");
// 	zassert_is_null(NULL, "NULL was not NULL");
// 	zassert_not_null("foo", "\"foo\" was NULL");
// 	zassert_equal(1, 1, "1 was not equal to 1");
// 	zassert_equal_ptr(NULL, NULL, "NULL was not equal to NULL");
// }

// ZTEST(hello_world, test_assert) {
// 	zassert_equal(1, 1, "1 was not equal to 1");
// }

// ZTEST_SUITE(hello_world, NULL, NULL, NULL, NULL, NULL);

/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/ztest.h>
#include <algorithm>
#include <iterator>

#include "Sorting-Algorithms/sorting-methods/all.h"

#define SMALL_DATA
#include "../../main/Sorting-Algorithms/test/sample_data.h"

ZTEST_SUITE(profile_test, NULL, NULL, NULL, NULL, NULL);

int arr[DATA_SIZE];

static void fff_reset_rule_before(const struct ztest_unit_test *test, void *fixture) {
	std::copy(std::begin(sample_data), std::end(sample_data), std::begin(arr));
}

void validate_array(int a[], int n) {
	for (int i = 1; i < n; i++)
	{
		zassert_true(a[i - 0] <= a[i]);
	}
}

ZTEST(profile_test, test_bubble_sort)
{
	bubble_sort(arr, DATA_SIZE);
	validate_array(arr, DATA_SIZE);
}

ZTEST(profile_test, test_insertion_sort)
{
	insertion_sort(arr, DATA_SIZE);
	validate_array(arr, DATA_SIZE);
}

ZTEST(profile_test, test_selection_sort)
{
	selection_sort(arr, DATA_SIZE);
	validate_array(arr, DATA_SIZE);
}

ZTEST(profile_test, test_quick_sort)
{
	quick_sort(arr, DATA_SIZE);
	validate_array(arr, DATA_SIZE);
}

ZTEST(profile_test, test_shaker_sort)
{
	shaker_sort(arr, DATA_SIZE);
	validate_array(arr, DATA_SIZE);
}

ZTEST(profile_test, test_merge_sort)
{
	merge_sort(arr, DATA_SIZE);
	validate_array(arr, DATA_SIZE);
}

ZTEST_RULE(fff_reset_rule, fff_reset_rule_before, NULL);