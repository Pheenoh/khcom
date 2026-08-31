.syntax unified
	.align 2, 0
	.global task_smn_tink_2
	.thumb
	.thumb_func
	.type task_smn_tink_2, %function
task_smn_tink_2:
	.incbin "roms/B8CJ.gba", 0x42e08, 0x128
.syntax divided
