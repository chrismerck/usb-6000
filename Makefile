all:
	g++ -lusb-1.0 -I/usr/include/libusb-1.0 main.cpp -onidaq

clean:
	rm -f nidaq
