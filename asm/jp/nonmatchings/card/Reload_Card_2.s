.syntax unified
	.text
	.align 2, 0
	.global Reload_Card_2
	.thumb
	.thumb_func
	.type Reload_Card_2, %function
Reload_Card_2:
	.incbin "roms/B8CJ.gba", 0x833a8, 0x174
.syntax divided
