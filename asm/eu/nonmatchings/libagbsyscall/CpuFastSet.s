.syntax unified
	.text
	.align 2, 0
	.global CpuFastSet
	.thumb
	.thumb_func
	.type CpuFastSet, %function
CpuFastSet:
	.incbin "roms/B8CP.gba", 0x116afc, 0x4
.syntax divided
