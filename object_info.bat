avr-objcopy -O binary -R .eeprom  main.elf main.bin
avr-objcopy -O ihex -R .eeprom  main.elf main.hex
avr-objcopy -j .eeprom --set-section-flags=.eeprom="alloc,load" --change-section-lma .eeprom=0 --no-change-warnings -O ihex main.elf main.eep
avr-objdump -dt main.elf > main.lss
rem test_fp_use.bat main.lss
rem overall_info.bat main.lss femtoos_shared.i main.map > main.defs
echo ""
avr-size main.elf | C:\WinAVR-20100110\utils\bin\tee.exe main.size
rem overall_info main.lss femtoos_shared.i main.map labels

