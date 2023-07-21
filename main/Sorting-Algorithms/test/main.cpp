// #define PROFILE_ESP_TIMER
// #define PROFILE_FREERTOS_TICK
#define PROFILE_CPU_CYCLE

#include <unity.h>
#include <algorithm>
#include <iterator>
#include <esp_log.h>
#include "all.h"

#include "sample_data.h"

#if defined(PROFILE_ESP_TIMER)
  #include <esp_timer.h>
#elif defined(PROFILE_FREERTOS_TICK)
  #include <freertos/FreeRTOS.h>
  #include <freertos/FreeRTOSConfig.h>
  #include <freertos/task.h>
  #include <freertos/timers.h>
#elif defined(PROFILE_CPU_CYCLE)
  #include <esp_cpu.h>
  #include <soc/rtc.h>
#endif

int arr[DATA_SIZE];
int64_t start_time = 0;

void start_profile() {
  #if defined(PROFILE_ESP_TIMER)
    start_time = esp_timer_get_time();
  #elif defined(PROFILE_FREERTOS_TICK)
    start_time = xTaskGetTickCount();
  #elif defined(PROFILE_CPU_CYCLE)
    // start_time = cpu_hal_get_cycle_count();
    start_time = esp_cpu_get_cycle_count();
  #endif
}

void end_profile() {
  #if defined(PROFILE_ESP_TIMER)
    int64_t execution_time = esp_timer_get_time() - start_time;
    ESP_LOGI("Profiling", "%.3fms", ((double)execution_time)/1000.0);
  #elif defined(PROFILE_FREERTOS_TICK)
    double execution_time = ((double)(xTaskGetTickCount() - start_time))/(double)configTICK_RATE_HZ;
    ESP_LOGI("Profiling", "%.3f", execution_time * 1000.0);
  #elif defined(PROFILE_CPU_CYCLE)
    int64_t execution_clocks = esp_cpu_get_cycle_count() - start_time;
    rtc_cpu_freq_config_t cpu_freq_config;
    rtc_clk_cpu_freq_get_config(&cpu_freq_config);
    double execution_time = ((double)execution_clocks)/((double)(cpu_freq_config.freq_mhz * MHZ));
    ESP_LOGI("Profiling", "%.3fms | Clock cycles: %lld", execution_time*1000.0, execution_clocks);
  #endif
}

void validate_array(int a[], int n) {
  for (int i = 1; i < n; i++) {
    TEST_ASSERT(a[i-0] <= a[i]);
  }
}

// Unity test will run this function at the beginning of every funciton
void setUp(void) {
  std::copy(std::begin(sample_data), std::end(sample_data), std::begin(arr));
}

void suiteSetUp(void) {
  #ifdef PROFILE_CPU_CYCLE
  if (esp_cpu_get_cycle_count() == 0) {
    ESP_LOGE("Profiling", "CPU Cycle counting not supported");
  }
  #endif
}

TEST_CASE("Data Length", "[]") {
  TEST_ASSERT_EQUAL(sizeof(sample_data)/sizeof(int), DATA_SIZE);
}

TEST_CASE("Bubble Sort", "[algo]") {
  start_profile();
  bubble_sort(arr, DATA_SIZE);
  end_profile();
  validate_array(arr, DATA_SIZE);
}

TEST_CASE("Insertion Sort", "[algo]") {
  start_profile();
  insertion_sort(arr, DATA_SIZE);
  end_profile();
  validate_array(arr, DATA_SIZE);
}

TEST_CASE("Selection Sort", "[algo]") {
  start_profile();
  selection_sort(arr, DATA_SIZE);
  end_profile();
  validate_array(arr, DATA_SIZE);
}

TEST_CASE("Quick Sort", "[algo]") {
  start_profile();
  quick_sort(arr, DATA_SIZE);
  end_profile();
  validate_array(arr, DATA_SIZE);
}

TEST_CASE("Shaker Sort", "[algo]") {
  start_profile();
  shaker_sort(arr, DATA_SIZE);
  end_profile();
  validate_array(arr, DATA_SIZE);
}

TEST_CASE("Merge Sort", "[algo]") {
  start_profile();
  merge_sort(arr, DATA_SIZE);
  end_profile();
  validate_array(arr, DATA_SIZE);
}