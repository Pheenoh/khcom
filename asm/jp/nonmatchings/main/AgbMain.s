.syntax unified
	.align 2, 0
	.global AgbMain
	.thumb
	.thumb_func
	.type AgbMain, %function
AgbMain:
	.incbin "roms/B8CJ.gba", 0x44c, 0x90
.syntax divided
