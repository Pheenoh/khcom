.syntax unified
	.align 2, 0
	.global CgbSound
	.thumb
	.thumb_func
	.type CgbSound, %function
CgbSound:
	.incbin "roms/B8CJ.gba", 0x120ad0, 0x480
.syntax divided
