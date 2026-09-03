.syntax unified
	.text
	.align 2, 0
	.global ply_voice
	.thumb
	.thumb_func
	.type ply_voice, %function
ply_voice:
	.incbin "roms/B8CP.gba", 0x11e1fc, 0x30
.syntax divided
