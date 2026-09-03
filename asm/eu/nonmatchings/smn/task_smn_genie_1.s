.syntax unified
	.text
	.align 2, 0
	.global task_smn_genie_1
	.thumb
	.thumb_func
	.type task_smn_genie_1, %function
task_smn_genie_1:
	.incbin "roms/B8CP.gba", 0x48a18, 0x6bc
.syntax divided
