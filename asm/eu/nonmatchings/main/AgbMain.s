.syntax unified
	.text
	.align 2, 0
	.global AgbMain
	.thumb
	.thumb_func
	.type AgbMain, %function
AgbMain:
	.incbin "roms/B8CP.gba", 0x490, 0x90
.syntax divided
