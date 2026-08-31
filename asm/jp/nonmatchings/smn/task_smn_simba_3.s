.syntax unified
	.align 2, 0
	.global task_smn_simba_3
	.thumb
	.thumb_func
	.type task_smn_simba_3, %function
task_smn_simba_3:
	.incbin "roms/B8CJ.gba", 0x436c8, 0x48
.syntax divided
