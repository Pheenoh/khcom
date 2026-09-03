.syntax unified
	.text
	.align 2, 0
	.global task_smn_tink_1
	.thumb
	.thumb_func
	.type task_smn_tink_1, %function
task_smn_tink_1:
	.incbin "roms/B8CJ.gba", 0x4291c, 0x4ec
.syntax divided
