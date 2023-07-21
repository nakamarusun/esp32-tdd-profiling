# Test Driven Development with Profiling in ESP32

### Usage
1. Have QEMU (Espressif fork) and ESP-IDF installed. Make sure that when installing ESP-IDF, pytest is instealled.
2. Go to test directory and build
```
cd test
idf.py build
```
3. Run pytest
```
pytest -s --target esp32 --embedded-services idf,qemu
```