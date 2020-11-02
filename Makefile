all:
	$(MAKE) -C tests/pcsx2 $@

clean:
	rm -rfv pcsx2/build tests/pcsx2/PCSX2

