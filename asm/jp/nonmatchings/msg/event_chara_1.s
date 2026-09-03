.syntax unified
	.align 2, 0
	.global event_chara_1
	.thumb
	.thumb_func
	.type event_chara_1, %function
event_chara_1:
	.incbin "roms/B8CJ.gba", 0x6e040, 0x27c
.syntax divided
