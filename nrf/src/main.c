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
#include "all.h"

ZTEST_SUITE(framework_tests, NULL, NULL, NULL, NULL, NULL);


ZTEST(framework_tests, test_assert)
{
	zassert_true(1, "1 was false");
	zassert_false(0, "0 was true");
	zassert_is_null(NULL, "NULL was not NULL");
	zassert_not_null("foo", "\"foo\" was NULL");
	zassert_equal(1, 1, "1 was not equal to 1");
	zassert_equal_ptr(NULL, NULL, "NULL was not equal to NULL");
}