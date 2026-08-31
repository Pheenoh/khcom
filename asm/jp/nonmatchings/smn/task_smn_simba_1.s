.syntax unified
	.align 2, 0
	.global task_smn_simba_1
	.thumb
	.thumb_func
	.type task_smn_simba_1, %function
task_smn_simba_1:
	.incbin "roms/B8CJ.gba", 0x43244, 0x35c
.syntax divided
