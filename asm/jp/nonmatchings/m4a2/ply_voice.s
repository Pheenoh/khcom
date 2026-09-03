.syntax unified
	.text
	.align 2, 0
	.global ply_voice
	.thumb
	.thumb_func
	.type ply_voice, %function
ply_voice:
	.incbin "roms/B8CJ.gba", 0x11f758, 0x30
.syntax divided
