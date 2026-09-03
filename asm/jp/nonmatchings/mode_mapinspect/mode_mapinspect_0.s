.syntax unified
	.text
	.align 2, 0
	.global mode_mapinspect_0
	.thumb
	.thumb_func
	.type mode_mapinspect_0, %function
mode_mapinspect_0:
	.incbin "roms/B8CJ.gba", 0x108d38, 0x510
.syntax divided
