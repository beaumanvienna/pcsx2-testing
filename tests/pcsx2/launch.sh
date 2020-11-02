#!/bin/bash
rm -rf ~/.marley/PCSX2
mkdir ~/.marley/PCSX2

cp -v ~/dev/test-pcsx2/pcsx2/build/plugins/USBnull/libUSBnull-0.7.0.so ~/.marley/PCSX2/
cp -vr ~/tmp/sstates ~/.marley/PCSX2/

./PCSX2 ~/Gaming/PS2/Crash\ Nitro\ Kart\ \(Europe\)\ \(En,Fr,De,Es,It,Nl\).iso
