#include <stdio.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

extern "C" void app_main(void)
{
  int n = 0;
  while (1) {
    ESP_LOGI("TEST", "Printing number %d", n++);
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}
