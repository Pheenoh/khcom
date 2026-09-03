.syntax unified
	.text
	.align 2, 0
	.global task_smn_king_1
	.thumb
	.thumb_func
	.type task_smn_king_1, %function
task_smn_king_1:
	.incbin "roms/B8CP.gba", 0x493ec, 0x2fc
.syntax divided
