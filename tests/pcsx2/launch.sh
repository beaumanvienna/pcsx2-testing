#!/bin/bash
rm -rf ~/.marley/PCSX2
mkdir ~/.marley/PCSX2

cp -vr ~/tmp/sstates ~/.marley/PCSX2/

./PCSX2 ~/Gaming/PS2/Crash\ Nitro\ Kart\ \(Europe\)\ \(En,Fr,De,Es,It,Nl\).iso
