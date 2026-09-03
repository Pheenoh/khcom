.syntax unified
	.text
	.align 2, 0
	.global CpuFastSet
	.thumb
	.thumb_func
	.type CpuFastSet, %function
CpuFastSet:
	.incbin "roms/B8CJ.gba", 0x118060, 0x4
.syntax divided
