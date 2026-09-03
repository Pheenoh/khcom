.syntax unified
	.text
	.align 2, 0
	.global CpuSet
	.thumb
	.thumb_func
	.type CpuSet, %function
CpuSet:
	.incbin "roms/B8CP.gba", 0x116b00, 0xc
.syntax divided
