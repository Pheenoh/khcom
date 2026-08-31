.syntax unified
	.align 2, 0
	.global task_smn_tinkeff_3
	.thumb
	.thumb_func
	.type task_smn_tinkeff_3, %function
task_smn_tinkeff_3:
	.incbin "roms/B8CJ.gba", 0x430e8, 0x18
.syntax divided
