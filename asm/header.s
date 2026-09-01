	.arm
	.section .text
	.global _start
_start:
	b EntryPoint

RomHeaderNintendoLogo:
	.space 156
RomHeaderGameTitle:
	.space 12
RomHeaderGameCode:
	.space 4
RomHeaderMakerCode:
	.space 2
RomHeaderMagic:
	.byte 0
RomHeaderMainUnitCode:
	.byte 0
RomHeaderDeviceType:
	.byte 0
RomHeaderReserved1:
	.space 7
RomHeaderSoftwareVersion:
	.byte 0
RomHeaderComplementCheck:
	.byte 0
RomHeaderReserved2:
	.space 2
