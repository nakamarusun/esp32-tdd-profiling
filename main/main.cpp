#include <stdio.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <Sorting-Algorithms/sorting-methods/all.h>

extern "C" void app_main(void)
{
  // Normal code is placed here
  int n = 0;
  while (1) {
    int arr[5] = {5, 2, 3, 1, 4};
    bubble_sort(arr, 5);
    for (int i = 0; i < 5; i++) {
      printf("%d ");
    }
    printf("\n");
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}
