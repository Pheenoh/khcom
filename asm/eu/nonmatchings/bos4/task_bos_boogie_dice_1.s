.syntax unified
	.text
	.align 2, 0
	.global task_bos_boogie_dice_1
	.thumb
	.thumb_func
	.type task_bos_boogie_dice_1, %function
task_bos_boogie_dice_1:
	.incbin "roms/B8CP.gba", 0xd6ad8, 0x5d0
.syntax divided
