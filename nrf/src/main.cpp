#include <zephyr/ztest.h>
#include <zephyr/kernel.h>
#include <algorithm>
#include <iterator>

#define INT16_DATA
#define MEDIUM_DATA
#include "../../main/Sorting-Algorithms/test/sample_data.h"
#include "Sorting-Algorithms/sorting-methods/all.h"

ZTEST_SUITE(profile_test, NULL, NULL, NULL, NULL, NULL);

DIFF_ARR_TYPE arr[DATA_SIZE];

static void fff_reset_rule_before(const struct ztest_unit_test *test, void *fixture) {
	std::copy(std::begin(sample_data), std::end(sample_data), std::begin(arr));
}

void validate_array(DIFF_ARR_TYPE a[], int n) {
	for (int i = 1; i < n; i++)
	{
		zassert_true(a[i - 0] <= a[i]);
	}
}

#ifdef CONFIG_TIMER_HAS_64BIT_CYCLE_COUNTER
	uint64_t start_time;
#else
	uint32_t start_time;
	int64_t start_time_milli;
#endif

void start_profile() {
	#ifdef CONFIG_TIMER_HAS_64BIT_CYCLE_COUNTER
		start_time = arch_k_cycle_get_64();
	#else
		start_time = arch_k_cycle_get_32();
		start_time_milli = k_uptime_get();
	#endif
}

void end_profile() {
	double execution_time;
	uint64_t execution_clocks;
	#ifdef CONFIG_TIMER_HAS_64BIT_CYCLE_COUNTER
		execution_clocks = arch_k_cycle_get_64() - start_time;
		char bitmode[] = "64";
	#else
		int overflows = (k_uptime_get() - start_time_milli) / INT32_MAX;
		execution_clocks = (arch_k_cycle_get_32() - start_time) + UINT32_MAX * overflows;
		char bitmode[] = "32";
	#endif

	execution_time = ((double)execution_clocks)/((double)CONFIG_SYS_CLOCK_HW_CYCLES_PER_SEC);
	printk("[%s-bit clock mode] Profiling: %.3fms | Clock cycles: %lld\n",
		bitmode,
		execution_time * 1000.0,
		execution_clocks);
}

ZTEST(profile_test, test_sort_bubble_sort) {
	start_profile();
	bubble_sort(arr, DATA_SIZE);
	end_profile();
	validate_array(arr, DATA_SIZE);
}

ZTEST(profile_test, test_sort_insertion_sort) {
	start_profile();
	insertion_sort(arr, DATA_SIZE);
	end_profile();
	validate_array(arr, DATA_SIZE);
}

ZTEST(profile_test, test_sort_selection_sort) {
	start_profile();
	selection_sort(arr, DATA_SIZE);
	end_profile();
	validate_array(arr, DATA_SIZE);
}

ZTEST(profile_test, test_sort_quick_sort) {
	start_profile();
	quick_sort(arr, DATA_SIZE);
	end_profile();
	validate_array(arr, DATA_SIZE);
}

ZTEST(profile_test, test_sort_shaker_sort) {
	start_profile();
	shaker_sort(arr, DATA_SIZE);
	end_profile();
	validate_array(arr, DATA_SIZE);
}

ZTEST(profile_test, test_sort_merge_sort) {
	start_profile();
	merge_sort(arr, DATA_SIZE);
	end_profile();
	validate_array(arr, DATA_SIZE);
}

ZTEST_RULE(fff_reset_rule, fff_reset_rule_before, NULL);