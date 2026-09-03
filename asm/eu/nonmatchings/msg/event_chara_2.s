.syntax unified
	.text
	.align 2, 0
	.global event_chara_2
	.thumb
	.thumb_func
	.type event_chara_2, %function
event_chara_2:
	.incbin "roms/B8CP.gba", 0x6d790, 0x134
.syntax divided
