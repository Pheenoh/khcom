.syntax unified
	.align 2, 0
	.global event_chara_2
	.thumb
	.thumb_func
	.type event_chara_2, %function
event_chara_2:
	.incbin "roms/B8CJ.gba", 0x6e2bc, 0x134
.syntax divided
