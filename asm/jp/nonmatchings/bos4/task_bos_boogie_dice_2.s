.syntax unified
	.align 2, 0
	.global task_bos_boogie_dice_2
	.thumb
	.thumb_func
	.type task_bos_boogie_dice_2, %function
task_bos_boogie_dice_2:
	.incbin "roms/B8CJ.gba", 0xda30c, 0xd8
.syntax divided
