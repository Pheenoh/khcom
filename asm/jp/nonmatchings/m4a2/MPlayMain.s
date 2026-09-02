.syntax unified
	.align 2, 0
	.global MPlayMain
	.thumb
	.thumb_func
	.type MPlayMain, %function
MPlayMain:
	.incbin "roms/B8CJ.gba", 0x11f828, 0x27c
.syntax divided
