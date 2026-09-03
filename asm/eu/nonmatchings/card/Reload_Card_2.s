.syntax unified
	.text
	.align 2, 0
	.global Reload_Card_2
	.thumb
	.thumb_func
	.type Reload_Card_2, %function
Reload_Card_2:
	.incbin "roms/B8CP.gba", 0x82a20, 0x174
.syntax divided
