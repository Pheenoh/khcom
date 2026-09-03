.syntax unified
	.text
	.align 2, 0
	.global Deck_Clear_0
	.thumb
	.thumb_func
	.type Deck_Clear_0, %function
Deck_Clear_0:
	.incbin "roms/B8CP.gba", 0xa3ae8, 0x174
.syntax divided
