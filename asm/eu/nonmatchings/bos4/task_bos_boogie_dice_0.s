.syntax unified
	.text
	.align 2, 0
	.global task_bos_boogie_dice_0
	.thumb
	.thumb_func
	.type task_bos_boogie_dice_0, %function
task_bos_boogie_dice_0:
	.incbin "roms/B8CP.gba", 0xd6940, 0x198
.syntax divided
