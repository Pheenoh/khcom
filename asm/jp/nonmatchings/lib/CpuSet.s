.syntax unified
	.align 2, 0
	.global CpuSet
	.thumb
	.thumb_func
	.type CpuSet, %function
CpuSet:
	.incbin "roms/B8CJ.gba", 0x118064, 0x8
.syntax divided
