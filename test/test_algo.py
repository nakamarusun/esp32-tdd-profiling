from pytest_embedded_qemu import QemuDut

def test_app(dut: QemuDut, record_property):
    record_property("bruh", [1, 2, 3, 4, 5])
    record_property("bruh", "test")
    dut.expect_unity_test_output(timeout=30)